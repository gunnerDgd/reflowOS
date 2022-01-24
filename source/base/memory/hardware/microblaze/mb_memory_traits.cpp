#include <reflowOS/base/memory/hardware/microblaze/mb_memory_traits.hpp>

using namespace reflowOS::hardware_specific::microblaze;

void						 		memory_traits::initialize()
{
	MB_MEMORY_ITERATE_TAG_BEGIN(it_tag = 0)
		block_manage_address[it_tag].block_state	  = block_tag::state::unallocated;
		block_manage_address[it_tag].attached_pointer = block_base_address + block_size * it_tag;
		block_manage_address[it_tag].attached_process = 0;
	MB_MEMORY_ITERATE_TAG_END
}

void						 		memory_traits::shutdown ()
{

}

block_tag*						 	memory_traits::allocate  (alloc_process alloc_proc, alloc_pointer alloc_hint)
{
	alloc_size alloc_base = (!alloc_hint) ? 0 : ((alloc_hint / block_size) + 1);

	MB_MEMORY_ITERATE_TAG_BEGIN(it_tag = alloc_hint)
		if(block_manage_address[it_tag].attached_process == 0
		&& block_manage_address[it_tag].block_state == block_tag::state::unallocated)
		{
			block_manage_address[it_tag].attached_process = alloc_proc;
			block_manage_address[it_tag].block_state	  = block_tag::state::allocated;

			return &block_manage_address[it_tag];
		}
	MB_MEMORY_ITERATE_TAG_END

	return nullptr;
}

void		  				 		  memory_traits::deallocate(alloc_process alloc_proc, block_tag& alloc_tag)
{
	if(alloc_tag.attached_process != alloc_proc || alloc_tag.block_state != block_tag::state::allocated)
		return;

	alloc_tag.attached_process = 0;
	alloc_tag.block_state      = block_tag::state::unallocated;
}
