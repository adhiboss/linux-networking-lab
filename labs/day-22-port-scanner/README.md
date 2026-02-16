# Lab Day 22: Simple TCP Port Scanner (Linux)

## Objective
Scan a target IP and detect open TCP ports using bash + /dev/tcp.

---

## Requirements
- Linux / WSL
- Bash

---

## Script: port_scan.sh
```bash
#!/bin/bash

TARGET=$1

if [ -z "$TARGET" ]; then
  echo "Usage: $0 <target-ip>"
  exit 1
fi

echo "Scanning $TARGET..."

for port in {20..100}; do
  timeout 1 bash -c "echo > /dev/tcp/$TARGET/$port" 2>/dev/null
  if [ $? -eq 0 ]; then
    echo "Port $port is OPEN"
  fi
done
