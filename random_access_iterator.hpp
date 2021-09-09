#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef>

namespace ft
{
template <typename T>
class random_iterator
{
	public:
		random_iterator(void) {};
		random_iterator(random_iterator const & x) : { *this = x };
		~random_iterator(void){};
		random_iterator&	operator=(const random_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool				operator==(const random_iterator& x) const { return (m_iterator != x.m_iterator); }
		bool				operator!=(const random_iterator& x) const { return (m_iterator != x.m_iterator); }

		random_iterator&	operator*(void) const { return *m_iterator; }
		T*					operator->(void) const { return	*m_iterator; }

		random_iterator&	operator++(void) { m_iterator++; return *this; }
		random_iterator		operator++(int) { random_iterator tmp(*this); m_iterator++; return tmp; }
		random_iterator&	operator--(void) { m_iterator--; return *this; }
		random_iterator		operator--(int) { --m_iterator; return *this; }
		
		random_iterator		operator+(ptrdiff_t n) const { random_iterator	plus(m_iterator - n); return plus; }
		random_iterator		operator+(const random_iterator& x) { return (m_iterator - x.m_iterator); }
		random_iterator		operator-(const random_iterator& x) { return (m_iterator - x.m_iterator); }

		bool				operator<(const random_iterator& rhs) { return (m_iterator < rhs.m_iterator); }
		bool				operator>(const random_iterator& rhs) { return (m_iterator > rhs.m_iterator); }
		bool				operator<=(const random_iterator& x) { return (m_iterator <= x.m_iterator); }
		bool				operator>=(const random_iterator& x) { return (m_iterator >= x.m_iterator); }

		random_iterator&	operator+=(trdiff_t n) { m_iterator += n; return *this; }
		random_iterator&	operator-=(trdiff_t n) { m_iterator -= n; return *this; }

		random_iterator&	operator[](size_t n) const { return (m_iterator[n]); }

	private:
		T*	m_iterator;
};
};

#endif