#include<iostream>

using namespace std;

class Auto{
	const int *a;
	public:
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
 		Auto(const &Auto aA){
 			// tutaj robimy potrzebne kopiowania 
 			
 		}
	
};



int main(){
	int zm = 32;
	int *var = &zm;
	Auto a(var);
	Auto b = a;		// problem bo b odwolywalo sie do adresu zmiennej a przypisanej do obiektu a
	cout << "--------------" << endl;
	a.getA();
	b.getA();
	
	
	
	return 0;
}
