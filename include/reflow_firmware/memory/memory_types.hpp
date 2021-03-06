#pragma once
#include <xparameters.h>

#include <cstddef>
#include <cstdint>

#define REFLOW_STATIC_VARIABLE(type, name)		 static 		  type name;
#define REFLOW_CONST_VARIABLE(type, name, value) static constexpr type name = value;
#define REFLOW_DEFINE_TYPE(type, redefine)		 typedef 		  type redefine;

namespace reflow_firmware::memory {
	REFLOW_DEFINE_TYPE   (std::size_t  , size_type)
	REFLOW_DEFINE_TYPE   (std::uint8_t*, pointer_type)

	REFLOW_CONST_VARIABLE(size_type, pointer_base	    , XPAR_MIG_7SERIES_0_BASEADDR)
	REFLOW_CONST_VARIABLE(size_type, pointer_dedicated  , XPAR_MIG_7SERIES_0_BASEADDR)
	REFLOW_CONST_VARIABLE(size_type, pointer_allocatable, pointer_base + 128 * 1024 * 1024)

	REFLOW_CONST_VARIABLE(size_type, block_size 	 , 4096)
	REFLOW_CONST_VARIABLE(size_type, memory_size	 , 256 * 1024 * 1024)
	REFLOW_CONST_VARIABLE(size_type, allocatable_size, 128 * 1024 * 1024)

	REFLOW_CONST_VARIABLE(size_type, block_count			 , memory_size       / block_size)
	REFLOW_CONST_VARIABLE(size_type, block_allocatable_count , allocatable_size  / block_size)
	REFLOW_CONST_VARIABLE(size_type, block_allocatable_offset, pointer_dedicated / block_size)

	enum class block_state : std::uint8_t
	{
		allocated  ,
		unallocated,
		reserved   ,
		locked	   ,
		dedicated
	};

	struct block	  { std::uint8_t context[block_size] ; };
	struct block_tag  { block_state  tag	[block_count]; };
	struct block_stat
	{
		size_type count_allocated  ,
				  count_unallocated,
				  count_reserved   ;
	};
}
