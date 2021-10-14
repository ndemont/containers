#ifndef RANDOM_ACCESS_ITERATOR_TAG_HPP
# define RANDOM_ACCESS_ITERATOR_TAG_HPP

// # include <cstddef>
// # include "iterator_traits.hpp"
// # include "input_iterator.hpp"
// # include "iterator.hpp"
// # include "reverse_iterator.hpp"

// namespace ft
// {

// template <typename T>
// class  random_access_iterator_tag : public input_iterator<T>
// {
// 	public:
// 		random_access_iterator_tag(void) {};
// 		random_access_iterator_tag(T* value) : m_iterator(value) {};
// 		random_access_iterator_tag(const  random_access_iterator_tag & x) { *this = x; };
// 		~random_access_iterator_tag(void){};
		
// 		random_access_iterator_tag&		operator=(const  random_access_iterator_tag& x) { m_iterator = x.m_iterator; return *this; }

// 		bool							operator==(const  random_access_iterator_tag& x) const { return (m_iterator != x.m_iterator); }
// 		bool							operator!=(const  random_access_iterator_tag& x) const { return (m_iterator != x.m_iterator); }

// 		T&								operator*(void) const { return *m_iterator; }
// 		T*								operator->(void) const { return	m_iterator; }

// 		random_access_iterator_tag<T>&	operator++(void) { m_iterator++; return *this; }
// 		random_access_iterator_tag<T>	operator++(int) { ++m_iterator; return *this; }
// 		random_access_iterator_tag<T>&	operator--(void) { m_iterator--; return *this; }
// 		random_access_iterator_tag<T>	operator--(int) { --m_iterator; return *this; }
		
// 		random_access_iterator_tag<T>	operator+(ptrdiff_t n) const { return  random_access_iterator_tag(m_iterator + n); }
// 		random_access_iterator_tag<T>	operator-(ptrdiff_t n) const { return  random_access_iterator_tag(m_iterator - n); }
// 		random_access_iterator_tag<T>	operator-(const  random_access_iterator_tag& x) const { return  random_access_iterator_tag(m_iterator - x.m_iterator); }

// 		bool							operator<(const  random_access_iterator_tag& x) const { return (m_iterator < x.m_iterator); }
// 		bool							operator>(const  random_access_iterator_tag& x) const { return (m_iterator > x.m_iterator); }
// 		bool							operator<=(const  random_access_iterator_tag& x) const { return (m_iterator <= x.m_iterator); }
// 		bool							operator>=(const  random_access_iterator_tag& x) const { return (m_iterator >= x.m_iterator); }

// 		random_access_iterator_tag<T>&	operator+=(ptrdiff_t n) { m_iterator += n; return *this; }
// 		random_access_iterator_tag<T>&	operator-=(ptrdiff_t n) { m_iterator -= n; return *this; }

// 		T&								operator[](ptrdiff_t n) const { return (m_iterator[n]); }

// 	private:
// 		T*	m_iterator;
// };
// };

#endif