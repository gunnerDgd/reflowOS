#include <reflowOS/base/memory/types/memory_types.hpp>
#include <reflowOS/base/memory/types/size_type.hpp>

namespace reflowOS::memory::types {

	template <typename T>
	struct is_static_pointer 										 { STATIC_MEMORY_TYPE(bool) value = false; };

	template <size_type MemorySize>
	struct is_static_pointer<static_pointer_description<MemorySize>> { STATIC_MEMORY_TYPE(bool) value = true; };

	template <typename T>
	struct is_dynamic_pointer 										 { STATIC_MEMORY_TYPE(bool) value = false; };

	template <>
	struct is_dynamic_pointer<dynamic_pointer_description> 			 { STATIC_MEMORY_TYPE(bool) value = true; };

	template <typename T>
	using is_static_pointer_v  = is_static_pointer<T>::value;

	template <typename T>
	using is_dynamic_pointer_v = is_dynamic_pointer<T>::value;
}
