# Day 12 – Port Scanning & Service Discovery

## Purpose
Learn how to identify open ports and running services on a system.

## Tools Used
- ss
- lsof
- nmap

## Commands
```bash
ss -tuln
ss -tulpn
lsof -i
nmap -p 1-100 localhost
