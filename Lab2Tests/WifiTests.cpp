#pragma once
#include "../Workfunctions.h"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WifiTests {
	TEST_CLASS(Lab_wifi) {
public:
	
	TEST_METHOD(Check_get_wifi_parameters) {
		Wifi wifi("his_name", "1234", "first");
		string name = "his_name";
		string pas = "1234";
		string mes = "first";
		Assert::AreEqual(name, wifi.Get_wifi_name());
		Assert::AreEqual(pas, wifi.Get_wifi_password());
		Assert::AreEqual(mes, wifi.Get_wifi_mes());
	}
	};
}