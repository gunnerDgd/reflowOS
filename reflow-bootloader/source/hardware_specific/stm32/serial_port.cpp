#include <reflow_bootloader/comm/serial_port.hpp>

reflow_bootloader::communication::serial_port::configuration::configuration
					 (baud_rate   brate   ,
					  stop_bit    stopbits,
					  data_length dlen 	  ,
					  parity      pbit    ) : __M_conf_baudrate(brate)	 ,
											  __M_conf_stopbit (stopbits),
											  __M_conf_datalen (dlen)	 ,
											  __M_conf_parity  (pbit)    {  }

constexpr reflow_bootloader::communication::serial_port::serial_port (index_type idx, configuration conf)
	: __M_serial_handle(hardware_specific::serial_device[idx])
{
	LL_USART_SetParity	 	  (__M_serial_handle, conf.__M_conf_parity) ;
	LL_USART_SetDataWidth	  (__M_serial_handle, conf.__M_conf_datalen);
	LL_USART_SetStopBitsLength(__M_serial_handle, conf.__M_conf_stopbit);

	LL_USART_Enable			  (__M_serial_handle);
}

reflow_bootloader::communication::serial_port::~serial_port()
{
	LL_USART_Disable(__M_serial_handle);
}

template <>
typename reflow_bootloader::communication::serial_port::configuration::baud_rate&
		 reflow_bootloader::communication::serial_port::operator[](types::baud_rate)   { return __M_serial_configuration.__M_conf_baudrate; }

template <>
typename reflow_bootloader::communication::serial_port::configuration::stop_bit&
		 reflow_bootloader::communication::serial_port::operator[](types::stop_bit)    { return __M_serial_configuration.__M_conf_stopbit; }

template <>
typename reflow_bootloader::communication::serial_port::configuration::data_length&
		 reflow_bootloader::communication::serial_port::operator[](types::data_length) { return __M_serial_configuration.__M_conf_datalen; }

template <>
typename reflow_bootloader::communication::serial_port::configuration::parity&
		 reflow_bootloader::communication::serial_port::operator[](types::parity)	   { return __M_serial_configuration.__M_conf_parity ; }