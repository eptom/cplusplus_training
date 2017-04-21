#include<iostream>

using namespace std;

class Auto{
	const int *a;
	public:
		explicit Auto(int var){						// bez EXPLICIT mozna by bylo zrobic tak: Auto a = 5; -> czyli niejawne wywolanie
			cout << "explicit" << endl;				// EXPLICIT zabrania niejawanych konwersji -> czyli tutaj poprawne jest np. Auto a(5); 
		}
		Auto(int *var):a(var){		// poprzez liste inicalizacyjna mozemy przypisac wartosc do zmiennej const
							// inicjalizacja jest czynnoscia inna niz przypisanie
		cout << a << endl;
		};
		void getA(){
			cout << a << endl;
		}
		// konstruktor kopiujacy
								//	Je¿eli obiekt pracuje na jakimœ zewnêtrznym zasobie (np. pamiêci operacyjnej) i posiada 
								//	do niego odwo³anie (np. wskaŸnik), to jego klasê koniecznie nale¿y wyposa¿yæ w 
								//	konstruktor kopiuj¹cy. Bez niego zostanie bowiem podczas kopiowanie obiektu zostanie 
								//  skopiowane samo odwo³anie do zasobu (czyli wskaŸnik) zamiast stworzenia jego 
								//  duplikatu (czyli alokacji nowej porcji pamiêci). 
		// ****** nazwa_klasy::nazwa_klasy([const] nazwa_klasy& obiekt)
 		Auto(const Auto &aa ){
 			// tutaj robimy potrzebne kopiowania 
 			cout << "konstruktor kopiujacy" << endl;
 			this->a = aa.a;					// bez tego nie bedzie przekopiowana wartosc
 		}
	
};



int main(){
	int zm = 32;
	int *var = &zm;
	cout << var << endl;		// adres zmiennej var
	Auto a(var);
	Auto b = a;		// problem bo b odwolywalo sie do adresu zmiennej a przypisanej do obiektu a
	cout << "--------------" << endl;
	a.getA();
	b.getA();		// bez kopiowania nie bedzie zainicjalizowana zmienna a
					// trzeba zatem przypisac do zmiennej a adres obiketu
	
	
	
//	Auto aj = 5;			// - bez explicit zadziala   // error: copy-initialization does not consider B::B(int)
	Auto ak = (Auto)5;		// OK: explicit cast performs static_cast	
	Auto al = Auto(5);		// OK
	Auto aj(5);
	
	
	return 0;
}
