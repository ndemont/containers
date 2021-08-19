#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>
# include <string>
# include <limits>
# include <memory>

template <class T, class Container = std::deque<T> >
class stack
{
	public:

	typedef	T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;


	/* CONSTRUCTORS */
	explicit stack (const container_type& ctnr = container_type()) : m_ctnr(ctnr) {};
	
	/* MEMBERS FUNCTIONS */
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
		return (m_ctnr.front());
	}
	const value_type&	top(void) const
	{
		return (m_ctnr.front());
	}
	void				push(const value_type& val)
	{
		m_ctnr.push_front(val);
	}
	void				pop(void)
	{
		m_ctnr.pop_front();
	}

	/* Non-member function overloads */
	bool	operator==(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr == rhs.m_ctnr);
	}
	bool	operator!=(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr != rhs.m_ctnr);
	}
	bool	operator<(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr < rhs.m_ctnr);
	}
	bool	operator<=(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr <= rhs.m_ctnr);
	}
	bool	operator>(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr > rhs.m_ctnr);
	}
	bool	operator>=(const stack<T,Container>& rhs)
	{
		return (this->m_ctnr >= rhs.m_ctnr);
	}

	private:
		container_type	m_ctnr;
};

#endif
