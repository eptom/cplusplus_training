#include <iostream>
#include <string>
using namespace std;
// Builder - umozliwa stworzenie obiektow, bez potrzeby podowania duzej ilosci argumentow

class Car{
	private:
		int rocznik;
		string marka;
		//string model;
	public:
		void setRocznik(const int &r){	rocznik = r;	}
		void setMarka(const string &m){	marka = m; 		}
		void show() const{
			cout << "Car " << marka << " from : " << rocznik << endl;
		}
};

class CarBuilder{
	protected:
		Car *mCar;
	public:
		void createNewCar(){
			mCar = new Car();
		}
		Car *getCar(){
			return mCar;
		}
		virtual void buildRocznik()=0;
		virtual void buildMarka()=0;
		virtual ~CarBuilder(){};
};
class Ford : public CarBuilder{
	public:
		virtual void buildRocznik()	{	mCar->setRocznik(2012);	};
		virtual void buildMarka()	{	mCar->setMarka("Ford");	};
		virtual ~Ford(){};
};
class Opel : public CarBuilder{
	public:
		virtual void buildRocznik()	{	mCar->setRocznik(2016);	};
		virtual void buildMarka()	{	mCar->setMarka("Opel");	};
		virtual ~Opel(){};
};

class Build{
	private:
		CarBuilder *build;
	public:
		void showCar(){
			build->getCar()->show();
		}
		void buildCar(CarBuilder *cb){
			build = cb;
			build->createNewCar();
			build->buildRocznik();
			build->buildMarka();
		}
};


int main(){

	Build b;
	Ford f;
	Opel o;
	b.buildCar(&f);
	b.showCar();
	
	b.buildCar(&o);
	b.showCar();
	
	return 0;
}
