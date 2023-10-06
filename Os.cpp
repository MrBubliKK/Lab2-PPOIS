#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Os { //ÊËÀÑÑ ÎÏÅÐÀÖÈÎÍÍÎÉ ÑÈÑÒÅÌÛ
private:
	string name_os;
	string password_os;
	int size_os;
	bool access_os;
	

public:
	Os (string name_os, int size_os) :
		name_os(name_os),
		size_os(size_os) {}

	string Get_name_os() {
		return this->name_os;
	}

	void Set_name_os(string name_os) {
		this->name_os = name_os;
	}

	int Get_size_os() {
		return this->size_os;
	}

	void Set_size_os(int size_os) {
		this->size_os = size_os;
	}
	
	string Get_password_os() {
		return this->password_os;
	}

	void Set_password_os(string password_os) {
		this->password_os = password_os;
	}
};
