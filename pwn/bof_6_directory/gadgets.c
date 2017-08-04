#include "myasm.h"

void call_open_gadget(void){
	asm volatile(
		"jmp open\n\t"
	);
}

void call_read_gadget(void){
	asm volatile(
		"jmp read\n\t"
	);
}

void call_write_gadget(void){
	asm volatile(
		"jmp write\n\t"
	);
}

void set_firstarg(void){
	asm volatile(
		"mov [esp+0x8],eax\n\t"
	);
}

void set_thirdarg(void){
	asm volatile(
		"mov [esp+0x10],eax\n\t"
	);
}

void pop_pop(void){
	asm volatile(
		"pop ebx\n\t"
		"pop ebx\n\t"
	);
}

void pop_pop_pop(void){
	asm volatile(
		"pop ecx\n\t"
		"pop ecx\n\t"
		"pop ecx\n\t"
	);
}

