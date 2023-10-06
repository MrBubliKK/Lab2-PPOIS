#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Logo.cpp"
#include "File.cpp"
using namespace std;


class Disk { //КЛАСС ДИСКА
private:
	const int disk_memory = 300;
	int files_memory = 0;
	string disk_name;
	vector <File> list_files;

public:
	Disk(string disk_name) :
		disk_name(disk_name) {}

	//Возвращает память диска
	int Get_disk_memory() {
		return this->disk_memory;
	}

	//Возвращает размер файловой памяти
	int Get_files_memory() {
		return this->files_memory;
	}

	//Добавляет к файловой памяти
	void Increase_file_memory(int value) {
		this->files_memory += value;
	}

	//Удаляет из файловой памяти
	void Reduce_file_memory(int value) {
		this->files_memory -= value;
	}

	string Get_disk_name() {
		return this->disk_name;
	}

	void Set_disk_name(string disk_name) {
		this->disk_name = disk_name;
	}

	vector <File> Get_list_files() {
		return this->list_files;
	}

	void Add_file(int file_size, string file_name, string file_expansion) {
		list_files.push_back(File(file_size, file_expansion, file_name));
		return;
	}

	int Get_number_file(string file_name, string file_expansion) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((list_files[i].Get_file_expansion() == file_expansion)
				&& (list_files[i].Get_name_file() == file_name)) {
				return i;
			}
		}
		return -1;
	}

	void Del_final_file(string file_name, string file_expansion) {
		list_files.erase(list_files.begin() + Get_number_file(file_name, file_expansion));
		return;
	}

	//Проверяет присутствие файла на диске
	bool Check_file_in_disk(string file_name, string file_expansion) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((list_files[i].Get_name_file() == file_name)
				&& (list_files[i].Get_file_expansion() == file_expansion)) {
				return false;
			}
		}
		return true;
	}


	//Проверяет заполненность диска
	bool Check_full_size_disk(int file_size) {
		if ((files_memory + file_size) > disk_memory) {
			cout << "ERROR: Память диска заполнена!\n";
			return false;
		}
		return true;
	}

	void Print_disk_files() {
		for (int i = 0; i < list_files.size(); i++) {
			cout << list_files[i].Get_name_file() << "." << list_files[i].Get_file_expansion() << endl;
		}
		return;
	}
};