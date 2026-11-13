#pragma once

#include "consumer_nonblocking.h"


void consumer_nonblocking(hls::stream<unsigned short int> &din,
		           unsigned short int &sout,
				   unsigned short int n);
