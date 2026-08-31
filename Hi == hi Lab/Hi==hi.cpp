#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int compareStrings(string string1, string string2) {
	bool equal = true;
	int result;
	do {
		for (int i = 0; i <= string1.length() && i <= string2.length(); i++) {
			char a = string1[i];
			char b = string2[i];
			tolower(a);
			tolower(b);
			if (static_cast<int>(a) > static_cast<int>(b)) {
				result = 1;
				equal = false;
			} if (static_cast<int>(a) < static_cast<int>(b)) {
				result = -1;
				equal = false;
			} if (i == string1.length() && i == string2.length() && static_cast<int>(a) == static_cast<int>(b)) {
				result = 0;
				equal = false;
			} if (string1.length() == 0 && string2.length() == 0) {
				result = 0;
				equal = false;
			}
		}

	} while (equal != false);
	cout << result << endl;
	return result;
}

void tests() {
	assert(compareStrings("hello", "hello") == 0);
	assert(compareStrings("Hello", "hello") == 0);
	assert(compareStrings("HELLO", "hello") == 0);
	assert(compareStrings("apple", "banana") == -1);
	assert(compareStrings("banana", "apple") == 1);
	assert(compareStrings("Apple", "banana") == -1);
	assert(compareStrings("apple", "BANANA") == -1);
	assert(compareStrings("app", "apple") == -1);
	assert(compareStrings("apple", "app") == 1);
	assert(compareStrings("", "") == 0);
	assert(compareStrings("", "a") == -1);
	assert(compareStrings("a", "") == 1);
	assert(compareStrings("abc123", "abc123") == 0);
}

int main() {

	string string1;
	string string2;
	bool cont = false;
	string cont_var;
	
	tests();

	cout << "Hello! Welcome to the string comparison lab!" << endl << endl << endl;

	cout << "Please enter the first string: ";
	getline(cin, string1);
	cout << "Now enter the second string: ";
	getline(cin, string2);
	cout << endl;
	cout << "Thank you, you have chosen " << string1 << " and " << string2 << " for your strings." << endl;
	compareStrings(string1, string2);	

}

