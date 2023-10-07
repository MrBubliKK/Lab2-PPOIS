#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "BasketTests.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiskTests {
	TEST_CLASS(Lab_disk) {
public:

	TEST_METHOD(Check_full_size_disk) {
		Disk disk("first");
		Assert::IsFalse(disk.Check_full_size_disk(400));
	}

	TEST_METHOD(Get_not_number_file) {
		Disk disk("first");
		disk.Add_file(50, "one", "txt");
		disk.Print_disk_files();
		Assert::AreEqual(-1, disk.Get_number_file("two", "pdf"));
	}

	};
}