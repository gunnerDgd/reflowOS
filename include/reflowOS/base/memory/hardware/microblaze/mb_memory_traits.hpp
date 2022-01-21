#include <reflowOS/base/memory/basic_memory_manager.hpp>
#include <xparameters.h>

namespace reflowOS 			{
namespace hardware_specific {
	class microblaze_memory_traits
	{
	public:
		typedef AllocType   alloc_type;
		typedef AllocType*  alloc_pointer;

		typedef void*		alloc_raw_pointer;
		typedef std::size_t alloc_size;

	public:
		microblaze_memory_traits (alloc_raw_pointer, alloc_size);
		~microblaze_memory_traits();

	public:
		alloc_pointer allocate  (alloc_size);
		alloc_pointer allocate  (alloc_size, alloc_pointer);
		void		  deallocate(alloc_size, alloc_pointer);

	private:


	private:
		alloc_raw_pointer __M_memtraits_base_pointer;
		alloc_size		  __M_memtraits_base_size;

	private:

	};
}
}
