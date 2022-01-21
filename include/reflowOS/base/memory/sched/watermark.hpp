#include <cstdint>
#include <cstddef>

namespace reflowOS {
namespace memory   {
	struct watermark
	{
	public:
		typename std::size_t wm_size_type;
		typedef  void*		 wm_pointer_type;
		struct section     { wm_pointer_type start_point, end_point; };

	public:
		section system_section;
		section config_section;
		section program_section;
	};
}
}
