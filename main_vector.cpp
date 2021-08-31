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
	ft::vector<int>::iterator	first(array1.begin());
	ft::vector<int>::iterator	last(array1.end());
	ft::vector<int>	array3(first, last);
	std::cout << "Array 3" << std::endl;
	for (size_t i = 0; i < array3.size(); i++)
		std::cout << array3.at(i) << std::endl;
	ft::vector<int> array4 = array2;
	std::cout << "Array 4" << std::endl;
	for (size_t i = 0; i < array4.size(); i++)
		std::cout << array4[i] << std::endl;
	std::cout << "Array 4" << std::endl;
	array4.resize(12, 6);
	for (size_t i = 0; i < array4.size(); i++)
		std::cout << array4.at(i) << std::endl;
	std::cout << array4.empty() << std::endl;
	std::cout << "front = " << array4.front() << std::endl;
	std::cout << "back = " << array4.back() << std::endl;
	ft::reverse_iterator<ft::vector<int>::iterator>	fst(array4.rbegin());
	ft::reverse_iterator<ft::vector<int>::iterator>	lst(array4.rend());
	for (ft::reverse_iterator<ft::vector<int>::iterator> i = fst; i < lst; i++)
		std::cout << *i << std::endl;
	return 0;
}