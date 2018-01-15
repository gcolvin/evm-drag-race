#include "ttmath/ttmath.h"

typedef ttmath::UInt<TTMATH_BITS(256)> u256;

// 2**20 tests
int main() {

	// magic seeds
	u256 shub = 0xbf4081282dfa56a3;
	shub *= 0xa5b708b0c35cd0a5;
	shub *= 0xa272a20711dc7819;
	shub *= 0xa218939391d9bb23;

	u256 blum[5] = { 
		0xa67e7b7edc1b7859,
		0xf446feafddc24db7,
		0x9e110a193cb96c5d,
		0xc21abeddad8a1085
	};

	// force memory access
	volatile unsigned char out[5][32];

	blum[0] = 0;
	for (int i = 0; i < 32768; ++i) {

		// need 32 bytes of output for each log argument
		for (int j = 0; j < 32; ++j) {
		
			// harvest low order byte of 5 Blum Blum Shubs for 5-word log output
			for (int l = 0; l < 5; ++l) {		
				u256 bbs = blum[l];
				bbs *= bbs;
				bbs %= shub;
				blum[l] = bbs;
				out[l][j] = bbs.ToUInt() & 0x255;
			}
		}
	}
	return out[4][31];
}
