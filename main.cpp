#include<mpi.h>



int main(int argc, char**argv){
	int rank, size;
	MPI_Status mystatus;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);
	
// Game




	MPI_Finalize();
	return 0;
}
