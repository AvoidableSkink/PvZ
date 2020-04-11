#include "GameModel.h"
#include "mpi.h"


#define MCW MPI_COMM_WORLD

//GAME_STATUS -1 is lost, otherwise processor who ended game first

int main(int argc, char**argv){
	int rank, size;
	MPI_Status mystatus;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);
	int game_status = 1;

    GameModel gameModel;
	int mode = 1;

    while(game_status == 1) {


		//Communicate with other processes
		int flag;

		MPI_Iprobe(MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,&flag,MPI_STATUS_IGNORE);
		while(mode){
			int ender_rank;
			MPI_Recv(&ender_rank,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,MPI_STATUS_IGNORE);
			game_status = false;
				//Game status is the rank of the processor that ended the game
				if(rank == ender_rank -1){
					break;
				}else{

					MPI_Send(&ender_rank,1,MPI_INT,rank+1,1,MCW);
					mode = false;
					break;

				}
				//if not the last processor tell the next processor the game is over

			} 

		// GAME 
		gameModel.Update();

		MPI_Barrier(MCW);
		gameModel.Render();

		//1 means game is ongoing, 0 is won, -1 is lost
		game_status = gameModel.getStatus();	

		//Tell other processors the game is over
			if(game_status != 1 && mode == 1){
				if(game_status == -1){
					std::cout<<"THE ZOMBIES ATE YOUR BRAINS\n";
				}else{
					std::cout<<"Ok, you win. No more eatin brains for us. We just want to make music video with you now. sincerely,\n the Zombies";
						
				}
				MPI_Send(&rank,1,MPI_INT,rank+1,1,MCW);
			}

	MPI_Barrier(MCW);
	}





    
	

	MPI_Finalize();
	return 0;
}
