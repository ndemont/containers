#include "vector.hpp"

int		main(void)
{
	ft::vector<int>	array1(5, 12);
	ft::vector<int>	array2(10, 2);

	std::cout << "Array 1" << std::endl;
	for (size_t i = 0; i < array1.size(); i++)
		std::cout << array1.at(i) << std::endl;
	std::cout << "Array 2" << std::endl;
	for (size_t i = 0; i < array2.size(); i++)
		std::cout << array2.at(i) << std::endl;
	//array1 = array2;
	std::cout << "New Array 1" << std::endl;
	for (size_t i = 0; i < array1.size(); i++)
		std::cout << array1.at(i) << std::endl;
	std::cout << std::endl;
	ft::vector<int>::iterator	first(array1.begin());
	ft::vector<int>::iterator	last(array1.end());
	ft::vector<int>	array4(first, last);
	std::cout << "Array 4" << std::endl;
	for (size_t i = 0; i < 15; i++)
		std::cout << array4.at(i) << std::endl;
	return 0;
}