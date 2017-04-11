import socket

bind_ip = "0.0.0.0"
bind_port = 12345

def main():
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.bind((bind_ip,bind_port))
    s.listen(5)
    while True:
        client,addr = s.accept()
        res = client.recv(1024)
        print(res)

if __name__ == "__main__":
    main()
