#include <reflowOS/base/process/asm/microblaze/context.hpp>
#include <type_traits>

namespace reflowOS::hardware_specific::microblaze {
	class context_traits
	{
	public:
		template <typename PrevContext, typename NextContext>
		struct is_switchable 				   { constexpr static bool value = false; };

		template <>
		struct is_switchable<context, context> { constexpr static bool value = true ; };

	public:
		typedef void  (*execute_type)(void*);
		typedef void*   parameter_type;
		typedef context context_type;

	public:
		template <typename MemoryAllocator>
		static void allocate_stack  (context_type&);
		template <typename MemoryAllocator>
		static void deallocate_stack(context_type&);

	public:
		template <typename PrevContext, typename NextContext,
				  typename = std::enable_if_t<is_switchable<std::remove_reference_t<PrevContext>,
				  	  	  	  	  	  	  	  	  	  	    std::remove_reference_t<NextContext>>>>
		static void switch_to (PrevContext&&, NextContext&&);

		template <typename PrevContext, typename NextContext,
				  typename = std::enable_if_t<is_switchable<std::remove_reference_t<PrevContext>,
						  	  	  	  	  	  	  	  	  	std::remove_reference_t<NextContext>>>>
		static void execute_at(PrevContext&&, NextContext&&, execute_type, parameter_type);
	};
}

using namespace reflowOS::hardware_specific::microblaze;

template <typename PrevContext, typename NextContext,
		  typename = std::enable_if_t<is_switchable<std::remove_reference_t<PrevContext>,
				  	  	  	  	  	  	  	  	  	std::remove_reference_t<NextContext>>>>
void context_traits::switch_to (PrevContext&& prev, NextContext&& next)
{
	store_and_switch (&prev, &next);
}

template <typename PrevContext, typename NextContext,
		  typename = std::enable_if_t<is_switchable<std::remove_reference_t<PrevContext>,
						  	  	  	  	  	  	  	std::remove_reference_t<NextContext>>>>
void context_traits::execute_at(PrevContext&& prev, NextContext&& next, execute_type exec, parameter_type exec_args)
{
	store_and_execute(&prev, &next, exec, exec_args);
}

