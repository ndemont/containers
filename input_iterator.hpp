#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"
# include "iterator.hpp"

namespace ft
{

template <typename T>
class input_iterator
{
	public:
		input_iterator(void) {};
		input_iterator(T* value) : m_iterator(value) {};
		input_iterator(const input_iterator & x) { *this = x; };
		~input_iterator(void){};
		input_iterator&	operator=(const input_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool					operator==(const input_iterator& x) const { return (m_iterator != x.m_iterator); }
		bool					operator!=(const input_iterator& x) const { return (m_iterator != x.m_iterator); }

		T&						operator*(void) const { return *m_iterator; }
		T*						operator->(void) const { return	m_iterator; }

		input_iterator<T>&		operator++(void) { m_iterator++; return *this; }
		input_iterator<T>		operator++(int) { ++m_iterator; return *this; }

		bool					operator<(const input_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool					operator>(const input_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool					operator<=(const input_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool					operator>=(const input_iterator& x) const { return (m_iterator >= x.m_iterator); }

		T&						operator[](ptrdiff_t n) const { return (m_iterator[n]); }

	private:
		T*	m_iterator;
};
};

#endif