#ifndef VECTOR_HPP
# define VECTOR_HPP

//# include "iterator_traits.hpp"
# include <iostream>

template <typename T, class Alloc = std::allocator<T> >
class vector
{
	public:
		
		/* MEMBER TYPES */
		class iterator;
		typedef T													value_type;
		typedef Alloc												allocator_type;
		// typedef allocator_type::reference						reference;
		// typedef allocator_type::const_reference					const_reference;
		// typedef allocator_type::pointer							pointer;
		// typedef allocator_type::const_pointer					const_pointer;
		// typedef random_access_iterator_tag						iterator;
		// typedef const random_access_iterator_tag					const_iterator;
		// typedef reverse_iterator<iterator>						reverse_iterator;
		// typedef const reverse_iterator<iterator>					const_reverse_iterator;
		//typedef	ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef	size_t												size_type;

		/* CONSTRUCTORS */
		explicit vector<T>(const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_vector(0), m_size(0) {};
		explicit vector<T>(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_size(n)
		{
			m_vector = m_alloc.allocate(m_size);
			std::cout << "Size constructor called" << std::endl;
			for (size_type i = 0; i < m_size; i++) 
				m_vector[i] = val;
			std::cout << "Size construction done" << std::endl;
		}
        vector<T>(iterator first, iterator last, const allocator_type& alloc = allocator_type()) : m_alloc(alloc)
		{
			m_size = last - first;
			m_vector = m_alloc.allocate(m_size);
			for (size_type i = 0; first != last; i++)
			{
				m_vector[i] = *first;
				i++;
				first++;
			}
		}
		vector<T>(const vector<T>&x) 
		{
			if (this != &x)
				*this = x;
		}
		~vector<T>(void)
		{
			if (m_vector)
				delete m_vector;
		}

		/* OPERATORS */
		vector& operator=(const vector& x)
		{
			if (m_vector)
				delete m_vector;
			m_alloc = x.m_alloc;
			m_size = x.m_size;
			m_vector = m_alloc.allocate(m_size);
			for (size_type i = 0; i < m_size; i++)
				m_vector[i] = x[i];
			return *this;
		}
		value_type & operator[](size_type n)
		{
			return m_vector[n];
		}

		value_type const & operator[](size_type n) const
		{
			return m_vector[n];
		}

		/* ITERATOR */
		class iterator
		{
			public:
				iterator(T *vector) : m_iterator(vector) {};
				iterator(iterator const & x) : m_iterator(x.m_iterator) {};
				~iterator(void){};

				iterator&	operator=(const iterator& x)
				{
					m_iterator = x.m_iterator;
				}
				iterator&	operator-(const iterator& x)
				{
					return (x.m_iterator - m_iterator);
				}
				iterator&	operator++(void)
				{
					m_iterator++;
					return *this;
				}
				iterator	operator++(int)
				{
					++m_iterator;
					return this;
				}
				T	operator*(void) 
				{
					return *m_iterator;
				}

			private:
				iterator(void){};
				T*	m_iterator;
  		};
		
	private:
	value_type			*m_vector;
	size_type			m_size;
	allocator_type 		m_alloc;
};

#endif