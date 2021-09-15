#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP

# include <cstddef>

namespace ft
{
template <typename T>
class input_iterator_tag
{
	public:
		input_iterator_tag(void) {};
		input_iterator_tag(T* value) : m_iterator(value) {};
		input_iterator_tag(const input_iterator_tag & x) { *this = x; };
		~input_iterator_tag(void){};
		input_iterator_tag&	operator=(const input_iterator_tag& x) { m_iterator = x.m_iterator; return *this; }

		bool				operator==(const input_iterator_tag& x) const { return (m_iterator != x.m_iterator); }
		bool				operator!=(const input_iterator_tag& x) const { return (m_iterator != x.m_iterator); }

		T&					operator*(void) const { return *m_iterator; }
		T*					operator->(void) const { return	m_iterator; }

		input_iterator_tag<T>&	operator++(void) { m_iterator++; return *this; }
		input_iterator_tag<T>	operator++(int) { ++m_iterator; return *this; }
		//input_iterator_tag<T>&	operator--(void) { m_iterator--; return *this; }
		//input_iterator_tag<T>	operator--(int) { --m_iterator; return *this; }
		
		//input_iterator_tag<T>	operator+(ptrdiff_t n) const { return input_iterator_tag(m_iterator + n); }
		//input_iterator_tag<T>	operator-(ptrdiff_t n) const { return input_iterator_tag(m_iterator - n); }
		//input_iterator_tag<T>	operator-(const input_iterator_tag& x) const { return input_iterator_tag(m_iterator - x.m_iterator); }

		bool				operator<(const input_iterator_tag& x) const { return (m_iterator < x.m_iterator); }
		bool				operator>(const input_iterator_tag& x) const { return (m_iterator > x.m_iterator); }
		bool				operator<=(const input_iterator_tag& x) const { return (m_iterator <= x.m_iterator); }
		bool				operator>=(const input_iterator_tag& x) const { return (m_iterator >= x.m_iterator); }

		//input_iterator<T>&	operator+=(ptrdiff_t n) { m_iterator += n; return *this; }
		//input_iterator<T>&	operator-=(ptrdiff_t n) { m_iterator -= n; return *this; }

		T&					operator[](ptrdiff_t n) const { return (m_iterator[n]); }

	private:
		T*	m_iterator;
};
};

#endif