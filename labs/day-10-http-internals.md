# Day 10 – HTTP Internals and curl Deep Dive

## Purpose

This lab focuses on understanding how HTTP works internally, including headers, status codes, and request methods.

---

## Concepts Learned

- HTTP Request  
  A message sent by a client to request a resource from a server.

- HTTP Response  
  A message sent by a server back to the client.

- HTTP Headers  
  Key–value pairs that provide metadata about requests and responses.

- Status Codes  
  Numeric codes that indicate the result of an HTTP request.

---

## Common HTTP Status Codes

| Code | Meaning |
|------|--------|
| 200  | OK |
| 301  | Moved Permanently |
| 400  | Bad Request |
| 401  | Unauthorized |
| 403  | Forbidden |
| 404  | Not Found |
| 500  | Internal Server Error |

---

## Commands Practiced

```bash
curl -I http://example.com
curl -v http://example.com
curl -X GET http://example.com
