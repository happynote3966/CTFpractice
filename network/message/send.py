import socket

target_host = "127.0.0.1"
target_port = 12345

def main():
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.connect((target_host,target_port))
    s.send("FLAG{Packet_is_data_of_network!}")


if __name__ == '__main__':
    main()
