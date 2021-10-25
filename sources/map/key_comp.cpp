#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>				mymap;
	NAMESPACE::map<char,int>::key_compare	mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";
	char highest = mymap.rbegin()->first;     // key value of last element

	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( mycomp((*it++).first, highest) );

	std::cout << std::endl;

	return 0;
}