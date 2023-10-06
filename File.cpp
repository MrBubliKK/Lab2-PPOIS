#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class File { //КЛАСС ФАЙЛА
private:
	int file_size;
	string file_expansion;
	string file_name;

public:
	File(int file_size, string file_expansion, string file_name) :
		file_size(file_size),
		file_expansion(file_expansion),
		file_name(file_name) {}

	//Возвращает размер файла
	int Get_file_size() {
		return this->file_size;
	}

	//Задает размер файла
	void Set_file_size(int file_size) {
		this->file_size = file_size;
	}

	//Возвращает расширение
	string Get_file_expansion() {
		return this->file_expansion;
	}

	//Задает расширение
	void Set_file_expansion(string file_expansion) {
		this->file_expansion = file_expansion;
	}

	string Get_name_file() {
		return this->file_name;
	}

	void Set_name_file(string file_name) {
		this->file_name = file_name;
	}

};