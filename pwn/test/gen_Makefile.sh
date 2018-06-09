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
	\$(CC) \$(CFLAGS) -o \$@

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

popd
