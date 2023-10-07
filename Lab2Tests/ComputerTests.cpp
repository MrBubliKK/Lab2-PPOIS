#pragma once
#include "Sys_blockTests.cpp"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComputerTests {
	TEST_CLASS(Lab_computer) {
public:

	TEST_METHOD(Check_list_disks) {
		Computer computer;
		computer.Add_disk("first");
		string disk_name = "first";
		Assert::AreEqual(disk_name, computer.Get_list_disks()[0].Get_disk_name());
		computer.Add_disk("first");
	}

	TEST_METHOD(Check_list_systems) {
		Sys_block sys_block;
		Computer computer;
		computer.Set_two_os(sys_block);
		string name_os = "linux";
		Assert::AreEqual(name_os, computer.Get_list_systems()[0].Get_name_os());
		Assert::AreEqual(400, computer.Get_list_systems()[0].Get_size_os());
	}

	TEST_METHOD(Connect_disk) {
		Computer computer;
		Drive drive;
		computer.Add_disk("first");
		computer.Add_disk("second");
		string disk_name = "first";
		computer.Connect_disk_in_drive(drive, computer.Get_list_disks()[0].Get_disk_name());
		computer.Connect_disk_in_drive(drive, computer.Get_list_disks()[1].Get_disk_name());
		computer.Connect_disk_in_drive(drive, "third");
		Assert::AreEqual(disk_name, drive.Get_disk_name());
	}

	TEST_METHOD(Disconnect_disk){
		Computer computer;
		Drive drive;
		computer.Add_disk("first");
		computer.Add_disk("second");
		computer.Disconnect_disk_in_drive(drive, "third");
		computer.Connect_disk_in_drive(drive, computer.Get_list_disks()[0].Get_disk_name());
		computer.Disconnect_disk_in_drive(drive, "second");
		computer.Disconnect_disk_in_drive(drive, "first");
		string result = "0";
		Assert::AreEqual(result, drive.Get_disk_name());
	}

	TEST_METHOD(Add_file_in_disk) {
		Computer computer;
		Sys_block sys_block;
		Drive drive;

		sys_block.Add_file(50, "txt", "one");
		computer.Add_disk("first");
		computer.Connect_disk_in_drive(drive, "first");
		computer.Add_file_in_disk("first", sys_block, "one", "txt");
		computer.Add_file_in_disk("first", sys_block, "one", "txt");
		string file_name = "one";
		string file_expansion = "txt";
		Assert::AreEqual(file_name, computer.Get_list_disks()[0].Get_list_files()[0].Get_name_file());
		Assert::AreEqual(file_expansion, computer.Get_list_disks()[0].Get_list_files()[0].Get_file_expansion());
		Assert::AreEqual(50, computer.Get_list_disks()[0].Get_list_files()[0].Get_file_size());
	}

	TEST_METHOD(Add_file_in_sys) {
		Computer computer;
		Drive drive;
		Sys_block sys_block;

		computer.Add_disk("first");
		sys_block.Add_file(50, "txt", "one");
		computer.Add_file_in_disk("first", sys_block, "one", "txt");
		computer.Add_file_in_sys_from_disk("first", sys_block, "one", "txt");
		string file_name = "one";
		string file_expansion = "txt";
		Assert::AreEqual(file_name, sys_block.Get_list_files()[0].Get_name_file());
		Assert::AreEqual(file_expansion, sys_block.Get_list_files()[0].Get_file_expansion());
		Assert::AreEqual(50, sys_block.Get_list_files()[0].Get_file_size());
		Assert::AreEqual(-1, computer.Get_number_disk("second"));
	}

	TEST_METHOD(change_disk_name) {
		Computer computer;
		computer.Add_disk("first");
		computer.Add_disk("second");
		computer.Change_disk_name("second", "first");
		computer.Change_disk_name("fourth", "fifth");
		computer.Change_disk_name("third", "first");
		string disk_name = "third";
		computer.Print_list_disks();
		Assert::AreEqual(disk_name, computer.Get_list_disks()[0].Get_disk_name());
	}

	TEST_METHOD(Check_wifi) {
		Computer computer;
		computer.Create_list_wifi();
		string wifi_name = "domashniy";
		string wifi_pas = "123456";
		computer.Print_list_wifi();
		Assert::AreEqual(wifi_name, computer.Get_list_wifi()[0].Get_wifi_name());
		Assert::AreEqual(wifi_pas, computer.Get_list_wifi()[0].Get_wifi_password());
	}

	TEST_METHOD(Check_wifi_name) {
		Computer computer;
		computer.Create_list_wifi();
		Assert::AreEqual(true, computer.Check_wifi("domashniy"));
		Assert::AreEqual(false, computer.Check_wifi("first"));
	}

	TEST_METHOD(Check_number_wifi) {
		Computer computer;
		computer.Create_list_wifi();
		Assert::AreEqual(0, computer.Get_number_wifi("domashniy"));
		Assert::AreEqual(-1, computer.Get_number_wifi("last"));
	}

	TEST_METHOD(Check_connecting_wifi) {
		Computer computer;
		computer.Create_list_wifi();
		computer.Set_connecting_wifi("domashniy");
		string connecting_wifi = "domashniy";
		Assert::AreEqual(connecting_wifi, computer.Get_connecting_wifi());
	}
	
	};
}