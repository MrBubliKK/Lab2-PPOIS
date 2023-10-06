#pragma once
#include "OsTest.h"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Sys_blockTests {
	TEST_CLASS(Lab_sys_block) {
public:

	TEST_METHOD(Check_sys_condition) {
		Sys_block sys_block;
		sys_block.Set_sys_condition(true);
		Assert::IsTrue(sys_block.Get_sys_condition());
	}

	TEST_METHOD(Check_all_memory) {
		Sys_block sys_block;
		Assert::AreEqual(1200, sys_block.Get_all_memory());
	}

	TEST_METHOD(Check_files_memory) {
		Sys_block sys_block;
		sys_block.Increase_files_memory(300);
		Assert::AreEqual(300, sys_block.Get_file_memory());
		sys_block.Reduce_file_memory(200);
		Assert::AreEqual(100, sys_block.Get_file_memory());
	}

	TEST_METHOD(Check_file) {
		Sys_block sys_block;
		sys_block.Add_file(50, "txt", "one");
		sys_block.Add_file(30, "txt", "two");
		sys_block.Add_file(50, "txt", "one");
		sys_block.Print_list_files();
		Assert::IsTrue(sys_block.Check_file("txt", "one"));
	}

	TEST_METHOD(Check_full_file) {
		Sys_block sys_block;
		Assert::IsFalse(sys_block.Check_full_file(1300));
	}

	TEST_METHOD(Check_logo) {
		Sys_block sys_block;
		Basket basket;
		sys_block.Add_file(50, "txt", "one");
		sys_block.Add_logo("first", "one", "txt");
		sys_block.Add_logo("second", "one", "txt");
		sys_block.Add_logo("third", "second", "txt");
		sys_block.Del_logo_basket(basket, "second", "txt", "one");
		sys_block.Del_logo_basket(basket, "third", "txt", "one");
		sys_block.Print_list_logos();
		string name = "first";
		Assert::AreEqual(name, sys_block.Get_list_logos()[0].Get_name_logo());
		Assert::IsFalse(sys_block.Check_logo("first", "one", "txt"));
		Assert::IsFalse(sys_block.Check_logo("third", "second", "txt"));
	}

	TEST_METHOD(Check_logos_one_file) {
		Sys_block sys_block;
		Basket basket;
		sys_block.Add_file(30, "png", "two");
		sys_block.Add_file(50, "txt", "one");
		sys_block.Add_logo("first", "one", "txt");
		sys_block.Add_logo("main", "two", "png");
		sys_block.Add_logo("second", "one", "txt");
		sys_block.Check_all_logos_one_file(basket, "txt", "one");
		int result = sys_block.Get_list_logos().size();
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(Del_file) {
		Sys_block sys_block;
		Basket basket;
		sys_block.Add_file(30, "png", "two");
		sys_block.Add_file(50, "txt", "one");
		sys_block.Add_logo("first", "one", "txt");
		sys_block.Add_logo("main", "two", "png");
		sys_block.Add_logo("second", "one", "txt");
		sys_block.Del_file_basket(basket, "txt", "one");
		sys_block.Del_file_basket(basket, "one", "txt");
		int logo_result = sys_block.Get_list_logos().size();
		int file_result = sys_block.Get_list_files().size();
		Assert::AreEqual(1, file_result);
		Assert::AreEqual(1, logo_result);
	}

	TEST_METHOD(Check_restore_file) {
		Sys_block sys_block;
		Basket basket;
		sys_block.Add_file(30, "png", "two");
		sys_block.Del_file_basket(basket, "png", "two");
		sys_block.Add_file(30, "png", "two");
		sys_block.Exists_file_for_restore(basket, "two", "png", 0);
		sys_block.Del_file_basket(basket, "png", "two");
		sys_block.Exists_file_for_restore(basket, "two", "png", 0);
		int result = sys_block.Get_list_files().size();
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(Check_main_restore_file) {
		Sys_block sys_block;
		Basket basket;
		sys_block.Add_file(30, "png", "two");
		sys_block.Del_file_basket(basket, "png", "two");
		sys_block.Restore_file(basket, "txt", "two");
		sys_block.Restore_file(basket, "two", "png");
		int result = sys_block.Get_list_files().size();
		Assert::AreEqual(1, result);
	}

	TEST_METHOD(Check_exists_file_for_logo) {
		Sys_block sys_block;
		Basket basket;

		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("1", "one", "txt");
		sys_block.Add_logo("2", "one", "txt");
		sys_block.Add_logo("3", "one", "txt");
		sys_block.Exists_file_for_logo(basket, "1", "two", "txt", 0);
		sys_block.Exists_file_for_logo(basket, "1", "one", "txt", 0);

		sys_block.Del_logo_basket(basket, "1", "one", "txt");
	}

	TEST_METHOD(Check_restor_file) {
		Sys_block sys_block;
		Basket basket;

		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("1", "one", "txt");
		sys_block.Add_logo("2", "one", "txt");
		sys_block.Add_logo("3", "one", "txt");
		sys_block.Del_logo_basket(basket, "1", "one", "txt");
		sys_block.Restore_logo(basket, "1", "two", "txt");
		sys_block.Restore_logo(basket, "1", "one", "txt");
	}

	TEST_METHOD(Check_change_name_file_logos) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("first", "one", "txt");

		sys_block.Change_name_logs_and_file("txt", "second", "one", 0);
		string name = "second";
		Assert::AreEqual(name, sys_block.Get_list_files()[0].Get_name_file());
		Assert::AreEqual(name, sys_block.Get_list_logos()[0].Get_name_main_file());
	}

	TEST_METHOD(Check_find_file) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "first");
		Assert::IsTrue(sys_block.Find_file("txt", "second", "first"));
		Assert::IsFalse(sys_block.Find_file("png", "second", "first"));
	}

	TEST_METHOD(Check_change_name_file) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "first");
		sys_block.Change_name_file("txt", "first", "first");
		sys_block.Change_name_file("txt", "second", "first");
		sys_block.Change_name_file("png", "second", "first");
	}

	TEST_METHOD(Check_change_expansion) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("first", "one", "txt");
		sys_block.Change_expansion_logs_and_file(30, "png", "txt", "one", 0);

		string result = "png";
		Assert::AreEqual(result, sys_block.Get_list_files()[0].Get_file_expansion());
		Assert::AreEqual(result, sys_block.Get_list_logos()[0].Get_expansion_main_file());
	}

	TEST_METHOD(Check_expansion) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		Assert::IsTrue(sys_block.Check_exceptions(30, "txt", "txt", "one", 0));
		Assert::IsTrue(sys_block.Check_exceptions(50, "png", "txt", "one", 0));
		Assert::IsFalse(sys_block.Check_exceptions(50, "png", "txt", "one", 0));
	}

	TEST_METHOD(Check_change_expansion_file) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Change_expansion_file(50, "png", "txt", "one");
		sys_block.Change_expansion_file(50, "png", "txt", "two");
	}

	TEST_METHOD(Check_change_name_logo) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("first", "txt", "one");
		sys_block.Change_name_logo("second", "first", "one", "txt");
	}

	TEST_METHOD(Check_Del_all_logos) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("1", "one", "txt");
		sys_block.Add_logo("2", "one", "txt");
		sys_block.Add_logo("3", "one", "txt");
		sys_block.Del_all_logos_after_file_disk(sys_block.Get_list_files()[0]);
		int result = sys_block.Get_list_logos().size();
		Assert::AreEqual(0, result);
	}

	TEST_METHOD(Check_get_number_logo) {
		Sys_block sys_block;
		sys_block.Add_file(30, "txt", "one");
		sys_block.Add_logo("1", "one", "txt");
		sys_block.Add_logo("2", "one", "txt");
		sys_block.Print_memory();

		int falseresult = sys_block.Get_number_logo("one", "png", "1");
		int trueresult = sys_block.Get_number_logo("one", "txt", "2");
		Assert::AreEqual(1, trueresult);
		Assert::AreEqual(-1, falseresult);
	}

	};

}