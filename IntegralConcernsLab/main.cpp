#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

double integrate(function<double(double)> f, double a, double b, int precision = 100) {
	double width = (b - a) / precision;
	double total = 0.0;

	for (int i = 0; i < precision; i++) {
		double x = a + i * width;
		total += f(x) * width; 
	}
	return total;
}

double square(double x) { 
	return x * x; 
}

int main() {

	cout << integrate(square, 0, 3) << endl;
	cout << integrate(square, 0, 3, 10) << endl;
	cout << integrate(square, 0, 3, 10000) << endl;

	const double PI = 3.14159265358979;

	auto sine = [](double x) { return sin(x); };
	cout << integrate(sine, 0, PI, 10) << endl;
	cout << integrate(sine, 0, PI) << endl;
	cout << integrate(sine, 0, PI, 10000) << endl;

	auto line = [](double x) { return x; };
	cout << integrate(line, -2, 2) << endl;
}