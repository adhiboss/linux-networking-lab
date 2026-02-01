# Day 14 – TCP States, Latency & Packet Loss

## Purpose
Understand TCP connection states and how latency/packet loss affect communication.

---

## Concepts Learned
- TCP states: LISTEN, ESTABLISHED, TIME-WAIT, CLOSE-WAIT
- Latency vs throughput
- Packet loss impact on TCP

---

## Commands Practiced
```bash
ss -tan
ss -tan state established
ss -tan state time-wait
ping -c 5 google.com
ping -c 5 -i 0.2 google.com
