#include "vector.hpp"
#include "random_access_iterator.hpp"
int		main(void)
{
	size_t	a1 = 5;
	size_t	a2 = 10;
	int		b1 = 12;
	int		b2 = 2;

	ft::vector<int>	array1(a1, b1);
	ft::vector<int>	array2(a2, b2);

	std::cout << "Array 1" << std::endl;
	for (size_t i = 0; i < array1.size(); i++)
		std::cout << array1.at(i) << std::endl;
	std::cout << "Array 2" << std::endl;
	for (size_t i = 0; i < array2.size(); i++)
		std::cout << array2.at(i) << std::endl;
	ft::vector<int>::iterator	first(array1.begin());
	//ft::vector<int>::const_iterator	first(array1.begin());
	ft::vector<int>::iterator	last(array1.end());
	//ft::vector<int>::const_iterator	last(array1.end());
	ft::vector<int>	array3(first, last);
	//std::cout << "Array 3" << std::endl;
	//for (; first < last; ++first)
	//	std::cout << *first << std::endl;
	//ft::vector<int> array4 = array2;
	//std::cout << "Array 4" << std::endl;
	//for (size_t i = 0; i < array4.size(); i++)
	//	std::cout << array4[i] << std::endl;
	//std::cout << "Array 4" << std::endl;
	//array4.resize(12, 6);
	//for (size_t i = 0; i < array4.size(); i++)
	//	std::cout << array4.at(i) << std::endl;
	//std::cout << array4.empty() << std::endl;
	//std::cout << "front = " << array4.front() << std::endl;
	//std::cout << "back = " << array4.back() << std::endl;
	//ft::reverse_iterator<ft::vector<int>::iterator>	fst(array4.rbegin());
	//ft::reverse_iterator<ft::vector<int>::iterator>	lst(array4.rend());
	//for (ft::reverse_iterator<ft::vector<int>::iterator> i = fst; i < lst; i++)
	//	std::cout << *i << std::endl;
	return 0;
}