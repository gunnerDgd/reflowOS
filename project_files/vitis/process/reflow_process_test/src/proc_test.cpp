#include <xparameters.h>
#include <xil_printf.h>

struct pcb
{
	int registers[13];
	int ret_pointer  ;
	int stack_pointer;
};

void test()
{
	xil_printf  ("Hello Test #0\r\n");
	asm volatile("lwi  r21, r1, 0 \r\n"
				 "addi r21, r21, 8\r\n"
				 "bra  r21");
	xil_printf  ("Hello Test #1\r\n");

}

int main()
{
	xil_printf("Hello World\r\n");
	test();
	xil_printf("Hello Coroutine\r\n");
}
