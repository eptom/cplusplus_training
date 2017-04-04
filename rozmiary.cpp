#include <iostream>

using namespace std;

class A{
	public:
	int a;		// 4 bajty		
	short s;	// 2 bajty		// tutaj uzupelni do 4
	char c;		// 1 bajt - ale ustawiajac go w tym miejscu bedzie wlozony na wolne miejsce z short s.
	long l;		// 4 bajty
				// suma = wg rozmiarow powinno byc 11, ale bedzie 4 + 4 (2+1) + 4 
	//char c;		// 1 bajt		// tutaj uzupelni do 4
};

class B:public A{
	int b;
	char d[2];
	static long a;	// nie bedzie liczony bo to zmienna statyczna
};

int main(){
	A a;
	B b;
	cout << sizeof(a) << endl;	// 12
	cout << sizeof(b) << endl;  // wyswietla 20 bo uzupelnia (int - 32bity - 4 bajty i char [2] - 16 bitow - ale uzupelnia do 32 bo taka mam architekture)
	
	return 0;
}
