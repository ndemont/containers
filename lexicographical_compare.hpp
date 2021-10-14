#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft 
{

template <class T, class Compare> 
struct pair_less : std::binary_function <T,T,bool>
{
	bool operator() (const T& x, const T& y) const
	{ 
		if (Compare(x.first, y.first))
			return true;
		else if (Compare(y.first, x.first))
			return false;
		else if (Compare(x.second, y.second))
			return true;
		else
			return false;
	}
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
  while (first1 != last1)
  {
    if (first2 == last2 || *first2 < *first1)
		return false;
    else if (*first1 < *first2) 
		return true;
    ++first1;
	++first2;
  }
  return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

// template <class InputIterator1, class InputIterator2, class Compare>
// bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
// {
// 	while (first1 != last1)
// 	{
// 		if (first2 == last2 || comp((*first2).first, (*first1).first))
// 			return false;
// 		else if (comp((*first1).first, (*first2).first))
// 			return true;
// 		else if (comp((*first1).second, (*first2).second))
// 			return true;
// 		else if (comp((*first2).second, (*first1).second))
// 			return false;
// 		++first1;
// 		++first2;
// 	}
// 	return (first2 != last2);
// }

};
#endif