#include <reflowOS/base/memory/init/init_type.hpp>

namespace reflowOS::memory {
	void mman_init	    ();
	void mman_shutdown  ();

	void mman_allocate  ();
	void mman_deallocate();
}
