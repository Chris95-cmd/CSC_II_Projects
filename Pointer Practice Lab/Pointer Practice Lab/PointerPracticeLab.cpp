#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main() {

	srand(time(0));

	int a;

	int b;

	cout << "Please enter integer A: " << endl;
	cin >> a;
	cout << "Please enter integer B: " << endl;
	cin >> b;
	cout << " You have entered " << a << " for A, and " << b << " for B." << endl;

	int* ptr_a = &a;
	int* ptr_b = &b;

	cout << "Value pointed to by ptr_a: " << *ptr_a << endl;
	cout << "Value pointed to by ptr_b: " << *ptr_b << endl << endl << endl;

	int const size = 20;

	int max_array_array[size];

	cout << "This is the Array that is generated to calculate the maximum: " << endl;

	for (int i = 0; i < size; i++) {
		max_array_array[i] = rand() % 100;

		cout << max_array_array[i] << endl;
	}

	cout << endl;

	int* max_ptr = max_array_array;     
	int* current = max_array_array;

	for (int i = 1; i < size; i++) {
		current++;
		if (*current > *max_ptr) {
			max_ptr = current;
		}
	}
	cout << "Maximum value for this array is: " << *max_ptr << endl << endl << endl;

	char word_array[] = "I am going to nail the quiz tomorrow!!!";
	char* ptr = word_array;   

	int length = 0;

	while (*ptr != '\0') {
		ptr++;
		length++;
	}

	cout << "The string is: " << word_array << endl;

	cout << "The length of the string is: " << length << endl << endl << endl;

	while (*ptr != '\0') {
		ptr++;
	}
	
	ptr--;

	cout << "The reverse of the string is: ";
	while (ptr >= word_array) {
		cout << *ptr;
		ptr--;
	}

	cout << endl << endl << endl;

	const int size_2 = 21;

	vector<int> midpoint_vector(size_2);

	cout << "This is the Vector that is generated to find the midpoint: " << endl;

	for (int i = 0; i < size_2; i++) {
		midpoint_vector[i] = rand() % 200;
		cout << midpoint_vector[i] << endl;
	}

	int* left = &midpoint_vector[0];
	int* right = &midpoint_vector[midpoint_vector.size() - 1];

	while (left < right) {
		left++;
		right--;
	}

	if (left > right) {
		left--;
	}

	cout << "The midpoint of the vector is: " << *left << endl;
}