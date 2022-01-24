#include <cstdint>
#include <cstddef>

namespace reflowOS {
	template <typename ProcessContext, typename ProcessController>
	class basic_process
	{
	public:
		typedef ProcessContext    								 context_type   ;
		typedef ProcessController 								 controller_type;
		typedef basic_process<ProcessContext, ProcessController> this_type	    ;

	public:

	private:
		context_type    __M_process_context;
		controller_type __M_process_controller;
	};
}
