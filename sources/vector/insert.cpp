#include "checker.hpp"

template <typename T>
void	DisplayContainer(NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	NAMESPACE::vector<TYPE> vct(10);
	NAMESPACE::vector<TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	DisplayContainer(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	DisplayContainer(vct2);

	vct2.insert(vct2.end() - 2, 42);
	DisplayContainer(vct2);

	vct2.insert(vct2.end(), 2, 84);
	DisplayContainer(vct2);

	vct2.resize(4);
	DisplayContainer(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	DisplayContainer(vct2);

	DisplayContainer(vct);
	return (0);
}