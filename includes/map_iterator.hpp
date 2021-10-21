
#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "binary_function.hpp"
# include "equal.hpp"
# include "input_iterator.hpp"
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "map.hpp"
# include "pair.hpp"
# include "random_access_iterator_tag.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

template <class T, class U>
class const_map_iterator;

template <class T, class U>
class map_iterator : public ft::iterator<random_access_iterator_tag, T>
{
	public:
		typedef T					iterator_type;
		typedef U					value_type;
		typedef U*					pointer;
		typedef U&					reference;
		typedef	ptrdiff_t			difference_type;
		typedef size_t				size_type;

		map_iterator(void) {};
		map_iterator(iterator_type *x) : m_iterator(x) {};
		map_iterator(map_iterator const & x) : m_iterator(x.base()) {};
		//map_iterator(const_map_iterator<T, U> const & x) : m_iterator(x.base()) {};
		~map_iterator(void){};

		map_iterator&			operator=(const map_iterator& x) { m_iterator = x.m_iterator; return *this; }
		
		bool					operator==(const map_iterator& x) const { return (m_iterator == x.base()); }
		bool					operator!=(const map_iterator& x) const { return (m_iterator != x.base()); }
		template <class V, class W>
		friend bool				operator!=(const map_iterator& lhs, const const_map_iterator<V, W>& rhs) { return (lhs.base() != rhs.base()); }

		reference				operator*(void) const { return (m_iterator->pair); }
		pointer					operator->(void) const { return	&(operator*()); }

		map_iterator&			operator++(void)
		{
			if (m_iterator->right)
			{
				m_iterator = m_iterator->right;
				while (m_iterator->left)
					m_iterator = m_iterator->left;
			}
			else if (m_iterator->father && m_iterator->father->left == m_iterator)
			{
				m_iterator = m_iterator->father;
			}
			else if (m_iterator->father && m_iterator->father->right == m_iterator)
			{
				m_iterator = m_iterator->father;
				while (m_iterator->father)
				{
					if (m_iterator->father && (m_iterator->father->left == m_iterator))
					{
						m_iterator = m_iterator->father;
						return *this;
					}
					else
						m_iterator = m_iterator->father;
				}
			}
			return *this; 
		}

		map_iterator			operator++(int)  
		{
			map_iterator it = *this;
			++(*this);
			return it; 
		}

		map_iterator&			operator--(void) 
		{
			iterator_type*		father;
			iterator_type*		node;


			if (m_iterator->left)
			{
				m_iterator = m_iterator->left;
			}
			else if (m_iterator->father && m_iterator->father->right == m_iterator)
			{
				m_iterator = m_iterator->father;
			}
			else if (m_iterator->father && m_iterator->father->left == m_iterator)
			{
				father = m_iterator->father;
				node = m_iterator;
				while (father && father->right != node)
				{
					node = father;
					father = node->father;
				}
				if (father)
					m_iterator = father;
			}
			return *this;
		}

		map_iterator			operator--(int)  
		{ 
			map_iterator it = *this;
			--(*this);
			return it; 
		}

		iterator_type*			base(void) const {return m_iterator;};

	private:
		iterator_type*			m_iterator;
};

template <class T, class U>
class const_map_iterator : public ft::iterator<random_access_iterator_tag, T>
{
	public:	
		typedef T					iterator_type;
		typedef U					value_type;
		typedef const U*			pointer;
		typedef const U&			reference;
		typedef	ptrdiff_t			difference_type;
		typedef size_t				size_type;

		const_map_iterator(void) {};
		const_map_iterator(iterator_type *x) : m_iterator(x) {};
		const_map_iterator(const_map_iterator const & x) : m_iterator(x.base()) {};
		const_map_iterator(map_iterator<T, U> const & x) : m_iterator(x.base()) {};
		~const_map_iterator(void){};

		const_map_iterator&			operator=(const const_map_iterator& x)
		{ 
			m_iterator = x.m_iterator;
			return *this; 
		}

		bool					operator==(const const_map_iterator& x) const { return (m_iterator == x.base()); }
		bool					operator!=(const const_map_iterator& x) const { return (m_iterator != x.base()); }


		reference				operator*(void) const { return (m_iterator->pair); }
		pointer					operator->(void) const { return	&(operator*()); }

		const_map_iterator&		operator++(void) 
		{
			if (m_iterator && m_iterator->right)
			{
				m_iterator = m_iterator->right;
				while (m_iterator->left)
					m_iterator = m_iterator->left;
			}
			else if (m_iterator && m_iterator->father && m_iterator->father->left == m_iterator)
			{
				m_iterator = m_iterator->father;
			}
			else if (m_iterator && m_iterator->father && m_iterator->father->right == m_iterator)
			{
				m_iterator = m_iterator->father;
				while (m_iterator->father)
				{
					if (m_iterator->father && (m_iterator->father->left == m_iterator))
					{
						m_iterator = m_iterator->father;
						return *this;
					}
					else
						m_iterator = m_iterator->father;
				}
			}
			return *this; 
		}
		const_map_iterator		operator++(int) 
		{
			const_map_iterator it = *this;
			++(*this);
			return it; 
		}
		const_map_iterator&		operator--(void)
		{ 
			iterator_type*	father;
			iterator_type*	node;

			if (m_iterator->left)
				m_iterator = m_iterator->left;
			else if (m_iterator->father && m_iterator->father->right == m_iterator)
				m_iterator = m_iterator->father;
			else if (m_iterator->father && m_iterator->father->left == m_iterator)
			{
				father = m_iterator->father;
				node = m_iterator;
				while (father && father->right != node)
				{
					node = father;
					father = node->father;
				}
				if (father)
					m_iterator = father;
			}
			return *this;
		}
		const_map_iterator		operator--(int)
		{ 
			const_map_iterator it = *this;
			--(*this);
			return it;
		}

		iterator_type*			base(void) const { return m_iterator; };


	private:
		iterator_type*					m_iterator;
};
};

#endif