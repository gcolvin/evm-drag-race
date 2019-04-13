pragma solidity ^0.4.0;

contract rng {

	// 2**20 tests
	function rng() {
	
		// magic seeds
		uint256 shub = 0x627c8a0a11b125504c703040dd1821c53293b76dfd8bb9fca1159b123179435;
		uint[5] memory blum = [uint(0xa96d80548950c6e1fd4299395ee381a3),
									0xec36bfc9cfdfcbf201fd78ee4cdad4fb,
                    	    		0xdba29b85a759fb10848f01256f2b5c39,
		                   			0xa9390182a3a79447c8394ae189edcfc1,
									0xd66ec8a137fb01fae6b7a83c83d0adf9];
		uint256 mix = gasleft();
		for (uint i = 0; i < 32768; ++i) {
			uint8[32][5] memory out;

			// need 32 bytes of output for each log argument
			for (uint256 j = 0; j < 32; ++j) {
			
				// harvest bytes from 5 Blum Blum Shubs for 5-word log output
				for (uint k = 0; k < 5; ++k) {
				
					uint256 bbs = blum[k];
					bbs *= bbs;
					bbs %= shub;
					blum[k] = bbs;
					
					out[k][j] ^= uint8((mix ^= bbs) & 255);
				}
			}	
		}
		log4(bytes32(out[0]), bytes32(out[1]), bytes32(out[2]), bytes32(out[3]), bytes32(out[4]));
	}
}
