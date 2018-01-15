#include "ttmath/ttmath.h"
typedef ttmath::UInt<TTMATH_BITS(256)> u256;

int main() {
	u256 s("0xff3f9014f20db29ae04af2c2d265de17");
	u256 r;
	for (u256 i = 0; i < 1048576; ++i) {
		volatile unsigned v = 0;
		u256 z = s + v;
		u256 y("0xfe7fb0d1f59dfe9492ffbf73683fd1e870eec79504c60144cc7f5fc2bad1e611");
		u256 x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x = z;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y; x /= y;
		r = x;
	}
	return r != "0xff3f9014f20db29ae04af2c2d265de17";
}

