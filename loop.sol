pragma solidity *.*.*;

contract loop {
	int N;
	constructor() public {
	   int i;
		for (i = 0; i < 1048576; ++i) {
		}
		N = i;
	}
}
