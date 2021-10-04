
#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include "binary_search_tree.hpp"
# include "iterator.hpp"

namespace ft
{

template <class T>
class const_map_iterator;

template <class T>
class map_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef	ptrdiff_t								difference_type;
		typedef size_t									size_type;

		map_iterator(void) {};
		map_iterator(value_type *x) : m_iterator(x) {};
		map_iterator(map_iterator const & x) : m_iterator(x.m_iterator) {};
		map_iterator(const_map_iterator<T> const & x) : m_iterator(x.base()) {};
		~map_iterator(void){};

		map_iterator&			operator=(const map_iterator& x) { m_iterator = x.m_iterator; return *this; }
		
		bool					operator==(const map_iterator& x) const { return (m_iterator == x.base()); }
		bool					operator!=(const map_iterator& x) const { return (m_iterator != x.base()); }

		reference				operator*(void) const { return *m_iterator; }
		pointer					operator->(void) const { return	m_iterator; }

		map_iterator&			operator++(void)
		{ 
			if (m_iterator->right)
			{
				m_iterator = m_iterator->right;
				while (m_iterator->left)
					m_iterator = m_iterator->left;
			}
			else if (m_iterator->father)
				m_iterator = m_iterator->father;
			return *this; 
		}
		map_iterator			operator++(int)  
		{ 
			return map_iterator(m_iterator++); 
		}
		map_iterator&			operator--(void) 
		{ 
			while (m_iterator->left)
				m_iterator = m_iterator->left;
			return *this; 
		}
		map_iterator			operator--(int)  
		{ 
			return map_iterator(m_iterator--); 
		}


		value_type*				base(void) const {return m_iterator;};

	private:
		value_type*				m_iterator;
};

template <class T>
class const_map_iterator : public iterator<random_access_iterator_tag, T>
{

	public:
		typedef T			value_type;
		typedef const T*	pointer;
		typedef const T&	reference;
		typedef	ptrdiff_t	difference_type;
		typedef size_t		size_type;

		const_map_iterator(void) {};
		const_map_iterator(value_type *x) : m_iterator(x) {};
		const_map_iterator(const_map_iterator const & x) : m_iterator(x.m_iterator) {};
		const_map_iterator(map_iterator<T> const & x) : m_iterator(x.base()) {};
		~const_map_iterator(void){};

		const_map_iterator&			operator=(const const_map_iterator& x) { m_iterator = x.m_iterator; return *this; }

		bool						operator==(const const_map_iterator& x) const { return (m_iterator == x.base()); }
		bool						operator!=(const const_map_iterator& x) const { return (m_iterator != x.m_iterator); }

		reference					operator*(void) const { return *m_iterator; }
		pointer						operator->(void) const { return	m_iterator; }

		const_map_iterator&			operator++(void) { m_iterator++; return *this; }
		const_map_iterator			operator++(int)  { return const_map_iterator(m_iterator++); }
		const_map_iterator&			operator--(void) { m_iterator--; return *this; }
		const_map_iterator			operator--(int)  { return const_map_iterator(m_iterator--); }


		value_type*					base(void) const { return m_iterator; };


	private:
		value_type*					m_iterator;
};
};

#endif