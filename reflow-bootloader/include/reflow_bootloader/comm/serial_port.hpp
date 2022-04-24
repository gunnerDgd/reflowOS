#pragma once
#include <reflow_bootloader/hardware_specific/stm32/serial/f401_serial.hpp>
#include <reflow_bootloader/comm/serial_conf.hpp>

namespace reflow_bootloader {
namespace communication 	{

	class serial_port
	{
	public:
		using  native_handle_type = hardware_specific::serial_device::native_handle_type;
		class  enunmerator;
		struct configuration
		{
			friend class serial_port;

			using 	   baud_rate = std::uint32_t;
			enum class stop_bit    : int { bit_1 = LL_USART_STOPBITS_1  , bit_2 = LL_USART_STOPBITS_2 };
			enum class data_length : int { bit_8 = LL_USART_DATAWIDTH_8B, bit_9 = LL_USART_DATAWIDTH_9B };
			enum class parity 	   : int
			{
				none = LL_USART_PARITY_NONE,
				even = LL_USART_PARITY_EVEN,
				odd  = LL_USART_PARITY_ODD
			};

			configuration(baud_rate   brate    = 9600			   ,
						  stop_bit    stopbits = stop_bit::bit_1   ,
						  data_length dlen 	   = data_length::bit_8,
						  parity      pbit     = parity::none);

		private:
			baud_rate   __M_conf_baudrate;
			stop_bit 	__M_conf_stopbit ;
			data_length __M_conf_datalen ;
			parity      __M_conf_parity  ;
		};

	public:
		constexpr serial_port(index_type);
				 ~serial_port();

	public:
		template <typename AnyOption> void operator[](AnyOption&&) 							   {}
		template <>					  configuration::baud_rate  & operator[](types::baud_rate)  ;
		template <>					  configuration::stop_bit   & operator[](types::stop_bit)   ;
		template <>					  configuration::data_length& operator[](types::data_length);
		template <>					  configuration::parity     & operator[](types::parity)     ;

	private:
		native_handle_type __M_serial_handle	   ;
		configuration	   __M_serial_configuration;
	};


}
}
