#include <iostream>
#include <string>
using namespace std;
// Decorator
	// pozwala na dodanie nowych funkcjonalnosci klasy dynamicznie
	// mozna uzywac jako alternatywe do rozszerzania klas 
	// inna nazwa to "Wrapper"
	
class Car{							// klasa bazowa - abstrakcyjna
	protected:
		string str;
	public:
		Car(){ str = "Unknow Car"; }
		virtual string getDescription(){ return str; }
		virtual double getCost()=0;
		virtual ~Car(){ cout << "~~Car " << endl;	}
};

class OptionsDecorator : public Car{							// DEKORATOR	- abstrakcyjna
	public:
		virtual string getDescription()=0;
		virtual ~OptionsDecorator(){ cout << "~~OptionsDecorator " << endl;	}
};

class Ford : public Car{						
	public:
		Ford(){ str = "Ford"; }
		double getCost(){ return 3100.23; }
		~Ford(){ cout << "~~Ford " << endl;	}
};

class Navigation : public OptionsDecorator{	
		Car *_c;					
	public:
		Navigation(Car *c){ _c = c; }		// przypisanie do zmiennej _c obiektu przekazanego jako argument
		string getDescription(){
			return _c->getDescription() + "+ Navigation";
		}
		double getCost(){ 
			return _c->getCost() + 23.21; 
		}
		~Navigation(){ 
			cout << "~~Navigation " << endl;
			// trzeba usunac OBIEKT tymczasowy _c
			delete _c;
		}
};

class AC : public OptionsDecorator{	
		Car *_c;					
	public:
		AC(Car *c){ _c = c; }		// przypisanie do zmiennej _c obiektu przekazanego jako argument
		string getDescription(){
			return _c->getDescription() + "+ AC";
		}
		double getCost(){ 
			return _c->getCost() + 42.02; 
		}
		~AC(){ 
			cout << "~~AC " << endl;
			// trzeba usunac OBIEKT tymczasowy _c
			delete _c;
		}
};

int main(){
	Car *car = new Ford();
	cout << " I will buy " << car->getDescription() << " for " << car->getCost() << endl;
	// ale chce jeszcze nawigacje
	car = new Navigation(car);
	cout << " I will buy " << car->getDescription() << " for " << car->getCost() << endl;
	car = new AC(car);
	cout << " I will buy " << car->getDescription() << " for " << car->getCost() << endl;
	delete car;
	return 0;
}
