#pragma once

#include <cstdint>
#include <cstddef>

#define STATIC_MEMORY_TYPE(type) 			static constexpr type
#define DEFINE_MEMORY_TYPE(type, redefined) typedef type redefined;

namespace reflowOS::memory::types {

	DEFINE_MEMORY_TYPE(std::size_t  , size_type)
	DEFINE_MEMORY_TYPE(std::size_t  , offset_type)
	DEFINE_MEMORY_TYPE(std::uint8_t*, pointer_type)

	template <offset_type address = -1>
	union pointer_description
	{
		STATIC_MEMORY_TYPE(offset_type)  pointer_integer = address;
		STATIC_MEMORY_TYPE(pointer_type) pointer_address;
	};

	template <>
	union pointer_description<-1>
	{
		offset_type  pointer_integer;
		pointer_type pointer_address;
	};

	template <offset_type address>
	using static_pointer_description  = pointer_description<address>;
	using dynamic_pointer_description = pointer_description<>		;

	STATIC_MEMORY_TYPE(size_type) kilobyte = 1024;
	STATIC_MEMORY_TYPE(size_type) megabyte = kilobyte * 1024;
	STATIC_MEMORY_TYPE(size_type) gigabyte = megabyte * 1024;

	STATIC_MEMORY_TYPE(size_type) block_size = 4 * kilobyte; // Standard x86-64 Page Size.

	struct block 	 { std::uint8_t context[block_size]; };
	struct block_tag
	{
		enum class state : std::uint8_t
		{
			allocated   = (1 << 0),
			unallocated = (1 << 1),
			reserved    = (1 << 2)
		};

		DEFINE_MEMORY_TYPE(std::uint32_t, process_type)  ;
		DEFINE_MEMORY_TYPE(std::uint32_t, timestamp_type);
		DEFINE_MEMORY_TYPE(block*		, block_pointer) ;

		process_type   attached_process;
		block_pointer  attached_block  ;
		timestamp_type accessed_time   ;
	};
}
