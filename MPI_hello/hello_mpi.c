# include <stdlib.h>
# include <stdio.h>
# include <time.h>

# include "mpi.h"

int main ( int argc, char *argv[] );
void timestamp ( );

/******************************************************************************/

int main ( int argc, char *argv[] )

/******************************************************************************/
{
  int id;
  int ierr;
  int p;
  double wtime;
/*
  Initialize MPI.
*/
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    printf ( "\n" );
    printf ( "HELLO_MPI - Fatal error!\n" );
    printf ( "  MPI_Init returned nonzero IERR.\n" );
    exit ( 1 );
  }
/*
  Get the number of processes.
*/
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );
/*
  Get the individual process ID.
*/
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );
/*
  Process 0 prints an introductory message.
*/
  if ( id == 0 ) 
  {
    wtime = MPI_Wtime ( );

    printf ( "\n" );
    printf ( "P%d:  HELLO_MPI - Master process:\n", id );
    printf ( "\n" );
  }
/*
  Every process prints a hello.
*/
  printf ( "P%d:    'Hello, world!'\n", id );

  if ( id == 0 )
  {
    wtime = MPI_Wtime ( ) - wtime;
    printf ( "P%d:    Elapsed wall clock time = %f seconds.\n", id, wtime );
  }
/*
  Terminate MPI.
*/
  ierr = MPI_Finalize ( );
/*
  Terminate
*/
  if ( id == 0 )
  {
    printf ( "\n" );
    printf ( "P%d:  HELLO_MPI - Master process:\n", id );
    printf ( "P%d:    Normal end of execution: 'Goodbye!'\n", id );
    printf ( "\n" );
    timestamp ( );
  }
  return 0;
}
/******************************************************************************/

void timestamp ( )

/******************************************************************************/
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}

