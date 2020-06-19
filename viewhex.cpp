#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string.h>

int main(int ArgN, char *Args[]) {
	if(ArgN == 1) {
		std::cerr << "Error: No Argment!" << std::endl;
		std::cout << "Usage: viewhex [File name] ( [From] [To] )" << std::endl;
		return -1;
	}
	if(strcmp(Args[1], "-h") == 0 || strcmp(Args[1], "--help") == 0) {
		std::cout << "Usage: viewhex [File name] ( [From] [To] )" << std::endl;
		return -1;
	}
	std::ifstream File(Args[1], std::ios::binary);
	if(!File) {
		std::cerr << "Error: Can't Open the File!" << std::endl;
		std::cout << "Usage: viewhex [File name] ( [From] [To] )" << std::endl;
		return -1;
	}
	File.seekg(0, std::ios_base::end);
	int Filesize = File.tellg();
	int FPoint = 0, EPoint = Filesize;
	if(ArgN == 4) {
		FPoint = atoi(Args[2]);
		EPoint = atoi(Args[3]);	
	}
	File.seekg(0, std::ios_base::beg);
	unsigned char Filedata[Filesize];
	File.read((char*)&Filedata, Filesize);
	File.close();
	std::cout << std::setfill('0');
	for(int num = FPoint;num < Filesize && num < EPoint;num += 1) {
		switch(Filedata[num]) {
			case '\n':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\n  at " << "0x" << std::setw(10) << num << '\n';		
				break;			
			case '\r':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\r  at " << "0x" << std::setw(10) << num << '\n';
				break;		
			case '\t':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\t  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\a':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\a  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\b':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\b  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\v':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\v  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\f':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\f  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\e':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\e  at " << "0x" << std::setw(10) << num << '\n';
				break;
			case '\0':
				std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: \\0  at " << "0x" << std::setw(10) << num << '\n';
				break;			
			default:
				if(Filedata[num] < 0x1F || Filedata[num] == 0x7F) {
					std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: CTR at " << "0x" << std::setw(10) << num << '\n';
				} else {
					std::cout << std::dec <<std::setw(10) << num << ": " << std::hex << "0x" << std::setw(10) << (int)Filedata[num] << " ASCII: " << Filedata[num] << "   at " << "0x" << std::setw(10) << num << '\n';
				}
				break;
		}	
	}
	std::cout << std::endl;
	return 0;
	}
