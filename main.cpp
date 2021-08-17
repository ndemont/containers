#include "vector.hpp"

int		main(void)
{
	vector<int>				array1(5, 12);
	vector<int>				array2(10, 2);
	vector<int>				array3(10, 2);

	for (int i = 0; i < 10; i++)
		std::cout << array2[i] << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array1[i] << std::endl;
	array3 = array1;
	array1 = array2;
	for (int i = 0; i < 10; i++)
		std::cout << array1[i] << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << array3[i] << std::endl;
	vector<int>::iterator	begin(&array1[0]);
	vector<int>::iterator	end(&array1[4]);
	vector<int>	array4(begin, end);
	for (int i = 0; i < 4; i++)
		std::cout << array4[i] << std::endl;
	return 0;
}