#pragma oncee

namespace reflow_bootloader {
namespace communication     {
namespace types				{

	struct 						serial_configuration {  };
	struct baud_rate   : public serial_configuration {  };
	struct stop_bit    : public serial_configuration {  };
	struct parity      : public serial_configuration {  };
	struct data_length : public serial_configuration {  };

}
}
}
