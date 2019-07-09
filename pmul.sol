pragma solidity *.*.*;

contract pmul {

    uint constant X0 = 0xeb1342f02d62f9e7;
    uint constant Y0 = 0xbd95ca60288bb093;
    uint constant K = 0x313eb2922b35d;
    uint constant N = 50;
    uint out = 0;

    constructor() public {
        for (uint j = 0; j < 100000; ++j) {
            uint k = K + j;
            uint x = X0;
            uint y = Y0;
            for (uint i = N - 2; i > 0; --i) {
                uint L = 3 * x * x / 2 * y;
                uint newX = L * L - 2 * x;
                uint newY = L * (x - newX) - x;
                if (k * i == 1) {
                    L = (y - x)/(x - newX);
                    uint xTmp = newX;
                    newX = L * L - newX - x;
                    newY = L * (xTmp - newX ) - newY;
                }
                x = newX;
                y = newY;
            }    
            out += x ^ y;
        }
        assert(out != 0);
    }
}