#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Drive { //ÊËÀÑÑ ÄÈÑÊÎÂÎÄÀ
private:
	string disk_name ="0";

public:

	string Get_disk_name() {
		return this->disk_name;
	}

	void Set_disk_name(string disk_name) {
		this->disk_name = disk_name;
	}
};