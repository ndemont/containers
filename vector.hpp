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
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef value_type &											reference;
		typedef value_type const &										const_reference;
		typedef value_type *											pointer;
		typedef value_type const *										const_pointer;
		typedef ft::iterator<random_access_iterator_tag, value_type>	iterator;
		typedef const iterator											const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef const reverse_iterator									const_reverse_iterator;
		typedef	std::ptrdiff_t											difference_type;
		typedef	size_t													size_type;

		/* CONSTRUCTORS */
		explicit vector<T>(const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_vector(NULL), m_size(0), m_capacity(0) {};
		explicit vector<T>(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_size(n), m_capacity(n)
		{
			m_vector = m_alloc.allocate(m_capacity);
			for (size_type i = 0; i < m_size; i++) 
				m_vector[i] = val;
		}
		vector<T>(iterator first, iterator last, const allocator_type& alloc = allocator_type()) : m_alloc(alloc)
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
		vector<T>(const vector<T>&x) : m_alloc(x.m_alloc), m_vector(NULL), m_size(0), m_capacity(0)
		{
			if (this != &x)
				*this = x;
		}

		/* DESTRUCTOR */
		~vector<T>(void)
		{
			if (m_vector)
				m_alloc.deallocate(m_vector, m_capacity);
		}

		/* OPERATOR= */
		vector& operator=(const vector& x)
		{
			if (m_vector)
				m_alloc.deallocate(m_vector, m_capacity);
			m_alloc = x.m_alloc;
			m_capacity = x.m_capacity;
			m_size = 0;
			m_vector = m_alloc.allocate(m_capacity);
			for (size_type i = 0; i < x.m_size; i++)
			{
				value_type a = x[i];
				this->push_back(a);
			}
			return *this;
		}

		/* ITERATORS */
		iterator	begin(void)
		{
			iterator	begin(m_vector);
			return begin;
		}
		const_iterator begin(void) const
		{
			iterator begin(m_vector);
			return begin;
		}
		iterator end()
		{
			iterator end(m_vector + m_size);
			return end;
		}
		const_iterator end() const
		{
			iterator end(m_vector + m_size);
			return end;
		}
		//rbegin;
		//rend;
		
		/* CAPACITY */
		size_type size(void) const
		{
			return m_size;
		}
		size_type max_size() const
		{
			return (m_alloc.max_size());
		}
		void resize (size_type n, value_type val = value_type())
		{
			if (n < m_size)
			{
				for (size_t i = n; i < m_size; i++)
					m_vector[i].~value_type();
				m_size = n;
			}
			else if (n > m_size)
			{
				if (n > m_capacity)
				{
					value_type *tmp = new value_type(m_size);

					for (size_type i = 0; i < m_size; i++)
						tmp[i] = m_vector[i];
					m_vector = m_alloc.allocate(n, m_vector);
					m_capacity = n;
					for (size_type i = 0; i < n; i++)
						m_vector[i] = tmp[i];
					delete tmp;
				}
				for (size_type i = m_size; i < n; i++)
					m_vector[i] = val;
				m_size = n;
			}

		}
		size_type capacity(void) const
		{
			return m_capacity;
		}
		bool empty(void) const
		{
			return (m_size);
		}
		void reserve (size_type n)
		{
			if (n > m_capacity)
			{
				value_type *tmp = new value_type(m_size);

				for (size_type i = 0; i < m_size; i++)
					tmp[i] = m_vector[i];
				m_vector = m_alloc.allocate(n, m_vector);
				m_capacity = n;
				for (size_type i = 0; i < n; i++)
					m_vector[i] = tmp[i];
				delete tmp;
			}
		}

		/* ELEMENT ACCESS */
		reference operator[](size_type n)
		{
			iterator pos = this->begin();
			pos = pos + n;
			return *pos;
		}
		const_reference operator[](size_type n) const
		{
			iterator pos = this->begin();
			pos = pos + n;
			return *pos;
		}
		reference at (size_type n)
		{
			try
			{
				if (m_size < n)
					throw std::out_of_range("element is out of range");
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			return m_vector[n];
		}
		const_reference at (size_type n) const
		{
			try
			{
				if (m_size < n)
					throw std::out_of_range("element is out of range");
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			return m_vector[n];
		}
		reference front(void)
		{
			iterator pos = this->begin();
			return *pos;
		}
		const_reference front(void) const
		{
			iterator pos = this->begin();
			return *pos;
		}
		reference back(void)
		{
			iterator pos = this->end();

			pos--;
			return *pos;
		}
		const_reference back(void) const
		{
			iterator pos = this->end();

			pos--;
			return *pos;
		}

		/* MODIFIERS */
		template <class InputIterator>
		void assign	(InputIterator first, InputIterator last)
		{

		}
		void assign	(size_type n, const value_type& val)
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
		void push_back	(const value_type& val)
		{
			if (m_size == m_capacity)
			{
				m_vector = m_alloc.allocate(m_capacity + 1, m_vector);
				m_capacity++;
			}
			m_vector[m_size] = val;
			m_size++;
		}
		void pop_back (void)
		{
			m_size--;
			m_vector[m_size].~value_type();
		}

		iterator insert (iterator position, const value_type& val)
		{

		}
		void insert (iterator position, size_type n, const value_type& val)
		{

		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{

		}

		iterator erase (iterator position)
		{
			iterator erased;

			(*position).~value_type();
			erased = position;
			position++;
			while (position != this->end())
			{
				*(position - 1) = *position;
				position++;
			}
			return erased;
		}
		iterator erase (iterator first, iterator last)
		{
			return first;
		}

		void swap (vector& x)
		{
			vector tmp;

			tmp = x;
			x = this;
			this = tmp;
		}
		void clear(void)
		{
			for (size_type i = 0; i < m_size; i++)
				m_vector[i].~value_type();
		}

		/* ALLOCATOR */
		//get_allocator;

		/* NON-MEMBER FONCTION OVERLOADS */
		//relational operators;
		//swap;

		/* TEMPLATE SPEXIALIZATIONS */
		//vector<bool>;

	private:
		value_type			*m_vector;
		size_type			m_size;
		size_type			m_capacity;
		allocator_type 		m_alloc;
};

};

#endif