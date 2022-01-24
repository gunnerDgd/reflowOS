#include <cstdint>
#include <cstddef>

#include <xparameters.h>
#include <type_traits>

#define MEMORY_STATIC(type) constexpr static type

namespace reflowOS::hardware_specific::microblaze {

	typedef std::uint32_t size_type;
	typedef uint8_t*	  pointer_type;

	MEMORY_STATIC(size_type)    megabyte = 1024 * 1024;
	MEMORY_STATIC(size_type)    kilobyte = 1024;

	MEMORY_STATIC(size_type) 	total_size = 128 * megabyte; // Size of the Entire Memory.
	MEMORY_STATIC(size_type) 	block_size = 4   * kilobyte; // Size of the Memory Page.

	typedef std::uint8_t block_context[block_size];
	struct 				 block_tag
	{
		enum class state : uint8_t
		{
			unallocated = 0,
			allocated   = (1 << 0),
			reserved	= (1 << 1)
		};

		typedef std::uint32_t block_process_id;
		typedef pointer_type  block_pointer;

		block_process_id 	  attached_process;
		block_pointer	 	  attached_pointer;

		state				  block_state;
	};

	MEMORY_STATIC(size_type)    block_manage_count   = 32;											   // Entire Count of Blocks that used for Management.
	MEMORY_STATIC(size_type)    block_entire_count   = (total_size / block_size) - block_manage_count; // Entire Count of Usable Blocks.

	MEMORY_STATIC(pointer_type) block_memory_base    = XPAR_MIG_7SERIES_0_BASEADDR + 128 * megabyte;   		// Base Pointer of Entire Blocks.
	MEMORY_STATIC(block_tag*)   block_manage_address = block_memory_base;									// Base Pointer of Block Management Tag.
	MEMORY_STATIC(pointer_type) block_base_address   = block_memory_base + block_manage_count * block_size; // Base Pointer of Usable Blocks.
}

#define MB_MEMORY_ITERATE_TAG_BEGIN(it_name) for(std::uint32_t it_name ; it_name < block_entire_count ; it_name++) {
#define MB_MEMORY_ITERATE_TAG_END }
