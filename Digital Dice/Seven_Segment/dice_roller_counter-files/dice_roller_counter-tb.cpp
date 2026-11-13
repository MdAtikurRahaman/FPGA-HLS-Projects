#include "dice_roller_counter-tb.h"
#include <iostream>
#include <map>
#include <time.h>




int main() {

	int status = 0;

	bool          roll;
	ap_uint<8>   first_random_number;
	ap_uint<8>   second_random_number;

	srand (time(NULL));

	roll = 1;
	dice_roller_counter(roll, first_random_number, second_random_number);
	std::cout << " first_random_number = " << first_random_number << " second_random_number = " << second_random_number<< std::endl;



	for (int i = 0; i < 20; i++) {
		int r =rand()%1024;
		for (int j = 0; j < r; j++) {
			roll = 0;
			dice_roller_counter(roll, first_random_number, second_random_number);
		}
		roll = 1;
		dice_roller_counter(roll, first_random_number, second_random_number);
		std::cout << " first_random_number = " << first_random_number << " second_random_number = " << second_random_number<< std::endl;
	}

	return status;


}
