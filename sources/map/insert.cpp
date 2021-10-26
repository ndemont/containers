#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert(NAMESPACE::pair<char,int>('a',100) );
	mymap.insert(NAMESPACE::pair<char,int>('z',200) );

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool>	ret;
	ret = mymap.insert(NAMESPACE::pair<char,int>('z',500));
	if (ret.second == false) 
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}

	// second insert function version (with hint position):
	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	mymap.insert(it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert(it, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	NAMESPACE::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:" << std::endl;
	for (it = mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "anothermap contains:" << std::endl;
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	return 0;
}