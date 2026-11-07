#include <iostream>
#include <string>
#include <exception>
#include <ctime>

using namespace std;

class bad_egg : public exception {
public:
    const char* what() const  {
        return "This egg is rotten!";
    }
};

class Egg {
private:
    string size;
    string flavor;

public:
    Egg(string s, string f) : size(s), flavor(f) {}
    virtual ~Egg() {}

    string get_size() const { return size; }

    string get_flavor() const { return flavor; }

    virtual void eat_egg() const = 0;
};

class BoiledEgg : public Egg {
public:
    BoiledEgg() : Egg("large", "savory") {}

    void eat_egg() const {
        cout << "You peel and eat a " << get_size() << " " << get_flavor()
            << " boiled egg. It is firm and a little crumbly." << endl;
    }
};

class ScrambledEgg : public Egg {
public:
    ScrambledEgg() : Egg("medium", "buttery") {}

    void eat_egg() const {
        cout << "You eat a " << get_size() << " " << get_flavor()
            << " scrambled egg. It is soft, fluffy, and warm." << endl;
    }
};

class ChocolateEgg : public Egg {
public:
    ChocolateEgg() : Egg("large", "sweet") {}

    void eat_egg() const {
        cout << "You unwrap a " << get_size() << " " << get_flavor()
            << " chocolate egg. It melts in your mouth." << endl;
    }
};

class RottenEgg : public Egg {
public:
    RottenEgg() : Egg("medium", "rotten") {}

    void eat_egg() const {
        throw bad_egg();
    }
};

class Carton {
private:
    Egg* eggs[12];
    int count = 0;

public:
    Carton() {
        for (int i = 0; i < 12; i++) {
            int decider = rand() % 4;
                if (decider == 0) {
                    eggs[i] = new BoiledEgg();
                    count++;
                }
                else if (decider == 1) {
                    eggs[i] = new ChocolateEgg();
                    count++;
                }
                else if (decider == 2) {
                    eggs[i] = new ScrambledEgg();
                    count++;
                }
                else {
                    eggs[i] = new RottenEgg();
                    count++;
                }
        }
    }

    ~Carton() {
        for (int i = 0; i < 12; i++) {
            delete eggs[i];
            count--;
        }
    }

    void eatEgg() {
        if (count == 0) {
            cout << "The carton is empty!" << endl;
            return;
        }
        Egg* egg = eggs[count - 1];
        eggs[count - 1] = nullptr;
        count--;

        try {
            egg->eat_egg();
        }
        catch (const bad_egg& e) {
            cout << e.what() << endl;
        }

        delete egg;
    }

    int getCount() const { return count; }
};

int main() {
    srand(time(0));
    Carton carton = Carton();


    cout << "Eggs in carton: " << carton.getCount() << endl;

    while (carton.getCount() > 0) {
        carton.eatEgg();
        cout << "Eggs in carton: " << carton.getCount() << endl;
    }
}
