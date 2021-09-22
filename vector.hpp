#ifndef VECTOR_HPP
# define VECTOR_HPP

//# include "iterator_traits.hpp"
# include <iostream>
# include <stdexcept>
# include <new>
# include "random_access_iterator.hpp"
# include "input_iterator.hpp"
# include "reverse_iterator.hpp"
# include "iterator.hpp"
# include "vector_iterator.hpp"
# include <cstddef>
# include <type_traits>

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
		typedef ft::vector_iterator<value_type>								iterator;
		typedef ft::const_vector_iterator<value_type>						const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef	ptrdiff_t													difference_type;
		typedef	size_t														size_type;

		/* CONSTRUCTORS */
		explicit vector(const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(alloc) { };
		explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(n), m_capacity(n), m_alloc(alloc)
		{
			this->assign(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last, const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(alloc)
		{
			this->assign(first, last);
		}
		
		vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type()) : m_alloc(alloc)
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
		vector(const vector<T>&x) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(x.m_alloc)
		{
			if (this != &x)
				*this = x;
		}

		/* DESTRUCTOR */
		~vector(void)
		{
			if (m_vector)
				m_alloc.deallocate(m_vector, m_capacity);
		}

		/* OPERATOR= */
		vector<T>& operator=(const vector& x)
		{
			this->assign(x.begin(), x.end());
			return *this;
		}

		/* ITERATORS */
		iterator		begin(void) {
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
		void	assign(InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last)
		{
 			InputIterator tmp = first;
			
			m_alloc.deallocate(m_vector, m_capacity);
			size_type	k = 0;
			for ( ; tmp != last; tmp++)
				k++;
			if (k > m_capacity)
				m_capacity = k;
			m_vector = m_alloc.allocate(m_capacity);
			m_size = 0;
			for (InputIterator it = first; it != last; it++)
			{
				this->push_back(*it);
			}
		}

		void	assign(size_type n, const value_type& val)
		{
			
			m_alloc.deallocate(m_vector, m_capacity);

			if (n > m_capacity)
				m_capacity = n;
			m_vector = m_alloc.allocate(m_capacity);
			m_size = 0;
			for (size_type i = 0; i < n; i++)
			{
				this->push_back(val);
			}
		}

		void	push_back(const value_type& val)
		{
			int amount = 0;
			if (m_capacity <= m_size)
			{

				if (m_capacity == 0)
					amount = 1;
				else
					amount = m_capacity * 2;
				reserve(amount);
				m_capacity = amount;
			}
			m_alloc.construct(&m_vector[m_size], val);
			m_size++;
		}

		void	pop_back(void)
		{
			m_size--;
			m_vector[m_size].~value_type();
		}

		iterator	insert(iterator position, const value_type& val)
		{
			vector<T>	tmp(*this);
			iterator	begin = this->begin();
			size_type	i = 0;

			
			m_alloc.deallocate(m_vector, m_capacity);
			try 
			{
				m_vector = m_alloc.allocate(tmp.m_capacity + 1);
			}
			catch (std::bad_alloc& ba)
  			{
   				std::cerr << "bad_alloc caught: " << ba.what() << '\n';
  			}
			m_size = 0;
			while (begin < position)
			{
				this->push_back(tmp[i]);
				i++;
				begin++;
			}
			this->push_back(val);
			while (tmp[i])
			{
				this->push_back(tmp[i]);
				i++;
			}
			return --position;
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
			vector<T>	tmp(*this);
			iterator	begin = this->begin();
			size_type	i = 0;

			*this = vector(m_size + n);
			while (begin < position)
			{
				m_vector[i] = tmp[i];
				i++;
				begin++;
			}
			for (size_t j = 0; j < n; j++)
				m_vector[i + j] = val;
			while (tmp[i])
			{
				m_vector[i + n] = tmp[i];
				i++;
			}
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last)
		{
			vector<T>	tmp(*this);
			iterator	begin = this->begin();
			size_type	i = 0;
			size_type	j = 0;
			size_type	len = 0;

			for (InputIterator it = first; it != last; it++)
				len++;
			*this = vector(m_size + len);
			while (begin < position)
			{
				m_vector[i] = tmp[i];
				i++;
				begin++;
			}
			for (; first != last; first++)
				m_vector[i + j++] = *first;
			while (tmp[i])
			{
				m_vector[i + len] = tmp[i];
				i++;
			}
		}

		iterator	erase(iterator position)
		{
			size_t	pos = position - begin();
			size_t	len = end() - begin() - 1;

			for (; pos < len; pos++)
			{
				(*this)[pos] = (*this)[pos + 1];
			}
			(*(end())).~value_type();
			m_size--;
			return position;
		}

		iterator	erase(iterator first, iterator last)
		{
			size_t	start = first - begin();
			size_t	end = last - begin();
			size_t	erased = last - first;

			for (; start <= end; start++)
			{
				(*this)[start] = (*this)[start + erased];
			}
			//(*(end())).~value_type();
			m_size = m_size - erased;
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
			if (lhs.m_size == rhs.m_size)
			{
				for (size_t i = 0; i < lhs.m_size; i++)
				{
					if (lhs.m_vector[i] != rhs.m_vector[i])
						return false;
				}
				return true;
			}
			else
				return false;
		}
		friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

		friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0; i < lhs.m_size; i++)
			{
				if (lhs.m_vector[i] < rhs.m_vector[i])
					return true;
				else if (lhs.m_vector[i] > rhs.m_vector[i])
					return false;
			}
			return false;
		}
		friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}
		friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}
		friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

		friend void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			(void)x;
			(void)y;
		}

	private:
		pointer				m_vector;
		size_type			m_size;
		size_type			m_capacity;
		allocator_type 		m_alloc;
};

/* TEMPLATE SPECIALIZATIONS */
template <class Alloc>
class vector<bool,Alloc>;


};

#endif