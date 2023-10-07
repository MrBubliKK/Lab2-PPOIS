#pragma once
#include "MonicTests.cpp"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OsTests {
	TEST_CLASS(Lab_os) {
public:

	TEST_METHOD(Check_size_os) {
		Os os("windows", 500);
		os.Set_size_os(400);
		Assert::AreEqual(400, os.Get_size_os());

	}

	TEST_METHOD(Check_pas_os) {
		Os os("windows", 300);
		os.Set_password_os("12345");
		string result = "12345";
		Assert::AreEqual(result, os.Get_password_os());
	}

	TEST_METHOD(Check_name_os) {
		Os os("windows", 300);
		os.Set_name_os("linux");
		string result = "linux";
		Assert::AreEqual(result, os.Get_name_os());
	}
	};
}