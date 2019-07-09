pragma solidity *.*.*;

contract fun {

	uint[2] bottom;

	function f1A(uint top) private {
		bottom[0] = top;
	}
	function f1B(uint top) private {
		bottom[0] = top;
	}
	function f1(uint top) private {
		f1A(top);
		f1B(top);
	}

	function f2A(uint top) private {
		bottom[1] = top;
	}
	function f2B(uint top) private {
		bottom[1] = top;
	}
	function f2(uint top) private {
		f2A(top);
		f2B(top);
	}

	function f(uint top1, uint top2) private {
		f1(top1);
		f2(top2);
	}

	constructor() public {
		for (uint i = 0; i < 65536; ++i) {
			uint x = i;
			uint y = i;
			f(x, y);
		}
	}
}
