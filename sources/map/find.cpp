#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>			mymap;
	NAMESPACE::map<char,int>::iterator	it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << std::endl;
	std::cout << "a => " << mymap.find('a')->second << std::endl;
	std::cout << "c => " << mymap.find('c')->second << std::endl;
	std::cout << "d => " << mymap.find('d')->second << std::endl;

	return 0;
}