#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "WifiTests.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BasketTests {
	TEST_CLASS(Lab_basket) {
public:
	TEST_METHOD(Chek_del_files_basket) {
		Basket basket;
		basket.Add_file_in_basket(30, "txt", "first");
		basket.Add_file_in_basket(30, "txt", "first");
		string expansion = "txt";
		string name = "first";
		basket.Print_deleting_files();
		Assert::AreEqual(30, basket.Get_deleting_files()[0].Get_file_size());
		Assert::AreEqual(expansion, basket.Get_deleting_files()[0].Get_file_expansion());
		Assert::AreEqual(name, basket.Get_deleting_files()[0].Get_name_file());
	}

	TEST_METHOD(Check_del_logos_basket) {
		Basket basket;
		basket.Add_logo_in_basket("logo", "txt", "first");
		basket.Add_logo_in_basket("logo", "txt", "first");
		string logo_name = "logo";
		string file_expansion = "txt";
		string file_name = "first";
		basket.Print_deleting_logos();
		Assert::AreEqual(logo_name, basket.Get_deleting_logo()[0].Get_name_logo());
		Assert::AreEqual(file_expansion, basket.Get_deleting_logo()[0].Get_expansion_main_file());
		Assert::AreEqual(file_name, basket.Get_deleting_logo()[0].Get_name_main_file());
	}

	TEST_METHOD(Check_clear_basket) {
		Basket basket;
		basket.Add_file_in_basket(30, "txt", "first");
		basket.Add_logo_in_basket("logo", "txt", "first");
		basket.Clear_basket();
		int file_size = basket.Get_deleting_files().size();
		int logo_size = basket.Get_deleting_logo().size();
		Assert::AreEqual(0, file_size);
		Assert::AreEqual(0, logo_size);
	}
	};
}