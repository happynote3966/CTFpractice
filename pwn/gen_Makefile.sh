#!/bin/bash


pushd ./
mkdir $1_directory
cd $1_directory

cat << EOS > Makefile
# Makefile

PROGRAM := $1
SOURCE := $1.c

CC := gcc
CFLAGS := -Wall

# -m32 : Generate 32bit binary
# -m64 : Generate 64bit binary
# -s : Remove all symbol table and relocation information
# -g : 
# -fstack-protector : Enable anti-BOF (canary,stack cookie)
# -fno-stack-protector : Disable anti-BOF (canary,stack cookie)
# -z execstack : Disable anti-Data-Execution (DEP,ExecShield)
# -Wl,-z,norelro
# -Wl,-z,relro :
# -Wl,-z,relro, -Wl,-z,lazy : Enable RELRO(lazy)
# -Wl,-z,relro, -Wl,-z,now : Enable RELRO
# -mpush-args : Enable arg passing by PUSH
# -mno-push-args : Disable args passing by PUSH
# -fPIE : Enable Position Independent Execuable
# -fno-PIE : Disable Position Independent Executable
# -static : Generate static binary
# -fomit-frame-pointer :
# -O0
# -O1
# -O2
# -O3


\$(PROGRAM): \$(SOURCE)
	\$(CC) \$(CFLAGS) -o \$@ \$+

#clean:
#	rm 

EOS

cat << EOS > $1.c
#include <stdio.h>
int main(void){
	setvbuf(stdin,NULL,_IONBF,0x0);
	setvbuf(stdout,NULL,_IONBF,0x0);
	return 0;
}

EOS

cat << EOS > exploit_$1.py
import struct
import socket
import telnetlib

def sock(ip,port):
	s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	s.connect((ip,port))
	return s


def shell(s):
	t = telnetlib.Telnet()
	t.sock = s
	t.interact()


def p32(data):
	return struct.pack("<I",data)

def p64(data):
	return struct.pack("<Q",data)

def u32(data):
	return struct.unpack("<I",data)[0]

def u64(data):
	return struct.unpack("<Q",data)[0]


def main():
	s = sock("localhost",10000)
	buf = "AAAA"
	buf += "\n"
	s.send(buf)
	s.recv(1024)
	shell(s)


if __name__ == '__main__':
	main()


EOS



popd
