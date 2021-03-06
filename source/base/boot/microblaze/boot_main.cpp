#include <reflowOS/base/boot/hardware_specific/microblaze/boot_data.hpp>


namespace reflowOS::system_object {
	static  mman_type* memory_manager;
}

namespace reflowOS::hardware_specific::microblaze {
	void start_boot()
	{
		reflowOS::system_object::memory_manager = reflowOS::system::mman_type::initialize(); // Initializes Memory Manager and Memory Backend.
	}
}
