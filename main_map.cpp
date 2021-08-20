#include "map.hpp"

int		main(void)
{
	ft::map<char, int>	tree1;

	tree1['a'] = 10;
	std::cout << tree1['a'] << std::endl;
	tree1['b'] = 30;
	tree1['c'] = 50;
	tree1['d'] = 70;

	std::cout << tree1['a'] << std::endl;
	std::cout << tree1['b'] << std::endl;
	std::cout << tree1['c'] << std::endl;
	std::cout << tree1['d'] << std::endl;
	return (0);
}