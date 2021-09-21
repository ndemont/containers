#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>
# include "input_iterator.hpp"
# include "iterator.hpp"

namespace ft
{

template <typename T>
class random_access_iterator : public input_iterator<T>
{
	public:
		random_access_iterator(void) {};
		random_access_iterator(T* value) : m_iterator(value) {};
		random_access_iterator(const random_access_iterator & x) { *this = x; };
		~random_access_iterator(void){};
		random_access_iterator&	operator=(const random_access_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool						operator==(const random_access_iterator& x) const { return (m_iterator != x.m_iterator); }
		bool						operator!=(const random_access_iterator& x) const { return (m_iterator != x.m_iterator); }

		T&							operator*(void) const { return *m_iterator; }
		T*							operator->(void) const { return	m_iterator; }

		random_access_iterator<T>&	operator++(void) { m_iterator++; return *this; }
		random_access_iterator<T>	operator++(int) { ++m_iterator; return *this; }
		random_access_iterator<T>&	operator--(void) { m_iterator--; return *this; }
		random_access_iterator<T>	operator--(int) { --m_iterator; return *this; }
		
		random_access_iterator<T>	operator+(ptrdiff_t n) const { return random_access_iterator(m_iterator + n); }
		random_access_iterator<T>	operator-(ptrdiff_t n) const { return random_access_iterator(m_iterator - n); }
		random_access_iterator<T>	operator-(const random_access_iterator& x) const { return random_access_iterator(m_iterator - x.m_iterator); }

		bool						operator<(const random_access_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool						operator>(const random_access_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool						operator<=(const random_access_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool						operator>=(const random_access_iterator& x) const { return (m_iterator >= x.m_iterator); }

		random_access_iterator<T>&	operator+=(ptrdiff_t n) { m_iterator += n; return *this; }
		random_access_iterator<T>&	operator-=(ptrdiff_t n) { m_iterator -= n; return *this; }

		T&							operator[](ptrdiff_t n) const { return (m_iterator[n]); }

	private:
		T*	m_iterator;
};
};

#endif