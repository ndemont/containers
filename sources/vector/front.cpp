#include "checker.hpp"

int main(void)
{
	NAMESPACE::vector<TYPE> myvector;

	myvector.push_back(78);
	std::cout << "myvector.front() is now " << myvector.front() << std::endl;

	myvector.push_back(16);
	std::cout << "myvector.front() is now " << myvector.front() << std::endl;

	myvector.front() -= myvector.back();
	std::cout << "myvector.front() is now " << myvector.front() << std::endl;

	return 0;
}