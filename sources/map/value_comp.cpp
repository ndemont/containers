#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:" << std::endl;

	NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( mymap.value_comp()(*it++, highest) );

	return 0;
}