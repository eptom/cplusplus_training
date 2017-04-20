#include <iostream>

using namespace std;

class A{
	mutable int a;			// bez mutable by nie mozna bylo tego zmienic
	public:
	A(){
		a = 5;
	}
	void foo(const int var) const{		// const zapewnia nas ze zadne zmienne klasy nie zostana zmienione przez nia
		cout << " Przed zmiana a = " << a << endl;
		a = var;
		//var = 66; 			// niedozwolone
		cout << " Po zmianie a = " << a << endl;
	}

};


int main(){
	int temp = 55;
	const int ctemp = 34;
	int const ctemp2 = 34; // jest tym samym co const int
	
	A a;
	a.foo(ctemp);
	
	return 0;
}
