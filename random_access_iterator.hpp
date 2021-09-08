
#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
class iterator
{

	class const_iterator;

	public:
		typedef T			value_type;
		typedef size_t		size_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		iterator(void) {};
		iterator(value_type *x) : m_iterator(x) {};
		iterator(iterator const & x) : m_iterator(x.m_iterator) {};
		~iterator(void){};

		value_type*	get_iterator(void) const
		{
			return m_iterator;
		}

		iterator&	operator=(const iterator& x)
		{
			m_iterator = x.m_iterator;
			return *this;
		}

		bool	operator==(const iterator& x) const
		{
			return (m_iterator != x.m_iterator);
		}

		bool	operator==(const const_iterator& x) const
		{
			return (m_iterator != x.m_iterator);
		}
		

		bool	operator!=(const iterator& x) const
		{
			return (m_iterator != x.m_iterator);
		}

		bool	operator!=(const const_iterator& x) const
		{
			return (m_iterator != x.m_iterator);
		}

		reference	operator*(void) const
		{
			return *m_iterator;
		}

		pointer operator->(void) const
		{
			return	&(*m_iterator);
		}

		iterator&	operator++(void)
		{
			m_iterator++;
			return *this;
		}
		iterator	operator++(int)
		{
			iterator	tmp(*this); 
			m_iterator++; 
			return tmp;
		}
				iterator&	operator--(void)
		{
			m_iterator--;
			return *this;
		}
		iterator	operator--(int)
		{
			--m_iterator;
			return *this;
		}


		iterator&	operator+(size_type n)
		{
			m_iterator = m_iterator + n;
			return *this;
		}

		iterator operator+(difference_type n) const
		{
			iterator	plus(m_iterator - n);
			return plus;
		}

		iterator&	operator-(size_type n)
		{
			m_iterator = m_iterator - n;
			return *this;
		}

		iterator operator-(difference_type n) const
		{
			iterator	minus(m_iterator + n);
			return minus;
		}

		size_type	operator-(const iterator& x)
		{
			return (m_iterator - x.m_iterator);
		}

		friend bool	operator<(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.m_iterator < rhs.m_iterator);
		}

		friend bool	operator>(const iterator& lhs, const iterator& rhs)
		{
			return (lhs.m_iterator > rhs.m_iterator);
		}

		friend iterator& operator+(size_type n, const iterator& rhs)
		{
			ft::iterator<iterator_category, value_type> *plus = NULL;
			*plus = rhs.m_iterator + n;
			return *plus;
		}

		bool	operator<=(const iterator& x)
		{
			return (m_iterator <= x.m_iterator);
		}
		bool	operator>=(const iterator& x)
		{
			return (m_iterator >= x.m_iterator);
		}

		iterator&	operator+=(const iterator& x)
		{
			return (m_iterator += x.m_iterator);
		}

		iterator&	operator+=(size_type n)
		{
			m_iterator += n;
			return *this;
		}

		iterator&	operator-=(const iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		iterator&	operator-=(size_type n)
		{
			m_iterator -= n;
			return *this;
		}

		reference	operator[](difference_type n) const
		{
			return (m_iterator[n]);
		}

	private:
		value_type*	m_iterator;
};

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
class const_iterator
{
	public:
		typedef T			value_type;
		typedef size_t		size_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	const_iterator_category;

		const_iterator(void) {};
		const_iterator(value_type *x) : m_const_iterator(x) {};
		const_iterator(const const_iterator & x) : m_const_iterator(x.m_const_iterator) {};
		const_iterator(const iterator<const_iterator_category, value_type> & x) : m_const_iterator(x.get_iterator()) {};
		~const_iterator(void){};

		value_type*	get_const_iterator(void) const
		{
			return m_const_iterator;
		}

		const_iterator&	operator=(const const_iterator& x)
		{
			m_const_iterator = x.m_const_iterator;
			return *this;
		}

		bool	operator==(const const_iterator& x) const
		{
			return (m_const_iterator != x.m_const_iterator);
		}
		bool	operator!=(const const_iterator& x) const
		{
			return (m_const_iterator != x.m_const_iterator);
		}

		reference	operator*(void) const
		{
			return *m_const_iterator;
		}
		reference	operator->(void)
		{
			return *m_const_iterator;
		}


		const_iterator&	operator++(void)
		{
			m_const_iterator++;
			return *this;
		}
		const_iterator	operator++(int)
		{
			const_iterator	tmp(*this); 
			m_const_iterator++; 
			return tmp;
		}
				const_iterator&	operator--(void)
		{
			m_const_iterator--;
			return *this;
		}
		const_iterator	operator--(int)
		{
			--m_const_iterator;
			return *this;
		}

		const_iterator&	operator+(size_type n)
		{
			m_const_iterator = m_const_iterator + n;
			return *this;
		}

		const_iterator operator+(difference_type n) const
		{
			const_iterator	plus(m_const_iterator - n);
			return plus;
		}

		const_iterator&	operator-(size_type n)
		{
			return (m_const_iterator - n);
		}

		const_iterator operator-(difference_type n) const
		{
			const_iterator	minus(m_const_iterator + n);
			return minus;
		}

		size_type	operator-(const const_iterator& x) const
		{
			return (m_const_iterator - x.m_const_iterator);
		}

		friend bool	operator<(const const_iterator& lhs, const const_iterator& rhs)
		{
			return (lhs.m_const_iterator < rhs.m_const_iterator);
		}

		friend const_iterator& operator+(size_type n, const const_iterator& rhs)
		{
			return (rhs + n);
		}

		friend bool	operator>(const const_iterator& lhs, const const_iterator& rhs)
		{
			return (lhs.m_const_iterator > rhs.m_const_iterator);
		}
		bool	operator<=(const const_iterator& x)
		{
			return (m_const_iterator <= x.m_const_iterator);
		}
		bool	operator>=(const const_iterator& x)
		{
			return (m_const_iterator >= x.m_const_iterator);
		}

		const_iterator&	operator+=(const const_iterator& x)
		{
			return (m_const_iterator += x.m_const_iterator);
		}

		const_iterator&	operator+=(size_type n)
		{
			m_const_iterator += n;
			return *this;
		}

		const_iterator&	operator-=(const const_iterator& x)
		{
			return (m_const_iterator -= x.m_const_iterator);
		}

		const_iterator&	operator-=(size_type n)
		{
			m_const_iterator -= n;
			return *this;
		}

		reference	operator[](difference_type n) const
		{
			return (m_const_iterator[n]);
		}

	private:
		value_type*	m_const_iterator;
};


};

#endif