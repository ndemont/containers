#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>			mymap;
	NAMESPACE::map<char,int>::iterator	itlow;
	NAMESPACE::map<char,int>::iterator	itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (NAMESPACE::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	return 0;
}