#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>

#include "Basket.cpp"
using namespace std;

class Sys_block {  //����� ���������� �����
private:
	bool sys_condition = false;
	const int all_memory = 1200;
	int files_memory{};
	vector <File> list_files;
	vector <Logo> list_logos;

public:

	void Print_list_logos() {
		cout << "\n\n------------------------������ � �������------------------------\n";
		for (int i = 0; i < list_logos.size(); i++) {
			cout << list_logos[i].Get_name_logo() << " " 
				<< "(����: " << list_logos[i].Get_name_main_file()
				<< "." << list_logos[i].Get_expansion_main_file() << ")" << endl;
		}
		cout << "--------------------------------------------------------------------\n\n";
	}
	
	void Print_list_files() {
		cout << "\n\n------------------------����� � �������------------------------\n";
		for (int i = 0; i < list_files.size(); i++) {
			cout << list_files[i].Get_name_file() << "." << list_files[i].Get_file_expansion() << endl;
		}
		cout << "--------------------------------------------------------------------\n\n";
	}

	//������ ��������� �������
	bool Get_sys_condition() {
		return this->sys_condition;
	}

	//������ ��������� �������
	void Set_sys_condition(bool sys_condition) {
		this->sys_condition = sys_condition;
	}

	//������� ����� ������ ������
	int Get_all_memory() {
		return this->all_memory;
	}

	//������� ������ �������� ������
	int Get_file_memory() {
		return this->files_memory;
	}

	//��������� � �������� ������
	void Increase_files_memory(int value) {
		this->files_memory += value;
	}

	//������� �� �������� ������
	void Reduce_file_memory(int value) {
		this->files_memory -= value;
	}

	vector <File> Get_list_files() {
		return this->list_files;
	}

	//��������� �� ������������� �����
	bool Check_file(string file_expansion, string file_name) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((file_expansion == list_files[i].Get_file_expansion())
				&& (file_name == list_files[i].Get_name_file())) {
				return true;
			}
		}
		return false;
	}

	//��������� ������������� ������ �����
	bool Check_full_file(int file_size) {
		if (files_memory + file_size > all_memory) {
			cout << "ERROR: ������ ���������!\n";
			return false;
		}
		return true;
	}

	//��������� ����
	void Add_file(int file_size, string file_expansion, string file_name) {
		if (!Check_file(file_expansion, file_name)) {
			if (Check_full_file(file_size)) {
				Increase_files_memory(file_size);
				list_files.push_back(File(file_size, file_expansion, file_name));
				return;
			}
			return;
		}
		cout << "ERROR: ����� ���� ��� ����������.\n";
	}

	//������� �������� ������
	void Print_files_memory() {
		cout << files_memory;
	}

	vector <Logo> Get_list_logos() {
		return list_logos;
	}

	bool Check_logo(string logo_name, string file_name, string file_expansion) {
		for (int i = 0; i < list_logos.size(); i++) {
			if ((logo_name == Get_list_logos()[i].Get_name_logo()) &&
				(file_name == Get_list_logos()[i].Get_name_main_file()) &&
				(file_expansion == Get_list_logos()[i].Get_expansion_main_file())) {
				cout << "ERROR: ����� ����� ��� ����������!\n";
				return false;
			}
		}
		return Check_file(file_expansion, file_name);
	}

	/*bool Check_existence_file(string file_name, string file_expansion) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((file_name == Get_list_files()[i].Get_name_file())
				&& (file_expansion == Get_list_files()[i].Get_file_expansion())) {
				return true;
			}
		}
		cout << "������ ����� �� ����������!\n";
		return false;
	}*/

	void Add_logo(string logo_name, string file_name, string file_expansion) {
		if (Check_file(file_expansion, file_name)) {
			if (Check_logo(logo_name, file_name, file_expansion)) {
				list_logos.push_back(Logo(logo_name, file_name, file_expansion));
				cout << "ERROR: ����� ������ ��� ����� " << file_name << "." << file_expansion << ".\n";
				return;
			}
			return;
		}
		cout << "ERROR: ��� ���������� ����� ��� ������!\n";
		return;
	}

	void Del_logo_basket(Basket& basket, string logo_name, string file_expansion, string file_name) {
		for (int i = 0; i < list_logos.size(); i++) {
			if ((list_logos[i].Get_expansion_main_file() == file_expansion)
				&& (list_logos[i].Get_name_logo() == logo_name)
				&& (list_logos[i].Get_name_main_file() == file_name)) {
				basket.Add_logo_in_basket(list_logos[i].Get_name_logo(),
					list_logos[i].Get_expansion_main_file(), list_logos[i].Get_name_main_file());
				list_logos.erase(list_logos.begin() + i);
				cout << "ERROR: ����� ������ � �������.\n";
				return;
			}
		}
		cout << "ERROR: ������ ������ ���!\n";
		return;
	}

	//���������� ��� ������ ������ ����� � �������
	void Check_all_logos_one_file(Basket& basket, string file_expansion, string file_name) {
		int counter = 0;
		while (counter < list_logos.size()) {
			if ((list_logos[counter].Get_expansion_main_file() == file_expansion)
				&& (list_logos[counter].Get_name_main_file() == file_name)) {
				Del_logo_basket(basket, list_logos[counter].Get_name_logo(),
					list_logos[counter].Get_expansion_main_file(), list_logos[counter].Get_name_main_file());
				counter = 0;
				continue;
			}
			counter++;
		}
	}

	//
	void Del_file_basket(Basket& basket, string file_expansion, string file_name) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((list_files[i].Get_file_expansion() == file_expansion)
				&& (list_files[i].Get_name_file() == file_name)) {
				basket.Add_file_in_basket(list_files[i].Get_file_size(),
					list_files[i].Get_file_expansion(), list_files[i].Get_name_file());
				Reduce_file_memory(list_files[i].Get_file_size());
				Check_all_logos_one_file(basket, file_expansion, file_name);
				list_files.erase(list_files.begin() + i);
				cout << "���� ������ � �������.\n";
				return;
			}
		}
		cout << "ERROR: ������ ����� ���!\n";
		return;
	}

	//��������������� ���� � ������� �� �������
	void Exists_file_for_restore(Basket& basket, string file_name, string file_expansion, int number) {
		if ((basket.Get_deleting_files()[number].Get_file_expansion() == file_expansion)
			&& (basket.Get_deleting_files()[number].Get_name_file() == file_name)) {
			if (!Check_file(file_expansion, file_name)) {
				if (Check_full_file(basket.Get_deleting_files()[number].Get_file_size())) {
					list_files.push_back(basket.Get_deleting_files()[number]);
					basket.Del_final_file(file_expansion, file_name);
					return;
				}
				else {
					return;
				}
			}
			else {
				cout << "ERROR: �� ���������� ��� ���� ����� ����.\n";
				return;
			}
		}
	}

	//�������� ������� �������������� ����� � �������
	void Restore_file(Basket& basket, string file_name, string file_expansion) {
		for (int i = 0; i < basket.Get_deleting_files().size(); i++) {
			Exists_file_for_restore(basket, file_name, file_expansion, i);
			return;
		}
		cout << "ERROR: ������ ����� ��� ��� ��������������!\n";
		return;
	}

	void Exists_file_for_logo(Basket& basket, string logo_name, string file_name, string file_expansion, int number) {
		if (Check_file(file_expansion, file_name)) {
			if (Check_logo(logo_name, file_name, file_expansion)) {
				list_logos.push_back(basket.Get_deleting_logo()[number]);
				basket.Del_final_logo(logo_name, file_name, file_expansion);
				return;
			}
			else {
				cout << "ERROR: ����� ����� ��� ����������!\n";
				return;
			}
		}
		else {
			cout << "ERROR: �� ���������� ����� ��� ������!\n";
			return;
		}
	}

	void Restore_logo(Basket& basket, string logo_name, string file_name, string file_expansion) {
		for (int i = 0; i < basket.Get_deleting_logo().size(); i++) {
			if ((basket.Get_deleting_logo()[i].Get_name_logo() == logo_name)
				&& (basket.Get_deleting_logo()[i].Get_name_main_file() == file_name)
				&& (basket.Get_deleting_logo()[i].Get_expansion_main_file() == file_expansion)) {
				Exists_file_for_logo(basket, logo_name, file_name, file_expansion, i);
				return;
			}
		}
		cout << "ERROR: ������ ������ ��� ��� ���������������!\n";
		return;
	}


	//������ ��� ����� � �������� �������
	void Change_name_logs_and_file(string file_expansion,
		string new_file_name, string old_file_name, int number) {
		for (int i = 0; i < list_logos.size(); i++) {
			if ((list_logos[i].Get_name_main_file() == old_file_name)
				&& (list_logos[i].Get_expansion_main_file() == file_expansion)) {
				list_logos[i].Set_name_main_file(new_file_name);
			}
		}
		list_files[number].Set_name_file(new_file_name);
		return;
	}

	bool Find_file(string file_expansion,
		string new_file_name, string old_file_name) {
		for (int j = 0; j < list_files.size(); j++) {
			if ((list_files[j].Get_file_expansion() == file_expansion)
				&& list_files[j].Get_name_file() == old_file_name) {
				Change_name_logs_and_file(file_expansion, new_file_name, old_file_name, j);
				return true;
			}
		}
		return false;
	}

	void Change_name_file(string file_expansion,
		string new_file_name, string old_file_name) {
		if (!Check_file(file_expansion, new_file_name)) {
			if (!Find_file(file_expansion, new_file_name, old_file_name)) {
				cout << "ERROR: ��� ����� ��� ��������� ��������!\n";
				return;
			}
			else {
				return;
			}
		}
		else {
			cout << "ERROR: ����� ���� ��� ����������!\n";
			return;
		}
	}

	//������ ���������� ����� ���� �� �����
	void Change_expansion_logs_and_file(int file_size, string new_file_expansion,
		string old_file_expansion, string file_name, int number) {
		if (Check_full_file(file_size - list_files[number].Get_file_size())) {
			for (int i = 0; i < list_logos.size(); i++) {
				if ((list_logos[i].Get_name_main_file() == file_name)
					&& (list_logos[i].Get_expansion_main_file() == old_file_expansion)) {
					list_logos[i].Set_expansion_main_file(new_file_expansion);
				}
			}
			list_files[number].Set_file_expansion(new_file_expansion);
			list_files[number].Set_file_size(file_size);
			return;
		}
		return;
	}

	//��������� ������������� 
	bool Check_exceptions(int file_size, string new_file_expansion,
		string old_file_expansion, string file_name, int number) {
		if ((list_files[number].Get_file_expansion() == old_file_expansion)
			&& (list_files[number].Get_name_file() == file_name)) {
			if (!Check_file(new_file_expansion, file_name)) {
				Change_expansion_logs_and_file(file_size, new_file_expansion, old_file_expansion, file_name, number);
				return true;
			}
			else {
				cout << "ERROR: ����� ���� ��� ����������!\n";
				return true;
			}
		}
		return false;
	}

	//��� ������� ��� ��������� ���������� �����
	void Change_expansion_file(int file_size, string new_file_expansion, 
		string old_file_expansion, string file_name) {
		for (int j = 0; j < list_files.size(); j++) {
			if (Check_exceptions(file_size, new_file_expansion, old_file_expansion, file_name, j)) {
				return;
			}
		}
		cout << "ERROR: ��� ����� ��� ��������� ����������!\n";
		return;
	}

	void Change_name_logo(string new_logo_name, string old_logo_name,
		string file_name, string file_expansion) {
		for (int i = 0; i < list_logos.size(); i++) {
			if ((list_logos[i].Get_expansion_main_file() == file_expansion)
				&& (list_logos[i].Get_name_main_file() == file_name)
				&& (list_logos[i].Get_name_logo() == old_logo_name)) {
				list_logos[i].Set_name_logo(new_logo_name);
				return;
			}
		}
		cout << "ERROR: ��� ������ ��� ��������� ��������!\n";
	}

	//���� ������� �����
	int Get_number_file(string file_name, string file_expansion) {
		for (int i = 0; i < list_files.size(); i++) {
			if ((list_files[i].Get_file_expansion() == file_expansion)
				&& list_files[i].Get_name_file() == file_name) {
				return i;
			}
		}
		return -1;
	}

	//������� ��� ������ ����� �������� ����� �� ����
	void Del_all_logos_after_file_disk(File& file) {
		int counter = 0;
		while (counter < list_logos.size()) {
			if ((list_logos[counter].Get_expansion_main_file() == file.Get_file_expansion())
				&& (list_logos[counter].Get_name_main_file() == file.Get_name_file())) {
				list_logos.erase(list_logos.begin() + counter);
				counter = 0;
				continue;
			}
			counter++;
		}
	}

	//����� ������� ����
	void Del_final_file(File& file) {
		Reduce_file_memory(file.Get_file_size());
		Del_all_logos_after_file_disk(file);
		list_files.erase(list_files.begin() + Get_number_file(file.Get_name_file(), file.Get_file_expansion()));
		return;
	}

	//���� ������� ������
	int Get_number_logo(string file_name, string file_expansion, string logo_name) {
		for (int i = 0; i < list_logos.size(); i++) {
			if ((list_logos[i].Get_expansion_main_file() == file_expansion)
				&& (list_logos[i].Get_name_logo() == logo_name)
				&& (list_logos[i].Get_name_main_file() == file_name)) {
				return i;
			}
		}
		return -1;
	}

	//��������� ������� �����
	void Del_final_logo(Logo& logo) {
		list_logos.erase(list_logos.begin() + Get_number_logo(logo.Get_name_main_file(), 
			logo.Get_expansion_main_file(), logo.Get_name_logo()));
		return;
	}

	void Print_memory() {
		cout << "                             ��������� " << Get_file_memory() << "/" << Get_all_memory() << "�\n";
		return;
	}
};