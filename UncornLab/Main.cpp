#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Unicorn {
private:
    unique_ptr<string> name;
    static vector<string> nameList;

    static int findName(const std::string& searchName) {
        for (int i = 0; i < nameList.size(); i++) {
            if (nameList[i] == searchName) {
                return i;
            }
        }
        return -1;
    }

public:
    Unicorn(const string& wantedName) {
        if (findName(wantedName) != -1) {
            cout << "Error: a unicorn named " << wantedName << " already exists!" << endl;
        }
        else {
            name = make_unique<string>(wantedName);
            nameList.push_back(wantedName);
        }
    }
    static void deleteUnicorn(const string& deleteName) {
        int index = findName(deleteName);
        if (index == -1) {
            cout << "Error: no unicorn named " << deleteName << " found!" << endl;
        }
        else {
            nameList.erase(nameList.begin() + index);
            cout << "Deleted " << deleteName << "." << endl;
        }
    }

    static void prettyPrint() {
        if (nameList.size() == 0) {
            cout << "(no unicorns)" << endl;
        }
        for (int i = 0; i < nameList.size(); i++) {
            cout << i + 1 << ". " << nameList[i] << endl;
        }
    }
};

vector<string> Unicorn::nameList;

int main() {
    Unicorn("Charlie");
    Unicorn("Charlie");
    Unicorn("Randy");
    Unicorn("Bob");
    Unicorn("Jerry");
    Unicorn("Bob");
    Unicorn("John");
    Unicorn::prettyPrint();

    Unicorn::deleteUnicorn("Bob");
    Unicorn::deleteUnicorn("Jerome");

    Unicorn::prettyPrint();
    Unicorn("Bob");
    Unicorn::prettyPrint();
}
