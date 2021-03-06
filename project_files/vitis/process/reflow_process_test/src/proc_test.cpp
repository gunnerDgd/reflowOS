#include <xparameters.h>
#include <xil_printf.h>

struct test_pcb
{
	int stack_pointer,
		instruction_pointer;
};

extern "C"
{
	void store_and_switch (test_pcb*, test_pcb*);
	void store_and_execute(test_pcb*, test_pcb*, void(*)(void*), void*);
}

test_pcb main_stk, test_stk;

void test(void* unused)
{
	xil_printf("Hello Test #0\r\n");
	store_and_switch(&test_stk, &main_stk);
	xil_printf("Hello Test #1\r\n");
	store_and_switch(&test_stk, &main_stk);
}

int main()
{
	test_stk.stack_pointer = XPAR_MIG_7SERIES_0_BASEADDR + 1024*1024*132;
	xil_printf		 ("\r\n\r\nHello Main #0\r\n");
	store_and_execute(&main_stk, &test_stk, &test, NULL);
	xil_printf		 ("Hello Main #1\r\n");
	store_and_switch (&main_stk, &test_stk);
	xil_printf		 ("Hello Main #2\r\n");
}
