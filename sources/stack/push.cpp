#include "checker.hpp"

int	main(void)
{
	NAMESPACE::stack<TYPE>	mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << std::endl;

	return 0;
}