#include "ttmath/ttmath.h"
typedef ttmath::UInt<TTMATH_BITS(256)> u256;

int main() {
	u256 s("0x4bfcd8bb2ac462735b48a17580690283980aa2d679f091c64364594df113ea37");
	u256 r;
	for (u256 i = 0; i < 1048576; ++i) {
		volatile unsigned v = 0;
		u256 z = s + v;
		u256 y("0x97f9b1765588c4e6b69142eb00d20507301545acf3e1238c86c8b29be227d46e");
		u256 x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x = z;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y; x -= y;
		r = x;
	}
	return r != "0x4bfcd8bb2ac462735b48a17580690283980aa2d679f091c64364594df113ea37";
}

