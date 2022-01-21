#include <cstdint>
#include <cstddef>

#include <xparameters.h>

#define MEMORY_STATIC(type) constexpr static type

namespace reflowOS {
namespace memory   {

	typedef std::uint32_t size_type;
	typedef std::uint64_t pointer_type;

	MEMORY_STATIC(size_type) memory_size = XPAR_MIG_7SERIES_0_HIGHADDR - XPAR_MIG_7SERIES_0_BASEADDR;
	MEMORY_STATIC(size_type) page_size   = 4096;

	MEMORY_STATIC(size_type)    mman_size 		 	   = page_size * 32;
	MEMORY_STATIC(size_type)    mman_entire_page_count = memory_size / page_size;
	MEMORY_STATIC(size_type)    mman_manage_page_count = mman_entire_page_count - 65; // 32 for MMAN, 33 for Boot Modules.
	MEMORY_STATIC(pointer_type) mman_base			   = XPAR_MIG_7SERIES_0_BASEADDR + (65 * page_size);

	struct page_entity
	{
		std::uint32_t attached_process;
		std::uint32_t block_id;
	};

	typedef uint8_t     page	 [page_size];
	typedef page_entity page_mman[mman_manage_page_count];
}
}
