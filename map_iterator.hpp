
#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "iterator.hpp"
# include <cstddef>

namespace ft
{

template <class T>
class const_map_iterator;

template <class T>
class map_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef	ptrdiff_t								difference_type;
		typedef size_t									size_type;

		map_iterator(void) {};
		map_iterator(value_type *x) : m_iterator(x) {};
		map_iterator(map_iterator const & x) : m_iterator(x.m_iterator) {};
		map_iterator(const_map_iterator<T> const & x) : m_iterator(x.base()) {};
		~map_iterator(void){};

		map_iterator&		operator=(const map_iterator& x) { m_iterator = x.m_iterator; return *this; }
		
		bool					operator==(const map_iterator& x) const { return (m_iterator == x.base()); }
		bool					operator!=(const map_iterator& x) const { return (m_iterator != x.base()); }

		reference				operator*(void) const { return *m_iterator; }
		pointer					operator->(void) const { return	&(*m_iterator); }

		map_iterator&		operator++(void) { m_iterator++; return *this; }
		map_iterator			operator++(int)  { return map_iterator(m_iterator++); }
		map_iterator&		operator--(void) { m_iterator--; return *this; }
		map_iterator			operator--(int)  { return map_iterator(m_iterator--); }

		map_iterator			operator+(difference_type n) { return map_iterator(m_iterator + n); }
		map_iterator			operator+(difference_type n) const { return map_iterator	(m_iterator + n); }
		friend map_iterator	operator+(difference_type n, const map_iterator& x) { return map_iterator(n + x.base()); }

		template <class U>
		friend difference_type	operator-(const map_iterator& lhs, const map_iterator<U>& rhs) { return (lhs.m_iterator - rhs.m_iterator); }
		
		map_iterator			operator-(difference_type n) { return map_iterator(m_iterator - n); }
		map_iterator			operator-(difference_type n) const { return map_iterator(m_iterator - n); }
		
		bool					operator<(const map_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool					operator>(const map_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool					operator<=(const map_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool					operator>=(const map_iterator& x) const { return (m_iterator >= x.m_iterator); }

		map_iterator&		operator+=(const map_iterator& x) { return (m_iterator += x.m_iterator); }
		map_iterator&		operator+=(size_type n) { m_iterator += n; return *this; }
		map_iterator&		operator-=(const map_iterator& x) { return (m_iterator -= x.m_iterator); }
		map_iterator&		operator-=(size_type n) { m_iterator -= n; return *this; } 
		
		reference				operator[](difference_type n) const { return (m_iterator[n]); }

		value_type*				base() const {return m_iterator;};

	private:
		value_type*	m_iterator;
};

template <class T>
class const_map_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T			value_type;
		typedef const T*	pointer;
		typedef const T&	reference;
		typedef	ptrdiff_t	difference_type;
		typedef size_t		size_type;

		const_map_iterator(void) {};
		const_map_iterator(value_type *x) : m_iterator(x) {};
		const_map_iterator(const_map_iterator const & x) : m_iterator(x.m_iterator) {};
		const_map_iterator(map_iterator<T> const & x) : m_iterator(x.base()) {};
		~const_map_iterator(void){};

		const_map_iterator&			operator=(const const_map_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool							operator==(const const_map_iterator& x) const { return (m_iterator == x.base()); }
		bool							operator!=(const const_map_iterator& x) const { return (m_iterator != x.m_iterator); }

		reference						operator*(void) const { return *m_iterator; }
		pointer							operator->(void) const { return	&(*m_iterator); }

		const_map_iterator&			operator++(void) { m_iterator++; return *this; }
		const_map_iterator			operator++(int)  { return const_map_iterator(m_iterator++); }
		const_map_iterator&			operator--(void) { m_iterator--; return *this; }
		const_map_iterator			operator--(int)  { return const_map_iterator(m_iterator--); }


		const_map_iterator			operator+(difference_type n) { return const_map_iterator(m_iterator + n); }
		const_map_iterator			operator+(difference_type n) const { return const_map_iterator(m_iterator + n); }
		friend const_map_iterator	operator+(difference_type n, const const_map_iterator& x) { return const_map_iterator(n + x.base()); }
		
		template <class U>
		friend difference_type			operator-(const const_map_iterator& lhs, const const_map_iterator<U>& rhs) { return (lhs.m_iterator - rhs.base()); }
		const_map_iterator&			operator-(difference_type n) { m_iterator = m_iterator - n; return *this; }
		const_map_iterator			operator-(difference_type n) const { return const_map_iterator(m_iterator - n); }
		
		bool							operator<(const const_map_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool							operator>(const const_map_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool							operator<=(const const_map_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool							operator>=(const const_map_iterator& x) const { return (m_iterator >= x.m_iterator); }

		friend const_map_iterator& operator+(size_type n, const const_map_iterator& rhs) { const_map_iterator<T> *plus = rhs.m_iterator + n; return *plus; }

		const_map_iterator&			operator+=(const const_map_iterator& x) { return (m_iterator += x.m_iterator); }
		const_map_iterator&			operator+=(size_type n){ m_iterator += n; return *this; }
		const_map_iterator&			operator-=(const const_map_iterator& x) { return (m_iterator -= x.m_iterator); }
		const_map_iterator&			operator-=(size_type n) { m_iterator -= n; return *this; }
		
		reference						operator[](difference_type n) const { return (m_iterator[n]); }

		value_type*						base() const {return m_iterator;};


	private:
		value_type*	m_iterator;
};

};

#endif