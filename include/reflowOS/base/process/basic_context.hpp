#define CONTEXT_STD(type) constexpr static type

/*
 * "basic_context" Class.
 *
 *
 * 			- template <typename MemoryAllocator> basic_context(MemoryAllocator&&, )
 * 				--> An safe way to allocate new context (Process Control Block).
 * 				--> Uses High - Level Memory Manager to allocate context memory and stack.\
 *
 * 				-->
 */

namespace reflowOS {
	template <typename ContextTraits>
	class basic_context
	{
	public:
		typedef			 basic_context<ContextTraits>  this_type;

		typedef 		 ContextTraits 				   traits_type;
		typedef typename ContextTraits::context_type   context_type;

		typedef typename ContextTraits::execute_type   execute_type;
		typedef typename ContextTraits::parameter_type parameter_type;

	public:
		template <typename MemoryAllocator>
		static this_type* create_context(MemoryAllocator&&, execute_type, parameter_type);

		template <typename MemoryAllocator>
		static void		  delete_context(MemoryAllocator&&, this_type&);
	private:
		context_type __M_context_pcb;
	};

	template <typename AnyContext>
	struct is_context 							  { CONTEXT_STD(bool) value = false; };

	template <typename AnyContext>
	struct is_context<basic_context<ContextType>> { CONTEXT_STD(bool) value = false; };
}

template <typename ContextTraits>
template <typename MemoryAllocator>
reflowOS::basic_context<ContextTraits>::this_type* reflowOS::basic_context<ContextTraits>::create_context(MemoryAllocator&& exec_alloc, execute_type exec, parameter_type exec_args)
{
	// Not Created Yet.
	return nullptr;
}

template <typename ContextTraits>
template <typename MemoryTraits>
reflowOS::basic_context<ContextTraits>::this_type* reflowOS::basic_context<ContextTraits>::create_context(execute_type exec, parameter_type exec_args)
{
	this_type* cr_context = reinterpret_cast<this_type*>(MemoryTraits::allocate()); // Allocate 1 Page for Init Process (PID 0)
	traits_type::allocate_stack<MemoryTraits>(cr_context->__M_context_pcb);

	return cr_context;
}

template <typename ContextTraits>
template <typename MemoryAllocator>
void		  reflowOS::basic_context<ContextTraits>::delete_context(MemoryAllocator&&, this_type*)
{

}

template <typename ContextTraits>
template <typename MemoryTraits>
void		  reflowOS::basic_context<ContextTraits>::delete_context(this_type* dealloc_context)
{
	traits_type::deallocate_stack(dealloc_context->__M_context_pcb);
}
