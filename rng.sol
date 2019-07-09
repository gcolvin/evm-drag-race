pragma solidity *.*.*;

contract rng {

	constructor() public {
	
      // force indeterminate output
      uint256[32] memory out;
      uint256 mix = gasleft();

      // magic seeds
      //    blum is product of primes congruent to 3 mod 4
      //    shub is prime (and must be coprime to p and q)
      uint256 p = 0xbfb9e9cfa0a26397;
      uint256 q = 0xf965dcb10cd35adb;
      uint256 blum = p * q;
      uint256 shub = 0xfdf63130357d68d7;

      for (uint256 i = 0; i < 4096; ++i) {
         uint256 bbs = 0;
         uint256 j;
         for (j = 0; j < 256; ++j) {
            blum *= blum;
            blum %= shub;
            bbs |= blum & 1;
            bbs << 1;
         }
         out[j] = bbs;
         mix = out[bbs % 32];
      }
   }
}
