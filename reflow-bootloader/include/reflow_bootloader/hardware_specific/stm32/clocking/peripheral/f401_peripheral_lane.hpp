#pragma once
#include "stm32f4xx_ll_rcc.h"

namespace reflow_bootloader {
namespace hardware_specific {
namespace clocking 			{

								   struct peripheral_lane 	   							{};
								   struct high_performance_bus : public peripheral_lane {}; // AHB
	template <std::uint8_t LaneId> struct generic_peripheral   : public peripheral_lane {}; // APB1, APB2
}
}
}