#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);  // Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get the rank of the process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get the number of processes

    char message[100];
    int root = 0;

    // Root process broadcasts a message to all other processes
    if (rank == root) {
        strcpy(message, "Hello from root!");
        printf("Process %d broadcasting message: %s\n", rank, message);
        MPI_Bcast(message, 100, MPI_CHAR, root, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(message, 100, MPI_CHAR, root, MPI_COMM_WORLD);
        printf("Process %d received broadcast message: %s\n", rank, message);
    }

    // Communication between processes
    if (rank != root) {
        // Send message from each non-root process to root process
        sprintf(message, "Hello from process %d", rank);
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, root, 0, MPI_COMM_WORLD);
    } else {
        // Root process receives messages from all other processes
        for (int i = 1; i < size; i++) {
            MPI_Recv(message, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Root process received message: %s\n", message);
        }
    }

    // Example of direct process-to-process communication
    if (rank == 1) {
        // Process 1 sends a message to Process 2
        strcpy(message, "Message from process 1 to process 2");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 2, 1, MPI_COMM_WORLD);
    } else if (rank == 2) {
        // Process 2 receives the message from Process 1
        MPI_Recv(message, 100, MPI_CHAR, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received message: %s\n", rank, message);
    }

    MPI_Finalize();  // Finalize the MPI environment
    return 0;
}
