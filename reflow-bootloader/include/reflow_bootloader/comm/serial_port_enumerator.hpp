#include <reflow_bootloader/comm/serial_port.hpp>

namespace reflow_bootloader {
namespace communication 	{

	class serial_port::enumerator
	{
	public:
		using native_handle_type = typename serial_port::native_handle_type;
		using value_type 		 = serial_port;
		using reference 		 = serial_port&;
		using pointer 			 = serial_port*;

	public:
		constexpr enumerator();

	public:
		reference
	};
}
}
