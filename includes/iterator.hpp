#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP


# include <cstddef>
# include <cstdio>
# include <iostream>
# include <typeinfo>
# include "iterator_traits.hpp"
# include "iterator.hpp"
# include "pair.hpp"

namespace ft
{


	struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	struct output_iterator_tag {};

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator : public Category
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};


	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef std::ptrdiff_t								difference_type;
			typedef T 										value_type;
			typedef T* 										pointer;
			typedef T& 										reference;
			typedef	ft::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef std::ptrdiff_t								difference_type;
			typedef T 										value_type;
			typedef T* 										pointer;
			typedef T& 										reference;
			typedef ft::random_access_iterator_tag			iterator_category;
	};


template <class U>
class const_reverse_iterator;

template <class Iterator>
class reverse_iterator 
: public iterator<typename iterator_traits<Iterator>::iterator_category, 
					typename iterator_traits<Iterator>::value_type,
					typename iterator_traits<Iterator>::difference_type,
					typename iterator_traits<Iterator>::pointer,
					typename iterator_traits<Iterator>::reference>

{
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		reverse_iterator(void) {};
		explicit reverse_iterator (iterator_type it) : m_iterator(it) {};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		template <class Iter>
		reverse_iterator(const const_reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		
		iterator_type			base() const { return m_iterator; }

		reference 				operator*(void) const { iterator_type it = m_iterator; return *(--it);}// return *(m_iterator - 1); }
		pointer 				operator->(void) const { return	&(operator*()); }

		reverse_iterator 		operator+(difference_type n) const { return reverse_iterator(m_iterator - n); }
		friend reverse_iterator	operator+(difference_type n, const reverse_iterator& x) { return reverse_iterator(x.base() - n); }
		reverse_iterator 		operator-(difference_type n) const	{ return reverse_iterator(m_iterator + n); }
		difference_type 		operator-(const reverse_iterator& x) const { return (x.base() - m_iterator); }

		reverse_iterator& 		operator++(void) { m_iterator--; return *this; }
		reverse_iterator  		operator++(int) { return reverse_iterator(m_iterator--); }
		reverse_iterator& 		operator--(void) { m_iterator++; return *this; }
		reverse_iterator  		operator--(int) { return reverse_iterator(m_iterator++); }

		reverse_iterator&		operator+=(const reverse_iterator& x) { return (m_iterator -= x.base()); }
		reverse_iterator&		operator+=(difference_type n) { m_iterator -= n; return *this; }
		reverse_iterator&		operator-=(const reverse_iterator& x) { return (m_iterator += x.base()); }
		reverse_iterator& 		operator-=(difference_type n) { m_iterator += n; return *this; }

		reference				operator[](difference_type n) const { return (base()[-n-1]); }

		template <class U>
		bool 					operator==(const reverse_iterator<U>& x) const { return (m_iterator == x.base()); }
		friend bool				operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator == rhs.m_iterator); }
		template <class U>
		bool					operator!=(const reverse_iterator<U>& x) const { return (m_iterator != x.base()); }
		friend bool				operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator != rhs.m_iterator); }
		template <class U>
		bool					operator<=(const reverse_iterator<U>& x) const { return (m_iterator >= x.base()); }
		friend bool				operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator >= rhs.m_iterator); }
		template <class U>
		bool					operator>=(const reverse_iterator<U>& x) const { return (m_iterator <= x.base()); }
		friend bool				operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator <= rhs.m_iterator); }
		template <class U>
		bool					operator>(const reverse_iterator<U>& x) const { return (m_iterator < x.base()); }
		friend bool				operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator < rhs.m_iterator); }
		template <class U>
		bool					operator<(const reverse_iterator<U>& x) const { return (m_iterator > x.base());}
		friend bool				operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator > rhs.m_iterator);}

	private:
		iterator_type	m_iterator;
};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

template <class Iterator>
class const_reverse_iterator
{
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		const_reverse_iterator(void) {};
		explicit const_reverse_iterator (iterator_type it) : m_iterator(it) {};
		template <class Iter>
		const_reverse_iterator(const const_reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		template <class Iter>
		const_reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		
		iterator_type					base() const { return iterator_type(m_iterator); }

		reference						operator*() const { return *(m_iterator - 1); }
		pointer							operator->(void) const { return	&(*m_iterator); }

		const_reverse_iterator			operator+(difference_type n) const { return const_reverse_iterator(m_iterator - n); }
		friend const_reverse_iterator	operator+(difference_type n, const const_reverse_iterator& x) { return const_reverse_iterator(n + x.base()); }
		const_reverse_iterator			operator-(difference_type n) const { return const_reverse_iterator(m_iterator + n); }
		difference_type					operator-(const reverse_iterator<Iterator>& x) const { return (x.base() - m_iterator); }

		const_reverse_iterator&			operator++(void) { m_iterator--; return *this; }
		const_reverse_iterator			operator++(int) { --m_iterator; return *this; }
		const_reverse_iterator&			operator--(void) { m_iterator++; return *this; }
		const_reverse_iterator			operator--(int) { ++m_iterator; return *this; }

		const_reverse_iterator&			operator+=(const const_reverse_iterator& x) { return (m_iterator -= x.m_iterator); }
		const_reverse_iterator& 		operator+=(difference_type n) { m_iterator -= n; return *this; }
		const_reverse_iterator&			operator-=(difference_type n) { m_iterator += n; return *this; }

		reference						operator[](difference_type n) const { return (base()[-n-1]); }

		friend bool						operator==(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator == rhs.m_iterator); }
		friend bool						operator!=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator != rhs.m_iterator); }
		friend bool						operator<=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator >= rhs.m_iterator); }
		friend bool						operator>=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator <= rhs.m_iterator); }
		friend bool						operator>(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator < rhs.m_iterator); }
		template <class U>
		bool							operator<(const const_reverse_iterator<U>& x) { return (m_iterator > x.base()); }
		friend bool						operator<(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator > rhs.m_iterator); }
	
	private:
		iterator_type	m_iterator;
};

	template <class Iterator>
	const_reverse_iterator<Iterator> operator+(typename const_reverse_iterator<Iterator>::difference_type n, const const_reverse_iterator<Iterator>& rev_it);

	template <class Iterator>
	typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs);

};

#endif