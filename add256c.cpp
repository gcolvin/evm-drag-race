#include "ttmath/ttmath.h"
typedef ttmath::UInt<TTMATH_BITS(256)> u256;

int main() {
	u256 s("0x802431afcbce1fc194c9eaa417b2fb67dc75a95db0bc7ec6b1c8af11df6a1da9");
	u256 r;
	for (u256 i = 0; i < 1048576; ++i) {
		volatile unsigned v = 0;
		u256 z = s + v;
		u256 y("0xa1f5aac137876480252e5dcac62c354ec0d42b76b0642b6181ed099849ea1d57");
		u256 x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x = z;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		x += y; x += y; x += y; x += y; x += y; x += y; x += y; x += y;
		r = x;
	}
	return r != "0x9f7eddc3444467c3e7afc7507a765053e9b860c8b6ff34ded09948967e0bf319";
}

