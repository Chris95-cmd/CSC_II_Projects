#include <iostream>
#include <functional>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
T add(T x, T y) {
    return x + y;
}

template <typename T>
T subtract(T x, T y) {
    return x - y;
}

template <typename T>
T multiply(T x, T y) {
    return x * y;
}

template <typename T>
T divide(T x, T y) {
    return x / y;
}

template <typename T>
T fold(function<T(T, T)> f, vector<T> v) {
    T result;
    T start = v[0];
    if (v.size() < 2) {
        return v[0];
    }
    else {
        for (int i = 1; i != v.size(); i++) {
            result = f(v[i], start);
            start = result;
        }
        v.erase(v.begin());
        return f(result, fold(f, v));
    }
}

int main() {
    vector<int> v = { 1, 2, 3, 4, 5 };
    cout << fold<int>(add<int>, v) << endl;
    cout << fold<int>(multiply<int>, v) << endl;
    cout << fold<int>(add<int>, v) << endl;

    vector<int> v1 = { 1, 2, 3, 4, 5 };
    assert(fold<int>(add<int>, v1) == 55);
    assert(fold<int>(subtract<int>, v1) == 9);
    assert(fold<int>(multiply<int>, v1) == 86400000);

    assert(fold<int>(add<int>, vector<int>{7}) == 7);
    assert(fold<int>(subtract<int>, vector<int>{10, 4}) == -10);
    assert(fold<int>(multiply<int>, vector<int>{6, 7}) == 294);
    assert(fold<int>(divide<int>, vector<int>{20, 4}) == 0);

    assert(fold<int>(add<int>, vector<int>{-1, -2, -3}) == -14);
    assert(fold<int>(subtract<int>, vector<int>{-1, -2, -3}) == -4);
    assert(fold<int>(multiply<int>, vector<int>{-2, 3, -4}) == 1152);

    vector<double> v3 = { 1.5, 2.5, 3.0 };
    assert(fold<double>(add<double>, v3) == 15.5);
    assert(fold<double>(subtract<double>, v3) == 4.5);
    assert(fold<double>(multiply<double>, v3) == 253.125);

    vector<double> v4 = { 1.0, 2.0, 4.0, 8.0 };
    assert(fold<double>(divide<double>, v4) == 0.25);

    assert(fold<double>(add<double>, vector<double>{0.5, 0.25, 0.125}) == 1.375);
    assert(fold<double>(divide<double>, vector<double>{1.0, 4.0}) == 1.0);
    assert(fold<double>(multiply<double>, vector<double>{-1.5, 2.0}) == -6.0);

    cout << "Tests passed!" << endl;
}
