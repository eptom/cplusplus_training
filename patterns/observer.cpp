#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
// observer - daje notyfikacje odnosnie zmian w obserwowanych obiektach
class IObserver{						// observer - klasa abstrakcyjna
	public:
		virtual void update(float a,float b, float c)=0;
};
class IDisplay{							// interfejs do wyswietlania
	public:
		virtual void show()=0;
};

class IPogoda {
	virtual void registerOb(IObserver *ob)=0;
	virtual void removeOb(IObserver *ob)=0;
	virtual void notifyOb() = 0;
};
class Pogoda : public IPogoda{					// glowna klasa do zmiany pogody
	private:
		float m_hum;
		float m_temp;
		float m_pres;
		list<IObserver*> m_obs;
	public:
		void data(float a, float b, float c){
			m_hum = a;
			m_temp = b;
			m_pres = c;
			notifyOb();			// informacja o zmianie
		}
		void registerOb(IObserver *ob){
			m_obs.push_back(ob);
		}
		void removeOb(IObserver *ob){
			m_obs.remove(ob);
		}
	protected:
		void notifyOb(){
			list<IObserver*>::iterator pos = m_obs.begin();
			while(pos!=m_obs.end()){
				((IObserver*)(*pos))->update(m_hum,m_temp,m_pres);
				(dynamic_cast<IDisplay*>(*pos))->show();
				++pos;
			}
		}
};

class PogodaObs : public IObserver, public IDisplay {
	private:
		float m_h;
		float m_t;
		float m_p;
		Pogoda &pog;
	public:
		PogodaObs(Pogoda &p):pog(p){
			pog.registerOb(this);
		}
		void show(){
			cout << "_____PogodaObservator_____" << endl;
			cout << "humidity: " << m_h << endl;
			cout << "temparature: " << m_t << endl;
			cout << "pressure: " << m_p << endl;
			cout << "__________________________" << endl;
		}
		void update(float h, float t, float p){
			m_h=h;
			m_t=t;
			m_p=p;
		}
};

int main(){
	Pogoda *p = new Pogoda;
	// trzeba stworzyc observatora
	PogodaObs *obs = new PogodaObs(*p);
	
	p->data(10.2,28.2,1001);
	p->data(12,22.2,998);
	p->data(9,23,1011);
	
	
	return 0;
}
