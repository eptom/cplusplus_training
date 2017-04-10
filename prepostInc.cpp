#include <iostream>

using namespace std;


int main(){

	int a;
	
	for(a=5;a<10;++a){
		cout << " wchodze do petli i a = " << a << endl;
		a++;
		cout <<"post :" << a << endl;
		++a+1;
		cout << "pre  :" << a << endl;
	}
	
	int b = a;
	cout << " po wyjsciu z petli b = a = " << a << endl;
	b = ++a;
	cout << " b = ++a" << endl;
	cout << " a = " << a << " b = " << b << endl;
	b = a++;
	cout << " b = a++" << endl;
	cout << " a = " << a << " b = " << b << endl;
	cout << " _____________ " << endl;
	
	int c = 6;
	cout << " c+= ++c + ++c " << endl;
	//c = ++c + ++c +c
	//c = 7   + 8   +9
	c+= ++c + ++c;
	cout << " c = " << c << endl; 

	
	c = 6;
	cout << " c+= c++ + c++ " << endl;
	//c = c+++c++ +c
	//c = 6  +7   +7
	c+= c++ + c++;
	cout << " c = " << c << endl; 
	
	cout << " _____________ " << endl;
	int _a=1; 
	int _b=2; 
	cout << " _a = " << _a << endl;
	cout << " _b = " << _b << endl; 
	cout << " wykonuje dzialanie _a+++_b " << endl;
	int _c =_a+++_b; 
	cout << " _a = " << _a << endl;
	cout << " _b = " << _b << endl;  
	
	cout << " _c = " << _c << endl; 
	return 0;
}
