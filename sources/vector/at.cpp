#include "checker.hpp"
#include <iostream>
#include <string>

int	main(void)
{
  NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i = 0; i < myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i = 0; i < myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << std::endl;

  return 0;
}