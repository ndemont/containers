#include "checker.hpp"

int	main(void)
{
  NAMESPACE::vector<TYPE> myvector;
  int					            myint = 10;

  do {
    myint--;
    myvector.push_back(myint);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers." << std::endl;

  return 0;
}