#include <reflow_bootloader/clock/system_clock.hpp>
#include <reflow_bootloader/hardware_specific/stm32/clocking/f401_prescaler.hpp>

namespace reflow_bootloader {
namespace clocking 			{

	struct system_clock::configuration
	{
		friend class system_clock;
		using native_handle_type   = std::uint32_t;
		using prescale_coefficient = hardware_specific::prescaler::prescale_coefficient;

		enum class sources : native_handle_type
		{
			internal_oscillator = LL_RCC_SYS_CLKSOURCE_HSI,
			external_oscillator = LL_RCC_SYS_CLKSOURCE_HSE,
			prescaled 			= LL_RCC_SYS_CLKSOURCE_PLL
		};

		configuration(sources 			   src ,
					  prescale_coefficient coff) : __M_clksrc_handle   (static_cast<native_handle_type>(sources)),
							  	  	  	  	  	   __M_clksrc_prescaler(coff) {  }

	private:
		native_handle_type   __M_clksrc_handle   ;
		prescale_coefficient __M_clksrc_prescaler;
	};

}
}