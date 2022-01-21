#include <reflowOS/base/memory/hardware/microblaze/mb_memory_traits.hpp>

using namespace reflowOS::hardware_specific;

microblaze_memory_traits::microblaze_memory_traits (alloc_raw_pointer raw_pointer, alloc_size raw_size)
	: __M_memtraits_base_pointer(raw_pointer),
	  __M_memtraits_base_size   (raw_size)
{

}

microblaze_memory_traits::~microblaze_memory_traits()
{

}

typename microblaze_memory_traits::alloc_pointer microblaze_memory_traits::allocate(alloc_size alloc_size)
{

}

typename microblaze_memory_traits::alloc_pointer microblaze_memory_traits::allocate  (alloc_size alloc_size, alloc_pointer alloc_hint)
{

}

void microblaze_memory_traits::deallocate(alloc_size, alloc_pointer)
{

}
