#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Sys_block.cpp"
#include "Monic.cpp"
#include "Os.cpp"
#include "Wifi.cpp"
using namespace std;

class Computer {  //КЛАСС КОМПЬЮТЕРА
private:
	string connecting_wifi;
	vector <Disk> list_disks;
	vector <Os> list_systems;
	vector <Wifi> list_wifi;
public:
	void Turn_on_sys_block(Sys_block& sys_block) {
		sys_block.Set_sys_condition(true);
	}

	void Turn_off_sys_block(Sys_block& sys_block) {
		sys_block.Set_sys_condition(false);
	}

	void Turn_on_monic(Monic& monic) {
		monic.Set_monic_condition(true);
	}

	void Turn_off_monic(Monic& monic) {
		monic.Set_monic_condition(false);
	}

	void Set_two_os(Sys_block& sys_block) {
		this->list_systems.push_back(Os("linux", 400));
		this->list_systems.push_back(Os("windows", 600));
		sys_block.Increase_files_memory(1000);
		this->list_systems[1].Set_password_os("laboratornaya");
	}

	vector <Os> Get_list_systems() {
		return this->list_systems;
	}

	vector <Disk> Get_list_disks() {
		return this->list_disks;
	}

	//Проверяет, есть ли такой диск
	bool Check_disk(string disk_name) {
		for (int i = 0; i < list_disks.size(); i++) {
			if ((list_disks[i].Get_disk_name() != "0")
				&& (list_disks[i].Get_disk_name() == disk_name)) {
				return true;
			}
		}
		return false;
	}

	//Добавляет диск в список
	void Add_disk(string disk_name) {
		if (!Check_disk(disk_name)) {
			list_disks.push_back(Disk(disk_name));
			return;
		}
		else {
			cout << "ERROR: Диск с таким именем уже есть!\n";
			return;
		}
	}

	//Подключает диск к дисководу
	void Connect_disk_in_drive(Drive& drive, string disk_name) {
		if (Check_disk(disk_name)) {
			if (drive.Get_disk_name() == "0") {
				drive.Set_disk_name(disk_name);
				return;
			}
			cout << "ERROR: В дисководе уже есть диск!\n";
			return;
		}
		cout << "ERROR: Диска с таким имем нет!\n";
		return;
	}

	//Отключает диск от дисковода
	void Disconnect_disk_in_drive(Drive& drive, string disk_name) {
		if (Check_disk(disk_name)) {
			if (drive.Get_disk_name() == disk_name) {
				if (drive.Get_disk_name() != "0") {
					drive.Set_disk_name("0");
					return;
				}
				cout << "ERROR: Дисковод пустой!\n";
				return;
			}
			cout << "ERROR: В дисководе диск с другим именем!\n";
			return;
		}
		cout << "ERROR: Диска с таким именем нет!\n";
		return;
	}


	void Add_file_in_disk(string disk_name, Sys_block& sys_block, string file_name, string file_expansion) {
		if (list_disks[Get_number_disk(disk_name)].Check_file_in_disk(file_name, file_expansion)) {
			int size = sys_block.Get_list_files()[sys_block.Get_number_file(file_name, file_expansion)].Get_file_size();
			if (list_disks[Get_number_disk(disk_name)].Check_full_size_disk(size)) {
				list_disks[Get_number_disk(disk_name)].Add_file(size, file_name, file_expansion);
				list_disks[Get_number_disk(disk_name)].Increase_file_memory(size);
				sys_block.Del_final_file(sys_block.Get_list_files()[sys_block.Get_number_file(file_name, file_expansion)]);
				return;
			}
			return;
		}
		cout << "ERROR: Такой файл уже есть на диске!\n";
		return;
	}


	//Добавляет файл из диска в систему
	void Add_file_in_sys_from_disk(string disk_name, Sys_block& sys_block, string file_name, string file_expansion) {
		if (!list_disks[Get_number_disk(disk_name)].Check_file_in_disk(file_name, file_expansion)) {
			int size = list_disks[Get_number_disk(disk_name)].Get_list_files()[list_disks[Get_number_disk(disk_name)].Get_number_file(file_name, file_expansion)].Get_file_size();
			sys_block.Add_file(size, file_expansion, file_name);
			list_disks[Get_number_disk(disk_name)].Reduce_file_memory(size);
			list_disks[Get_number_disk(disk_name)].Del_final_file(file_name, file_expansion);
			return;
		}
		cout << "ERROR: Файла нет на диске!\n";
		return;
	}

	int Get_number_disk(string disk_name) {
		for (int i = 0; i < list_disks.size(); i++) {
			if (list_disks[i].Get_disk_name() == disk_name) {
				return i;
			}
		}
		return -1;
	}

	void Change_disk_name(string new_disk_name, string old_disk_name) {
		if (Check_disk(old_disk_name)) {
			if (!Check_disk(new_disk_name)) {
				list_disks[Get_number_disk(old_disk_name)].Set_disk_name(new_disk_name);
				return;
			}
			cout << "ERROR: Диск с таким именем уже существует!\n";
			return;
		}
		cout << "ERROR: Диска с таким именем для изменения нет!\n";
		return;
	}

	void Print_list_disks() {
		cout << "\n\n------------------------СПИСОК ДИСКОВ------------------------\n";
		for (int i = 0; i < list_disks.size(); i++) {
			cout << list_disks[i].Get_disk_name() << endl;
		}
		cout << "--------------------------------------------------------------------\n\n";
	}

	vector <Wifi> Get_list_wifi() {
		return list_wifi;
	}

	void Print_list_wifi() {
		cout << "\n\n------------------------СПИСОК WIFI------------------------\n";
		for (int i = 0; i < list_wifi.size(); i++) {
			cout << "- " << list_wifi[i].Get_wifi_name() << endl;;
		}
		cout << "--------------------------------------------------------------------\n\n";
	}

	bool Check_wifi(string wifi_name) {
		for (int i = 0; i < list_wifi.size(); i++) {
			if (wifi_name == list_wifi[i].Get_wifi_name()) {
				return true;
			}
		}
		return false;
	}

	int Get_number_wifi(string wifi_name) {
		for (int i = 0; i < list_wifi.size(); i++) {
			if (wifi_name == list_wifi[i].Get_wifi_name()) {
				return i;
			}
		}
		return -1;
	}

	void Create_list_wifi() {
		list_wifi.push_back(Wifi("domashniy", "123456", "\nУ вас нет роутера, чтобы выйти в интернет!\n"));
		list_wifi.push_back(Wifi("CyberWorld2021", "TechMaster21", "\nВы не оплатили интернет, чтобы им пользоваться!\n"));
		list_wifi.push_back(Wifi("NetSphere2021", "OnlineWizard21", "\nВаш пароль взломан, и вы не можете зайти в сеть!\n"));
		list_wifi.push_back(Wifi("WebConnect2021", "DigitalGuru21", "\nУ вас нет роутера, чтобы выйти в интернет!\n"));
		list_wifi.push_back(Wifi("TechEmpire2021", "InternetKing21", "\nВы не оплатили интернет, чтобы им пользоваться!\n"));
		list_wifi.push_back(Wifi("eWorld2021", "DataQueen21", "\nВаш пароль взломан, и вы не можете зайти в сеть!\n"));
		list_wifi.push_back(Wifi("VirtualNet2021", "WebMaster21", "\nЭто пиратская сеть. Гос. органы отключили вам ее!\n"));
		list_wifi.push_back(Wifi("DigitalRealm2021", "TechSavvy21", "\nУ вас нет роутера, чтобы выйти в интернет!\n"));
		list_wifi.push_back(Wifi("OnlineUniverse2021", "CyberGeek21", "\nЭто пиратская сеть. Гос. органы отключили вам ее!\n"));
		list_wifi.push_back(Wifi("WebWorld2021", "NetNinja21", "\nВы не оплатили интернет, чтобы им пользоваться!\n"));
		list_wifi.push_back(Wifi("TechHub2021", "CodeMaster21", "\nЭто пиратская сеть. Гос. органы отключили вам ее!\n"));
		list_wifi.push_back(Wifi("eConnect2021", "DataWhiz21", "\nУ вас нет роутера, чтобы выйти в интернет!\n"));
		list_wifi.push_back(Wifi("Netopia2021", "WebWizard21", "\nВаш пароль взломан, и вы не можете зайти в сеть!\n"));
		list_wifi.push_back(Wifi("CyberSpace2021", "TechGenius21", "\nВы не оплатили интернет, чтобы им пользоваться!\n"));
		list_wifi.push_back(Wifi("WebEmpire2021", "InternetQueen21", "\nВаш пароль взломан, и вы не можете зайти в сеть!\n"));
		return;
	}

	void Set_connecting_wifi(string wifi_name) {
		this->connecting_wifi = wifi_name;
	}

	string Get_connecting_wifi() {
		return this->connecting_wifi;
	}
};