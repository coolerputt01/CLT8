#pragma once


#include <cstdint>
#include <array>
#include <iostream>
struct CLTPU{
	static const int RAM_SIZE = 16;
	std::array<uint8_t,RAM_SIZE> RAM{};
		
	uint8_t PC = 0;
	uint8_t R0 = 0;
	uint8_t R1 = 0;
	uint8_t IR = 0;

	bool isRunning = true;
	 
	void loadProgram(const std::array<uint8_t,RAM_SIZE> &program){
		RAM = program;
	}

	void fetch(){
		IR = RAM[PC];
		PC++;
	}

	void decodeAndExecute(){
		uint8_t opcode = (IR & 0xF0) >> 4;
		uint8_t operand = IR & 0xF0;
	
		switch(opcode){
			case 0x0:
				isRunning = false;
				break;
			case 0x1:
				R0 = RAM[operand];
				break;
			case 0x2:
				R1 = RAM[operand];
				break;
			case 0x3:
				RAM[operand] = R0;
				break;
			case 0x4:
				R0 += R1;
				break;
			case 0x5:
				R0 -= R1;
				break;
			case 0x6:
				PC = operand;
				break;
			case 0x7:
				if(R0 == 0){
					PC = operand;
				}
				break;
			default:
				std::cerr<<"Unknown opcode...\n";
				isRunning = false;
		
		}

	}
	void debug() {
        	std::cout << "PC: " << (int)PC
             	<< " | R0: " << (int)R0
             	<< " | R1: " << (int)R1
             	<< "\n";
    	}

	void run(){
		fetch();
		decodeAndExecute();
		debug();
		}
};
