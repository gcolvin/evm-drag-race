#include "ttmath/ttmath.h"
typedef ttmath::UInt<TTMATH_BITS(256)> u256;

int main() {
	u256 s("0xc27b83c7d9d312389735f7b3b3b85eb630608f906992f889b6c8814e31b8eb3b");
	u256 r;
	for (u256 i = 0; i < 8192; ++i) {
		volatile unsigned v = 0;
		u256 z = s + v;
		u256 y("0xdd1620ca66b8877ff381a3475f3892560337791da698c011eaa92fb9626161c3");
		u256 x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x = z;
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y); x.Pow(y);
		r = x;
	}
	if (r != "0x3b46f4bb35c94a2cb5f8c1e1e1f918b76a3fe3da9874d2c8abf29a85f90aa37b")
		throw;
}

