	.text
	.globl store_and_switch
	.globl store_and_execute

/*
	store_and_switch() function.
		- Paramters
			--> hardware_specific::microblaze::context* prev (Stored in R5 Register by Microblaze Stack Convention)
			--> hardware_specific::microblaze::context* next (Stored in R6 Register by Microblaze Stack Convention)
*/

	.ent   store_and_switch
	.align 2
store_and_switch:
	swi  r1 , r5 , 0  // Stores Current Stack Pointer to the Prev Struct.
	swi  r15, r5 , 4  // Stores Callee's Program Counter to the Prev Struct.

	lwi  r1 , r6 , 0  // Loads Next Stack Pointer from "next" struct.
	lwi  r22, r6 , 4
	addi r22, r22, 4  // Adds 4 Byte (Instruction Size) to the Program Counter to Perform Next Instruction.

	bra  r22

	.end store_and_switch

/*
	store_and_execute() function.
		- Paramters
			--> hardware_specific::microblaze::context* 			   prev 	 (Stored in R5 Register by Microblaze Stack Convention)
			--> hardware_specific::microblaze::context* 			   next 	 (Stored in R6 Register by Microblaze Stack Convention)
			--> hardware_specific::microblaze::context::execute_type   exec 	 (Stored in R7 Register by Microblaze Stack Convention.)
			--> hardware_specific::microblaze::context::parameter_type exec_args (Stored in R8 Register by Microblaze Stack Convention.)
*/


	.ent   store_and_execute
	.align 2
store_and_execute:
	swi  r1 , r5, 0 // Stores Current Stack Pointer to the Prev Struct.
	swi  r15, r5, 4 // Stores Callee's Program Counter to the Prev Struct.

	lwi  r1 , r6, 0 // Loads Newly Allocated Stack Pointer from "next" struct.
	addi r5, r8, 0 // Loads Execution Parameter from exec_args Parameter (R8 Register).
	bra  r7        // Starts Execution.

	.end store_and_execute
