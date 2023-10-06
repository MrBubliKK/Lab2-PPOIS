#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Wifi {  //ÊËÀÑÑ ÈÍÒÅÐÍÅÒÀ
private:
	string wifi_name;
	string wifi_password;
	string wifi_mes;

public:
	Wifi(string wifi_name, string wifi_password, string wifi_mes) :
		wifi_name(wifi_name),
		wifi_password(wifi_password),
		wifi_mes(wifi_mes) {}

	string Get_wifi_name() {
		return this->wifi_name;
	}

	void Set_wifi_name(string wifi_name) {
		this->wifi_name = wifi_name;
	}

	string Get_wifi_password() {
		return this->wifi_password;
	}

	void Set_wifi_password(string wifi_passowrd) {
		this->wifi_password = wifi_passowrd;
	}

	string Get_wifi_mes() {
		return this->wifi_mes;
	}
};