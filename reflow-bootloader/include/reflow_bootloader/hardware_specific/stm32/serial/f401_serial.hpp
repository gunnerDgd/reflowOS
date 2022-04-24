#pragma once

#include <reflow_bootloader/hardware_specific/stm32/f401_types.hpp>
#include <cstdint>

namespace reflow_bootloader {
namespace hardware_specific {
namespace serial_device     {

/*
 * If your device supports serial communication,
 * two things must be declared by the header in "hardware_specific/{Your Device Name}".
 *
 * 		- serial_handle_t
 * 			--> in namespace reflow_bootloader::hardware_specific::types
 * 			--> Represents Native Handle Type of the USART / UART Port. Same with Register Type.
 * 			--> In STM32, This stands for the handle type which LL driver uses to initialize Serial Operation.
 */

	using 					native_handle_type 				   = USART_TypeDef*;
	static inline constexpr native_handle_type serial_device[] = { USART1, USART6 };

/*
 * Optional Field for Name Aliasing
 * This Field is not necessary for Reflow bootloader standard.
 */
	static inline constexpr types::serial_handle_t system_serial    = USART1;
	static inline constexpr types::serial_handle_t auxiliary_serial = USART6;
}
}
}