pragma solidity ^0.4.0;

contract rng {

	// 2**20 tests
	function rng() {
	
		// magic seeds
		uint256 shub = 0x627c8a0a11b125504c703040dd1821c53293b76dfd8bb9fca1159b123179435;
		uint blum = uint(0xa96d80548950c6e1fd4299395ee381a3),
									0xec36bfc9cfdfcbf201fd78ee4cdad4fb,
                    	    		0xdba29b85a759fb10848f01256f2b5c39,
		                   			0xa9390182a3a79447c8394ae189edcfc1,
									0xd66ec8a137fb01fae6b7a83c83d0adf9;
		uint8[32] memory out;
		uint256 mix = gasleft();
		for (uint i = 0; i < 32768; ++i) {

			// need 32 bytes of output for log argument
			for (uint j = 0; j < 32; ++j) {

				uint256 bbs = blum;
				bbs *= bbs;
				bbs %= shub;
				blum = bbs;				
				
				out[j] ^= uint8((mix ^= bbs) & 255);
			}	
		}
		log0(bytes32(out));
	}
}
