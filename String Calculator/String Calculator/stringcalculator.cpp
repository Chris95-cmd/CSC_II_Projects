#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int string_calculator(string str) {
	if (str.empty()) {
		return 0;
	}

	int sum = 0;
	string current_number = "";

	for (char c : str) {
		if (c == ',' || c == ';') {
			sum += stoi(current_number);
			current_number = "";
		}
		else {
			current_number += c;
		}
	}

	sum += stoi(current_number);
	return sum;
}

int main() {
	assert(string_calculator("") == 0);
	assert(string_calculator("0") == 0);
	assert(string_calculator("1") == 1);
	assert(string_calculator("4,5,6") == 15);
	assert(string_calculator("1;2") == 3);
	assert(string_calculator("4;7;8") == 19);
	assert(string_calculator("1,5;16") == 22);
	assert(string_calculator("56,180;2,15") == 253);

	cout << "All Tests Passed!" << endl;

}

