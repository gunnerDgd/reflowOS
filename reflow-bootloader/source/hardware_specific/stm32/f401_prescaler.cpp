#include <reflow_bootloader/hardware_specific/stm32/clocking/f401_prescaler.hpp>

reflow_bootloader::hardware_specific::clocking::prescaler::prescale_coefficient::prescale_coefficient
	(coefficient_type m,
	 coefficient_type n,
	 coefficient_type q) : __M_prescale_coff_m(m << (RCC_PLLCFGR_PLLM_0)),
	 	 	 	 	 	   __M_prescale_coff_n(n)						 ,
						   __M_prescale_coff_q(q << (RCC_PLLCFGR_PLLQ_0)) {  }


void reflow_bootloader::hardware_specific::clocking::prescaler::scale_to()
{
	do    { LL_RCC_PLL_Disable(); }
	while ( LL_RCC_PLL_IsReady() );
}

void reflow_bootloader::hardware_specific::clocking::prescaler::scale_to(clock_soruce         clk_src ,
																		 prescale_coefficient clk_coff)
{
	this->scale_to(); // Switch off PLL prescaler module;
	LL_RCC__PLL_ConfigDomain_SYS(static_cast<std::uint32_t>(clk_src),
								 clk_coff.__M_prescale_coff_m,
								 clk_coff.__M_prescale_coff_n,
								 clk_coff.__M_prescale_coff_q);

		   LL_RCC_PLL_Enable (); // Enable PLL prescaler module.
	while(!LL_RCC_PLL_IsReady());
}

typename reflow_bootloader::hardware_specific::clocking::prescaler::clock_source
		 reflow_bootloader::hardware_specific::clocking::prescaler::prescaler_source ()
{
	return static_cast<clock_source>(LL_RCC_PLL_GetMainSource());
}

bool reflow_bootloader::hardware_specific::clocking::prescaler::current_state()
{
	return LL_RCC_PLL_IsReady();
}