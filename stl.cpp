#include<iostream>
#include <algorithm> 
#include <set>
#include <map>

/*
STL (Standard Template Library) to standardowa biblioteka szablonów. Jest fragmentem biblioteki standardowej C++ i zawiera:
• kontenery 
• iteratory – obiekty pozwalaj¹ce na sekwencyjny dostêp do danych przechowywanych w kontenerze (bez koniecznoœci zag³êbiania siê w nie)
• algorytmy – szablony funkcji do przetwarzania danych w kontenerze (find,sort,reverse)

Kontenery:
array - tablica statyczna, rozmiar niemodyfikowalny, brak wstawiania / usuwania elementów

vector - tablica dynamiczna, elementy przechowywane w ci¹g³ym obszarze pamiêci, swobodny dostêp do elementów za pomoc¹ indeksowania,
			wstawianie i usuwanie elementów automatycznie zmienia rozmiar tablicy,
			wydajnoœæ: szybkie przegl¹danie i dostêp, wolne wstawianie i usuwanie (wymaga „przesuwania” elementów w pamiêci)
			
list - lista dwukierunkowa (jednokierunkowa: forward_list), elementy przechowywane w nieci¹g³ym obszarze pamiêci
		poruszanie siê krokowe w dwóch kierunkach (brak indeksowania),
		pod wzglêdem wydajnoœci – przeciwieñstwo kontenera vector (powolne przegl¹danie i dostêp, szybkie wstawianie i usuwanie)
		
deque - kolejka dwukierunkowa (double-ended queue), wstawianie i usuwanie elementów na obu koñcach
set  - zbiór operacje na zbiorach: suma, czêœæ wspólna, ró¿nica, zawieranie
multiset - jak kontener set ale elementy mog¹ siê powtarzaæ
bitset - specjalna wersja kontenera set ze zoptymalizowanym sposobem przechowywania wartoœci bitowych
map - mapa (s³ownik, tablica asocjacyjna) zawiera pary klucz-wartoœæ, elementy dostêpne poprzez unikatowy klucz

Adaptery:
stack - stos LIFO (Last In First Out) – dostêp tylko do wierzcho³ka stosu, operacje: push(), pop(), top()
queue - kolejka FIFO (First In First Out) – wstawianie elementów na koñcu, usuwanie z pocz¹tku, operacje: push(), pop(), front(), back()
*/

int main(){
	// vector
	std::vector <int> tab;
	tab.push_back(3);		// push_back dodaje element do konca tablicy
	tab.push_back(5);		// pop_back usuwa ostatni element tablicy
	tab.push_back(3);
	tab.push_back(1); tab.push_back(1); 
	std::cout << "Tablica ma rozmiar (size()) :" << tab.size() << std::endl; 
	std::cout << "Tablica natomiast zarezerwowala (capacity()) :" << tab.capacity() << std::endl; 
	tab.shrink_to_fit(); 	// zmniejsza rozmiar tablicy do faktycznej liczby elementow
	std::cout << "Po shrink_to_fit() tablica posiada (capacity()) :" << tab.capacity() << std::endl; 
	// iterator
	for (std::vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	//sort
  	std::sort (tab.begin(), tab.end()); 
  	
  	for (std::vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	//reverse
  	std::reverse(tab.begin(),tab.end());
  	for (std::vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	//count
  	int mycount = std::count (tab.begin(),tab.end(), 3);
  	std::cout << "3 wystepuje w tablicy " << mycount << " razy.\n";
  	
  	//find
	std::vector<int>::iterator it;
		it = find (tab.begin(), tab.end(), 5);
  		if (it != tab.end()){	// jesli nie znajdzie zwraca ostatni element z vectora
  			std::cout << "Znalazlem " << *it << " ";
  			// distance
  			int dist = std::distance(tab.begin(), it);
  			std::cout << "na pozycji " << dist << " \n";
  		}
  		
  		it = find (tab.begin(), tab.end(), 6);
  		if (it != tab.end()){	// jesli nie znajdzie it zwraca ostatni element z vectora
  			std::cout << "Znalazlem " << *it << " \n";
  		} else { std::cout << "Nie znalazlem " << " \n"; }
  		
  	//erase
  	tab.erase (tab.begin()+3);			// erase przyjmuje jako arugment iterator	/ badz zakres 
  	for (std::vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	//clear
  	tab.clear();
  	std::cout << "Tablica ma rozmiar (size()) :" << tab.size() << std::endl; 
  	
  	// SET
  	std::set<int> set;
  	set.insert(1);
  	set.insert(2);
  	set.insert(3);
  	std::cout << "set: \n";
  	for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	set.insert(1);		// nie doda bo juz taki element istnieje
  	set.insert(6);
  	set.insert(0);		// doda na poczatek 
  	for (std::set<int>::iterator it=set.begin(); it!=set.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
  	
  	// MAP
  	std::map<int, std::string> mapa;		// map<klucz, wartosc>
  	mapa[1] = "poniedzialek";
   	mapa[2] = "wtorek";
   	mapa[3] = "sroda";
   	mapa[4] = "czwartek";
   	mapa[5] = "piatek";
  	
  	std::cout << "trzeci dzien tygodnia:  " << mapa[3] << '\n';
  	mapa.insert ( std::pair<int, std::string>(6,"sobota") );		// insert nie nadpisze istniejacego elementu
  	for( auto it : mapa ){
  		std::cout << "Klucz " << it.first << " posiada wartosc " << it.second << "\n";
  	}
  	std::cout << "\n";
  	mapa[3] = "alamakota";
  	for( std::map<int, std::string>::iterator it=mapa.begin(); it!=mapa.end(); it++ ){
  		std::cout << "Klucz " << it->first << " posiada wartosc " << it->second << "\n";
  	}
  	std::cout << "\n";
  	mapa.insert ( std::pair<int, std::string>(1,"blabla") );
  	for( auto it : mapa ){
  		std::cout << "Klucz " << it.first << " posiada wartosc " << it.second << "\n";
  	}
	return 0;
}
