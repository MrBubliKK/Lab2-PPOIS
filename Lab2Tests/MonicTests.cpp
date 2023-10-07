#pragma once
#include "LogoTests.cpp"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MonicTests {
	TEST_CLASS(Lab_monic) {
public:

	TEST_METHOD(Check_monic_condition) {
		Monic monic;
		monic.Set_monic_condition(true);
		Assert::IsTrue(monic.Get_monic_condition());
	}
	};
}