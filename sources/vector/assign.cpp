#include "checker.hpp"


int	main(void)
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  NAMESPACE::vector<int>::iterator it;
  it = first.begin()+1;

  second.assign (it,first.end() -1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign(myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << std::endl;
  std::cout << "Size of second: " << int (second.size()) << std::endl;
  std::cout << "Size of third: " << int (third.size()) << std::endl;
  return 0;
}