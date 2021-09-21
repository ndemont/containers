
#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"
# include <cstddef>

namespace ft
{
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator : public Category
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};
};

#endif