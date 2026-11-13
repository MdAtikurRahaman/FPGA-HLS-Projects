#pragma once

#include "data_consumer.h"


void data_consumer(hls::stream<unsigned short int> &din,
		           unsigned short int &sout,
				   unsigned short int n);
