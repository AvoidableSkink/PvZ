#include "GameModel.h"
#include "mpi.h"


#define MCW MPI_COMM_WORLD

int main(int argc, char**argv){
	int rank, size;
	MPI_Status mystatus;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);
	int alive = true;

    GameModel gameModel;

    std::cout << "test" << std::endl;
    while(alive) {
	gameModel.Update();

	//some sort of way to get each processor to render in the correct order...
	//gameModel.render();
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
