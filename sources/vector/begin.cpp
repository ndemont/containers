#include "checker.hpp"

int main (void)
{
	NAMESPACE::vector<TYPE> myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<TYPE>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}