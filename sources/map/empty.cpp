#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
		mymap.erase(mymap.begin());
	}

	return 0;
}