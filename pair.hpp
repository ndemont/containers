#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2> 
struct pair
{
	public:
		typedef	T1	first_type;
		typedef	T2	second_type;

	/* CONSTRUCTORS */
	pair(void) : m_first(first_type()), m_second(second_type()) {};
	template<class U, class V>
	pair(const pair<U,V>& pr) : m_first(pr.m_first), m_second(pr.m_second) {};
	pair(const first_type& a, const second_type& b) : m_first(a), m_second(b) {};

	/* OPERATOR= */
	pair&	operator=(const pair& pr)
	{
		m_first = pr.m_first;
		m_second = pr.m_second;
		
		return (*this);
	}

	/* Non-member function overloads */
	friend bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.m_first == rhs.m_first && lhs.m_second == rhs.m_second);
	}

	friend bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	friend bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.m_first < rhs.m_first || (!(rhs.m_first < lhs.m_first) && lhs.m_second < rhs.m_second));
	}

	friend bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	friend bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	friend bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	first_type	m_first;
	second_type	m_second;
};

template <class T1, class T2>
pair<T1,T2>	make_pair(T1 x, T2 y)
{
	return (pair<T1,T2>(x,y));
}

};

#endif