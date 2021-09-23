
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "iterator.hpp"
# include <cstddef>

namespace ft
{

template <class T>
class const_vector_iterator;

template <class T>
class vector_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef	ptrdiff_t								difference_type;
		typedef size_t									size_type;

		vector_iterator(void) {};
		vector_iterator(value_type *x) : m_iterator(x) {};
		vector_iterator(vector_iterator const & x) : m_iterator(x.m_iterator) {};
		vector_iterator(const_vector_iterator<T> const & x) : m_iterator(x.base()) {};
		~vector_iterator(void){};

		vector_iterator&		operator=(const vector_iterator& x) { m_iterator = x.m_iterator; return *this; }
		
		bool					operator==(const vector_iterator& x) const { return (m_iterator == x.base()); }
		bool					operator!=(const vector_iterator& x) const { return (m_iterator != x.base()); }

		reference				operator*(void) const { return *m_iterator; }
		pointer					operator->(void) const { return	&(*m_iterator); }

		vector_iterator&		operator++(void) { m_iterator++; return *this; }
		vector_iterator			operator++(int)  { return vector_iterator(m_iterator++); }
		vector_iterator&		operator--(void) { m_iterator--; return *this; }
		vector_iterator			operator--(int)  { return vector_iterator(m_iterator--); }

		vector_iterator			operator+(difference_type n) { return vector_iterator(m_iterator + n); }
		vector_iterator&		operator+(difference_type n) const { return vector_iterator	(m_iterator + n); }
		friend vector_iterator	operator+(difference_type n, const vector_iterator& x) { return vector_iterator(n + x.base()); }

		template <class U>
		friend difference_type	operator-(const vector_iterator& lhs, const vector_iterator<U>& rhs) { return (lhs.m_iterator - rhs.m_iterator); }
		vector_iterator&		operator-(difference_type n) { m_iterator = m_iterator - n; return *this; }
		vector_iterator			operator-(difference_type n) const { return vector_iterator(m_iterator - n); }
		
		bool					operator<(const vector_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool					operator>(const vector_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool					operator<=(const vector_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool					operator>=(const vector_iterator& x) const { return (m_iterator >= x.m_iterator); }

		vector_iterator&		operator+=(const vector_iterator& x) { return (m_iterator += x.m_iterator); }
		vector_iterator&		operator+=(size_type n) { m_iterator += n; return *this; }
		vector_iterator&		operator-=(const vector_iterator& x) { return (m_iterator -= x.m_iterator); }
		vector_iterator&		operator-=(size_type n) { m_iterator -= n; return *this; } 
		
		reference				operator[](difference_type n) const { return (m_iterator[n]); }

		value_type*				base() const {return m_iterator;};

	private:
		value_type*	m_iterator;
};

template <class T>
class const_vector_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T			value_type;
		typedef const T*	pointer;
		typedef const T&	reference;
		typedef	ptrdiff_t	difference_type;
		typedef size_t		size_type;

		const_vector_iterator(void) {};
		const_vector_iterator(value_type *x) : m_iterator(x) {};
		const_vector_iterator(const_vector_iterator const & x) : m_iterator(x.m_iterator) {};
		const_vector_iterator(vector_iterator<T> const & x) : m_iterator(x.base()) {};
		~const_vector_iterator(void){};

		const_vector_iterator&			operator=(const const_vector_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool							operator==(const const_vector_iterator& x) const { return (m_iterator == x.base()); }
		bool							operator!=(const const_vector_iterator& x) const { return (m_iterator != x.m_iterator); }

		reference						operator*(void) const { return *m_iterator; }
		pointer							operator->(void) const { return	&(*m_iterator); }

		const_vector_iterator&			operator++(void) { m_iterator++; return *this; }
		const_vector_iterator			operator++(int)  { return const_vector_iterator(m_iterator++); }
		const_vector_iterator&			operator--(void) { m_iterator--; return *this; }
		const_vector_iterator			operator--(int)  { return const_vector_iterator(m_iterator--); }


		const_vector_iterator			operator+(difference_type n) { return const_vector_iterator(m_iterator + n); }
		const_vector_iterator&			operator+(difference_type n) const { return const_vector_iterator(m_iterator + n); }
		friend const_vector_iterator	operator+(difference_type n, const const_vector_iterator& x) { return const_vector_iterator(n + x.base()); }
		
		template <class U>
		friend difference_type			operator-(const const_vector_iterator& lhs, const const_vector_iterator<U>& rhs) { return (lhs.m_iterator - rhs.base()); }
		const_vector_iterator&			operator-(difference_type n) { m_iterator = m_iterator - n; return *this; }
		const_vector_iterator			operator-(difference_type n) const { return const_vector_iterator(m_iterator - n); }
		
		bool							operator<(const const_vector_iterator& x) const { return (m_iterator < x.m_iterator); }
		bool							operator>(const const_vector_iterator& x) const { return (m_iterator > x.m_iterator); }
		bool							operator<=(const const_vector_iterator& x) const { return (m_iterator <= x.m_iterator); }
		bool							operator>=(const const_vector_iterator& x) const { return (m_iterator >= x.m_iterator); }



		const_vector_iterator&			operator+=(const const_vector_iterator& x) { return (m_iterator += x.m_iterator); }
		const_vector_iterator&			operator+=(size_type n){ m_iterator += n; return *this; }
		const_vector_iterator&			operator-=(const const_vector_iterator& x) { return (m_iterator -= x.m_iterator); }
		const_vector_iterator&			operator-=(size_type n) { m_iterator -= n; return *this; }
		
		reference						operator[](difference_type n) const { return (m_iterator[n]); }

		value_type*						base() const {return m_iterator;};


	private:
		value_type*	m_iterator;
};

};

#endif