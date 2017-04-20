#include <iostream>
#include <string>
using namespace std;
// Adapter - pozwala wykorzystac interfejs jednej klasy - kiedy nie sa kompatybilne
	// dwie rozne klasy + klasy abstrakcyjne (interfejsy)
	
class IWtyczkaEU{								// INTERFEJS EU
	public:
		virtual ~IWtyczkaEU()=default;
		virtual void podlaczEU()=0;
};
class IWtyczkaUSA{								// INTERFEJS USA
	public:
		virtual ~IWtyczkaUSA()=default;
		virtual void podlaczUSA()=0;
};
class WtyczkaEU : public IWtyczkaEU{
	public:
	void podlaczEU(){ cout << " Jestem wtyczka EU" << endl;	}
};
class WtyczkaUSA : public IWtyczkaUSA{
	public:
	void podlaczUSA(){ cout << " Jestem wtyczka USA" << endl;	}
};
class WtyczkaEU_IN{
	public:
		void wlacz(IWtyczkaEU *ieu){
			ieu->podlaczEU();
			cout << " wlaczam wtyczke do pradu w EUROPIE" << endl;
		}
};

class WtyczkaUSAinEUAdapter : public WtyczkaEU{
	private:
		WtyczkaUSA *usa;
	public:
		WtyczkaUSAinEUAdapter(WtyczkaUSA *u):usa(u){}
		void podlaczEU(){
			usa->podlaczUSA();
		}
};


int main(){
	WtyczkaEU *eu = new WtyczkaEU();
	WtyczkaUSA *usa = new WtyczkaUSA();
	WtyczkaEU_IN in;
	in.wlacz(eu);
		
	//in.wlacz(usa);		// nie podlacze wtyczki usa w eu
						// potrzebny jest adapter
	WtyczkaUSAinEUAdapter *adapterUSA = new WtyczkaUSAinEUAdapter(usa);
	in.wlacz(adapterUSA);

	return 0;
}
