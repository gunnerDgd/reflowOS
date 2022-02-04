#pragma once
#include <reflow_firmware/memory/memory_types.hpp>
#include <type_traits>

namespace reflow_firmware::static_object {
	extern reflow_firmware::memory::block_tag  memory_block_tag ;
	extern reflow_firmware::memory::block_stat memory_block_stat;
}

namespace reflow_firmware::memory {
	template <typename Executable>
	void iterate			(Executable&&, block_state)

	template <typename Executable, typename ExecCondition>
	void conditional_iterate(Executable&&, ExecCondition&&);
}

template <typename Executable>
void reflow_firmware::memory::iterate(Executable&& exec, block_state stat)
{
	for(int it = 0 ; it < )
}

template <typename Executable, typename ExecCondition>
void reflow_firmware::memory::conditional_iterate(Executable&& exec, ExecCondition&& stat)
{

}
