#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Shape {
public:
	virtual double getParimeter() {
		return 0;
	}
	virtual double getArea() {
		return 0;
	}
};

class Rectangle : public Shape {
protected:
	double length;
	double width;
public:
	Rectangle(double _length, double _width) : length(_length), width(_width){}
	double getArea() {
		return length * width;
	}
	double getPerimeter() {
		return (2 * length) + (2 * width);
	}
};

class rightTriangle : public Shape {
protected:
	double length;
	double width;
	double hypotenuse;
public:
	rightTriangle(double _length, double _width) : length(_length), width(_width) {
		hypotenuse = sqrt((pow(length, 2)) + (pow(width, 2)));
	}
	double getArea() {
		return (length * width) / 2;
	}
	double getPerimeter() {
		return length + width + hypotenuse;
	}
};

class Circle : public Shape {
protected: 
	double radius;
	const double PI = 3.14159265359;
public:
	Circle(double _radius) : radius(_radius){}
	double getArea() {
		return PI * pow(radius, 2);
	}
	double getPerimeter() {
		return 2 * PI * radius;
	}
};

class Square : public Rectangle {
public:
	Square(double length_width) : Rectangle(length_width, length_width) {
		
	}
};

class IsoscelesRightTriangle : public rightTriangle {
public:
	IsoscelesRightTriangle(double length_width) : rightTriangle(length_width, length_width) {}
};

int main() {

	Rectangle r(4, 5);
	assert(r.getArea() == 20);
	assert(r.getPerimeter() == 18);

	rightTriangle t(3, 4);
	assert(t.getArea() == 6);
	assert(t.getPerimeter() == 12);

	Circle c(2);
	assert(c.getArea() == 3.14159265359 * 4);
	assert(c.getPerimeter() == 2 * 3.14159265359 * 2);

	Square s(4);
	assert(s.getArea() == 16);
	assert(s.getPerimeter() == 16);

	IsoscelesRightTriangle irt(2);
	assert(irt.getArea() == 2);
	assert(irt.getPerimeter() == 2 + 2 + sqrt(8.0));

	cout << "All tests passed!" << endl;
	
}