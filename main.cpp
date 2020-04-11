#include "GameModel.h"
#include "mpi.h"


#define MCW MPI_COMM_WORLD

//GAME_STATUS 1 is won, 0 is lost

int main(int argc, char**argv){
	int rank, size;
	MPI_Status mystatus;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);
	bool game_ongoing = true;

    GameModel gameModel;

    std::cout << "test" << std::endl;
    while(game_ongoing) {

	// CHECK if the prior processors are dead od done
	int flag;

	MPI_Iprobe(MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,&flag,MPI_STATUS_IGNORE);
	//work
	while(flag){
		MPI_Recv(&GAME_STATUS,1,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,MPI_STATUS_IGNORE);
		game_ongoing = false;
			//send status to the next processor

			//if not the last processor tell the next processor the game is over
			if(rank < size-1){
				MPI_Send(&GAME_STATUS,1,MPI_INT,rank+1,1,MCW);
			else{
				//if this is the last processor tell the user the game is over and the result
				if(GAME_STATUS ==0){
					std::cout<<"THE ZOMBIES ATE YOUR BRAINS\n";
				}else{
					std::cout<<"Ok, you win. No more eatin brains for us. We just want to make music video with you now. sincerely,\n the Zombies";
				}

			}} 

		}

		MPI_Iprobe(MPI_ANY_SOURCE,MPI_ANY_TAG,MCW,&flag,MPI_STATUS_IGNORE);
	}





	gameModel.Update();

	MPI_Barrier(MCW);
	gameModel.Render();
	game_ongoing = gameModel.getStatus();
    }	
	
	/*GameModel Game_Model; // or we could do this per processor or something...
	std::cout<<"test\n";
	while(alive){
		Game_Model.Update();
		Game_Model.Render();
			MPI_Barrier(MCW);
	}

	*/
//send death message or cleared message





	MPI_Finalize();
	return 0;
}
