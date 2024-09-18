# mpi_chatserver
An MPI program to implement a chat server where a root process broadcasts a message to all other processes, and processes can communicate with each other using MPI_Send and MPI_Recv.

Prerequisite: Familiarity with the Message Passing Interface (MPI) and its fundamental functions such as MPI_Init, MPI_Comm_rank, MPI_Comm_size, MPI_Send, MPI_Recv, and MPI_Finalize.

Concept
MPI is a standardized and portable message-passing system designed to function on parallel computing architectures. It allows processes to communicate with each other by sending and receiving messages.
In a typical MPI program:
 Initialization and Finalization: All MPI programs start with MPI_Init and end with MPI_Finalize.
 Rank and Size: Each process in an MPI program is assigned a unique identifier called rank, and the total number of processes is referred to as the size of the communicator.
 Point-to-Point Communication: This includes sending and receiving messages between pairs of processes using MPI_Send and MPI_Recv.
 Broadcasting: A message from one process (usually the root) is sent to all other processes in the communicator using MPI_Bcast.

Procedure
 Create multiple processors.
 Broadcast a message from the process with rank "root" to all other processes in the group.
 Every processor in the group receives the message from the root using MPI_Recv.
 Communication between processors is done using MPI_Send.
 Demonstrate the implementation with at least 4 processors.

Sample Input
mpicc −o mpi chatserver.c
mpirun −np 4 mpi

Output
Process 0 broadcasting message: Hello from root!
Process 1 received broadcast message: Hello from root!
Process 2 received broadcast message: Hello from root!
Process 3 received broadcast message: Hello from root!
Root process received message: Hello from process 1
Root process received message: Hello from process 2
Root process received message: Hello from process 3
Process 2 received message: Message from process 1 to process 2
