#include <reflowOS/base/memory/hardware/microblaze/mb_memory_type.hpp>
#include <utility>

#include <xparameters.h>

namespace reflowOS::hardware_specific::microblaze {
	class memory_traits
	{
	public:
		typedef size_type		 alloc_size;
		typedef std::uint8_t*    alloc_type;

		typedef std::uint32_t	 alloc_process;
		typedef block_tag	     alloc_block  ;
		typedef void*			 alloc_pointer;

		MEMORY_STATIC(size_type) alloc_unit = block_size;

	public:
		static void			 initialize();
		static void			 shutdown  ();

	public:
		static alloc_block*  allocate  	    (alloc_process alloc_proc = 1, alloc_pointer alloc_hint = nullptr);
		static alloc_block*	 allocate_ranged(alloc_process alloc_proc = 1, alloc_pointer alloc_hint = nullptr, alloc_size);
		static void		     deallocate		(alloc_process alloc_proc = 1, alloc_pointer);
	};
}
