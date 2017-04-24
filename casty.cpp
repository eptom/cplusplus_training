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
				static_cast mo�na u�ywa� np. do: 
						- konwersji mi�dzy typami numerycznymi 
						- rzutowania liczby na typ wyliczeniowy (enum) 
						- rzutowanie wskaznika do obiektu klasy bazowej na wskaznik do obiektu klasy pochodnej - ale musimy byc pewni danej konwersji
						- pozwala takze na upcast - czyli rzutowanie na obiekt dziedziczony
				Poprawno�� rzutowania static_cast jest sprawdzana w czasie kompilacji programu. */
 	A * a = new A;
	B * b = static_cast<B*>(a);				// rzutujemy obiekt a (typu A) na obiekt b typu B (w dol)
	
//	A * a = new A;
//	B * b = dynamic_cast<B*>(a);				// rzutujemy obiekt a (typu A) na obiekt b typu B (w dol)
												// nie da sie przerzutowac jesli klasa bazowa nie polimorficzna ( funkcja virtualna )
												// w bloku try catch pokazano ze juz to dziala
	
	B * db = new B;
	A * da = static_cast<A*>(db);			// rzutujemy obiekt db (typu B) na obiekt da typu A (w gore)
	

	/*****		dynamic_cast  ***//*
					Przy pomocy dynamic_cast mo�na rzutowa� wska�niki i referencje do obiekt�w w d� 
					hierarchii dziedziczenia. Oznacza to, �e mo�na zamieni� odwo�anie do obiektu klasy 
					bazowej na odwo�anie do obiektu klasy pochodnej.
				Poprawno�� rzutowania dynamic_cast jest sprawdzana w czasie dzia�ania programu. */
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
						mo�e s�u�y� do dowolnych konwersji mi�dzy wska�nikami, a tak�e do rzutowania wska�nik�w na typy liczbowe i odwrotnie. 
						Wachlarz mo�liwo�ci jest wi�c szeroki, niestety: 
 				Poprawno�� rzutowania reinterpret_cast nie jest sprawdzana. */
 	
 	/**** 		const_cast 
	 					s�u�y do usuwania przydomk�w const i volatile z opatrzonych nimi wska�nik�w do zmiennych. */
	const char * c = "sample text";
//	print(c);					// invalid conversion
	print(const_cast<char*>(c));
	 		
	return 0;
}
