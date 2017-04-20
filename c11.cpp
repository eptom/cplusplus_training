#include <iostream>
#include <vector>

// default -
struct SomeType
{
  SomeType() = default; //Domy�lny konstruktor jest jawnie okre�lony.
  SomeType(int value);
};


// nullptr 
// W starszym C++, sta�a 0 spe�nia dwie funkcje: sta�ej ca�kowitej i pustego wska�nika (jest to cecha z j�zyka C od roku 1972).
// Przez lata programi�ci obchodzili t� niejednoznaczno�� za pomoc� identyfikatora NULL zamiast 0.

void foo(int a){
	std::cout << " int a " << std::endl;
}
void foo(int *a){
	std::cout << " int *a " << std::endl;	
}

int main(){
	int a = 5;
	int *b = &a;
	foo(b);
	
	int c = NULL;
	char *d = NULL;
//	foo(NULL);				// error - nie moze dopasowac
	foo(c);						// chyba ze jest przypisana

	foo(nullptr);
	
	// auto i decltype
	auto innaZmienna = L"To jest tekst";
	
	int jakisInt;
	decltype(jakisInt) innaZmiennaInt = 5;
	
	// petla for
	int moja_tablica[5] = {1, 2, 3, 4, 5};
		for(int &x : moja_tablica)
		{
		  x *= 2;
		}
	
	// funkcja lambda
	//informujesz, �e zaczyna si� wyra�enie lambda
//	[] (/*definiujesz argumenty funkcji*/)->/*tu okre�lasz zwracany typ*/ { /*cialo */ }( /*warto�ci argument�w z jakimi wyra�enie lambda ma zosta� wywo�ane*/ )
	[]( int x, int y )->void { std::cout << "Wyrazenie lambda: " << x << " + " << y << " = " << x+y << std::endl; }( 5, 6 );
	
	return 0;
}
