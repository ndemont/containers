#include "checker.hpp"

int	main(void)
{
  NAMESPACE::vector<TYPE> 			myvector(3,100);
  namespace::vector<TYPE>::iterator	it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  NAMESPACE::vector<TYPE>	anothervector(2,400);
  myvector.insert(it + 2, anothervector.begin(), anothervector.end());

  int myarray[] = { 501,502,503 };
  myvector.insert(myvector.begin(), myarray, myarray + 3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << std::endl;

  