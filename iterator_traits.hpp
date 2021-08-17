#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>

namespace ft
{
	template <typename Iterator>
	class iterator_traits
	{
		public:
			typedef Iterator::difference_type	difference_type;
			typedef Iterator::value_type		value_type;
			typedef Iterator::pointer			pointer;
			typedef Iterator::reference			reference;
			typedef Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T 							value_type;
			typedef T* 							pointer;
			typedef T& 							reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t					difference_type;
			typedef T 							value_type;
			typedef T* 							pointer;
			typedef T& 							reference;
			typedef random_access_iterator_tag	iterator_category;
	};
};

#endif