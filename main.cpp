#include "GameModel.h"
#include "mpi.h"


#define MCW MPI_COMM_WORLD

//GAME_STATUS -1 is lost, otherwise processor who ended game first

int main(int argc, char**argv)
{
    int rank, size;
    MPI_Status mystatus;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    int game_status = 1; 	//1 means game is ongoing, 0 is won, -1 is lost
    bool prior_processor_won = false;
    bool not_heard_from_prior_processor = true;
    GameModel gameModel(rank);
    int mode = 1; //used to get message from prior processor while game is ongoing
    int flag; //flag in message
    int ender_rank; // the processor that lost the game

    //for sending and recieving mesages
    int next;
    int prev;
    next = rank +1;
    prev = rank -1;
    if(next + 1 >= size){ next = 0;}
    if(prev - 1 < 0){ prev = size-1;}


    //1 means game is ongoing, 0 is won, -1 is lost
    while(game_status == 1) 
	{
      //every processor controls a 1 X 10 row

	  //Communicate with other processes

		if(not_heard_from_prior_processor)
		{
			MPI_Iprobe(MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,&flag,MPI_STATUS_IGNORE);
			while(mode)
			{
				MPI_Recv(&ender_rank,1,MPI_INT,prev,MPI_ANY_TAG,MCW,MPI_STATUS_IGNORE);
				if(ender_rank == -100)
				{
					prior_processor_won = true;
					not_heard_from_prior_processor = false;
					break;
				}

				//if not the last processor tell the next processor the game is over
				if(rank == ender_rank -1 || (ender_rank == 0 && rank == size-1) )
				{
					break;

				} else {

					int next;
					next = rank +1;
					if(next +1 >= size){ next = 0;}
					MPI_Send(&ender_rank,1,MPI_INT,next,1,MCW);
					mode = false;
					break;
				}

			} 
		}

		//end communicate with others

		// GAME PLAY
std::cout << "gon update" << std::endl;
		gameModel.Update();
std::cout << "updated" << std::endl;
		MPI_Barrier(MCW);
std::cout << "made it lmao" << std::endl;

		//kinda hacky way to get the rank 0 to render first...
		//this is important so that it can clear the screen each time
		if(rank == 0)
		    gameModel.Render();
		MPI_Barrier(MCW);
		if(rank!=0)
		    gameModel.Render();

		//checking game status
		//1 means game is ongoing, 0 is won, -1 is lost
		game_status = gameModel.getStatus();	

		//If this processor reports the game is over
		if(game_status != 1)
		{
			if(game_status == -1)
			{
				std::cout<<"THE ZOMBIES ATE YOUR BRAINS\n";
				MPI_Send(&rank,1,MPI_INT,next,1,MCW);
			}

		} else 
		{
			break;
		}

		MPI_Barrier(MCW);
    }

    if(game_status == 0 && prior_processor_won && !not_heard_from_prior_processor)
	{	
		int wonSoFar = -100;
		MPI_Send(&wonSoFar,1,MPI_INT,next,1,MCW);

    }

    if(not_heard_from_prior_processor)
	{
		MPI_Iprobe(prev,MPI_ANY_TAG,MCW,&flag,MPI_STATUS_IGNORE);
		MPI_Recv(&ender_rank,1,MPI_INT,prev,MPI_ANY_TAG,MCW,MPI_STATUS_IGNORE);
		//if this won and the prior ones won
		if(ender_rank == -100)
		{
			prior_processor_won = true;
			not_heard_from_prior_processor = false;
			MPI_Send(&ender_rank,1,MPI_INT,next,1,MCW);
		}
    }


    MPI_Finalize();
    return 0;
}
