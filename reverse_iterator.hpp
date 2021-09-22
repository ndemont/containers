#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"

namespace ft
{

template <class U>
class const_reverse_iterator;

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

		reverse_iterator(void) {};
		explicit reverse_iterator (iterator_type it) : m_iterator(it) {};
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		template <class Iter>
		reverse_iterator(const const_reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		
		iterator_type			base() const { return m_iterator; }

		reference 				operator*(void) const { return *m_iterator; }
		pointer 				operator->(void) const { return	&(*m_iterator); }

		reverse_iterator 		operator+(difference_type n) const { return reverse_iterator(m_iterator - n); }
		friend reverse_iterator	operator+(difference_type n, const reverse_iterator& x) { return reverse_iterator(n + x.base()); }
		reverse_iterator 		operator-(difference_type n) const	{ return reverse_iterator(m_iterator - n); }
		difference_type 		operator-(const reverse_iterator& x) const { return (m_iterator - x.base()); }

		reverse_iterator& 		operator++(void) { m_iterator--; return *this; }
		reverse_iterator  		operator++(int) { --m_iterator; return *this; }
		reverse_iterator& 		operator--(void) { m_iterator++; return *this; }
		reverse_iterator  		operator--(int) { ++m_iterator; return *this; }

		reverse_iterator&		operator+=(const reverse_iterator& x) { return (m_iterator -= x.base()); }
		reverse_iterator&		operator+=(difference_type n) { m_iterator = m_iterator - n; return *this; }
		reverse_iterator&		operator-=(const reverse_iterator& x) { return (m_iterator -= x.base()); }
		reverse_iterator& 		operator-=(difference_type n) { m_iterator = m_iterator + n; return *this; }

		reference				operator[](difference_type n) const { return (m_iterator[n]); }

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
		bool				operator>(const reverse_iterator<U>& x) const { return (m_iterator < x.base()); }
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
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		const_reverse_iterator(void) {};
		explicit const_reverse_iterator (iterator_type it) : m_iterator(it) {};
		template <class Iter>
		const_reverse_iterator(const const_reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		template <class Iter>
		const_reverse_iterator(const reverse_iterator<Iter>& rev_it) : m_iterator(rev_it.base()) {};
		
		iterator_type			base() const { return iterator_type(m_iterator); }

		reference				operator*() const { return *m_iterator; }
		pointer					operator->(void) const { return	&(*m_iterator); }

		const_reverse_iterator	operator+(difference_type n) const { return const_reverse_iterator(m_iterator - n); }
		friend const_reverse_iterator	operator+(difference_type n, const const_reverse_iterator& x) { return const_reverse_iterator(n + x.base()); }
		const_reverse_iterator	operator-(difference_type n) const { return const_reverse_iterator(m_iterator + n); }

		const_reverse_iterator&	operator++(void) { m_iterator--; return *this; }
		const_reverse_iterator	operator++(int) { --m_iterator; return *this; }
		const_reverse_iterator&	operator--(void) { m_iterator++; return *this; }
		const_reverse_iterator	operator--(int) { ++m_iterator; return *this; }

		const_reverse_iterator&	operator+=(const const_reverse_iterator& x) { return (m_iterator -= x.m_iterator); }
		const_reverse_iterator& operator+=(difference_type n) { m_iterator -= n; return *this; }
		const_reverse_iterator&	operator-=(difference_type n) { m_iterator += n; return *this; }

		reference				operator[](difference_type n) const { return (m_iterator[n]); }

		friend bool				operator==(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator == rhs.m_iterator); }
		friend bool				operator!=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator != rhs.m_iterator); }
		friend bool				operator<=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator >= rhs.m_iterator); }
		friend bool				operator>=(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator <= rhs.m_iterator); }
		friend bool				operator>(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator < rhs.m_iterator); }
		template <class U>
		bool					operator<(const const_reverse_iterator<U>& x) { return (m_iterator > x.base()); }
		friend bool				operator<(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs) { return (lhs.m_iterator > rhs.m_iterator); }
	
	private:
		iterator_type	m_iterator;
};

	template <class Iterator>
	const_reverse_iterator<Iterator> operator+(typename const_reverse_iterator<Iterator>::difference_type n, const const_reverse_iterator<Iterator>& rev_it);

	template <class Iterator>
	typename const_reverse_iterator<Iterator>::difference_type operator-(const const_reverse_iterator<Iterator>& lhs, const const_reverse_iterator<Iterator>& rhs);

};

#endif