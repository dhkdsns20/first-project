#include <iostream>
using namespace std;

#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {  //memory 0으로 초기화
		mem[i] = 0;
	}
	// 다른 방법memset(mem,0,size)
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}

