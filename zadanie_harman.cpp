#include <iostream>
using namespace std;

class A{
	public:
	A(){
		cout << "A" << endl;
	}
	//virtual ~A(){
	~A(){
		cout << "~~A" << endl;
	}
};

class B{
	public:
	B(){
		cout << "B" << endl;
	}
	~B(){
		cout << "~~B" << endl;
	}
};

class C : public A{
	public:
	C(){
		cout << "C" << endl;
	}
	~C(){
		cout << "~~C" << endl;
	}
	
	B b;
};

int main(){
	
	A *a = new C();

	delete a;
	
	
	return 0;
}
