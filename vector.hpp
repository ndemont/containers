#ifndef VECTOR_HPP
# define VECTOR_HPP

//# include "iterator_traits.hpp"
# include <iostream>
# include <stdexcept>
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

template <typename T, class Alloc = std::allocator<T> >
class vector
{
	public:
		
		/* MEMBER TYPES */
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef value_type &												reference;
		typedef value_type const &											const_reference;
		typedef value_type *												pointer;
		typedef value_type const *											const_pointer;
		typedef ft::iterator<random_access_iterator_tag, value_type>		iterator;
		typedef ft::const_iterator<random_access_iterator_tag, value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef const reverse_iterator										const_reverse_iterator;
		typedef	std::ptrdiff_t												difference_type;
		typedef	size_t														size_type;

		/* CONSTRUCTORS */
		explicit vector<T>(const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(alloc) {};
		explicit vector<T>(int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_size(n), m_capacity(n), m_alloc(alloc)
		{
			m_vector = m_alloc.allocate(m_capacity);
			for (size_type i = 0; i < m_size; i++) 
				m_vector[i] = val;
		}
		template <class InputIterator>
		vector<T>(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : m_alloc(alloc)
		{
			InputIterator tmp = first;
			
			m_capacity = 0;
			while (tmp != last)
			{
				m_capacity++;
				tmp++;
			}
			m_size = m_capacity;
			m_vector = m_alloc.allocate(m_capacity);
			for (size_type i = 0; first != last; i++)
			{
				m_vector[i] = *first;
				first++;
			}
		}
		vector<T>(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type()) : m_alloc(alloc)
		{
			m_capacity = last - first;
			m_size = m_capacity;
			m_vector = m_alloc.allocate(m_capacity);
			for (size_type i = 0; first != last; i++)
			{
				m_vector[i] = *first;
				first++;
			}
		}
		vector<T>(const vector<T>&x) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(x.m_alloc)
		{
			if (this != &x)
				*this = x;
		}

		/* DESTRUCTOR */
		~vector<T>(void)
		{
			//if (m_vector)
				//m_alloc.deallocate(m_vector, m_capacity);
		}

		/* OPERATOR= */
		vector& operator=(const vector& x)
		{
			this->assign(x.begin(), x.end());
			return *this;
		}

		/* ITERATORS */
		iterator		begin(void)
		{
			iterator	begin(m_vector);
			return begin;
		}
		const_iterator	begin(void) const
		{
			return const_iterator(m_vector);
		}
		iterator		end()
		{
			iterator end(m_vector + m_size);
			return end;
		}
		const_iterator	end() const
		{
			return const_iterator(m_vector + m_size);
		}
		reverse_iterator	rbegin()
		{
			reverse_iterator	rbegin(m_vector + m_size - 1);
			return rbegin;
		}
		const_reverse_iterator	rbegin() const
		{
			const_reverse_iterator	rbegin(m_vector + m_size - 1);
			return rbegin;
		}
		reverse_iterator	rend()
		{
			reverse_iterator rend(m_vector - 1);
			return rend;
		}
		const_reverse_iterator	rend() const
		{
			const_reverse_iterator rend(m_vector - 1);
			return rend;
		}

		/* CAPACITY */
		size_type	size(void) const
		{
			return m_size;
		}
		size_type	max_size() const
		{
			return (m_alloc.max_size());
		}
		void		resize(size_type n, value_type val = value_type())
		{
			if (n < m_size)
			{
				while (m_size > n)
					pop_back();
			}
			else if (n > m_size)
			{
				while (m_size != n)
					push_back(val);
			}
		}
		size_type	capacity(void) const
		{
			return m_capacity;
		}
		bool	empty(void) const
		{
			return (m_size);
		}
		void	reserve(size_type n)
		{
			if (n > m_capacity)
			{
				vector<T>	newVector(begin(), end());

				m_vector = m_alloc.allocate(n, m_vector);
				m_capacity = m_capacity * 2;
				for (size_type i = 0; i < m_size; i++)
					m_vector[i] = newVector[i];
			}
		}

		/* ELEMENT ACCESS */
		reference	operator[](size_type n)
		{
			iterator pos = this->begin();
			pos = pos + n;
			return *pos;
		}
		const_reference	operator[](size_type n) const
		{
			const_iterator pos = this->begin();
			pos = pos + n;
			return *pos;
		}
		reference	at(size_type n)
		{
			if (m_size < n)
				throw std::out_of_range("element is out of range");
			return m_vector[n];
		}
		const_reference at(size_type n) const
		{
			if (m_size < n)
				throw std::out_of_range("element is out of range");
			return m_vector[n];
		}
		reference front(void)
		{
			iterator pos = this->begin();
			return *pos;
		}
		const_reference front(void) const
		{
			const_iterator pos = this->begin();
			return *pos;
		}
		reference back(void)
		{
			iterator pos = this->end();

			pos--;
			return *pos;
		}
		const_reference	back(void) const
		{
			const_iterator pos = this->end();

			pos--;
			return *pos;
		}

		/* MODIFIERS */
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last)
		{
			vector	newVector(first, last);

			m_size = newVector.size();
			if (m_size > m_capacity)
			{
				m_vector = m_alloc.allocate(m_size, m_vector);
				m_capacity = m_size;
			}
			for (size_type i = 0; i < m_size; i++)
			{
				m_vector[i] = newVector[i];
			}
		}

		void	assign(size_type n, const value_type& val)
		{
			if (n > m_capacity)
			{
				m_vector = m_alloc.allocate(n, m_vector);
				m_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				m_vector[i] = val;
			m_size = n;
		}
		void	push_back(const value_type& val)
		{
			vector	newVector(this->begin(), this->end());

			m_size = newVector.size();
			if (m_size >= m_capacity)
			{
				m_vector = m_alloc.allocate(m_size + 1, m_vector);
				m_capacity = m_capacity * 2;
				if (!m_capacity)
					m_capacity++;
			}
			for (size_type i = 0; i < m_size; i++)
				m_vector[i] = newVector[i];
			m_size++;
			m_vector[m_size - 1] = val;
		}
		void	pop_back(void)
		{
			m_size--;
			m_vector[m_size].~value_type();
		}

		iterator	insert(iterator position, const value_type& val)
		{
			(void)position;
			(void)val;
			return position;
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			(void)position;
			(void)val;
			(void)n;
		}
		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last)
		{
			(void)position;
			(void)first;
			(void)last;
		}

		iterator	erase(iterator position)
		{
			iterator erased;

			(void)position;
			//(*position).~value_type();
			//erased = position;
			//position++;
			//while (position != this->end())
			//{
			//	*(position - 1) = *position;
			//	position++;
			//}
			return erased;
		}

		iterator	erase(iterator first, iterator last)
		{
			(void)last;
			return first;
		}

		void	swap(vector& x)
		{
			vector tmp(x);

			x = *this;
			*this = tmp;
		}
		void	clear(void)
		{
			while (m_size)
				pop_back();
		}

		/* ALLOCATOR */
		allocator_type get_allocator() const;

		/* NON-MEMBER FONCTION OVERLOADS */
		friend bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}
		friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}
		friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}
		friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}
		friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}
		friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
		}

		friend void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			(void)x;
			(void)y;
		}

	private:
		value_type			*m_vector;
		size_type			m_size;
		size_type			m_capacity;
		allocator_type 		m_alloc;
};

/* TEMPLATE SPECIALIZATIONS */
template <class Alloc>
class vector<bool,Alloc>;


};

#endif