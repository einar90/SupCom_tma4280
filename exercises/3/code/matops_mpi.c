#include "stdio.h"
#include "openmpi-x86_64/mpi.h"

int main(int argc, char const *argv[])
{
  int rank, size, tag, i;
  MPI_Status status;
  char message[20];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, & rank);

  tag = 100;

  if (rank == 0) {
    strcpy (message, "Hello, world");
    for (i=1; i < size; i++) {
      MPI_Send (  message,      // Initial address of send buffer (pointer)
                  13,           // Number of elements in send buffer (integer)
                  MPI_CHAR,     // Datatype of each send buffer element
                  i,            // Rank of destination (integer)
                  tag,          // Message tag (integer)
                  MPI_COMM_WORLD// Communicator
                );
    }
  }
  else {
    MPI_Recv (  message,        // Initial address of recieve buffer (pointer)
                13,             // Max number of elements in recieve buffer (int)
                MPI_CHAR,       // Datatype of each recieve buffer element
                0,              // Rank of source (integer)
                tag,            // Message tag (integer)
                MPI_COMM_WORLD, // Communicator
                &status         // Status object (pointer)
              );
  }
  printf ( "process %d :%s \n", rank, message);

  MPI_Finalize();
  return 0;
}
