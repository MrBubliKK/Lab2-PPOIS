#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Logo {  //ÊËÀÑÑ ßÐËÛÊÀ
private:
	string name_logo;
	string name_main_file;
	string expansion_main_file;

public:
	Logo(string name_logo, string name_main_file, string expansion_main_file) :
		name_logo(name_logo),
		name_main_file(name_main_file),
		expansion_main_file(expansion_main_file) {}

	string Get_name_logo() {
		return this->name_logo;
	}

	void Set_name_logo(string name_logo) {
		this->name_logo = name_logo;
	}

	string Get_name_main_file() {
		return this->name_main_file;
	}

	void Set_name_main_file(string name_main_file) {
		this->name_main_file = name_main_file;
	}

	string Get_expansion_main_file() {
		return this->expansion_main_file;
	}

	void Set_expansion_main_file(string expansion_main_file) {
		this->expansion_main_file = expansion_main_file;
	}
};