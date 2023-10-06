#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include "Computer.cpp"
using namespace std;




//������� ��������� �����
bool Turn_computer(Sys_block& sys_block, Monic& monic) {
	string turn_computer;
	while (true) {
		cout << "|---------------------------|-------------------------------|------------------------------|\n";
		cout << "|     �������� ���������    |      ��������� ���������      |      ��������� ���������     |\n";
		cout << "|            on             |               off             |              exit            |\n";
		cout << "|___________________________|_______________________________|______________________________|\n";
		cout << "                                            ";
		cin >> turn_computer;
		if (turn_computer == "on") {
			if (sys_block.Get_sys_condition()) {
				cout << "                              ERROR: ��������� ��� �������.\n";
				return true;
			}
			else {
				sys_block.Set_sys_condition(true);
				cout << "                              ��������� ���������.\n";
				return true;
			}
		}
		else if (turn_computer == "off") {
			if (sys_block.Get_sys_condition()) {
				sys_block.Set_sys_condition(false);
				if (monic.Get_monic_condition() == true) {
					monic.Set_monic_condition(false);
				}
				cout << "                             ��������� ����������.\n";
				continue;
			}
			else {
				cout << "                            ERROR: ��������� ��� ��������.\n";
				continue;
			}
		}
		else if (turn_computer == "exit") {
			return false;
		}
		else {
			cout << "                             ERROR: �� ����� ������������ ������.\n";
			continue;
		}
	}
	return true;
}

//������� ��������� ������
void Turn_monic(Monic& monic) {
	string turn_monic;
	while (true) {
		cout << "|-------------------------|---------------------------|----------------------|\n";
		cout << "|     �������� �������    |     ��������� �������     |      ����������      |\n";
		cout << "|            on           |            off            |         cont         |\n";
		cout << "|_________________________|___________________________|______________________|\n";
		cout << "                          ";
		cin >> turn_monic;
		if (turn_monic == "on") {
			if (monic.Get_monic_condition()) {
				cout << "               ERROR: ������� ��� �������.\n";
				continue;
			}
			monic.Set_monic_condition(true);
			break;
		}
		else if (turn_monic == "off") {
			if (monic.Get_monic_condition()) {
				monic.Set_monic_condition(false);
				continue;
			}
			cout << "              ERROR: ������� ��� ��������.\n";
			continue;
		}
		else if (turn_monic == "cont") {
			if (monic.Get_monic_condition() == false) {
				cout << "    ERROR: �� �� ������ ���������� � ����������� ���������!\n";
				continue;
			}
			break;
		}
			cout << "              ERROR: �� ����� ������������ ������.\n";
			continue;

	}
}

//������� ��������� ������ �� �����
void Set_os_password(Computer& computer) {
	string new_pas;
	string remember_pas;
	cout << "������� ����� ������: ";
	cin >> new_pas;
	while (true) {
		cout << "��������� ������: ";
		cin >> remember_pas;
		if (new_pas == remember_pas) {
			computer.Get_list_systems()[1].Set_password_os(new_pas);
			cout << "������ �������.\n";
			break;
		}
		else {
			cout << "ERROR: ��������� ������ ������������!\n";
		}
	}
}

void Change_os_pas(Computer& computer) {
	string change;
	while (true) {
		cout << "������ �������� ������ �� Windows? ('y' - ��   'n' - ���): ";
		cin >> change;

		if (change == "y") {
			Set_os_password(computer);
			break;
		}
		else if (change == "n") {
			break;
		}
		else {
			cout << "ERROR: ������������ ������!\n";
			continue;
		}
	}
}

//������� ����� � �������
void Enter_os(Computer& computer) {
	string change_os;
	string password_os;
	int count{};

	while (true) {
		cout << "�������� �� ��� ����� (windows/linux): ";
		cin >> change_os;
		if (change_os == computer.Get_list_systems()[1].Get_name_os()) {
			count = 0;
			while (true) {
				cout << "��� ����� � Windows ������� ������: ";
				cin >> password_os;
				if (password_os == computer.Get_list_systems()[1].Get_password_os()) {
					cout << "�� ������� ����� � Windows!\n";
					Change_os_pas(computer);
					return;
				}
				else {
					cout << "ERROR: �������� ������!\n";
					count++;
				}

				if (count == 3) {
					cout << "ERROR: ��������� ���������� �������. ����� �� Windows.\n";
					break;
				}
			}

		}
		else if (change_os == computer.Get_list_systems()[0].Get_name_os()) {
			cout << "�� ������� � Linux!\n";
			return;
		}
	}
}

//������� ����
void Create_File(Sys_block& sys_block) {
	string file_expansion;
	string file_name;

	cout << "������� �������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;

	if (file_expansion == "txt") {
		sys_block.Add_file(20, file_expansion, file_name);
	}
	else if (file_expansion == "png") {
		sys_block.Add_file(35, file_expansion, file_name);
	}
	else if (file_expansion == "jpg") {
		sys_block.Add_file(40, file_expansion, file_name);
	}
	else if (file_expansion == "docx") {
		sys_block.Add_file(45, file_expansion, file_name);
	}
	else if (file_expansion == "pdf") {
		sys_block.Add_file(50, file_expansion, file_name);
	}
	else if (file_expansion == "bat") {
		sys_block.Add_file(5, file_expansion, file_name);
	}
	else {
		cout << "ERROR: ������������ ����������!\n";
	}
}

//������� �����
void Create_logo(Sys_block& sys_block) {
	string logo_name;
	string file_name;
	string file_expansion;

	cout << "������� �������� ������: ";
	cin >> logo_name;
	cout << "������� �������� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	sys_block.Add_logo(logo_name, file_name, file_expansion);
}

//������� ���� � �������
void Delete_file_basket(Basket& basket, Sys_block& sys_block) {
	string file_name;
	string file_expansion;

	cout << "������� �������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	sys_block.Del_file_basket(basket, file_expansion, file_name);
}

//������� ���� ���������
void Delete_final_file(Basket& basket) {
	string file_name;
	string file_expansion;
	cout << "������� �������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	if (basket.Del_final_file(file_expansion, file_name)) {
		cout << "���� ������.\n";
		return;
	}
	cout << "ERROR: ���� �� ������.\n";
	return;
}

//������� ����� � �������
void Delete_logo_basket(Basket& basket, Sys_block& sys_block) {
	string logo_name;
	string file_name;
	string file_expansion;

	cout << "������� �������� ������";
	cin >> logo_name;
	cout << "������� �������� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	sys_block.Del_logo_basket(basket, logo_name, file_expansion, file_name);
}

void Delete_final_logo(Basket& basket) {
	//string change;
	string file_name;
	string file_expansion;
	string logo_name;

	cout << "������� �������� ������: ";
	cin >> logo_name;
	cout << "������� �������� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	if (basket.Del_final_logo(logo_name, file_name, file_expansion)) {
		cout << "����� ������.\n";
		return;
	}
	cout << "ERROR: ������ �� ����������!\n";
	return;
}

void Create_something(Sys_block& sys_block) {
	string change;

	while (true) {
		cout << "|----------------------|---------------------------|-------------------|\n";
		cout << "|    ������� ����      |       ������� �����       |      ����������   |\n";
		cout << "|       cfile          |           clogo           |         cont      |\n";
		cout << "|______________________|___________________________|___________________|\n";
		cout << "                                   ";
		cin >> change;
		if (change == "cfile") {
			Create_File(sys_block);
			continue;
		}
		else if (change == "clogo") {
			Create_logo(sys_block);
			continue;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout <<"                           ERROR: ������������ �������!\n";
			continue;
		}
	}
}

void Delete_something(Basket& basket, Sys_block& sys_block) {
	string change;

	while (true) {
		cout << "|----------------------------------|-------------------------------------|---------------------|\n";
		cout << "|'dfile' - ������� ���� � �������  |  'dlogo' - ������� ����� � �������  |      ����������     |\n";
		cout << "|             dfile                |                dlogo                |         cont        |\n";
		cout << "|__________________________________|_____________________________________|_____________________|\n";
		cout << "                                                    ";
		cin >> change;
		if (change == "dfile") {
			Delete_file_basket(basket, sys_block);
			continue;
		}
		else if (change == "dlogo") {
			Delete_logo_basket(basket, sys_block);
			continue;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                                               ERROR: ������������ ������!\n";
			continue;
		}
	}
}

void Delete_in_basket(Basket& basket) {
	string change;

	while (true) {
		cout << "|-----------------------------------|--------------------------------------|\n";
		cout << "|      ������� ���� �� �������      |       ������� ����� �� �������       |\n";
		cout << "|              dfile                |                 dlogo                |\n";
		cout << "|-----------------------------------|--------------------------------------|\n";
		cout << "|          �������� �������         |               ����������             |\n";
		cout << "|              clear                |                 cont                 |\n";
		cout << "|___________________________________|______________________________________|\n";
		cout << "                                    ";
		cin >> change;

		if (change == "dfile") {
			Delete_final_file(basket);
			continue;
		}
		else if (change == "dlogo") {
			Delete_final_logo(basket);
			continue;
		}
		else if (change == "clear") {
			basket.Clear_basket();
			cout << "                             ������� �������.\n";
			break;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                          ERROR: ������������ ������!\n";
			continue;		}
	}
}

void Restore_logo(Sys_block& sys_block, Basket& basket) {
	string logo_name;
	string file_name;
	string file_expansion;

	cout << "������� �������� ������: ";
	cin >> logo_name;
	cout << "������� �������� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	sys_block.Restore_logo(basket, logo_name, file_name, file_expansion);
}

void Restore_file(Sys_block& sys_block, Basket& basket) {
	string file_name;
	string file_expansion;

	cout << "������� �������� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	sys_block.Restore_file(basket, file_name, file_expansion);
}

void Restore_in_basket(Sys_block& sys_block, Basket& basket) {
	string change;
	while (true) {
		cout << "|----------------------------|--------------------------------|---------------------|\n";
		cout << "|      ������������ ����     |       ������������ �����       |      ����������     |\n";
		cout << "|           rfile            |             rlogo              |         cont        |\n";
		cout << "|____________________________|________________________________|_____________________|\n";
		cout << "                                           ";
		cin >> change;

		if (change == "rfile") {
			Restore_file(sys_block, basket);
			continue;
		}
		else if (change == "rlogo") {
			Restore_logo(sys_block, basket);
			continue;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                                    ERROR: ������������ ����!\n";
			continue;
		}
	}
}

void Change_name_file(Sys_block& sys_block) {
	string new_name;
	string old_name;
	string expansion;

	cout << "������� ��� �����, ������� ������ ��������: ";
	cin >> old_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> expansion;
	cout << "������� ����� ��� �����: ";
	cin >> new_name;
	sys_block.Change_name_file(expansion, new_name, old_name);
}

void Change_expansion_file(Sys_block& sys_block) {
	string name;
	string new_expansion;
	string old_expansion;

	cout << "������� ��� �����, ������� ������ ��������: ";
	cin >> name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> old_expansion;
	cout << "������� ����� ����������: ";
	cin >> new_expansion;
	if (new_expansion == "txt") {
		sys_block.Change_expansion_file(20, new_expansion, old_expansion, name);
		return;
	}
	else if (new_expansion == "png") {
		sys_block.Change_expansion_file(35, new_expansion, old_expansion, name);
		return;
	}
	else if (new_expansion == "jpg") {
		sys_block.Change_expansion_file(40, new_expansion, old_expansion, name);
		return;
	}
	else if (new_expansion == "docx") {
		sys_block.Change_expansion_file(45, new_expansion, old_expansion, name);
		return;
	}
	else if (new_expansion == "pdf") {
		sys_block.Change_expansion_file(50, new_expansion, old_expansion, name);
		return;
	}
	else if (new_expansion == "bat") {
		sys_block.Change_expansion_file(5, new_expansion, old_expansion, name);
		return;
	}
	else {
		cout << "ERROR: ������������ ����������!\n";
		return;
	}
}

void Change_name_logo(Sys_block& sys_block) {
	string old_name;
	string new_name;
	string file_expansion;
	string file_name;

	cout << "������� �������� ������: ";
	cin >> old_name;
	cout << "������� ��� ���������� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	cout << "������� ����� ��� ������: ";
	cin >> new_name;
	sys_block.Change_name_logo(new_name, old_name, file_name, file_expansion);
}

void Change_something(Sys_block& sys_block) {
	string change;

	while (true) {
		cout << "|------------------------------|--------------------------------------|\n";
		cout << "|      �������� ��� �����      |       �������� ���������� �����      |\n";
		cout << "|           cnfile             |                cefile                |\n";
		cout << "|______________________________|______________________________________|\n";
		cout << "|     �������� ��� ������      |             ����������               |\n";
		cout << "|           cnlogo             |                cont                  |\n";
		cout << "|______________________________|______________________________________|\n";
		cout << "                                   ";
		cin >> change;
		if (change == "cnfile") {
			Change_name_file(sys_block);
			continue;
		}
		else if (change == "cefile") {
			Change_expansion_file(sys_block);
			continue;
		}
		else if (change == "cnlogo") {
			Change_name_logo(sys_block);
			continue;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                             ERROR: ������������ ������!\n";
			continue;
		}
	}
}


void Create_disk(Computer& computer) {
	string disk_name;
	cout << "������� ��� ������ �����: ";
	cin >> disk_name;
	if (disk_name == "0") {
		cout << "ERROR: ����� ��� ������ �������!\n";
		return;
	}

	computer.Add_disk(disk_name);
	return;
}

void Change_name_disk(Computer& computer) {
	string new_disk_name;
	string old_disk_name;

	cout << "������� ��� ����� ��� ���������: ";
	cin >> old_disk_name;
	if (old_disk_name == "0") {
		cout << "ERROR: ����� ��� ������ �������!\n";
		return;
	}
	cout << "������� ����� ���: ";
	cin >> new_disk_name;
	if (new_disk_name == "0") {
		cout << "ERROR: ����� ��� ������ �������!\n";
		return;
	}

	computer.Change_disk_name(new_disk_name, old_disk_name);
}



void Connect_disk(Computer& computer, Drive& drive) {
	string disk_name;
	cout << "������� ��� �����: ";
	cin >> disk_name;
	if (disk_name == "0") {
		cout << "ERROR: ����� ��� ������ �������!\n";
		return;
	}

	computer.Connect_disk_in_drive(drive, disk_name);
	return;
}

void Disconnect_disk(Computer& computer, Drive& drive) {
	string disk_name;
	cout << "������� ��� �����: ";
	cin >> disk_name;
	if (disk_name == "0") {
		cout << "ERROR: ����� ��� ������ �������!\n";
		return;
	}

	computer.Disconnect_disk_in_drive(drive, disk_name);
	return;
}


void Transfer_file_on_drive(Sys_block& sys_block, Drive& drive, Computer& computer) {
	string file_name;
	string file_expansion;

	cout << "������� ��� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	if (sys_block.Check_file(file_expansion, file_name)) {
		computer.Add_file_in_disk(drive.Get_disk_name(), sys_block, file_name, file_expansion);
		return;
	}
	else {
		cout << "ERROR: ������ ����� �� ����������!\n";
		return;
	}
}

void Transfer_file_on_sys(Sys_block& sys_block, Drive& drive, Computer& computer) {
	string file_name;
	string file_expansion;

	cout << "������� ��� �����: ";
	cin >> file_name;
	cout << "����������: 'txt', 'png', 'jpg', 'docx', 'pdf', 'bat'\n ������� ���������� �����: ";
	cin >> file_expansion;
	if (!sys_block.Check_file(file_expansion, file_name)) {
		computer.Add_file_in_sys_from_disk(drive.Get_disk_name(), sys_block, file_name, file_expansion);
		return;

	}
	cout << "ERROR: ����� ���� ��� ���� � �������!\n";
	return;
}

void Work_with_files_disk(Sys_block& sys_block, Drive& drive, Computer& computer) {
	string change;

	while (true) {
		cout << "|------------------------------------|----------------------------------------|---------------------|\n";
		cout << "|      ����������� ���� �� ����      |        ����������� ���� � �������      |      ����������     |\n";
		cout << "|                tdfile              |                   tsfile               |         cont        |\n";
		cout << "|____________________________________|________________________________________|_____________________|\n";
		cout << "                                                   ";
		cin >> change;

		if (change == "tdfile") {
			Transfer_file_on_drive(sys_block, drive, computer);
			continue;
		}
		else if (change == "tsfile") {
			Transfer_file_on_sys(sys_block, drive, computer);
			return;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                                             ERROR: ������������ ������!\n";
			continue;
		}
	}
}

void Print_something(Sys_block& sys_block, Computer& computer, Drive& drive) {
	string change;

	while (true) {
		cout << "|--------------------------------------|---------------------------------------|\n";
		cout << "|      ���������� ����� � �������      |      ���������� ������ � �������      |\n";
		cout << "|                 wfsys                |                  wlsys                |\n";
		cout << "|______________________________________|_______________________________________|\n";
		cout << "|       ���������� ����� �� �����      |      ���������� ����� � �������       |\n";
		cout << "|                 wfdisk               |                wfbasket               |\n";
		cout << "|______________________________________|_______________________________________|\n";
		cout << "|     ���������� ������ � �������      |         ���������� ������ ������      |\n";
		cout << "|                wlbasket              |                 wdlist                |\n";
		cout << "|______________________________________|_______________________________________|\n";
		cout << "|           ���������� ������          |               ����������              |\n";
		cout << "|                wmemory               |                  cont                 |\n";
		cout << "|______________________________________________________________________________|\n";
		cout << "                                     ";
		cin >> change;

		if (change == "wfsys") {
			sys_block.Print_list_files();
			continue;
		}
		else if (change == "wlsys") {
			sys_block.Print_list_logos();
			continue;
		}
		else if (change == "wfdisk") {
			if (drive.Get_disk_name() != "0") {
				computer.Get_list_disks()[computer.Get_number_disk(drive.Get_disk_name())].Print_disk_files();
				continue;
			}
			cout << "                            ERROR: � ��������� ��� �����!\n";
		}
		else if (change == "wdlist") {
			computer.Print_list_disks();
			continue;
		}
		else if (change == "wmemory") {
			sys_block.Print_memory();
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                                ERROR: ������������ ��������!\n";
			continue;
		}
	}
}

void Work_with_drive(Computer& computer, Drive& drive, Sys_block& sys_block) {
	string change;

	while (true) {
		cout << "|-----------------------------|-------------------------------------|\n";
		cout << "|        ������� ����         |        �������� �������� �����      |\n";
		cout << "|           cdisk             |                 cndisk              |\n";
		cout << "|_____________________________|_____________________________________|\n";
		cout << "|        �������� ����        |              ������� ����           |\n";
		cout << "|           indisk            |                outdisk              |\n";
		cout << "|_____________________________|_____________________________________|\n";
		cout << "|       ������ � �������      |               ����������            |\n";
		cout << "|           dfile             |                  cont               |\n";
		cout << "|_____________________________|_____________________________________|\n";
		cout << "                             ";
		cin >> change;

		if (change == "cdisk") {
			Create_disk(computer);
			continue;
		}
		else if (change == "cndisk") {
			Change_name_disk(computer);
			continue;
		}
		else if (change == "indisk") {
			Connect_disk(computer, drive);
			continue;
		}
		else if (change == "outdisk") {
			Disconnect_disk(computer, drive);
			continue;
		}
		else if (change == "dfile") {
			Work_with_files_disk(sys_block, drive, computer);
			continue;
		}
		else if (change == "cont") {
			break;
		}
		else {
			cout << "                         ERROR: ������������ ������!\n";
			continue;
		}
	}
}

void Work_with_wifi(Computer& computer) {
	string wifi_name;
	string wifi_pas;
	computer.Print_list_wifi();

	while (true) {
		cout << "������� �������� ���������: ";
		cin >> wifi_name;
		if (computer.Check_wifi(wifi_name)) {
			cout << "������� ������ � ���������: ";
			cin >> wifi_pas;
			if (wifi_pas == computer.Get_list_wifi()[computer.Get_number_wifi(wifi_name)].Get_wifi_password()) {
				cout << "�� ������� ����� � ��������!\n";
				computer.Set_connecting_wifi(wifi_name);
				cout << computer.Get_list_wifi()[computer.Get_number_wifi(wifi_name)].Get_wifi_mes();
				break;
			}
			cout << "ERROR: �� ����� ������������ ������!\n";
			continue;
		}
		cout << "ERROR: ������ ��������� ���!\n";
		continue;
	}
}

void Work_with_something(Basket& basket, Sys_block& sys_block, Computer& computer, Drive& drive, Monic& monic) {
	string change;

	while (true) {
		cout << "|-------------------------------|------------------------------------------------|\n";
		cout << "|        ������� ����/�����     |                ������� ����/�����              |\n";
		cout << "|             create            |                      delete                    |\n";
		cout << "|_______________________________|________________________________________________|\n";
		cout << "|       �������� � �������      |            �������������� �� �������           |\n";
		cout << "|            dbasket            |                     rbasket                    |\n";
		cout << "|_______________________________|________________________________________________|\n";
		cout << "|       ��������� �������       |                  ������ � ������               |\n";
		cout << "|             change            |                       disk                     |\n";
		cout << "|_______________________________|________________________________________________|\n";
		cout << "|      ������ � ����������      |                      ��������                  |\n";
		cout << "|              wifi             |                       watch                    |\n";
		cout << "|_______________________________|________________________________________________|\n";
		cout << "|      ��������� � ��������     |           ��������� � ���������� �����         |\n";
		cout << "|              bmon             |                       bsys                     |\n";
		cout << "|_______________________________|________________________________________________|\n";
		//cout << "                              |      ����������      |\n";
		//cout << "                              |         cont         |\n";
		//cout << "                              |______________________|\n";
		cout << "                                      ";
		cin >> change;

		if (change == "create") {
			Create_something(sys_block);
			continue;
		}
		else if (change == "delete") {
			Delete_something(basket, sys_block);
			continue;
		}
		else if (change == "dbasket") {
			Delete_in_basket(basket);
			continue;
		}
		else if (change == "rbasket") {
			Restore_in_basket(sys_block, basket);
			continue;
		}
		else if (change == "change") {
			Change_something(sys_block);
			continue;
		}
		else if (change == "disk") {
			Work_with_drive(computer, drive, sys_block);
			continue;
		}
		else if (change == "watch") {
			Print_something(sys_block, computer, drive);
			continue;
		}
		else if (change == "wifi") {
			Work_with_wifi(computer);
		}
		else if (change == "bmon") {
			Turn_monic(monic);
		}
		else if (change == "bsys") {
			if (!Turn_computer(sys_block, monic)) {
				return;
			}
			else {
				Turn_monic(monic);
				Enter_os(computer);
				continue;
			}

		}
		/*else if (change == "cont") {
			break;
		}*/
		else {
			cout << "                                   ERROR: ������������ ������!\n";
			continue;
		}
	}
}