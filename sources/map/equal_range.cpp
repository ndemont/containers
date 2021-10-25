#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator, NAMESPACE::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;

	return 0;
}