#include <reflow_firmware/memory/memory_types.hpp>

namespace reflow_firmware::memory {

	struct watermark_section { memory::size_type start, end };
	struct watermark		 { watermark_section section[wm_count]; };
}
