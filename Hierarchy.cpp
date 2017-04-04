#include <iostream>
#include <vector>

// can be compiled >g++ Hierarchy.cpp -o Hierarchy

class Zwierze {
  public:
    virtual void dajGlos() = 0; // Pure virtual function makes this class Abstract, must be overridden 
				// Abstract class is some kind of "Interface" since we cannot create object of this class - we can only derive form this class. 
				// Abstract class can have other "normal" functions or variables
				// Pure Abstract class have only abstract functions = 0;
};

class Pies : public Zwierze {
  public:
    void dajGlos(){
      std::cout << "Hau Hau" << std::endl;
    }
  
};

class Kot : public Zwierze {
  public:
    void dajGlos(){
      std::cout << "Miau Miau" << std::endl;
    }
};

int main(){
  Zwierze *zw = new Pies();
  zw->dajGlos();
  
  Pies herman;
  Kot filemon;  
  herman.dajGlos();
  filemon.dajGlos();
  
  std::cout << "Przechodzimy do vectora" << std::endl;
  
  std::vector <Zwierze*> zwierzyniec;
  zwierzyniec.push_back(new Pies());
  zwierzyniec.push_back(new Kot());
  zwierzyniec.push_back(new Pies());
  zwierzyniec.push_back(new Kot());
  
  for(std::vector <Zwierze*>::iterator it_Zwierze = zwierzyniec.begin(); it_Zwierze != zwierzyniec.end(); ++it_Zwierze){	//pre inkrementacja nie potrzebuje przechowania tymczasowej zmiennej - przez co jest optymalniejsza
    (*it_Zwierze)->dajGlos();
  }
  
  std::cout << "size of vector: " << (int) zwierzyniec.size() << std::endl;		//4
  std::cout << "capacity of vector: " << (int) zwierzyniec.capacity() << std::endl;	//4
  
  zwierzyniec.push_back(new Pies());
  std::cout << "size of vector: " << (int) zwierzyniec.size() << std::endl;		//5
  std::cout << "capacity of vector: " << (int) zwierzyniec.capacity() << std::endl;	//8	- n^2 -> 4,8,16,32
  
  
  for(Zwierze *z : zwierzyniec){	// for this we need newer g++ and compile with > g++ -std=c++11 Hierarchy.cpp -o Hierarchy
    z->dajGlos();
  }
  
  
 return 0; 
}