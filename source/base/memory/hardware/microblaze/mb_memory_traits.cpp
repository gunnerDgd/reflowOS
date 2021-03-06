#include <reflowOS/base/memory/hardware/microblaze/mb_memory_traits.hpp>

using namespace reflowOS::hardware_specific::microblaze;

void	   memory_traits::initialize()
{
	MB_MEMORY_ITERATE_TAG_BEGIN(it_tag, 0)
		block_manage_address[it_tag].block_state	  = block_tag::state::unallocated;
		block_manage_address[it_tag].attached_pointer = block_base_address + block_size * it_tag;
		block_manage_address[it_tag].attached_process = 0;
	MB_MEMORY_ITERATE_TAG_END
}

void	   memory_traits::shutdown ()
{

}

block_tag* memory_traits::allocate  (alloc_process alloc_proc, alloc_pointer alloc_hint)
{
	alloc_size alloc_base = (!alloc_hint) ? 0 : (((alloc_size)alloc_hint / block_size) + 1);

	MB_MEMORY_ITERATE_TAG_BEGIN(it_tag, alloc_base)
		if(block_manage_address[it_tag].attached_process == 0
		&& block_manage_address[it_tag].block_state 	 == block_tag::state::unallocated)
		{
			block_manage_address[it_tag].attached_process = alloc_proc;
			block_manage_address[it_tag].block_state	  = block_tag::state::allocated;

			return &block_manage_address[it_tag];
		}
	MB_MEMORY_ITERATE_TAG_END

	return nullptr;
}

void	   memory_traits::deallocate(alloc_process alloc_proc, alloc_pointer dealloc_pointer)
{
	block_tag* dealloc_tag = &block_manage_address[(alloc_size)dealloc_pointer / block_size];

	if(dealloc_tag->attached_process != alloc_proc
	|| dealloc_tag->block_state      != block_tag::state::allocated) return;

	dealloc_tag->attached_process = 0;
	dealloc_tag->block_state      = block_tag::state::unallocated;
}

block_tag* memory_traits::allocate_ranged(alloc_process alloc_proc, alloc_pointer alloc_hint, alloc_size alloc_count)
{
	block_tag* aligned_range = nullptr;
	bool	   aligned_flag  = false;

	for(alloc_size it_block = 0 ; it_block < block_entire_count ; )
	{
		alloc_size it_align = 0;
		aligned_range       = &block_manage_address[it_block];
		for( ; it_align < alloc_count ; it_align++)
		{
			if(block_manage_address[it_align + it_block].block_state != block_tag::state::unallocated)
			{
				it_block += it_align + 1;
				break;
			}
		}

		if(it_align == alloc_count)
		{
			for(alloc_size it_alloc = 0 ; it_alloc < alloc_count ; it_alloc++)
			{
				block_manage_address[it_alloc + it_block].attached_process = alloc_proc;
				block_manage_address[it_alloc + it_block].block_state	   = block_tag::state::allocated;
			}
			return block_manage_address;
		}
	}

	return nullptr;
}
