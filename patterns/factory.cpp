#include <iostream>
#include <string>
using namespace std;
// Factory - umozliwa stworzenie obiektow, bez potrzeby podowania dokladnej nazwy klasy
enum CarType{
	Ford,
	Opel
};

class Car{
	public:
		Car()			{	cout << "Car" 	<< endl;};
		virtual void show()=0;
		virtual ~Car()	{ 	cout << "~~Car" << endl;};
};

class FordCar : public Car{
	public:
		FordCar(){	cout << "FordCar konstruktor" << endl;	}
		void show(){
			cout << "Jestem FORD z 2012 " << endl;
		}
		~FordCar(){	cout << "~~FordCar destruktor" << endl;	}
};

class OpelCar : public Car{
	public:
		OpelCar(){	cout << "OpelCar konstruktor" << endl;	}
		void show(){
			cout << "Jestem OPEL z 2016 " << endl;
		}
		~OpelCar(){	cout << "~~OpelCar destruktor" << endl;	}
};

class CarFactory{
	public:
		static Car *createCar(CarType s){
			switch (s)
			{
				case Ford: return new FordCar();
				case Opel: return new OpelCar();
				default: return 0;
			}
		}
};


int main(){

	Car *a = CarFactory::createCar(Ford);
	a->show();
	Car *b = CarFactory::createCar(Opel);
	b->show();
	delete a;
	delete b;

	return 0;
}
