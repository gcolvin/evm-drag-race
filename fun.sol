pragma solidity ^0.4.0;

contract fun {

	uint[2] bottom;

	function f1A(uint top) {
		bottom[0] = top;
	}
	function f1B(uint top) {
		bottom[0] = top;
	}
	function f1(uint top) {
		f1A(top);
		f1B(top);
	}

	function f2A(uint top) {
		bottom[1] = top;
	}
	function f2B(uint top) {
		bottom[1] = top;
	}
	function f2(uint top) {
		f2A(top);
		f2B(top);
	}

	function f(uint top1, uint top2) {
		f1(top1);
		f2(top2);
	}

	function fun() {
		for (uint i = 0; i < 65536; ++i) {
			uint x = i;
			uint y = i;
			f(x, y);
		}
	}
}
