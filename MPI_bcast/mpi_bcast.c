#include <stdio.h>
#include "mpi.h"


int main(argc, argv)
int argc;
char **argv;
{
	int rank, value;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //what rank is the current processor

    value = rank*2 + 1;
    if (rank == 0) {
        // if root process we assign the value to broadcast
	value = 40;
    } else {
    	printf("process %d: Before MPI_Bcast, value is %d\n", rank, value); 
	}

    // root process uses MPI_Bcast to broadcast the value, each other process uses MPI_Bcast to receive the broadcast value
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("process %d: After MPI_Bcast, value is %d\n", rank, value);

    MPI_Finalize();

	return 0;
}

