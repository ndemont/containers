#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iostream>
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "map_iterator.hpp"
# include "binary_search_tree.hpp"
# include "lexicographical_compare.hpp"

# define BLACK 0
# define RED 1

namespace ft
{
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair < const Key, T > > >
class map
{
	public:
		typedef Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		typedef	Compare										value_compare;
		typedef Alloc										allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef value_type*									pointer;
		typedef const value_type*							const_pointer;
		typedef size_t										size_type;

		typedef struct		s_tree
		{
			value_type		*pair;
			bool			end;
			s_tree			*father;
			s_tree			*left;
			s_tree			*right;
		}					tree;

		typedef ft::map_iterator<tree, value_type>			iterator;
		typedef ft::const_map_iterator<tree, value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;

		explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(initEnd()), m_alloc(alloc), m_compare(comp), v_compare(comp) {};
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(initEnd()), m_alloc(alloc), m_compare(comp), v_compare(comp)
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		};
		map(const map& x) : m_size(0), m_root(initEnd()), m_alloc(x.m_alloc), m_compare(x.m_compare), v_compare(x.v_compare)
		{ 
			if (this != &x)
				*this = x;
		};
		~map(void) {};
	
		map&	operator=(const map& x) 
		{
			clear();
			insert(x.begin(), x.end());
			return *this;
		};

		iterator				begin(void)
		{
			if (!m_root)
				return iterator(NULL);
			tree*	node = *m_root;
			while (node)
			{
				if (node->left)
					node = node->left;
				else
					break ;
			}

			return iterator(node); 
		};
		const_iterator			begin(void) const 
		{
			if (!m_root)
				return iterator(NULL);
			tree*	node = *m_root;
			while (node)
			{
				if (node->left)
					node = node->left;
				else
					break ;
			}
			return const_iterator(node); 
		};

		iterator				end(void) 
		{
			if (!m_root)
				return begin();
			tree*	node = *m_root;
			while (node && !node->end)
				node = node->right;
			return iterator(node); 
		};

		const_iterator			end(void) const 
		{
			if (!m_root)
				return begin();
			tree*	node = *m_root;
			while (node && !node->end)
				node = node->right;

			return const_iterator(node); 
		};

		reverse_iterator		rbegin(void) { return reverse_iterator(end()--); };
		const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(end()--); };
		reverse_iterator		rend(void) { return reverse_iterator(begin()); };
		const_reverse_iterator	rend(void) const { return const_reverse_iterator(begin()); };


		bool					empty(void) const { return (!m_size); }
		size_type				size(void) const { return (m_size); }
		size_type				max_size(void) const { return (m_alloc.max_size()); }

		mapped_type&			operator[](const key_type& k)
		{
			value_type pair(k, mapped_type());
			if (!m_root || !check_key(pair))
			{
				addNode(pair);
			}
			tree	*found = findKey(k);
			return (found->pair->second);
		}

		ft::pair<iterator,bool>		insert(const value_type& val)
		{
			ft::pair<iterator, bool>	inserted;
			inserted.second = !(check_key(val));
			tree	*newNode = addNode(val);
			inserted.first = iterator(newNode); 

			return inserted; 
		};

		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			ft::pair<iterator, bool>	inserted = insert(val); 
			return inserted.first;
		};

		template <class InputIterator>
		void	insert(InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last)
		{
			for (; first != last; first++)
				addNode(*first);
		};
		
		void		erase(iterator position)
		{
			erase((*position).first);
		};

		size_type	erase(const key_type& k)
		{ 
			tree	*found = findKey(k);
			if (!found)
				return 0;
			tree	*father = found->father;
			tree	*left = found->left;
			tree	*right = found->right;

			if (right)
			{
				if (father && father->right == found)
				{
					father->right = right;
					right->father = father;
					if (left)
					{
						tree	*tmp = father;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = left;
						if (left)
							left->father = tmp;
					}
				}
				else if (father && father->left == found)
				{
					if (right)
					{
						father->left = right;
						right->father = father;
						if (left)
						{
							tree	*tmp = father;
							while (tmp->left)
								tmp = tmp->left;
							tmp->left = left;
							left->father = tmp;
						}
					}
					else
					{
						father->left = left;
						left->father = father;
					}
				}
				else
				{
					iterator up = upper_bound(k);
					tree	*upt = findKey((*up).first);
					if (left)
					{
						upt->left = left;
						left->father = upt;
					}
					*m_root = right;
					right->father = NULL;
				}
			}
			else if (left)
			{
				if (father && father->right == found)
				{
					left->father = father;
					father->right = left;
					while (left->right)
						left = left->right;
					left->right = found->right;
				}
				else if (father && father->left == found)
				{
					left->father = father;
					father->left = left;
					while (left->right)
						left = left->right;
					left->right = found->right;
				}
				else
				{
					m_root = &left;
					left->father = NULL;
					while (left->right)
						left = left->right;
					left->right = found->right;
				}
			}
			m_size--;
			return (1);
		};

		void	erase(iterator first, iterator last)
		{ 
			for (iterator it = first; it != last; it++)
				erase((*it).first);
		};

		void	swap(map& x) 
		{ 
			map<Key, T> tmp = x;
				
			x = *this;
			*this = tmp;
		};
		void			clear(void)
		{
			size_t s = m_size;

			if (m_root)
			{
				for (iterator it = begin(); s-- > 0; it++)
					delete it.base();
				delete m_root;
				m_root = NULL;
			}
			m_size = 0;
		};

		key_compare			key_comp(void) const { return m_compare; };
		value_compare		value_comp(void) const { return v_compare; };

		iterator			find(const key_type& k)
		{ 
			tree	*found = findKey(k);

			if (!found)
				return end();
			else
				return iterator(found); 
		};
		const_iterator		find(const key_type& k) const
		{ 
			tree	*found = findKey(k);

			if (!found)
				return end();
			else
				return const_iterator(found); 
		};
		size_type			count(const key_type& k) const
		{ 
			if (findKey(k))
				return (1);
			else
				return (0);
		};
		
		iterator			lower_bound(const key_type& k) 
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(it->first, k)))
					return iterator(it);
			}
			return end(); 
		};

		const_iterator		lower_bound(const key_type& k) const
		{ 
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(it->first, k)))
					return const_iterator(it);
			}
			return end();
		};

		iterator			upper_bound(const key_type& k)
		{ 
			for (iterator it = begin(); it != end(); it++)
			{
				if ((m_compare(k, it->first)))
					return iterator(it);
			}
			return end(); 
		};

		const_iterator		upper_bound(const key_type& k) const
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if ((m_compare(k, it->first)))
					return const_iterator(it);
			}
			return end(); 
		};

		ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const 
		{ 
			ft::pair<const_iterator, const_iterator>	range;
			
			range.first = lower_bound(k); 
			range.second = upper_bound(k);

			return range; 
		};
		ft::pair<iterator,iterator>				equal_range(const key_type& k)
		{ 
			ft::pair<iterator, iterator> range;
			
			range.first = lower_bound(k); 
			range.second = upper_bound(k);

			return range; 
		};

		allocator_type get_allocator() const;

		private:
			size_type		m_size;
			tree			**m_root;
			allocator_type	m_alloc;
			key_compare		m_compare;
			value_compare	v_compare;

		tree	*addNode(ft::pair<const key_type, mapped_type> val)
		{
			if (check_key(val))
			{
				iterator	existing = findKey(val.first);
				return (existing.base());
			}
			if (!m_root)
			{
				m_root = new tree*;
				*m_root = newNode(val);
				tree	*last = newNode(val);
				(*m_root)->right = last;
				last->end = 1;
				last->father = *m_root;
				m_size++;
				return *m_root;
			}
			tree	*ref = *m_root;
			if (ref->end)
			{
				tree	*first = newNode(val);
				first->right = ref;
				ref->father = first;
				*m_root = first;
				m_size++;
				return *m_root;
			}
			while (ref)
			{
				if (m_compare(val.first, ref->pair->first))
				{
					if (!ref->left)
					{
						ref->left = newNode(val);
						ref->left->father = ref;
						m_size++;
						return ref->left;
					}
					ref = ref->left;
				}
				else
				{
					if (!ref->right)
					{
						ref->right = newNode(val);
						ref->right->father = ref;
						m_size++;
						return ref->right;
					}
					if (ref->right->end)
					{
						tree	*last = ref->right;
						ref->right = newNode(val);
						ref->right->father = ref;
						ref->right->right = last;
						last->father = ref->right;
						m_size++;
						return ref->right;
					}
					ref = ref->right;
				}
			}
			return NULL;
		}
 
		tree	*newNode(ft::pair<const key_type, mapped_type> val)
		{
			tree									*newNode = new tree;
			ft::pair<const key_type, mapped_type>	*pr = new pair<const key_type, mapped_type>(val);
			
			newNode->pair = pr;
			newNode->end = false;
			newNode->father = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		tree	*findKey(const key_type& k) const
		{
			for (iterator it = begin(); it != end(); it++)
				if ((*it).first == k)
					return it.base();
			return NULL;
		}

		bool	check_key(const value_type& val)
		{
			for (iterator it = begin(); it != end(); it++)
				if ((*it).first == val.first)
					return true;
			return false;
		}

		tree	**initEnd()
		{
			m_root = new tree*;
			value_type val = value_type();
			tree*	endNode = newNode(val);
			endNode->end = true;
			*m_root = endNode; 
			return (m_root);
		}

		friend bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) 
		{
			if (lhs.size() == rhs.size()) 
				return true;
			iterator	it_lhs = lhs.begin();
			iterator	it_rhs = rhs.begin();
			while ((it_lhs != lhs.end()) && (it_rhs != rhs.end()))
			{
				if ((*it_lhs).first != (*it_rhs).first)
					return false;
				if ((*it_lhs).second != (*it_rhs).second)
					return false;
				it_lhs++;
				it_rhs++;
			}
			if ((it_lhs == lhs.end()) && (it_rhs != rhs.end()))
				return true;
			return false;
		}
		friend bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
		friend bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			if (lhs.size() == rhs.size())
				return true;
			return false;
		}
		friend bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }
		friend bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }
		friend bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs < rhs)); }

};
};

#endif