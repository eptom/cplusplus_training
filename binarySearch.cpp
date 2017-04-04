#include <iostream>

using namespace std;

void binarySearch(int szukana, int *tab, int lewa, int prawa){

	int srd = (lewa+prawa) / 2;
	
	if(szukana == tab[srd]){
		cout << "Znaleziono szukana wartosc w tablicy pod numerem: " << srd << endl;
	}else if(szukana == tab[prawa]){
		cout << "Znaleziono szukana wartosc w tablicy pod numerem: " << prawa << endl;
	}else if(szukana == tab[lewa]){
		cout << "Znaleziono szukana wartosc w tablicy pod numerem: " << lewa << endl;
	}else{
		if (szukana > tab[srd]){	// szukana wartosc znajduje sie w polowce p - prawej
			binarySearch(szukana, tab, srd, prawa);
		}else{						// szukana wartosc znajduje sie w polowce l - lewej
			binarySearch(szukana, tab, lewa, srd);
		}
	}
	//cout << "Nie znaleziono szukanej wartosci w tablicy" << endl;
	return;	
}

int print(int *tab, int rozmiar){
	for(int i=0;i<rozmiar;i++){
		cout << tab[i] << " ";
	}
	cout << "" << endl;
}


int main(){
	
	const int rozmiar = 10;
	int tab [rozmiar] = {1,2,3,4,5,6,7,8,9,10}; 

	print(tab,10);
	
	for(int i=1;i<rozmiar+1;i++){
		cout << "Szukam wartosci: "<< i << endl;
		binarySearch(i,tab,0,rozmiar-1);
	}
	
	
	return 0;
}
