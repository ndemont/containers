#include "checker.hpp"

int main (void)
{
	NAMESPACE::vector<TYPE> myvector;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << std::endl;

	return 0;
}