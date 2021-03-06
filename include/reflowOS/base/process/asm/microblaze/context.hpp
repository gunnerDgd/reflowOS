#include <cstdint>
#include <cstddef>

namespace reflowOS::hardware_specific::microblaze {
	struct context
	{
		typedef std::uint32_t register_type;
		typedef void		(*execute_type)(void*);
		typedef void*		  parameter_type;

		register_type r_stack_pointer		;
		register_type r_program_counter		;
		register_type r_general_purposed[13];
	};

extern "C"
{
	void store_and_switch (context*, context*);
	void store_and_execute(context*, context*, context::execute_type, context::parameter_type);
}
}
