#include "checker.hpp"

int	main(void)
{
	NAMESPACE::vector<TYPE>	myints;
	std::cout << "0. size: " << myints.size() << std::endl;

	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	std::cout << "1. size: " << myints.size() << std::endl;

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << std::endl;

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << std::endl;

	return 0;
}