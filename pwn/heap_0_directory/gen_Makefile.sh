cat << EOS > Makefile
# Makefile

PROGRAM := heap_0
SOURCE := heap_0.c

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


$(PROGRAM): $(SOURCE)
        $(CC) $(CFLAGS) -o $@

#clean:
#       rm 

EOS
