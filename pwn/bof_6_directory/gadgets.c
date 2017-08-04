#include "myasm.h"

void syscall_gadget(void){
	asm volatile(
		"call write\n\t"
	);
}

void open_gadget(void){
	asm volatile(
		"pop eax\n\t"
		"pop ebx\n\t"
		"pop ecx\n\t"
		"int 0x80\n\t"
	);
}

void read_gadget(void){
	asm volatile(
		"mov ebx,eax\n\t"
		"pop eax\n\t"
		"pop edx\n\t"
		"pop ecx\n\t"
		"int 0x80\n\t"
	);
}

void write_gadget(void){
	asm volatile(
		"mov edx,eax\n\t"
		"pop ebx\n\t"
		"pop eax\n\t"
		"int 0x80\n\t"
	);
}
