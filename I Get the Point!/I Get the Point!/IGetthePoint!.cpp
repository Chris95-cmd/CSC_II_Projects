#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	double x;
	double y;

public:
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	double operator-(Point other) {
		return (sqrt(pow((other.x - x), 2.0) + pow((other.y - y), 2.0)));
	}

	bool operator==(const Point& other) const {
		return (x == other.x && y == other.y);
	}

	bool operator!=(const Point& other) const {
		return !(*this == other);
	}

	Point operator/(const Point& other) const {
		return Point((x + other.x) / 2, (y + other.y) / 2);
	}

};

ostream& operator<<(ostream& out, const Point& p) {
	out << "(" << p.get_x() << ", " << p.get_y() << ")";
	return out;
}

int main() {
	double z;

	Point P1 = Point(5, 4);

	Point P2 = Point(3, 2);

	Point P3 = Point(5, 4);

	cout << "Distance: " << (P1 - P2) << endl;

	cout << "Midpoint: " << (P1 / P2) << endl;

	if (P1 == P3) {
		cout << "Point 1 and Point 3 the same point" << endl;
	}

	if (P1 != P2) {
		cout << "Point 1 and Point 2 are different points" << endl;
	}

}