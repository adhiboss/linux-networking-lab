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
