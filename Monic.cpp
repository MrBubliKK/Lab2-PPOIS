#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Monic {  //КЛАСС МОНИТОРА
private:
	bool monic_condition = false;

public:
	//Выдает состояние моника
	bool Get_monic_condition() {
		return this->monic_condition;
	}

	//задает состояние моника
	void Set_monic_condition(bool monic_condition) {
		this->monic_condition = monic_condition;
	}
};