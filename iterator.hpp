
#ifndef VECTOR_vector_iterator_HPP
# define VECTOR_vector_iterator_HPP

# include "iterator_traits.hpp"
# include <cstddef>

namespace ft
{

	struct output_iterator_tag {};
	//struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	//struct random_access_iterator_tag {};

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
class iterator : public Category
{
	public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		iterator(void) {};
		iterator(value_type *x) : m_iterator(x) {};
		iterator(iterator_category const & x) : m_iterator(x.m_iterator) {};
		~iterator(void){};
	
	private:
		T*	m_iterator;
};

};

#endif