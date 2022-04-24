#pragma once
#include <cstdint>

namespace reflow_bootloader {
namespace clocking 		    {

	template <typename PeripheralLane, typename ClockTraits>
	class peripheral_clock
	{
	public:
		using  lane_type 	  = 		 PeripheralLane				;
		using  traits_type 	  = 		 ClockTraits   				;
		using  frequency_type = typename ClockTraits::frequency_type;

		using  configuration  = typename ClockTraits::configuration ;
		using  prescale_type  = typename ClockTraits::prescale_type ;

	public:
		peripheral_clock();
		peripheral_clock(configuration);

	public:
		frequency_type current_frequency() 					 { return traits_type::current_frequency()	  ; }
		prescale_type  current_scale	()					 { return traits_type::current_scale    ()	  ; }
		void 		   scale_to			(prescale_type coff) { 		  traits_type::scale_to			(coff); }
	};

}
}