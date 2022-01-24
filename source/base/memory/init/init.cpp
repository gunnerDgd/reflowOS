#include <reflowOS/base/memory/init/init.hpp>
#include <reflowOS/base/memory/init/init_type.hpp>

void reflowOS::memory::mman_init	()
{
	mman_page* init_list = reinterpret_cast<mman_page*>(mman_manage_base);
	uint8_t  * init_page = reinterpret_cast<uint8_t*>  (mman_base);

	for(size_type init_it = 0 ; init_it < mman_entire_count ; init_it++)
	{
		init_list[init_it].mman_pointer = init_page;
		std::memset(init_page, mman_);
	}
}

void reflowOS::memory::mman_shutdown()
{

}
