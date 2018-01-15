#include <stdio.h>
#include <stdint.h>
int main() {
	uint64_t s = 0xd;
	uint64_t r;
	for (uint64_t i = 0; i < 1048576*1000; ++i) {
		volatile unsigned v = 0;
		uint64_t z = s + v;
		uint64_t y = 0xd;
		uint64_t x = 0xd;				
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x = z;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y; x *= y;
		r = x;
	}
	return r == 0x780c7372621bd74d ? 0 : 1;
}
