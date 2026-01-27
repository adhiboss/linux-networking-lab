# Day 8 – Client–Server Communication using netcat (nc)

## Purpose

This lab demonstrates a simple client–server communication using the `netcat` (nc) utility.

---

## Concepts Learned

- Client–Server Model  
  A client sends data to a server, and the server receives it.

- Listening on a Port  
  A server listens on a specific TCP port for incoming connections.

- TCP Connection  
  Data is transmitted reliably between client and server.

---

## Server Setup

```bash
nc -l 8080
