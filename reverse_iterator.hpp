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
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it) {};
		
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
		reverse_iterator operator+(difference_type n) const;

		/*OPERATOR++ - Member functions*/
		reverse_iterator& operator++()
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
		reverse_iterator& operator+= (difference_type n);

		/*OPERATOR- - Member functions*/
		reverse_iterator operator-(difference_type n) const;

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
		reverse_iterator& operator-= (difference_type n);

		/*OPERATOR-> - Member functions*/
		pointer operator->() const;

		/*OPERATOR[] - Member functions*/
		reference operator[] (difference_type n) const
		{
			return (m_iterator[n]);
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
	/*RELATIONAL OPERATORS - Non Member function Overloads*/
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.m_iterator == rhs.m_iterator);
	}
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.m_iterator != rhs.m_iterator);
	}
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.m_iterator >= rhs.m_iterator);
	}
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.m_iterator <= rhs.m_iterator);
	}

	/*OPERAROR+ - Non Member function Overloads*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

	/*OPERATOR - - Non Member function Overloads*/
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
};

#endif