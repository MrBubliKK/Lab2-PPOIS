#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "ComputerTests.cpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WorkFunctionsTests {
	TEST_CLASS(Lab_functions) {
public:

	TEST_METHOD(Check_turn_computer) {
		Sys_block sys_block;
		Monic monic;

		stringstream turn_cond("on");
		cin.rdbuf(turn_cond.rdbuf());
		Assert::IsTrue(Turn_computer(sys_block, monic));
	}

	TEST_METHOD(Check_turn_comp_again) {
		Sys_block sys_block;
		Monic monic;

		sys_block.Set_sys_condition(true);
		stringstream turn_cond("on");
		cin.rdbuf(turn_cond.rdbuf());
		Assert::IsTrue(Turn_computer(sys_block, monic));
	}

	TEST_METHOD(Check_exit) {
		Sys_block sys_block;
		Monic monic;

		sys_block.Set_sys_condition(true);
		stringstream turn_cond("exit");
		cin.rdbuf(turn_cond.rdbuf());
		Assert::IsFalse(Turn_computer(sys_block, monic));
	}

	TEST_METHOD(Check_turn_monic) {
		Monic monic;
		stringstream turn_cond("on");
		cin.rdbuf(turn_cond.rdbuf());
		Turn_monic(monic);
	}

	TEST_METHOD(Check_turn_on_monic) {
		Monic monic;
		monic.Set_monic_condition(true);
		stringstream turn_cond("cont");
		cin.rdbuf(turn_cond.rdbuf());
		Turn_monic(monic);
	}

	TEST_METHOD(Change_n_os_pas) {
		Computer computer;
		stringstream turn_cond("n");
		cin.rdbuf(turn_cond.rdbuf());
		Change_os_pas(computer);
	}

	TEST_METHOD(Check_create_txt_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_png_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one png\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_jpg_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one jpg\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_docx_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one docx\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_pdf_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one pdf\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_bat_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one bat\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_no_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one gg\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_File(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_logo) {
		Sys_block sys_block;
		stringstream input;
		input << "one first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_logo(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_del_file_basket) {
		Basket basket;
		Sys_block sys_block;
		stringstream input;
		input << "first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Delete_file_basket(basket, sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_del_final_file_no_have) {
		Basket basket;
		stringstream input;
		input << "first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Delete_final_file(basket);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_del_logo_basket) {
		Sys_block sys_block;
		Basket basket;
		stringstream input;
		input << "one first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Delete_logo_basket(basket, sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_del_final_logo) {
		Sys_block sys_block;
		Basket basket;
		stringstream input;
		input << "one first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Delete_final_logo(basket);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_restore_logo) {
		Sys_block sys_block;
		Basket basket;
		stringstream input;
		input << "one first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Restore_logo(sys_block, basket);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_restore_file) {
		Sys_block sys_block;
		Basket basket;
		stringstream input;
		input << "one txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Restore_file(sys_block, basket);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_name_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one first txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_name_file(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_txt_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one txt png\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_expansion_file(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_png_file) {
		Sys_block sys_block;
		stringstream input;
		input << "one png txt\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_expansion_file(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_jpg_file) {
		Sys_block sys_block;
		stringstream input;
		input << "two jpg png\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_expansion_file(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_name_logo) {
		Sys_block sys_block;
		stringstream input;
		input << "one two png first\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_name_logo(sys_block);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_no_create_disk) {
		Computer computer;
		stringstream input;
		input << "0\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_disk(computer);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_create_disk) {
		Computer computer;
		stringstream input;
		input << "first\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Create_disk(computer);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_change_disk_name) {
		Computer computer;
		stringstream input;
		input << "first 0\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Change_name_disk(computer);
		input << "0 first\n";
		Change_name_disk(computer);
		input << "first second\n";
		Change_name_disk(computer);
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_connect_disk) {
		Computer computer;
		Drive drive;
		stringstream input;
		input << "0\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Connect_disk(computer, drive);
		input << "first\n";
		Connect_disk(computer, drive);	
		cin.rdbuf(origCin);
	}

	TEST_METHOD(Check_disconnect_disk) {
		Computer computer;
		Drive drive;
		stringstream input;
		input << "0\n";
		streambuf* origCin = std::cin.rdbuf(input.rdbuf());
		Disconnect_disk(computer, drive);
		input << "first\n";
		Disconnect_disk(computer, drive);
		cin.rdbuf(origCin);
	}
	
	};
}
