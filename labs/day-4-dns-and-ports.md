# Day 4 – DNS & Well-Known Ports

## Concepts Learned

- DNS (Domain Name System)  
  DNS translates human-readable domain names into IP addresses.

- Domain Name  
  A readable name used to identify a server (example: google.com).

- IP Resolution  
  The process of converting a domain name into an IP address.

- Well-Known Ports  
  Standard ports reserved for common services.

---

## Common Well-Known Ports

| Port | Service |
|------|--------|
| 22   | SSH |
| 80   | HTTP |
| 443  | HTTPS |
| 21   | FTP |
| 25   | SMTP |
| 53   | DNS |

---

## Commands Practiced

- getent hosts google.com  
- nslookup google.com  
- dig google.com  
- ss -tuln  

---

## Observations

- DNS is required before a client can contact a server using a domain name.
- getent uses the system’s resolver configuration.
- nslookup and dig provide detailed DNS query results.
- Services listen on standard ports by convention.
- ss shows active services and listening ports.

---

## Notes

This lab helped me understand how DNS works and how clients locate servers using domain names before establishing network connections.
