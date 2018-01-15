#include "ttmath/ttmath.h"

int main()
{
	ttmath::UInt<32> v(3), w(2);
	printf("%d\n", (int)(v * w));
}