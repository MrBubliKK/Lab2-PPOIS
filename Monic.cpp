#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Monic {  //����� ��������
private:
	bool monic_condition = false;

public:
	//������ ��������� ������
	bool Get_monic_condition() {
		return this->monic_condition;
	}

	//������ ��������� ������
	void Set_monic_condition(bool monic_condition) {
		this->monic_condition = monic_condition;
	}
};