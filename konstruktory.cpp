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
								//	Je�eli obiekt pracuje na jakim� zewn�trznym zasobie (np. pami�ci operacyjnej) i posiada 
								//	do niego odwo�anie (np. wska�nik), to jego klas� koniecznie nale�y wyposa�y� w 
								//	konstruktor kopiuj�cy. Bez niego zostanie bowiem podczas kopiowanie obiektu zostanie 
								//  skopiowane samo odwo�anie do zasobu (czyli wska�nik) zamiast stworzenia jego 
								//  duplikatu (czyli alokacji nowej porcji pami�ci). 
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
