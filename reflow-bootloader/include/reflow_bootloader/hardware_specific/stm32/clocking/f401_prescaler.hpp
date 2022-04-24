#include "stm32f4xx_ll_rcc.h"

namespace reflow_bootloader {
namespace hardware_specific {
namespace clocking			{

	/*
	 * class "internal_clock_prescaler"
	 *
	 * 	--> Set Main Clock Souce to HSI (Internal Clock Oscillator)
	 * 	--> USE LL_RCC_PLLSOURCE_HSI
	 */
	class prescaler
	{
	public:
		using      coefficient_type = std::uint8_t;
		struct 	   prescale_coefficient;
		enum class clock_source : std::uint32_t
		{
			internal = LL_RCC_PLLSOURCE_HSI,
			external = LL_RCC_PLLSOURCE_HSE
		};
	public:
		constexpr prescaler() {}
				 ~prescaler() { LL_RCC_PLL_Disable(); }

	public:
		void 		 scale_to     ()				  				; // Turn off prescaler.
		void 		 scale_to	  (clock_soruce, prescale_coefficient);

		clock_source prescaler_source();
		bool		 current_state   (); // true for Switched on, false for off.
	};


	struct prescaler::prescale_coefficient
	{
		friend class prescaler;
		using 		 coefficient_type = std::uint32_t;
		prescale_coefficient(coefficient_type m = 2  ,
							 coefficient_type n = 200,
							 coefficient_type q = 2) ;

	private:
		coefficient_type __M_prescale_coff_m,
						 __M_prescale_coff_n,
						 __M_prescale_coff_q;
	};

}
}
}

namespace reflow_bootloader {
namespace hardware_specific {
namespace registered_device {
	inline constexpr clocking::prescaler prescaler; // Registered Prescaler Device.
}
}
}