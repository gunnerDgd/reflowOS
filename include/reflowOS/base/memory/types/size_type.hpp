#pragma once
#include <reflowOS/base/memory/types/memory_types.hpp>

namespace reflowOS::memory::size_types {
	template <memory::types::size_type total_size>
	struct block_count { STATIC_MEMORY_TYPE(memory::types::size_type) value = total_size / memory::types::block_size; };

	template <memory::types::size_type total_size>
	using  block_count_v = block_count<total_size>::value;

	template <memory::types::size_type index>
	struct block_index { STATIC_MEMORY_TYPE(memory::types::size_type) value = index / memory::types::block_size; };

	template <memory::types::size_type index>
	using  block_index_v = block_index<index>::value;

	template <typename StaticPointer, memory::types::offset_type AddSize>
	struct add_static_pointer
	{
		DEFINE_MEMORY_TYPE(memory::types::static_pointer_description<StaticPointer::pointer_integer + AddSize>, value);
	};
}
