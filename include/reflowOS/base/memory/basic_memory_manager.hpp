#include <cstddef>
#include <cstdint>

#include <type_traits>

namespace reflowOS::memory {

	template <typename MemoryBackend>
	class basic_memory_manager
	{
	public:
		typedef basic_memory_manager<MemoryBackend>   this_type;

		typedef MemoryBackend						  alloc_backend;
		typedef typename MemoryBackend::alloc_process alloc_process;
		typedef typename MemoryBackend::alloc_type    alloc_type   ;
		typedef typename MemoryBackend::alloc_size    alloc_size   ;

		typedef typename MemoryBackend::alloc_pointer alloc_pointer; // void*
		typedef typename MemoryBackend::alloc_block	  alloc_block  ; // block_tag

	public:
		static this_type* initialize();
		static void		  shutdown  ();

	public:
		alloc_pointer 	  allocate       (alloc_process, alloc_pointer);
		alloc_pointer	  allocate_ranged(alloc_process, alloc_pointer, alloc_size);
		void	  		  deallocate	 (alloc_process, alloc_pointer);
	};
}

using namespace reflowOS::memory;

template <typename MemoryBackend>
typename basic_memory_manager<MemoryBackend>::this_type* basic_memory_manager<MemoryBackend>::initialize()
{
	return reinterpret_cast<this_type*>(alloc_backend::allocate(1, 1)); // Allocate One Page for Memory Manager.
}

template <typename MemoryBackend>
void 	 basic_memory_manager<MemoryBackend>::shutdown()
{
	alloc_backend::shutdown();
}

template <typename MemoryBackend>
void 	 basic_memory_manager<MemoryBackend>::allocate(alloc_process alloc_process, alloc_pointer alloc_hint)
{
	return alloc_backend::allocate(alloc_process, alloc_hint);
}

template <typename MemoryBackend>
void 	 basic_memory_manager<MemoryBackend>::allocate_aligned(alloc_process alloc_process, alloc_pointer alloc_hint, alloc_size alloc_count)
{
	return alloc_backend::allocate_ranged(alloc_process, alloc_hint, alloc_count);
}

template <typename MemoryBackend>
void 	 basic_memory_manager<MemoryBackend>::deallocate	 (alloc_process alloc_process, alloc_pointer alloc_pointer)
{
	return alloc_backend::deallocate(alloc_process, alloc_pointer);
}
