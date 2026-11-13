#pragma once

#include "producer_nonblocking.h"


void producer_nonblocking(
		hls::stream<unsigned short int> &dout,
		unsigned short int n);
