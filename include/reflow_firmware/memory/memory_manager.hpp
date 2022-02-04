#pragma once
#include <reflow_firmware/memory/memory_types.hpp>
#include <reflow_firmware/memory/memory_object.hpp>

namespace reflow_firmware::memory {

	void		 initialize();
	pointer_type allocate  (size_type);
	void 		 deallocate(size_type);
}
