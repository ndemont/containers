#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>	mymap;

	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << std::endl;

	return 0;
}
