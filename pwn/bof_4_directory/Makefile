CC := gcc
CFLAGS_BOF := -m32 -fno-stack-protector -O0 -no-pie -fno-PIC
CFLAGS_GADGETS := -m32 -O1 -no-pie -masm=intel -fomit-frame-pointer -c -fno-PIC

bof_4 : bof_4.o gadgets.o
	$(CC) $(CFLAGS_BOF) -o $@ $+

bof_4.o : bof_4.c
	$(CC) $(CFLAGS_BOF) -o $@ -c $<

gadgets.o : gadgets.c
	$(CC) $(CFLAGS_GADGETS) -o $@ -c $<
