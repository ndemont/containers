
#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{

template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
class iterator
{
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

		iterator&	operator=(const iterator& x)
		{
			m_iterator = x.m_iterator;
			return *this;
		}

		bool	operator==(const iterator& x)
		{
			return (m_iterator != x.m_iterator);
		}
		bool	operator!=(const iterator& x)
		{
			return (m_iterator != x.m_iterator);
		}

		reference	operator*(void) const
		{
			return *m_iterator;
		}
		reference	operator->(void)
		{
			return *m_iterator;
		}


		iterator&	operator++(void)
		{
			m_iterator++;
			return *this;
		}
		iterator	operator++(int)
		{
			++m_iterator;
			return *this;
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
		// iterator&	operator+(size_type n, const iterator& x)
		// {
		// 	return (x.m_iterator + n);
		// }
		iterator&	operator-(size_type n)
		{
			return (m_iterator - n);
		}
		// iterator&	operator-(size_type n, const iterator& x)
		// {
		// 	return (x.m_iterator + n);
		// }
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
		iterator&	operator-=(const iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		reference	operator[](difference_type n) const
		{
			return (m_iterator[n]);
		}

	private:
		value_type*	m_iterator;
};

};

#endif