#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Hero {
private:
	int strength;
	int courage;
	string hero_name;

public:
	Hero(string heroName) {
		hero_name = heroName;
		strength = rand() % 100;
		courage = rand() % 100;
	}

	int getStrength() {return strength;}
	int getCourage() {return courage;}
	string getName() {return hero_name;}
	void setCourage(int newCourage) {courage = newCourage;}

	void train(int hours) {
		strength += hours * 2;
		cout << hero_name << " trained for " << hours << " hours. " 
			<< hero_name << "'s strength is now " << strength << "." << endl;
	}
	
	void therapy() {
		int gain_courage = rand() % 10;
		courage += gain_courage;
		cout << hero_name << " attended therapy and gained " << gain_courage
			<< " courage. " << hero_name << "'s Courage is now " << courage << "." << endl;
	}
};

void go_on_quest(Hero& hero) {
	int dice_roll = rand() % 100;
	int strength_bonus_roll = dice_roll + hero.getStrength();
	string result;
	int courage_loss;

	if (strength_bonus_roll >= 75) {
		result = "a SUCCESS!";
		courage_loss = 10;
	}
	else if (strength_bonus_roll >= 50) {
		result = "NEUTRAL.";
		courage_loss = 25;
	}
	else {
		result = "a FAILURE!";
		courage_loss = 50;
	}

	hero.setCourage(hero.getCourage() - courage_loss);

	cout << hero.getName() << "'s quest was " << result << hero.getName()
		<< "'s courage is now " << hero.getCourage() << "." << endl;
}

int main() {
	srand(time(0));

	Hero h1("Neddard");
	Hero h2("Robb");
	Hero h3("Arya");

	cout << h1.getName() << ": STR " << h1.getStrength() << ", CRG " << h1.getCourage() << endl;
	cout << h2.getName() << ": STR " << h2.getStrength() << ", CRG " << h2.getCourage() << endl;
	cout << h3.getName() << ": STR " << h3.getStrength() << ", CRG " << h3.getCourage() << endl;

	cout << endl << "--- Training & therapy---" << endl;
	h1.train(4);
	h2.therapy();
	h3.train(2);
	h3.therapy();

	cout << endl << "--- Quests ---" << endl;
	for (int i = 0; i < 3; i++) {
		go_on_quest(h1);
		go_on_quest(h2);
		go_on_quest(h3);
	}
}