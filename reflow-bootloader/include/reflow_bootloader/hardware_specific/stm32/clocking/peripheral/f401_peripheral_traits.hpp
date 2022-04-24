#pragma once
#include <reflow_bootloader/hardware_specific/stm32/clocking/peripheral/f401_peripheral_lane.hpp>

namespace reflow_bootloader {
namespace hardware_specific {
namespace clocking 			{

	template <typename LaneType> class peripheral_clock_traits;

	using ahb   = peripheral_clock_traits<high_performance_bus>;
	using apb_1 = peripheral_clock_traits<generic_peripheral<0>>;
	using apb_2 = peripheral_clock_traits<generic_peripheral<1>>;

	template <>
	class peripheral_clock_traits<high_performance_bus>
	{
	public:
		using  frequency_type = std::uint32_t;
		using  prescale_type  = std::uint32_t;
		struct configuration;

	public:
		static frequency_type current_frequency();
		static prescale_type  current_scale    ();
		static void 		  scale_to		   (prescale_type);
	};

	template <>
	class peripheral_clock_traits<generic_peripheral<0>>
	{
	public:
		using  frequency_type = std::uint32_t;
		using  prescale_type  = std::uint32_t;
		struct configuration;

	public:
		static frequency_type current_frequency();
		static prescale_type  current_scale    ();
		static void 		  scale_to		   (prescale_type);
	};

	template <>
	class peripheral_clock_traits<generic_peripheral<1>>
	{
	public:
		using  frequency_type = std::uint32_t;
		using  prescale_type  = std::uint32_t;
		struct configuration;

	public:
		static frequency_type current_frequency();
		static prescale_type  current_scale    ();
		static void 		  scale_to		   (prescale_type);
	};

}
}
}