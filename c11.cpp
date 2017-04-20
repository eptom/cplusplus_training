#include <iostream>
#include <vector>

// default -
struct SomeType
{
  SomeType() = default; //Domyœlny konstruktor jest jawnie okreœlony.
  SomeType(int value);
};


// nullptr 
// W starszym C++, sta³a 0 spe³nia dwie funkcje: sta³ej ca³kowitej i pustego wskaŸnika (jest to cecha z jêzyka C od roku 1972).
// Przez lata programiœci obchodzili tê niejednoznacznoœæ za pomoc¹ identyfikatora NULL zamiast 0.

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
	//informujesz, ¿e zaczyna siê wyra¿enie lambda
//	[] (/*definiujesz argumenty funkcji*/)->/*tu okreœlasz zwracany typ*/ { /*cialo */ }( /*wartoœci argumentów z jakimi wyra¿enie lambda ma zostaæ wywo³ane*/ )
	[]( int x, int y )->void { std::cout << "Wyrazenie lambda: " << x << " + " << y << " = " << x+y << std::endl; }( 5, 6 );
	
	return 0;
}
