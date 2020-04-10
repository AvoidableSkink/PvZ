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
	GameModel Game_Model; // or we could do this per processor or something...

	while(alive){
		Game_Model.Update();
		Game_Model.Render();
			MPI_Barrier(MCW);
	}
//send death message or cleared message





	MPI_Finalize();
	return 0;
}
