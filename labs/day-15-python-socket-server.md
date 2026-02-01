# Day 15 – Python TCP Socket Server

## Purpose
Build a simple TCP client–server using Python sockets to understand low-level network communication.

---

## Concepts Learned
- Sockets and ports
- TCP connection lifecycle
- Blocking server behavior
- Client–server message exchange

---

## Server Code (server.py)
```python
import socket

HOST = "127.0.0.1"
PORT = 9090

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

print("Server listening on", PORT)
conn, addr = server.accept()
print("Connected by", addr)

data = conn.recv(1024)
print("Received:", data.decode())

conn.sendall(b"Hello from server")
conn.close()
server.close()
