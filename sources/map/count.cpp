#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>	mymap;
	char						c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of mymap." << std::endl;
		else
			std::cout << " is not an element of mymap." << std::endl;
	}

	return 0;
}