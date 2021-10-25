#include "checker.hpp"

int	main(void)
{
	NAMESPACE::stack<int>	mystack;
	int sum (0);

	for (int i = 1; i <= 10; i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << std::endl;

	return 0;
}