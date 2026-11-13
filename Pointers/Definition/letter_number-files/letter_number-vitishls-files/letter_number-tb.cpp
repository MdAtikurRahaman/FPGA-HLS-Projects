#include "letter_number-tb.h"
#include <iostream>



int main() {

		int           status = 0;

		bool          sel;
		unsigned int  index;
		ap_uint<8>    data_code;
		ap_uint<4>    enable_code;


		sel = 0; index = 2;
		letter_number( sel, index, data_code, enable_code);
		std::cout << " sel = " << sel
				  << " code = " << index
				  << " seven_segment_data = "   << data_code
				  << " seven_segment_enable = " << enable_code
				  << std::endl;
		//---------------------------------------------------------
		sel = 0; index = 4;
		letter_number( sel, index, data_code, enable_code);
		std::cout << " sel = " << sel
				  << " code = " << index
				  << " seven_segment_data = "   << data_code
				  << " seven_segment_enable = " << enable_code
				  << std::endl;
		//---------------------------------------------------------
		sel = 1; index = 0;
		letter_number( sel, index, data_code, enable_code);
		std::cout << " sel = " << sel
				  << " code = " << index
				  << " seven_segment_data = "   << data_code
				  << " seven_segment_enable = " << enable_code
				  << std::endl;
		//---------------------------------------------------------
		sel = 1; index = 5;
		letter_number( sel, index, data_code, enable_code);
		std::cout << " sel = " << sel
				  << " code = " << index
				  << " seven_segment_data = "   << data_code
				  << " seven_segment_enable = " << enable_code
				  << std::endl;
		//---------------------------------------------------------


		return status;
}
