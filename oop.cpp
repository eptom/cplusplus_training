#include <iostream>
using namespace std;

//**************** dziedziczenie
				// Dziedziczenie daje nam mozliwosc wykorzystania istniejacych juz klas w celu ich rozszerzenia
				// konstruktory i destruktory NIE sa dziedziczone, rowniez operatory przypisania
class A{
	public:
	int i;
};

class B : public A{	
	int j;			// klasa B oprocz zmiennej j, bedzie miala takze zmienna i  (public)
};

//*******************************
//**************** polimorfizm
				// Polimorfizm w programowaniu obiektowym oznacza wykorzystanie tego samego kodu 
				// do operowania na obiektach przynale¿nych ró¿nym klasom, dziedzicz¹cym od siebie. 
class C{
	
	public:
		virtual void wypisz(){
		//void wypisz(){
			cout << " funkcja wypisz() wywolana z klasy C" << endl;
		}
	virtual ~C(){
		cout << "~~C" << endl;
	}
};

class D : public C{
	public:
		void wypisz(){
			cout << " funkcja wypisz() wywolana z klasy D" << endl;	
		}
	~D(){
		cout << "~~D" << endl;
	}
	
};
//*******************************
//**************** enkapsulacja
				// Enkapsulacja (hermetyzacja) w programowaniu obiektowym oznacza ukrywanie implementacji 
				// do zmienia stanow mamy specjalne metody -> gettery i settery
class E{
	private:
		int stan;						// nie mamy dostepu do zmiennej - mozemy zmienic tylko poprzez funkcje setStan()
	public:
		void setStan(int newStan){
			this->stan = newStan;
		}
};
//*******************************
//**************** abstrakcja
				// Abstrakcja daje nam wzor/przyklad jak ma wygladac klasa -> przez co narzuca/ wymusza zaimplemeptowanie wszystkich dostepnych w niej danych
				// Klasa abstrakcyjna musi zawierac przynajmniej jedna funkcje CZYSTO wirtualna czyli bez ciala i przypisana do zera =0;
				// nie mozna utworzyc obiektu klasy abstrakcyjnej - mozna jedynie po niej dziedziczyc
				// jest tzw interfejsem 
class abtractF{
	public:
		virtual void wypisz()=0;	
		virtual ~abtractF(){
			cout << "~~abtractF" << endl;
		}
};

class F : public abtractF{
	public:
		void wypisz(){
			cout << "obiekt F" << endl;
		}
		~F(){
			cout << "~~F" << endl;
		}
};


int main(){
	B b;
	cout << "sizeof B : " << sizeof(b) << endl;		// sizeof == 8 bajtow -> (2xint)
	
	C *c = new D();
	c->wypisz();
	
	delete c;
	
	//abtractF f;		// error
	F f;		// gdy nie stworzymy funkcji wypisz -> kompilator nie pozwoli na utworzenie tego obiektu
	cout << "sizeof f : " << sizeof(f) << endl;		// sizeof == 8 bajtow -> (2xint)		
	
	return 0;
}
