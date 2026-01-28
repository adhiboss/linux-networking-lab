# Day 11 – DNS Internals & Name Resolution

## Purpose
Understand how Linux resolves domain names to IP addresses and the order of resolution.

---

## Concepts Learned
- DNS Resolution Flow
- /etc/hosts override
- Resolver configuration
- Caching behavior

---

## Files Involved
- /etc/hosts
- /etc/resolv.conf
- /etc/nsswitch.conf

---

## Commands Practiced
```bash
getent hosts google.com
nslookup google.com
dig google.com
cat /etc/hosts
cat /etc/resolv.conf
