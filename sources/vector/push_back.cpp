#include "checker.hpp"

int	main(void)
{
  NAMESPACE::vector<TYPE>	myvector;
  int						myint;

  std::cout << "Please enter some integers (enter 0 to end):" << std::endl;

  do {
    std::cin >> myint;
    myvector.push_back (myint);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers." << std::endl;

  return 0;
}