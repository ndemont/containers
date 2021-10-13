#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft 
{

// template <class T, class Key, class Compare = std::less<Key> > 
// struct node_less : std::binary_function <T, T, bool> 
// {
// 	bool operator() (const T& x, const T& y) const 
//   	{
// 		return (!Compare(x, y) && !Compare(y, x));
// 	}
// };

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (pred((*first1).first , (*first2).first) || pred((*first2).first , (*first1).first))
			return false;
		if (pred((*first1).second , (*first2).second) || pred((*first2).second , (*first1).second))
			return false;
		++first1;
		++first2;
	}
	return true;
}
};
#endif