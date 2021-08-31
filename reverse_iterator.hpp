#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator
{
	public:
		typedef Iterator										iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		/*CONSTRUCTORS - Member functions*/ 
		reverse_iterator();
		explicit reverse_iterator (iterator_type it);
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it);
		
		/*BASE - Member functions*/
		iterator_type base() const;

		/*OPERATOR* - Member functions*/
		reference operator*() const;

		/*OPERATOR+ - Member functions*/
		reverse_iterator operator+ (difference_type n) const;

		/*OPERATOR++ - Member functions*/
		reverse_iterator& operator++();
		reverse_iterator  operator++(int);

		/*OPERATOR+= - Member functions*/
		reverse_iterator& operator+= (difference_type n);

		/*OPERATOR- - Member functions*/
		reverse_iterator operator- (difference_type n) const;

		/*OPERATOR-- - Member functions*/
		reverse_iterator& operator--();
		reverse_iterator  operator--(int);

		/*OPERATOR-= - Member functions*/
		reverse_iterator& operator-= (difference_type n);

		/*OPERATOR-> - Member functions*/
		pointer operator->() const;

		/*OPERATOR[] - Member functions*/
		reference operator[] (difference_type n) const;

};
	/*RELATIONAL OPERATORS - Non Member function Overloads*/
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	/*OPERAROR+ - Non Member function Overloads*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

	/*OPERATOR - - Non Member function Overloads*/
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
};

#endif