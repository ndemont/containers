#include "checker.hpp"

int	main(void)
{
	NAMESPACE::vector<TYPE> myvector;

	// set some content in the vector:
	for (int i = 0; i < 100; i++)
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << std::endl;
	std::cout << "capacity: " << myvector.capacity() << std::endl;
	std::cout << "max_size: " << myvector.max_size() << std::endl;

	return 0;
}