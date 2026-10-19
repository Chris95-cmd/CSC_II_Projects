#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <cassert>

using namespace std;

/*vec_fill(T elem)
fills a 10 element vector with elem, elem + 1, elem + 2, etc.
returns the vector*/

template <typename T>
vector<T> vec_fill(T elem) {
    vector<T> v;
    for (int i = 0; i != 10; i++) {
        v.push_back(elem);
        elem++;
    }
    return v;
}

/*order(T& a, T& b, T& c)
Makes a hold the largest value from the arguments,
b hold the second largest value,
and c hold the third largest value.*/

template <typename T>
void order(T& a, T& b, T& c) {
    if (a < b) {
        swap(a, b);
    }
    if (a < c) {
        swap(a, c);
    }
    if (b < c) {
        swap(b, c);
    }
}

/*search(T begin, T end, int elem)
Uses iterators to search an arbitrary container of integers.
Returns an iterator to the first element equal to elem,
or end if elem is not found.*/

template <typename T>
T search(T begin, T end, int elem) {
    for (T it = begin; it != end; ++it) {
        if (*it == elem) {
            return it;
        }
    }
    return end;
}

int main() {
    vector<int> ints = vec_fill(10);
    assert(ints.size() == 10);
    assert(ints[0] == 10);
    assert(ints[9] == 19);

    vector<double> doubles = vec_fill(1.5);
    assert(doubles.size() == 10);
    assert(doubles[0] == 1.5);
    assert(doubles[9] == 10.5);

    vector<char> chars = vec_fill('a');
    assert(chars.size() == 10);
    assert(chars[0] == 'a');
    assert(chars[9] == 'j');

    int i1 = 3, i2 = 9, i3 = 5;
    order(i1, i2, i3);
    assert(i1 == 9 && i2 == 5 && i3 == 3);

    double d1 = 1.5, d2 = 0.5, d3 = 2.5;
    order(d1, d2, d3);
    assert(d1 == 2.5 && d2 == 1.5 && d3 == 0.5);

    string s1 = "apple", s2 = "cherry", s3 = "banana";
    order(s1, s2, s3);
    assert(s1 == "cherry" && s2 == "banana" && s3 == "apple");

    char c1 = 'x', c2 = 'z', c3 = 'y';
    order(c1, c2, c3);
    assert(c1 == 'z' && c2 == 'y' && c3 == 'x');

    int o1 = 9, o2 = 5, o3 = 3;
    order(o1, o2, o3);
    assert(o1 == 9 && o2 == 5 && o3 == 3);

    int r1 = 4, r2 = 4, r3 = 1;
    order(r1, r2, r3);
    assert(r1 == 4 && r2 == 4 && r3 == 1);

    vector<int> vec = { 5, 10, 15, 20 };
    auto vecFound = search(vec.begin(), vec.end(), 15);
    assert(vecFound != vec.end());
    assert(*vecFound == 15);
    assert(search(vec.begin(), vec.end(), 99) == vec.end());

    list<int> lst = { 1, 2, 3, 4 };
    auto lstFound = search(lst.begin(), lst.end(), 3);
    assert(lstFound != lst.end());
    assert(*lstFound == 3);
    assert(search(lst.begin(), lst.end(), 99) == lst.end());

    array<int, 5> arr = { 7, 8, 9, 10, 11 };
    auto arrFound = search(arr.begin(), arr.end(), 7);
    assert(arrFound != arr.end());
    assert(*arrFound == 7);
    assert(search(arr.begin(), arr.end(), 99) == arr.end());

    int plain[4] = { 2, 4, 6, 8 };
    int* plainFound = search(plain, plain + 4, 8);
    assert(plainFound != plain + 4);
    assert(*plainFound == 8);
    assert(search(plain, plain + 4, 99) == plain + 4);

    vector<int> empty;
    assert(search(empty.begin(), empty.end(), 1) == empty.end());

    vector<int> repeats = { 3, 7, 7, 1 };
    assert(search(repeats.begin(), repeats.end(), 7) == repeats.begin() + 1);

    cout << "vec_fill(10): ";
    for (int num : ints) {
        cout << num << " ";
    }
    cout << endl;

    cout << "vec_fill('a'): ";
    for (char ch : chars) {
        cout << ch << " ";
    }
    cout << endl;

    cout << "order(3, 9, 5) gives: " << i1 << " " << i2 << " " << i3 << endl;
    cout << "All tests passed!" << endl;

}