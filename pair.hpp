#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2> 
struct pair
{
	public:
		typedef	T1	key;
		typedef	T2	map;

	/* CONSTRUCTORS */
	pair(void) : first(key()), second(map()) {};
	template<class U, class V>
	pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
	pair(const key& a, const map& b) : first(a), second(b) {};

	/* OPERATOR= */
	pair&	operator=(const pair& pr)
	{
		first = pr.first;
		second = pr.second;
		
		return (*this);
	}

	/* Non-member function overloads */
	friend bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	friend bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	friend bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
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

	key	first;
	map	second;
};

template <class T1, class T2>
pair<T1,T2>	make_pair(T1 x, T2 y)
{
	return (pair<T1,T2>(x,y));
}

};

#endif