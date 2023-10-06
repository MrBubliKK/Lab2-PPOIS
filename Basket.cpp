#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Disk.cpp"
#include "Drive.cpp"
using namespace std;

class Basket {  //КЛАСС КОРЗИНЫ
private:
	vector <File> deleting_files;
	vector <Logo> deleting_logos;

public:
	//Очищает корзину
	void Clear_basket() {
		deleting_files.clear();
		deleting_logos.clear();
	}

	vector <File> Get_deleting_files() {
		return deleting_files;
	}

	vector <Logo> Get_deleting_logo() {
		return deleting_logos;
	}

	//Проверяет на существование файла
	bool Check_file(string file_expansion, string file_name) {
		for (int i = 0; i < deleting_files.size(); i++) {
			if ((file_expansion == deleting_files[i].Get_file_expansion())
				&& (file_name == deleting_files[i].Get_name_file())) {
				return true;
			}
		}
		return false;
	}

	//Проверяет ярлык на существование в корзине
	bool Check_logo(string logo_name, string file_expansion, string file_name) {
		for (int i = 0; i < deleting_logos.size(); i++) {
			if ((file_expansion == deleting_logos[i].Get_expansion_main_file())
				&& (file_name == deleting_logos[i].Get_name_main_file())
				&& (logo_name == deleting_logos[i].Get_name_logo())) {
				return true;
			}
		}
		return false;
	}
	
	//Удаляет полностью файл
	bool Del_final_file(string file_expansion, string file_name) {
		for (int i = 0; i < deleting_files.size(); i++) {
			if ((deleting_files[i].Get_file_expansion() == file_expansion)
				&& (deleting_files[i].Get_name_file() == file_name)) {
				deleting_files.erase(deleting_files.begin() + i);
				return true;
			}
		}
		return false;
	}

	//Добавляет файл в корзину
	void Add_file_in_basket(int file_size, string file_expansion, string file_name) {
		if (Check_file(file_expansion, file_name)) {
			Del_final_file(file_expansion, file_name);
		}
		deleting_files.push_back(File(file_size, file_expansion, file_name));
	}

	//Полностью удаляет ярлык
	bool Del_final_logo(string logo_name, string file_name, string file_expansion) {
		for (int i = 0; i < deleting_logos.size(); i++) {
			if ((deleting_logos[i].Get_expansion_main_file() == file_expansion)
				&& (deleting_logos[i].Get_name_logo() == logo_name)
				&& (deleting_logos[i].Get_name_main_file() == file_name)) {
				deleting_logos.erase(deleting_logos.begin() + i);
				return true;
			}
		}
		return false;
	}

	//Добавляет ярлык в корзину
	void Add_logo_in_basket(string logo_name, string file_expansion, string file_name) {
		if (Check_logo(logo_name, file_expansion, file_name)) {
			Del_final_logo(logo_name, file_name, file_expansion);
		}
		deleting_logos.push_back(Logo(logo_name, file_name, file_expansion));
	}

	void Print_deleting_files() {
		cout << "\n\n------------------------ФАЙЛЫ В КОРЗИНЕ------------------------\n";
		for (int i = 0; i < deleting_files.size(); i++) {
			cout << deleting_files[i].Get_name_file() << "." << deleting_files[i].Get_file_expansion() << endl;
		}
		cout << "--------------------------------------------------------------------\n\n";
	}

	void Print_deleting_logos() {
		cout << "\n\n------------------------ЯРЛЫКИ В КОРЗИНЕ------------------------\n";
		for (int i = 0; i < deleting_logos.size(); i++) {
			cout << deleting_logos[i].Get_name_logo() << " (файл: " << deleting_logos[i].Get_name_main_file() 
				<< "." << deleting_logos[i].Get_expansion_main_file() << ")\n";
		}
		cout << "--------------------------------------------------------------------\n\n";
	}

};