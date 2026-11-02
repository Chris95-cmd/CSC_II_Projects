#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Instrument {
protected:
	string name;
	string sound;
public:
	Instrument(string _n, string _s) : name(_n), sound(_s){}
	virtual void play(){
		cout << name << ": " << sound << " ";
	}
};

class Trumpet : public Instrument {
public:
	Trumpet() : Instrument("Trumpet", "doot") {}
	void play() {
	Instrument::play();
		cout << sound << sound << endl;
	}
};

class Violin : public Instrument {
public:
	Violin() : Instrument("Violin", "vwa") {}
	void play() {
	Instrument::play();
		cout << sound << sound << sound << sound << endl;
	}
};

class Piano : public Instrument {
public:
	Piano() : Instrument("Piano", "dee") {}
	void play() {
	Instrument::play();
		cout << sound << endl;
	}
};

class Trombone : public Instrument {
public:
	Trombone() : Instrument("Trombone", "Dwooooo~") {}
	void play() {
	Instrument::play();
	}
};

class Singer : public Instrument {
public:
	Singer() : Instrument("Singer", "blah") {}
	void play() {
	Instrument::play();
		cout << sound << sound << sound << sound << sound << endl;
	}
};

class Orchestra {
private:
	vector<Instrument*> orch;  
public:
	void addInstrument(Instrument* inst) {
		orch.push_back(inst);
	}

	void play() {
		for (int i = 0; i < orch.size(); i++) {
			orch[i]->play();
		}
	}
};

int main() {
	Trumpet trumpet;
	Violin violin;
	Piano piano;
	Trombone trombone;
	Singer singer;

	Orchestra symphony;
	symphony.addInstrument(&trumpet);
	symphony.addInstrument(&violin);
	symphony.addInstrument(&piano);
	symphony.addInstrument(&trombone);
	symphony.addInstrument(&trumpet);  
	symphony.addInstrument(&singer);

	symphony.play();
}