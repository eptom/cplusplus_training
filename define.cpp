#include <iostream>
#include <vector>
 
#define SZESC 1+5
#define DZIEWIEC 8+1
 
#define MNOZENIE_1(a,b) a * b
#define MNOZENIE_2(a,b) (a) * (b)

#define FOREACH(i,v) for (i=v.begin(); i!=v.end(); ++i)
 
int main()
{
    std::cout << SZESC << " razy " << DZIEWIEC << " == "  << MNOZENIE_1(SZESC, DZIEWIEC) << std::endl;
    std::cout << SZESC << " razy " << DZIEWIEC << " == " << MNOZENIE_2(SZESC, DZIEWIEC) << std::endl;
    
    std::cout << "---------------------- \n";
    std::vector<int> v;
    std::vector<int>::iterator it;
	v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);
	
	FOREACH(it,v)
	{
	    std::cout << *it << "\n";
	}
    return 0;
}
