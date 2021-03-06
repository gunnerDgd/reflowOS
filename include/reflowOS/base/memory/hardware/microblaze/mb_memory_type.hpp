#include <reflowOS/base/memory/types/memory_types.hpp>
#include <reflowOS/base/memory/types/size_type.hpp>

#include <xparameters.h>
#include <type_traits>

namespace reflowOS::hardware_specific::microblaze {
	STATIC_MEMORY_TYPE(memory::types::block_size)  size_entire 	   = 256 * memory::types::megabyte;
	STATIC_MEMORY_TYPE(memory::types::block_size)  size_hardware   = 128 * memory::types::megabyte;
	STATIC_MEMORY_TYPE(memory::types::block_size)  size_management = 32  * memory::types::block_size;
	STATIC_MEMORY_TYPE(memory::types::block_size)  size_usable	   = size_hardware - size_management;

	DEFINE_MEMORY_TYPE(memory::types::static_pointer_description<XPAR_MIG_7SERIES_0_BASEADDR>			, offset_memory)
	DEFINE_MEMORY_TYPE(memory::size_types::add_static_pointer<offset_memory    , 0>				 ::value, offset_hardware)
	DEFINE_MEMORY_TYPE(memory::size_types::add_static_pointer<offset_memory	   , size_hardware>  ::value, offset_management)
	DEFINE_MEMORY_TYPE(memory::size_types::add_static_pointer<offset_management, size_management>::value, offset_usable)
}

#define MB_MEMORY_ITERATE_TAG_BEGIN(it_name, it_init) for(std::uint32_t it_name = it_init; it_name < block_entire_count ; it_name++) {
#define MB_MEMORY_ITERATE_TAG_END }
