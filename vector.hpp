#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "iterator_traits.hpp"
# include "input_iterator.hpp"
# include "iterator.hpp"
# include "pair.hpp"
# include "random_access_iterator_tag.hpp"
# include "reverse_iterator.hpp"
# include "vector_iterator.hpp"
# include <iostream>

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
		explicit vector(const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(alloc) {};
		explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_vector(NULL), m_size(0), m_capacity(0), m_alloc(alloc)
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
			for (iterator it = begin(); it != end(); it++)
				m_alloc.destroy(&(*it));
			m_alloc.deallocate(m_vector, m_capacity);
		}

		/* OPERATOR= */
		vector<T>& operator=(const vector& x)
		{
			this->assign(x.begin(), x.end());
			return *this;
		}

		/* ITERATORS */
		iterator				begin(void) { return iterator(m_vector); }
		const_iterator			begin(void) const { return const_iterator(m_vector); }
		iterator				end(void) { return iterator(m_vector + m_size); }
		const_iterator			end(void) const { return const_iterator(m_vector + m_size); }
		reverse_iterator		rbegin(void) { return reverse_iterator(end()); }
		const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(end()); }
		reverse_iterator		rend(void) { return reverse_iterator(begin()); }
		const_reverse_iterator	rend(void) const { return const_reverse_iterator(begin()); }

		/* CAPACITY */
		size_type	size(void) const { return m_size; }
		size_type	max_size() const { return (m_alloc.max_size()); }
		void		resize(size_type n, value_type val = value_type())
		{
			if (n < m_size)
			{
				while (m_size > n)
					pop_back();
			}
			else if (n > m_size)
			{
				while (m_size < n)
					push_back(val);
			}
		}
		size_type	capacity(void) const { return m_capacity; }
		bool		empty(void) const { return (!m_size); }
		
		void	reserve(size_type n)
		{
			if (n > m_capacity)
			{
				vector<T>	newVector(begin(), end());
				clear();
				m_alloc.deallocate(m_vector, m_capacity);
				m_vector = m_alloc.allocate(n, m_vector);
				m_capacity = n;
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
			
			for (iterator it = begin(); it != end(); it++)
				m_alloc.destroy(&(*it));
			size_type	k = 0;
			for ( ; tmp != last; tmp++)
				k++;
			if (k > m_capacity)
			{
				m_alloc.deallocate(m_vector, m_capacity);
				m_capacity = k;
				m_vector = m_alloc.allocate(m_capacity);
			}
			m_size = 0;
			for (InputIterator it = first; it != last; it++)
				this->push_back(*it);
		}

		void	assign(size_type n, const value_type& val)
		{
			for (iterator it = begin(); it != end(); it++)
				m_alloc.destroy(&(*it));
			if (n > m_capacity)
			{
				m_alloc.deallocate(m_vector, m_capacity);
				m_capacity = n;
				m_vector = m_alloc.allocate(m_capacity);
			}
			m_size = 0;
			for (size_type i = 0; i < n; i++)
				this->push_back(val);
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
			}
			m_alloc.construct(m_vector + m_size, val);
			m_size++;
		}

		void		pop_back(void)
		{ 
			m_alloc.destroy(&(*(end() - 1))); 
			m_size--; 
		}

		iterator	insert(iterator position, const value_type& val)
		{
				difference_type	diff = position - begin();
				
				if (m_size + 1 > m_capacity)
				{
					if (m_size * 2 > m_size + 1)
						reserve(m_size * 2);
					else
						reserve(m_size + 1);
				}
				iterator	iter = end();
				for (; iter != begin() + diff; iter--)
				{
					m_alloc.construct(&(*iter), *(iter - 1));
					m_alloc.destroy(&(*(iter - 1)));
				}
				m_alloc.construct(&(*iter), val);
				m_size++;
				return (iter);
		}

		void	insert(iterator position, size_type n, const value_type& val)
		{
				difference_type	diff = position - begin();

				if (!n)
					return ;
				if (m_size + n > m_capacity)
				{
					if (m_size * 2 > m_size + n)
						reserve(m_size * 2);
					else
						reserve(m_size + n);
				}
				while (n--)
					insert(begin() + diff, val);
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last)
		{	
				difference_type	diff = position - begin();
				
				difference_type len = 0;
				for (InputIterator it = first; it != last; it++)
					len++;
				if (m_size + len > m_capacity)
				{
					if (m_size * 2 > m_size +len)
						reserve(m_size * 2);
					else
						reserve(m_size + len);
				}
				for (difference_type i = 0; first != last; first++, i++)
					insert(begin() + diff + i, *first);
		}

		iterator	erase(iterator position)
		{

			m_alloc.destroy(&(*position));
			for (iterator it = position; it != end() - 1; it++)
			{
				m_alloc.construct(&*(it), *(it + 1));
				m_alloc.destroy(&(*(it + 1)));
			}
			m_size--;
			return position;

		}

		iterator	erase(iterator first, iterator last)
		{
			difference_type range = 0;
			for (iterator it = first; it != last; it++)
				range++;
			for (; range > 0; range--)
				erase(first);
			return first;
		}

		void	swap(vector& x)
		{
			pointer			vector = x.m_vector;
			size_type		size = x.m_size;
			size_type		capacity = x.m_capacity;
			allocator_type	alloc = x.m_alloc;

			x.m_vector = this->m_vector;
			x.m_size = this->m_size;
			x.m_capacity = this->m_capacity;
			x.m_alloc = this->m_alloc;

			this->m_vector = vector;
			this->m_size = size;
			this->m_capacity = capacity;
			this->m_alloc = alloc;
		}

		void	clear(void)
		{
			while (m_size)
				pop_back();
		}

		allocator_type get_allocator() const { return m_alloc; }

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
		friend bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }
		friend bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0; i < lhs.size(); i++)
			{
				if (i >= rhs.size())
					return false;
				if (lhs.m_vector[i] < rhs.m_vector[i])
					return true;
				else if (lhs.m_vector[i] > rhs.m_vector[i])
					return false;
			}
			if (lhs.size() < rhs.size())
				return true;
			return false;
		}
		friend bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0; i < lhs.m_size; i++)
			{
				if (i >= rhs.size())
					return true;
				if (lhs.m_vector[i] > rhs.m_vector[i])
					return true;
				else if (lhs.m_vector[i] < rhs.m_vector[i])
					return false;
			}
			if (lhs.size() > rhs.size())
				return true;
			return false;
		}
		friend bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs > rhs)); }
		friend bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }

		friend void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			pointer			vector = x.m_vector;
			size_type		size = x.m_size;
			size_type		capacity = x.m_capacity;
			allocator_type	alloc = x.m_alloc;

			x.m_vector = y.m_vector;
			x.m_size = y.m_size;
			x.m_capacity = y.m_capacity;
			x.m_alloc = y.m_alloc;

			y.m_vector = vector;
			y.m_size = size;
			y.m_capacity = capacity;
			y.m_alloc = alloc;
		}

	private:
		pointer				m_vector;
		size_type			m_size;
		size_type			m_capacity;
		allocator_type 		m_alloc;
};

template <class Alloc>
class vector<bool,Alloc>;


};

#endif