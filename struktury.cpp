#include<iostream>


using namespace std;

class Auto{
	int a;
};

struct Rower : public Auto{
	int b=1;
};

int main(){
	Rower r;
	cout << sizeof(r) << endl;
	return 0;
}
