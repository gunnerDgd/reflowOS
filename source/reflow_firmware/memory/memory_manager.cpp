#include <reflow_firmware/memory/memory_manager.hpp>

void reflow_firmware::memory::initialize()
{

}

reflow_firmware::memory::pointer_type reflow_firmware::memory::allocate  (size_type index)
{
	if(static_object::memory_block_tag.tag[index] != block_state::unallocated)
		return nullptr;

	static_object::memory_block_tag.tag[index] = block_state::allocated;
	return index * block_size;
}

void reflow_firmware::memory::deallocate(size_type index)
{

}
