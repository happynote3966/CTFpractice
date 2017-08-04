#include "myasm.h"

void open_gadget(void){
	asm volatile(
		"mov eax,0x5\n\t"
		"mov ebx,0x0804a060\n\t"
		"mov ecx,0x0\n\t"
		"int 0x80\n\t"
	);
}

void read_gadget(void){
	asm volatile(
		"mov ebx,eax\n\t"
		"mov eax,0x3\n\t"
		"mov ecx,0x0804a0e0\n\t"
		"mov edx,0x32\n\t"
		"int 0x80\n\t"
	);
}

void write_gadget(void){
	asm volatile(
		"mov edx,eax\n\t"
		"mov eax,0x4\n\t"
		"mov ebx,0x1\n\t"
		"int 0x80\n\t"
	);
}
