#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "binary_function.hpp"
# include "equal.hpp"
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "map_iterator.hpp"
# include "pair.hpp"

# define BLACK 0
# define RED 1

namespace ft
{

	template <typename T>
	struct tree
	{
		T				pair;
		bool			end;
		int				nada;
		struct tree<T>	*father;
		struct tree<T>	*left;
		struct tree<T>	*right;
		tree(T p, bool last = false) : pair(p), end(last), father(NULL), left(NULL), right(NULL) {}; 
	};

template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair < const Key, T > > >
class map
{
	public:
		typedef Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		class value_compare : ft::binary_function<value_type, value_type, bool>
		{ 
  			friend class map;
			protected:
  				Compare comp;
 			value_compare (Compare c) : comp(c) {}
			public:
  				typedef bool result_type;
  				typedef value_type first_argument_type;
  				typedef value_type second_argument_type;
  				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		};
		typedef tree<value_type>											node_type; 
		typedef Alloc														allocator_type;
		typedef value_type&													reference;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
		typedef const value_type&											const_reference;
		typedef value_type*													pointer;
		typedef const value_type*											const_pointer;
		typedef size_t														size_type;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator_type;
		typedef ft::map_iterator<node_type, value_type>						iterator;
		typedef ft::const_map_iterator<tree<value_type>, value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		typedef ptrdiff_t													difference_type;

		explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(initEnd()), m_alloc(alloc), m_node_alloc(node_allocator_type()), m_compare(comp), v_compare(value_compare(comp)) {};
		template <class InputIterator>
		map(InputIterator first, typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(initEnd()), m_alloc(alloc), m_node_alloc(node_allocator_type()), m_compare(comp), v_compare(value_compare(comp))
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		};
		map(const map& x) : m_size(0), m_root(initEnd()), m_alloc(x.m_alloc), m_node_alloc(x.m_node_alloc), m_compare(x.m_compare), v_compare(x.v_compare)
		{ 
			if (this != &x)
				*this = x;
		};
		~map(void) { clear(); };
	
		map&	operator=(const map& x) { clear(); insert(x.begin(), x.end()); return *this; };

		iterator				begin(void)
		{
			if (!m_root)
				return iterator(NULL);
			node_type*	node = m_root;
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
			tree<value_type>*	node = m_root;
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
			tree<value_type>*	node = m_root;
			while (node && !node->end)
				node = node->right;
			return iterator(node); 
		};

		const_iterator			end(void) const 
		{
			if (!m_root)
				return begin();
			tree<value_type>*	node = m_root;
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
		size_type				max_size(void) const { return (m_node_alloc.max_size()); }

		mapped_type&			operator[](const key_type& k)
		{
			value_type pair(k, mapped_type());
			if (!m_root || !check_key(pair))
				addNode(pair);
			tree<value_type>	*found = findKey(k);
			return (found->pair.second);
		}

		ft::pair<iterator,bool>		insert(const value_type& val)
		{
			ft::pair<iterator, bool>	inserted;
			inserted.second = !(check_key(val));
			node_type	*newNode = addNode(val);
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
			{
				addNode(*first);
			}
		};
		
		void		erase(iterator position)
		{
			erase((*position).first);
		};

		size_type	erase(const key_type& k)
		{ 
			node_type	*found = findKey(k);
			if (!found)
				return 0;
			node_type	*father = found->father;
			node_type	*left = found->left;
			node_type	*right = found->right;
			if (right)
			{
				if (father && father->right == found)
				{
					father->right = right;
					right->father = father;
					if (left)
					{
						node_type	*tmp = right;
						while (tmp->left)
							tmp = tmp->left;
						tmp->left = left;
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
							node_type	*tmp = father;
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
					node_type	*upt = findKey((*up).first);
					if (left)
					{
						upt->left = left;
						left->father = upt;
					}
					m_root = right;
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
					m_root = left;
					left->father = NULL;
					while (left->right)
						left = left->right;
					left->right = found->right;
				}
			}
			else
			{
				if (father)
				{
					if (father->right == found)
						father->right = NULL;
					else if (father->left == found)
						father->left = NULL;
				}
			}
			m_alloc.destroy(&(found->pair));
			m_node_alloc.deallocate(found, 1);
			found = NULL;
			m_size--;
			return (1);
		};

		void	erase(iterator first, iterator last)
		{
			map<key_type, mapped_type>	tmp(first, last);
			for (iterator it = tmp.begin(); it != tmp.end(); it++)
				erase((*it).first);
		};

		void	swap(map& x) 
		{
			node_type	*tree;
			size_type	size;

			tree = x.m_root;
			size = x.m_size;
				
			x.m_root = this->m_root;
			x.m_size = this->m_size;

			this->m_root = tree;
			this->m_size = size;
		};

		void			clear(void)
		{
			clear_recur(m_root);
			m_root = NULL;
		};

		void	clear_recur(node_type *root)
		{
			if (root)
			{	
				if (root->left)
					clear_recur(root->left);
				if (root->right)
					clear_recur(root->right);
				m_alloc.destroy(&(root->pair));
				m_node_alloc.deallocate(root, 1);
				m_size = 0;
			}
			return ;
		}

		key_compare			key_comp(void) const { return m_compare; };

		value_compare		value_comp(void) const { return v_compare; };

		iterator			find(const key_type& k)
		{ 
			node_type	*found = findKey(k);

			if (!found)
				return end();
			else
				return iterator(found); 
		};
		const_iterator		find(const key_type& k) const
		{ 
			node_type	*found = findKey(k);

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
			for (const_iterator it = begin(); it != end(); it++)
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
			for (const_iterator it = begin(); it != end(); it++)
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
		ft::pair<iterator,iterator>	equal_range(const key_type& k)
		{ 
			ft::pair<iterator, iterator> range;
			
			range.first = lower_bound(k); 
			range.second = upper_bound(k);

			return range; 
		};

		allocator_type get_allocator() const;

		private:
			size_type			m_size;
			tree<value_type>	*m_root;
			allocator_type		m_alloc;
			node_allocator_type	m_node_alloc;
			key_compare			m_compare;
			value_compare		v_compare;

		node_type	*addNode(ft::pair<const key_type, mapped_type> val)
		{
			if (check_key(val))
			{
				iterator	existing = findKey(val.first);
				return (existing.base());
			}
			if (!m_root)
			{
				m_root = newNode(val);
				tree<value_type>	*last = newNode(val);
				(m_root)->right = last;
				last->end = 1;
				last->father = m_root;
				m_size++;
				return m_root;
			}
			node_type	*ref = m_root;
			if (ref->end)
			{
				node_type	*first = newNode(val);
				first->right = ref;
				ref->father = first;
				m_root = first;
				m_size++;
				return m_root;
			}
			while (ref)
			{
				if (m_compare(val.first, ref->pair.first))
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
						node_type	*last = ref->right;
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
 
		tree<value_type>	*newNode(ft::pair<const key_type, mapped_type> val)
		{
			node_type	*newNode = m_node_alloc.allocate(1);
			
			m_alloc.construct(&(newNode->pair), val);
			newNode->end = false;
			newNode->father = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		node_type	*findKey(const key_type& k) const
		{
			for (const_iterator it = begin(); it != end(); it++)
			{
				if ((*it).first == k)
					return it.base();
			}
			return NULL;
		}

		bool	check_key(const value_type& val)
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if ((*it).first == val.first)
					return true;
			}
			return false;
		}

		node_type	*initEnd(void)
		{
			node_type*	endNode = m_node_alloc.allocate(1);
			m_node_alloc.construct(endNode, node_type(value_type(), true));
			m_root = endNode; 
			return (m_root);
		}

		friend bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) 
		{
			if (lhs.m_size != rhs.m_size)
				return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		friend bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
		friend bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
		friend bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }
		friend bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }
		friend bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs < rhs)); }

};

	template <class Key, class T, class Compare, class Alloc>
	void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

};

#endif