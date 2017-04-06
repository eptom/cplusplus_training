#include <iostream>
#include <vector>
/*
template <class T> 					// < przyjmowane argumenty  Typ = T, int, Klasa, string, >	typename / class
  class NazwaKlasy					// zamiast class moze takze byc jakas funkcja + ew. typ zwracany
  {
      T jakaszmienna;
      ....
  };
  
---- trzeba pamietac ze template wyglada jak klasa -
---- od TEGO mozemy zaczac, a pozniej dopisac "template" <TYP> u gory

*/


// - przyklad template z funckja wypisujaca wartosci podane jako argument

template <typename Typ>
void funkcja(Typ a){
	std::cout << a << std::endl;
}

// - przyklad template z funckja wypisujaca wartosci podane jako argument

template <typename Typ>
inline Typ maximum(const Typ &a, const Typ &b){
	return a>b ? a:b;
}

// - przyklad template z klasa dzialajaca na vectorze - 2 funkcje (push,get)
template <class Typ>
class Stack{
	private:
		std::vector<Typ> elements;
	public:

		void push(const Typ &value){
			elements.push_back(value);
		}
		
		Typ get(const int &where){
			if(elements.empty()){
				std::cout << "Vector is empty" << std::endl;
			}else if(where >= elements.size()){
				std::cout << "Wrong position" << std::endl;
			}else{
				std::cout << elements.at(where) << std::endl;
				return elements.at(where);
			}
		}	
		
};

int main(){
	
	funkcja<int>(123);		// <int>(int)
	funkcja(321);			// <int>(int)
	funkcja("a");			// <char>(char)
	funkcja("string");
	
	std::cout << maximum(1.0,2.5) << std::endl;
	
	Stack<int> elementy;
	elementy.get(0);
	elementy.push(2);
	elementy.push(3);
	elementy.get(0);
	elementy.get(2);
	
	return 0;
}
