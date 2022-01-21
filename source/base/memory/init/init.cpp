#include <reflowOS/base/memory/init/init.hpp>

#define MMAN_ITERATE_START(it_name) for (std::uint32_t it_name = 0 ; it_name < mman_manage_page_count ; it_name++) {
#define MMAN_ITERATE_END }

void reflowOS::memory::mman_init	()
{
	page_entity* init_entry = reinterpret_cast<page_entity*>(mman_base);

	MMAN_ITEREATE_START(it_page)
		init_entry[it_page].block_id = it_page;
	MMAN_ITERATE_END
}

void reflowOS::memory::mman_shutdown()
{

}