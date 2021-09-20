
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "iterator.hpp"
# include <cstddef>

namespace ft
{

template <class T>
class vector_iterator : public ft::random_access_iterator<T>
{

	public:
		typedef T			value_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef	ptrdiff_t	difference_type;
		typedef size_t		size_type;


		vector_iterator(void) {};
		vector_iterator(value_type *x) : m_iterator(x) {};
		vector_iterator(vector_iterator const & x) : m_iterator(x.m_iterator) {};
		~vector_iterator(void){};

		value_type*	get_vector_iterator(void) const
		{
			return m_iterator;
		}

		vector_iterator&	operator=(const vector_iterator& x)
		{
			m_iterator = x.m_iterator;
			return *this;
		}

		bool	operator==(const vector_iterator& x) const
		{
			return (m_iterator != x.m_iterator);
		}

		bool	operator!=(const vector_iterator& x) const
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

		vector_iterator&	operator++(void)
		{
			m_iterator++;
			return *this;
		}
		vector_iterator	operator++(int)
		{
			vector_iterator	tmp(*this); 
			m_iterator++; 
			return tmp;
		}
				vector_iterator&	operator--(void)
		{
			m_iterator--;
			return *this;
		}
		vector_iterator	operator--(int)
		{
			--m_iterator;
			return *this;
		}


		vector_iterator&	operator+(size_type n)
		{
			m_iterator = m_iterator + n;
			return *this;
		}

		vector_iterator operator+(difference_type n) const
		{
			vector_iterator	plus(m_iterator - n);
			return plus;
		}

		vector_iterator&	operator-(size_type n)
		{
			m_iterator = m_iterator - n;
			return *this;
		}

		vector_iterator operator-(difference_type n) const
		{
			vector_iterator	minus(m_iterator + n);
			return minus;
		}

		size_type	operator-(const vector_iterator& x)
		{
			return (m_iterator - x.m_iterator);
		}

		friend bool	operator<(const vector_iterator& lhs, const vector_iterator& rhs)
		{
			return (lhs.m_iterator < rhs.m_iterator);
		}

		friend bool	operator>(const vector_iterator& lhs, const vector_iterator& rhs)
		{
			return (lhs.m_iterator > rhs.m_iterator);
		}

		friend vector_iterator& operator+(size_type n, const vector_iterator& rhs)
		{
			vector_iterator<T> *plus = NULL;

			*plus = rhs.m_iterator + n;
			return *plus;
		}

		bool	operator<=(const vector_iterator& x)
		{
			return (m_iterator <= x.m_iterator);
		}
		bool	operator>=(const vector_iterator& x)
		{
			return (m_iterator >= x.m_iterator);
		}

		vector_iterator&	operator+=(const vector_iterator& x)
		{
			return (m_iterator += x.m_iterator);
		}

		vector_iterator&	operator+=(size_type n)
		{
			m_iterator += n;
			return *this;
		}

		vector_iterator&	operator-=(const vector_iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		vector_iterator&	operator-=(size_type n)
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

//template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
//class const_vector_iterator
//{
//	public:
//		typedef T			value_type;
//		typedef size_t		size_type;
//		typedef Distance	difference_type;
//		typedef Pointer		pointer;
//		typedef Reference	reference;
//		typedef Category	const_vector_iterator_category;

//		const_vector_iterator(void) {};
//		const_vector_iterator(value_type *x) : m_iterator(x) {};
//		const_vector_iterator(const const_vector_iterator & x) : m_iterator(x.m_iterator) {};
//		const_vector_iterator(const vector_iterator<const_vector_iterator_category, value_type> & x) : m_iterator(x.get_vector_iterator()) {};
//		~const_vector_iterator(void){};

//		value_type*	get_const_vector_iterator(void) const
//		{
//			return m_iterator;
//		}

//		const_vector_iterator&	operator=(const const_vector_iterator& x)
//		{
//			m_iterator = x.m_iterator;
//			return *this;
//		}

//		bool	operator==(const const_vector_iterator& x) const
//		{
//			return (m_iterator != x.m_iterator);
//		}
//		bool	operator!=(const const_vector_iterator& x) const
//		{
//			return (m_iterator != x.m_iterator);
//		}
//		bool	operator!=(const vector_iterator<Category, T>& x) const
//		{
//			return (m_iterator != x.m_iterator);
//		}

//		reference	operator*(void) const
//		{
//			return *m_iterator;
//		}
//		reference	operator->(void)
//		{
//			return *m_iterator;
//		}


//		const_vector_iterator&	operator++(void)
//		{
//			m_iterator++;
//			return *this;
//		}
//		const_vector_iterator	operator++(int)
//		{
//			const_vector_iterator	tmp(*this); 
//			m_iterator++; 
//			return tmp;
//		}
//				const_vector_iterator&	operator--(void)
//		{
//			m_iterator--;
//			return *this;
//		}
//		const_vector_iterator	operator--(int)
//		{
//			--m_iterator;
//			return *this;
//		}

//		const_vector_iterator&	operator+(size_type n)
//		{
//			m_iterator = m_iterator + n;
//			return *this;
//		}

//		const_vector_iterator operator+(difference_type n) const
//		{
//			const_vector_iterator	plus(m_iterator - n);
//			return plus;
//		}

//		const_vector_iterator&	operator-(size_type n)
//		{
//			return (m_iterator - n);
//		}

//		const_vector_iterator operator-(difference_type n) const
//		{
//			const_vector_iterator	minus(m_iterator + n);
//			return minus;
//		}

//		size_type	operator-(const const_vector_iterator& x) const
//		{
//			return (m_iterator - x.m_iterator);
//		}

//		friend bool	operator<(const const_vector_iterator& lhs, const const_vector_iterator& rhs)
//		{
//			return (lhs.m_iterator < rhs.m_iterator);
//		}

//		friend const_vector_iterator& operator+(size_type n, const const_vector_iterator& rhs)
//		{
//			return (rhs + n);
//		}

//		friend bool	operator>(const const_vector_iterator& lhs, const const_vector_iterator& rhs)
//		{
//			return (lhs.m_iterator > rhs.m_iterator);
//		}
//		bool	operator<=(const const_vector_iterator& x)
//		{
//			return (m_iterator <= x.m_iterator);
//		}
//		bool	operator>=(const const_vector_iterator& x)
//		{
//			return (m_iterator >= x.m_iterator);
//		}

//		const_vector_iterator&	operator+=(const const_vector_iterator& x)
//		{
//			return (m_iterator += x.m_iterator);
//		}

//		const_vector_iterator&	operator+=(size_type n)
//		{
//			m_iterator += n;
//			return *this;
//		}

//		const_vector_iterator&	operator-=(const const_vector_iterator& x)
//		{
//			return (m_iterator -= x.m_iterator);
//		}

//		const_vector_iterator&	operator-=(size_type n)
//		{
//			m_iterator -= n;
//			return *this;
//		}

//		reference	operator[](difference_type n) const
//		{
//			return (m_iterator[n]);
//		}

//	private:
//		value_type*	m_iterator;
//};


};

#endif