#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> primeFactorsHelper(int n, int divisor)
{
    if (n <= 1)
    {
        return vector<int>();
    }

    if (n % divisor == 0)
    {
        vector<int> result = primeFactorsHelper(n / divisor, divisor);
        result.insert(result.begin(), divisor);
        return result;
    }

    return primeFactorsHelper(n, divisor + 1);
}

vector<int> primeFactors(int n)
{
    return primeFactorsHelper(n, 2);
}

void printVector(const vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    assert(primeFactors(1).empty());
    assert(primeFactors(0).empty());
    assert(primeFactors(-7).empty());
    assert(primeFactors(2) == vector<int>({ 2 }));
    assert(primeFactors(3) == vector<int>({ 3 }));
    assert(primeFactors(13) == vector<int>({ 13 }));
    assert(primeFactors(97) == vector<int>({ 97 }));
    assert(primeFactors(4) == vector<int>({ 2, 2 }));
    assert(primeFactors(8) == vector<int>({ 2, 2, 2 }));
    assert(primeFactors(27) == vector<int>({ 3, 3, 3 }));
    assert(primeFactors(6) == vector<int>({ 2, 3 }));
    assert(primeFactors(12) == vector<int>({ 2, 2, 3 }));
    assert(primeFactors(100) == vector<int>({ 2, 2, 5, 5 }));
    assert(primeFactors(210) == vector<int>({ 2, 3, 5, 7 }));
    assert(primeFactors(221) == vector<int>({ 13, 17 }));
    assert(primeFactors(1001) == vector<int>({ 7, 11, 13 }));

    cout << "All tests passed!" << endl;
    
    printVector(primeFactors(100));

}