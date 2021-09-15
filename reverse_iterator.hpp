#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator
{
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		/*CONSTRUCTORS - Member functions*/ 
		reverse_iterator(void) {};
		explicit reverse_iterator (iterator_type it) : m_iterator(it) {};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.m_iterator) {};
		//template <class Category, class T>
		//reverse_iterator(const const_iterator<Category, T>& rev_it) : m_iterator(rev_it.get_const_iterator()) {};
		
		/*BASE - Member functions*/
		iterator_type base() const
		{
			iterator_type copy(m_iterator);

			return copy;
		}

		/*OPERATOR* - Member functions*/
		reference operator*() const
		{
			return *m_iterator;
		}

		/*OPERATOR+ - Member functions*/
		reverse_iterator operator+(difference_type n) const
		{
			reverse_iterator	plus(m_iterator - n);
			return plus;
		}

		/*OPERATOR++ - Member functions*/
		reverse_iterator& operator++(void)
		{
			m_iterator--;
			return *this;
		}
		reverse_iterator  operator++(int)
		{
			--m_iterator;
			return *this;
		}

		/*OPERATOR+= - Member functions*/
		reverse_iterator&	operator+=(const reverse_iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		reverse_iterator& operator+=(difference_type n) const
		{
			m_iterator -= n;
			return *this;
		}

		/*OPERATOR- - Member functions*/
		reverse_iterator operator-(difference_type n) const
		{
			reverse_iterator	minus(m_iterator + n);
			return minus;
		}

		/*OPERATOR-- - Member functions*/
		reverse_iterator& operator--(void)
		{
			m_iterator++;
			return *this;
		}
		reverse_iterator  operator--(int)
		{
			++m_iterator;
			return *this;
		}

		/*OPERATOR-= - Member functions*/
		reverse_iterator&	operator-=(const reverse_iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			m_iterator += n;
			return *this;
		}

		/*OPERATOR-> - Member functions*/
		pointer operator->() const
		{
			return	&(*m_iterator);
		}

		/*OPERATOR[] - Member functions*/
		reference operator[](difference_type n) const
		{
			return (m_iterator[n]);
		}

		/*RELATIONAL OPERATORS - Non Member function Overloads*/
		friend bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
		return (lhs.m_iterator == rhs.m_iterator);
		}
		friend bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
		return (lhs.m_iterator != rhs.m_iterator);
		}
		friend bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator >= rhs.m_iterator);
		}
		friend bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator <= rhs.m_iterator);
		}
		friend bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator < rhs.m_iterator);
		}
		friend bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator > rhs.m_iterator);
		}
	private:
		iterator_type	m_iterator;
};


	/*OPERAROR+ - Non Member function Overloads*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

	/*OPERATOR - - Non Member function Overloads*/
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

template <class Iterator>
class const_reverse_iterator
{
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		/*CONSTRUCTORS - Member functions*/ 
		const_reverse_iterator(void) {};
		explicit const_reverse_iterator (iterator_type it) : m_iterator(it) {};
		//template <class Iter>
		//const_reverse_iterator(const const_reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.m_iterator) {};
		//template <class Category, class T>
		//const_reverse_iterator(const const_iterator<Category, T>& rev_it) : m_iterator(rev_it.m_const_iterator) {};
		
		/*BASE - Member functions*/
		iterator_type base() const
		{
			iterator_type copy(m_iterator);

			return copy;
		}

		/*OPERATOR* - Member functions*/
		reference operator*() const
		{
			return *m_iterator;
		}

		/*OPERATOR+ - Member functions*/
		const_reverse_iterator operator+(difference_type n) const
		{
			const_reverse_iterator	plus(m_iterator - n);
			return plus;
		}

		/*OPERATOR++ - Member functions*/
		const_reverse_iterator& operator++(void)
		{
			m_iterator--;
			return *this;
		}
		const_reverse_iterator  operator++(int)
		{
			--m_iterator;
			return *this;
		}

		/*OPERATOR+= - Member functions*/

		const_reverse_iterator&	operator+=(const const_reverse_iterator& x)
		{
			return (m_iterator -= x.m_iterator);
		}

		const_reverse_iterator& operator+=(size_t n)
		{
			m_iterator -= n;
			return *this;
		}

		/*OPERATOR- - Member functions*/
		const_reverse_iterator operator-(difference_type n) const
		{
			const_reverse_iterator	minus(m_iterator + n);
			return minus;
		}

		/*OPERATOR-- - Member functions*/
		const_reverse_iterator& operator--(void)
		{
			m_iterator++;
			return *this;
		}
		const_reverse_iterator  operator--(int)
		{
			++m_iterator;
			return *this;
		}

		/*OPERATOR-= - Member functions*/
		const_reverse_iterator& operator-=(difference_type n)
		{
			m_iterator += n;
			return *this;
		}

		/*OPERATOR-> - Member functions*/
		pointer operator->() const
		{
			return	&(*m_iterator);
		}

		/*OPERATOR[] - Member functions*/
		reference operator[](difference_type n) const
		{
			return (m_iterator[n]);
		}

		/*RELATIONAL OPERATORS - Non Member function Overloads*/
		friend bool operator==(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
		return (lhs.m_iterator == rhs.m_iterator);
		}
		friend bool operator!=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
		return (lhs.m_iterator != rhs.m_iterator);
		}
		friend bool operator<=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator >= rhs.m_iterator);
		}
		friend bool operator>=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator <= rhs.m_iterator);
		}
		friend bool operator>(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator < rhs.m_iterator);
		}
		friend bool operator<(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs)
		{
			return (lhs.m_iterator > rhs.m_iterator);
		}
	private:
		iterator_type	m_iterator;
};


	/*OPERAROR+ - Non Member function Overloads*/
	template <class Iterator>
	const_reverse_iterator<Iterator> operator+(typename const_reverse_iterator<Iterator>::difference_type n, const const_reverse_iterator<Iterator>& rev_it);

	/*OPERATOR - - Non Member function Overloads*/
	template <class Iterator>
	typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs);



};

#endif