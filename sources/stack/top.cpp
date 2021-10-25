#include "checker.hpp"

int	main(void)
{
	NAMESPACE::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << std::endl;

	return 0;
}