#include "checker.hpp"

int		main(void)
{
	const int start_size = 7;
	NAMESPACE::vector<TYPE> vct(start_size, 20);
	NAMESPACE::vector<TYPE> vct2;
	NAMESPACE::vector<TYPE>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	vct.resize(10, 42);
	vct.resize(18, 43);
	vct.resize(10);
	vct.resize(23, 44);
	vct.resize(5);
	vct.reserve(5);
	vct.reserve(3);
	vct.resize(87);
	vct.resize(5);
	vct2 = vct;
	vct.reserve(vct.capacity() + 1);
	vct2.resize(0);
	return (0);
}