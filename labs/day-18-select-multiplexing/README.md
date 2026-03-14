# Day 18 - select() Multiplexing TCP Server

## Goal
Build a TCP server that can handle multiple clients using `select()` without threads.

## Files
- `server.c` → select-based echo server
- `client.c` → simple TCP client

## How to Compile
```bash
gcc server.c -o server
gcc client.c -o client
