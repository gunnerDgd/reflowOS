#pragma once
#include <type_traits>

namespace reflow_bootloader {
namespace clocking 			{

	class system_clock
	{
	public:
		using  native_handle_type = hardware_specific::clocking::system_clock_source::native_handle_type;
		using  frequency_type     = std::uint32_t;
		struct configuration;

	public:
		system_clock()			   ;
		system_clock(configuration);

	public:
		native_handle_type native_handle    () { return __M_sysclock_source; }
		frequency_type 	   current_frequency();

	private:
		native_handle_type __M_sysclock_source;
	};

}
}