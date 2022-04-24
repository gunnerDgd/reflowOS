#include <reflow_bootloader/hardware_specific/stm32/clocking/peripheral/f401_peripheral_traits.hpp>

using namespace reflow_bootloader::hardware_specific::clocking;

typename peripheral_clock_traits<high_performance_bus>::frequency_type
		 peripheral_clock_traits<high_performance_bus>::current_frequency()
{
	LL_RCC_ClocksTypeDef 		freq_query ;
	LL_RCC_GetSystemClocksFreq(&freq_query); return freq_query.HCLK_Frequency;
}

typename peripheral_clock_traits<high_performance_bus>::prescale_type
		 peripheral_clock_traits<high_performance_bus>::current_scale    ()
{
	return LL_RCC_GetAHBPrescaler();
}

void peripheral_clock_traits<high_performance_bus>::scale_to(prescale_type coff)
{
	LL_RCC_SetAHBPrescaler(coff);
}

typename peripheral_clock_traits<generic_peripheral<0>>::frequency_type
		 peripheral_clock_traits<generic_peripheral<0>>::current_frequency()
{
	LL_RCC_ClocksTypeDef 		freq_query ;
	LL_RCC_GetSystemClocksFreq(&freq_query); return freq_query.PCLK1_Frequency;
}

typename peripheral_clock_traits<generic_peripheral<0>>::prescale_type
		 peripheral_clock_traits<generic_peripheral<0>>::current_scale    ()
{
	return LL_RCC_GetAPB1Prescaler();
}

void peripheral_clock_traits<generic_peripheral<0>>::scale_to(prescale_type coff)
{
	LL_RCC_SetAPB1Prescaler(coff);
}

typename peripheral_clock_traits<generic_peripheral<1>>::frequency_type
		 peripheral_clock_traits<generic_peripheral<1>>::current_frequency()
{
	LL_RCC_ClocksTypeDef 		freq_query ;
	LL_RCC_GetSystemClocksFreq(&freq_query); return freq_query.PCLK2_Frequency;
}

typename peripheral_clock_traits<generic_peripheral<1>>::prescale_type
		 peripheral_clock_traits<generic_peripheral<1>>::current_scale    ()
{
	return LL_RCC_GetAPB2Prescaler();
}

void peripheral_clock_traits<generic_peripheral<1>>::scale_to(prescale_type coff)
{
	LL_RCC_SetAPB2Prescaler(coff);
}
