#include <iostream>
using namespace std;

class A{
	int i;
	int j;
	public:
	A(){
		cout << "A" << endl;
	}
	A(const char *txt){
		cout << "aaaa" << endl;
	}
	virtual ~A(){					// identyfikator virtual powoduje wywolanie wszystkich destruktorow -> 
									// zaleca sie uzywanie go zawsze W KLASACH BAZOWYCH aby zapewnic usuniecie wszystkich mozliwych danych
									// jego brak moze doprowadzic do wyciekow pamieci !!!
	~A(){
		cout << "~~A" << endl;
	}
};

class B{
	int i;
	int j;
	public:
	B(){
		cout << "B" << endl;
	}
	~B(){
		cout << "~~B" << endl;
	}
};

class C : public A{
	public:
	C(){
		cout << "C" << endl;
	}
	C(const char *txt){
		cout << "cccc" << endl;
	}
	~C(){
		cout << "~~C" << endl;
	}
	
	B b;
};

class D{
	
};

int main(){
	
	A *a = new C("aaa");	// to dowodzi ze przy dziedziczeniu jest wywolywany konstruktor bezparametrowy
	delete a;
	
	B bb;
	cout << "sizeof B : " << sizeof(bb) << endl;
	
	A aa;		// destruktory sa wywolywane w odwrotnej kolejnosci do ich tworzenia
	C cc;		// C dziedziczy po A i ma obiekt B    (sizeof = 16 -> :A (2xint) + obiekt B (2xint)
	cout << "sizeof C (:A, zawierajace obiekt B): " << sizeof(cc) << endl;
	cout << "sizeof A: " << sizeof(aa) << endl;
	
	D dd;											// sizeof 1 bajt -> 8 bitow -> tablica metod wirtualnych
	cout << "sizeof D: " << sizeof(dd) << endl;
	
	return 0;
}
