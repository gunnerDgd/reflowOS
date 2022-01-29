#include <reflowOS/base/memory/hardware/microblaze/mb_memory_traits.hpp>
#include <reflowOS/base/memory/basic_memory_manager.hpp>

namespace reflowOS::system_types {
	typedef reflowOS::memory::basic_memory_manager<reflowOS::hardware_specific::microblaze::memory_traits> mman_type;
	typedef reflowOS::hardware_specific::microblaze::memory_traits										   mman_backend;
}

extern reflowOS::mman_type* reflowOS::system::memory_manager;
