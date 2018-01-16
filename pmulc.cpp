#include "assert.h"
#include "ttmath/ttmath.h"
typedef ttmath::UInt<TTMATH_BITS(256)> uint256;

uint256 const X0 = 0xeb1342f02d62f9e7;
uint256 const Y0 = 0xbd95ca60288bb093;
uint256 const K = 0x313eb2922b35d;
int const N = 50;
uint256 out = 0;

uint256 const U1(1);
uint256 const U2(2);
uint256 const U3(3);

int main(int argc, char**  argv) {
	for (int j = argc; j < 100000; ++j) {
		uint256 k = K + j;
		uint256 x = X0;
		uint256 y = Y0;
		for (int i = N - 2; i > 0; --i) {
			uint256 L = U3 * x * x / U2 * y;
			uint256 newX = L * L - U2 * x;
			uint256 newY = L * (x - newX) - x;
			if (k * i == U1) {
				L = (y - x)/(x - newX);
				uint256 xTmp = newX;
				newX = L * L - newX - x;
				newY = L * (xTmp - newX ) - newY;
			}
			x = newX;
			y = newY;
		}
		out += x ^ y;
	}
	return out == 0;
}
