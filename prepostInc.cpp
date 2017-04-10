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
	
	cout << " po wyjsciu z petli a = " << a << endl;
	++a;
	cout << " pre a = " << a << endl;
	a++;
	cout << " post a = " << a << endl;
	return 0;
}
