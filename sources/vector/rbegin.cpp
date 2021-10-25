#include "checker.hpp"

int main (void)
{
	NAMESPACE::vector<TYPE> myvector (5);  // 5 default-constructed ints

	int i=0;

	NAMESPACE::vector<TYPE>::reverse_iterator rit = myvector.rbegin();
	for(; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<TYPE>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}