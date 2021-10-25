#include "checker.hpp"

int	main(void)
{
	NAMESPACE::map<char,int>	foo;
	NAMESPACE::map<char,int>	bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:" << std::endl;
	for (NAMESPACE::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "bar contains:\n";
	for (NAMESPACE::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}