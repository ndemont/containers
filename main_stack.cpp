#include "stack.hpp"

#include <iostream>

int		main(void)
{
	ft::stack<int, ft::vector<int> >	files;
	ft::stack<int, ft::vector<int> >	cards;

	files.push(21);
	std::cout << files.top() << std::endl;
	files.push(12);
	std::cout << files.top() << std::endl;
	files.push(15);
	std::cout << files.top() << std::endl;
	files.push(1);
	std::cout << files.top() << std::endl;
	files.pop();
	std::cout << files.top() << std::endl;
	std::cout << "The number of files in the stack FILES is: " << files.size() << std::endl;
	std::cout << "The first file in the stack FILES is: " << files.top() << std::endl;

	cards.push(201);
	cards.push(102);
	cards.push(105);
	cards.push(1035);
	cards.push(1305);
	cards.push(105);
	cards.push(10);
	std::cout << "The number of files in the stack CARDS is: " << cards.size() << std::endl;
	std::cout << "The first file in the stack CARDS is: " << cards.top() << std::endl;
	std::cout << "Files < Cards = " << (files < cards) << std::endl;
	std::cout << "Files > Cards = " << (files > cards) << std::endl;
	return (0);
}