#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include <cstddef>


namespace ft
{

//template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
//class const_iterator
//{
//	public:
//		typedef T			value_type;
//		typedef size_t		size_type;
//		typedef Distance	difference_type;
//		typedef Pointer		pointer;
//		typedef Reference	reference;
//		typedef Category	const_iterator_category;

//		const_iterator(void) {};
//		const_iterator(value_type *x) : m_const_iterator(x) {};
//		const_iterator(const const_iterator & x) : m_const_iterator(x.m_const_iterator) {};
//		const_iterator(const iterator & x) : m_const_iterator(x.get_iterator()) {};
//		~const_iterator(void){};

//		const_iterator&	operator=(const const_iterator& x)
//		{
//			m_const_iterator = x.m_const_iterator;
//			return *this;
//		}

//		bool	operator==(const const_iterator& x) const
//		{
//			return (m_const_iterator != x.m_const_iterator);
//		}
//		bool	operator!=(const const_iterator& x) const
//		{
//			return (m_const_iterator != x.m_const_iterator);
//		}

//		reference	operator*(void) const
//		{
//			return *m_const_iterator;
//		}
//		reference	operator->(void)
//		{
//			return *m_const_iterator;
//		}


//		const_iterator&	operator++(void)
//		{
//			m_const_iterator++;
//			return *this;
//		}
//		const_iterator	operator++(int)
//		{
//			const_iterator	tmp(*this); 
//			m_const_iterator++; 
//			return tmp;
//		}
//				const_iterator&	operator--(void)
//		{
//			m_const_iterator--;
//			return *this;
//		}
//		const_iterator	operator--(int)
//		{
//			--m_const_iterator;
//			return *this;
//		}

//		const_iterator&	operator+(size_type n)
//		{
//			m_const_iterator = m_const_iterator + n;
//			return *this;
//		}

//		const_iterator operator+(difference_type n) const
//		{
//			const_iterator	plus(m_const_iterator - n);
//			return plus;
//		}

//		const_iterator&	operator-(size_type n)
//		{
//			return (m_const_iterator - n);
//		}

//		const_iterator operator-(difference_type n) const
//		{
//			const_iterator	minus(m_const_iterator + n);
//			return minus;
//		}

//		size_type	operator-(const const_iterator& x) const
//		{
//			return (m_const_iterator - x.m_const_iterator);
//		}

//		friend bool	operator<(const const_iterator& lhs, const const_iterator& rhs)
//		{
//			return (lhs.m_const_iterator < rhs.m_const_iterator);
//		}

//		friend const_iterator& operator+(size_type n, const const_iterator& rhs)
//		{
//			return (rhs + n);
//		}

//		friend bool	operator>(const const_iterator& lhs, const const_iterator& rhs)
//		{
//			return (lhs.m_const_iterator > rhs.m_const_iterator);
//		}
//		bool	operator<=(const const_iterator& x)
//		{
//			return (m_const_iterator <= x.m_const_iterator);
//		}
//		bool	operator>=(const const_iterator& x)
//		{
//			return (m_const_iterator >= x.m_const_iterator);
//		}

//		const_iterator&	operator+=(const const_iterator& x)
//		{
//			return (m_const_iterator += x.m_const_iterator);
//		}

//		const_iterator&	operator+=(size_type n)
//		{
//			m_const_iterator += n;
//			return *this;
//		}

//		const_iterator&	operator-=(const const_iterator& x)
//		{
//			return (m_const_iterator -= x.m_const_iterator);
//		}

//		const_iterator&	operator-=(size_type n)
//		{
//			m_const_iterator -= n;
//			return *this;
//		}

//		reference	operator[](difference_type n) const
//		{
//			return (m_const_iterator[n]);
//		}

//	private:
//		value_type*	m_const_iterator;
//};


};

#endif