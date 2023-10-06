#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Workfunctions.h"
using namespace std;



int main() {
	system("chcp 1251");
	string change;

	Sys_block sys_block;
	Monic monic;
	Computer computer;
	Basket basket;
	Drive drive;

	string turn_monic;
	computer.Set_two_os(sys_block);
	sys_block.Set_sys_condition(false);
	monic.Set_monic_condition(false);
	computer.Create_list_wifi();

	if (!Turn_computer(sys_block, monic)) {
		return 1;
	}
	Turn_monic(monic);
	Enter_os(computer);
	Work_with_something(basket, sys_block, computer, drive, monic);
	return 1;
}