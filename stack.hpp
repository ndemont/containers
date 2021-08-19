#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>
# include <string>
# include <limits>
# include <memory>
# include "vector.hpp"

template <class T, class Container = ft::vector<T> >
class stack
{
	public:

	typedef	T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;


	/* Constructors */
	explicit	stack(const container_type& ctnr = container_type()) : m_ctnr(ctnr) {};
	
	/* Member functions */
	bool				empty(void) const
	{
		return (m_ctnr.empty());
	}
	size_type			size(void) const
	{
		return (m_ctnr.size());
	}
	value_type&			top(void)
	{
		return (m_ctnr.back());
	}
	const value_type&	top(void) const
	{
		return (m_ctnr.front());
	}
	void				push(const value_type& val)
	{
		m_ctnr.push_back(val);
	}
	void				pop(void)
	{
		m_ctnr.pop_back();
	}

	/* Non-member function overloads */
	friend bool			operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr == rhs.m_ctnr);
	}
	friend bool			operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr != rhs.m_ctnr);
	}
	friend bool			operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr < rhs.m_ctnr);
	}
	friend bool			operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr <= rhs.m_ctnr);
	}
	friend bool			operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr > rhs.m_ctnr);
	}
	friend bool			operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.m_ctnr >= rhs.m_ctnr);
	}

	private:
		container_type	m_ctnr;
};

#endif
