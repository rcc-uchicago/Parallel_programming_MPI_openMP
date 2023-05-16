#include <stdio.h>
#include "mpi.h"

int main( int argc, char **argv )
{
    int isend, irecv[8];
    int rank, size;
    int i;

    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    isend = rank + 1;

    MPI_Gather(&isend, 1, MPI_INT, &irecv, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0)
	    for (i=0; i<size; i++)
		     printf("%d: irecv = %d! \n", i, irecv[i]);
		    //printf("%d!",i);


    MPI_Finalize();
    return 0;
}

