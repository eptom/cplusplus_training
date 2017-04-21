#include<iostream>
#include<typeinfo>
#include <exception>
using namespace std;

class A{};
class B : public A{};

class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

void print (char * str)
{
  cout << str << '\n';
}

int main(){
	/****   	static_cast   ****//*
				static_cast mo¿na u¿ywaæ np. do: 
						- konwersji miêdzy typami numerycznymi 
						- rzutowania liczby na typ wyliczeniowy (enum) 
						- rzutowanie wskaznika do obiektu klasy bazowej na wskaznik do obiektu klasy pochodnej - ale musimy byc pewni danej konwersji
						- pozwala takze na upcast - czyli rzutowanie na obiekt dziedziczony
				Poprawnoœæ rzutowania static_cast jest sprawdzana w czasie kompilacji programu. */
 	A * a = new A;
	B * b = static_cast<B*>(a);				// rzutujemy obiekt a (typu A) na obiekt b typu B (w dol)
	
//	A * a = new A;
//	B * b = dynamic_cast<B*>(a);				// rzutujemy obiekt a (typu A) na obiekt b typu B (w dol)
												// nie da sie przerzutowac jesli klasa bazowa nie polimorficzna ( funkcja virtualna )
												// w bloku try catch pokazano ze juz to dziala
	
	B * db = new B;
	A * da = static_cast<A*>(db);			// rzutujemy obiekt db (typu B) na obiekt da typu A (w gore)
	

	/*****		dynamic_cast  ***//*
					Przy pomocy dynamic_cast mo¿na rzutowaæ wskaŸniki i referencje do obiektów w dó³ 
					hierarchii dziedziczenia. Oznacza to, ¿e mo¿na zamieniæ odwo³anie do obiektu klasy 
					bazowej na odwo³anie do obiektu klasy pochodnej.
				Poprawnoœæ rzutowania dynamic_cast jest sprawdzana w czasie dzia³ania programu. */
	try {
	    Base * pba = new Derived;
	    Base * pbb = new Base;
	    Derived * pd;
	
	    pd = dynamic_cast<Derived*>(pba);							// tutaj konwersja sie udala
	    if (pd==0) cout << "Null pointer on first type-cast.\n";
	
	    pd = dynamic_cast<Derived*>(pbb);							// tutaj konwersja sie nie udala
	    if (pd==0) cout << "Null pointer on second type-cast.\n";
	
	} catch (exception& e) {cout << "Exception: " << e.what();}

	/****		reinterpret_cast 
						mo¿e s³u¿yæ do dowolnych konwersji miêdzy wskaŸnikami, a tak¿e do rzutowania wskaŸników na typy liczbowe i odwrotnie. 
						Wachlarz mo¿liwoœci jest wiêc szeroki, niestety: 
 				Poprawnoœæ rzutowania reinterpret_cast nie jest sprawdzana. */
 	
 	/**** 		const_cast 
	 					s³u¿y do usuwania przydomków const i volatile z opatrzonych nimi wskaŸników do zmiennych. */
	const char * c = "sample text";
//	print(c);					// invalid conversion
	print(const_cast<char*>(c));
	 		
	return 0;
}
