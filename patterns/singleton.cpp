#include <iostream>
using namespace std;
// Singleton - zapewnia ze klasa bedzie posiadala tylko i wylacznie jedna instancje - i zapewniala globalny dostep do niej

/* Check lista:
- private static attribute 									// przygotowac zmienna typu klasy
- public static accessor function in the class				// zrobic funkcje GetInstance
- do "lazy initialization" in accessor function				// zrobic inicjalizacje obiektu
- define all constructors									//
- clients may use only the accessor function 				//
*/

class Singleton{
	private:
		Singleton(){}
		Singleton(const Singleton &old);	// disallow copy constructor
		const Singleton &operator=(const Singleton &old);	// disallow assignment operator
		~Singleton(){}	
		const char *txt = "Singleton class";
	public:
		static Singleton &getInstance(){
			static Singleton *instance = new Singleton;
			return *instance;
		}
		void wypisz(){
			cout << txt << endl;
		}
};

int main(){
	
	Singleton::getInstance().wypisz();
	//Singleton a;		// nie wywolam utworzenia obiektu bo konstruktor jest private
	
	
	return 0;
}
