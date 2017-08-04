CC := gcc
CFLAGS_BOF := -m32 -fno-stack-protector -O0 -no-pie -fno-PIC
CFLAGS_GADGETS := -m32 -O1 -no-pie -masm=intel -fomit-frame-pointer -c -fno-PIC

bof_5 : bof_5.o gadgets.o
	$(CC) $(CFLAGS_BOF) -o $@ $+

bof_5.o : bof_5.c
	$(CC) $(CFLAGS_BOF) -o $@ -c $<

gadgets.o : gadgets.c
	$(CC) $(CFLAGS_GADGETS) -o $@ -c $<
