#include <iostream>
using namespace std;

#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) {  //memory 0���� �ʱ�ȭ
		mem[i] = 0;
	}
	// �ٸ� ���memset(mem,0,size)
}

Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}

