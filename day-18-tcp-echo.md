# Day 18 - TCP Echo Server (Simple Lab)

## Goal
Understand a basic TCP client-server model where the server echoes back what the client sends.

---

## Concepts Learned
- TCP connection setup
- Client sends message
- Server receives message
- Server sends back same message (echo)

---

## Steps (Using netcat)

### Terminal 1 (Server)
Run a TCP server on port 8080:
```bash
nc -l -p 8080
