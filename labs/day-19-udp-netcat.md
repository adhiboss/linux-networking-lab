# Day 19 - UDP Communication using netcat

## Goal
Learn how UDP communication works using netcat.

---

## What is UDP?
UDP (User Datagram Protocol) is a connectionless protocol.
- No handshake
- No reliability guarantee
- Faster than TCP

---

## Lab Steps

### Terminal 1 (UDP Server)
```bash
nc -u -l -p 9090
