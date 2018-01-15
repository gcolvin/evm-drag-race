// https://people.csail.mit.edu/rivest/Rivest-rc5rev.pdf
#include <stdint.h>

static uint32_t shift_left(uint32_t v, uint32_t n) {
	return v << n;
//	return v * pow(2, n);
}

static uint32_t shift_right(uint32_t v, uint32_t n) {
	return v >> n;
//	return v / pow(2, n);
}

static uint32_t rotate_left(uint32_t v, uint32_t n) {
	n &= 0x1f;
	return shift_left(v, n) | shift_right(v, 32 - n);
}

static uint32_t rotate_right(uint32_t v, uint32_t n) {
	n &= 0x1f;
	return shift_right(v, n) | shift_left(v, 32 - n);
}

static void encrypt(uint32_t S[26], uint32_t inout[4]) {
	for (uint32_t i = 0; i < 4; i += 2) {
		uint32_t A = inout[i];
		uint32_t B = inout[i+1];
		A += S[0];
		B += S[1];
		for (int j = 0; j < 12; ++j) {
			A = rotate_left((A ^ B), B) + S[2 * i];
			B = rotate_left((B ^ A), A) + S[2 * i + 1];
		}
		inout[i] = A;
		inout[i+1] = B;
	}
}

static void decrypt(uint32_t S[26], uint32_t inout[4]) {
	for (uint32_t i = 0; i < 4; i += 2) {
		uint32_t A = inout[i];
		uint32_t B = inout[i+1];
		for (int j = 12; j > 0; --j) {
			B = rotate_right(B - S[2 * i + 1], A) ^ A;
			A = rotate_right(A - S[2 * i], B) ^ B;
		}
		B -= S[1];
		A -= S[0];
		inout[i] = A;
		inout[i+1] = B;
	}
}

// expand key into S array using magic numbers derived from e and phi	
static void expand(uint32_t L[4], uint32_t S[26]) {
	uint32_t A = 0;
	uint32_t B = 0;
	uint32_t i = 0;
	uint32_t j = 0;
	S[0] = 0xb7e15163;
	for (i = 1; i < 26; ++i)
		S[i] = S[i - 1] + 0x9e3779b9;
	i = j = 0;
	int n = 3*26;
	while (n-- > 0) {
		A = S[i] = rotate_left((S[i] + A + B), 3);
		B = L[j] = rotate_left((L[j] + A + B), A + B);
		i = (i + 1) % 26;
		j = (j + 1) % 4;
	}
}

static uint32_t save[4];

// decrypt of encrypt should be the same
int test(uint32_t S[26], uint32_t messg[4]) {
	for (int i = 0; i < 4; ++i)
		save[i] = messg[i];
	encrypt(S, messg);
	decrypt(S, messg);
	for (int i = 0; i < 4; ++i) {
		if (messg[i] != save[i])
		  return 0;
	}
	return 1;
}

static uint32_t key[4] = { 0x243F6A88, 0x85A308D3, 0x452821E6, 0x38D01377 };
static uint32_t box[26];
static uint32_t message[4] = { 0xfeedface, 0xdeadbeef, 0xfeedbabe, 0xcafebeef };

int main(int argc, char** argv) {

	key[argc] += argc;
	expand(key, box);

	for (unsigned long i = 0; i < 50000; ++i)
		test(box, message);
		if (!test(box, message))
		  return 1;
	return 0;
}
