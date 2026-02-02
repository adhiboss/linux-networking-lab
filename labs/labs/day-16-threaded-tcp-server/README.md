# Day 16 – Threaded TCP Server

## Objective
Implement a TCP server capable of handling multiple clients concurrently using threads.

## Implementation
- Server listens on port 8080
- Each client connection is handled in a separate thread
- Thread-per-connection model using pthreads
- Server echoes received messages back to the client

## How to Run
```bash
gcc server.c -o server -lpthread
gcc client.c -o client

./server
./client
