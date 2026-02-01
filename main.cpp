#include <iostream>
#include "src/cpu.hpp"
#include <array>
#include <cstdint>

int main(){
	CLTPU cpu;
	std::array<uint8_t,CLTPU::RAM_SIZE> program{};
	
	program[0] = 0x1E;
	program[1] = 0x2F;
	program[2] = 0x40;
	
	program[4] = 0x00;
	
	program[14] = 5;
	program[15] = 3;
	
	cpu.loadProgram(program);
	cpu.run();
}
