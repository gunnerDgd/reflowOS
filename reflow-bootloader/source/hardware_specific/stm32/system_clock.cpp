#include <reflow_bootloader/hardware_specific/stm32/clocking/f401_system_clock.hpp>

reflow_bootloader::clocking::system_clock::system_clock()					{  }
reflow_bootloader::clocking::system_clock::system_clock(configuration conf)
	 : __M_sysclock_handle(conf.__M_clksrc_handle)
{
	if(conf.__M_clksrc_handle == sources::prescaled)
		hardware_specific::registered_device::prescaler.scale_to(conf.__M_clksrc_prescaler);

	LL_RCC_SetSysClkSource(__M_sysclock_handle);
}

typename reflow_bootloader::clocking::system_clock::native_handle_type
		 reflow_bootloader::clocking::system_clock::native_handle    () { return __M_sysclock_source; }

typename reflow_bootloader::clocking::system_clock::frequency_type
		 reflow_bootloader::clocking::system_clock::current_frequency()
{
	LL_RCC_ClocksTypeDef 		freq_query ;
	LL_RCC_GetSystemClocksFreq(&freq_query); return freq_query.SYSCLK_Frequency;
}