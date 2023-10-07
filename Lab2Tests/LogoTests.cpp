#pragma once
#include "FileTests.cpp"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogoTests {
	TEST_CLASS(Lab_logo) {
public:

	TEST_METHOD(Check_logo_name) {
		Logo logo("first", "main", "txt");
		logo.Set_name_logo("second");
		string result = "second";
		Assert::AreEqual(result, logo.Get_name_logo());
	}

	TEST_METHOD(Check_file_name) {
		Logo logo("first", "main", "txt");
		logo.Set_name_main_file("notmain");
		string result = "notmain";
		Assert::AreEqual(result, logo.Get_name_main_file());
	}

	TEST_METHOD(Check_file_expansion) {
		Logo logo("first", "main", "txt");
		logo.Set_expansion_main_file("png");
		string result = "png";
		Assert::AreEqual(result, logo.Get_expansion_main_file());
	}
	};
}