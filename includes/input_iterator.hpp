#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

// # include <cstddef>
// # include "binary_function.hpp"
// # include "equal.hpp"
// # include "iterator.hpp"
// # include "iterator_traits.hpp"
// # include "lexicographical_compare.hpp"
// # include "map.hpp"
// # include "map_iterator.hpp"
// # include "pair.hpp"
// # include "random_access_iterator_tag.hpp"
// # include "reverse_iterator.hpp"
// # include "stack.hpp"
// # include "vector.hpp"
// # include "vector_iterator.hpp"

// namespace ft
// {

// template <typename T>
// class input_iterator
// {
// 	public:
// 		input_iterator(void) {};
// 		input_iterator(T* value) : m_iterator(value) {};
// 		input_iterator(const input_iterator & x) { *this = x; };
// 		~input_iterator(void){};
// 		input_iterator&	operator=(const input_iterator& x) { m_iterator = x.m_iterator; return *this; }

// 		bool					operator==(const input_iterator& x) const { return (m_iterator != x.m_iterator); }
// 		bool					operator!=(const input_iterator& x) const { return (m_iterator != x.m_iterator); }

// 		T&						operator*(void) const { return *m_iterator; }
// 		T*						operator->(void) const { return	m_iterator; }

// 		input_iterator<T>&		operator++(void) { m_iterator++; return *this; }
// 		input_iterator<T>		operator++(int) { ++m_iterator; return *this; }

// 		bool					operator<(const input_iterator& x) const { return (m_iterator < x.m_iterator); }
// 		bool					operator>(const input_iterator& x) const { return (m_iterator > x.m_iterator); }
// 		bool					operator<=(const input_iterator& x) const { return (m_iterator <= x.m_iterator); }
// 		bool					operator>=(const input_iterator& x) const { return (m_iterator >= x.m_iterator); }

// 		T&						operator[](ptrdiff_t n) const { return (m_iterator[n]); }

// 	private:
// 		T*	m_iterator;
// };
// };

#endif