#pragma once
#include "DiskTests.cpp"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FileTests {
	TEST_CLASS(Lab_file) {
public:

	TEST_METHOD(Check_file_size) {
		File file(50, "txt", "one");
		file.Set_file_size(60);
		Assert::AreEqual(60, file.Get_file_size());
	}

	TEST_METHOD(Check_file_name) {
		File file(50, "txt", "one");
		file.Set_name_file("two");
		string result = "two";
		Assert::AreEqual(result, file.Get_name_file());
	}

	TEST_METHOD(Check_file_expansion) {
		File file(50, "txt", "one");
		file.Set_file_expansion("png");
		string result = "png";
		Assert::AreEqual(result, file.Get_file_expansion());
	}

	};
}