#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iostream>
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "map_iterator.hpp"
# include "binary_search_tree.hpp"

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
			key_type		first;
			mapped_type		second;
			size_type		color;
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

		explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(NULL), m_alloc(alloc), m_compare(comp), v_compare(comp) {};
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(NULL), m_alloc(alloc), m_compare(comp), v_compare(comp)
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		};
		map(const map& x) { (void)x; };
		~map(void) {};
	
		map&	operator=(const map& x) 
		{ 
			iterator	begin = x.begin();
			iterator	end = x.end();
			insert(begin, end);
			return *this;
		};

		iterator				begin(void)
		{ 
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
			tree*	node = *m_root;

			while (node && !node->end)
				node = node->right;
			return iterator(node); 
		};

		const_iterator			end(void) const 
		{
			tree*	node = *m_root;

			while (node && !node->end)
				node = node->right;
			return const_iterator(node); 
		};

		reverse_iterator		rbegin(void) { return reverse_iterator(end()--); };
		const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(end()--); };
		reverse_iterator		rend(void) { return reverse_iterator(begin()); };
		const_reverse_iterator	rend(void) const { return const_reverse_iterator(begin()); };


		bool					empty(void) const { return (m_size); }
		size_type				size(void) const { return (m_size); }
		size_type				max_size(void) const { return (m_alloc.max_size()); }

		mapped_type&			operator[](const key_type& k)
		{
			value_type pair(k, mapped_type());		

			if (!check_key(*m_root, k))
			{
				addNode(pair);
				m_size++;
			}
			tree	*found = findKey(k);
			return (found->second);
		}

		ft::pair<iterator,bool>		insert(const value_type& val)
		{
			ft::pair<iterator, bool>	inserted;
			inserted.second = check_key(*m_root, val.first);

			tree	*newNode = addNode(val);
			inserted.first = iterator(newNode); 

			return inserted; 
		};

		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			(void)val;
			return position;
		};
		template <class InputIterator>
		void									insert(InputIterator first, InputIterator last) {(void)last; (void)first;};
		
		void									erase(iterator position) {  (void)position; };
		size_type								erase(const key_type& k)
		{ 
			tree	*found = findKey(k);
			tree	*father = found->father;
			tree	*left = found->left;
			tree	*right = found->right;

			if (right)
			{
				if (father && father->right == found)
				{
					if (right)
					{
						father->right = right;
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
						father->right = left;
						left->father = father;
					}
				}
				if (father && father->left == found)
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
			}
			m_size--;
			return (m_size);
		};

		void									erase(iterator first, iterator last) { (void)last; (void)first; };


		void									swap(map& x) 
		{ 
			map<Key, T> tmp = x;
				
			x = *this;
			*this = tmp;
		};
		void									clear(void) {};

		key_compare		key_comp(void) const { return m_compare; };
		value_compare	value_comp(void) const { return v_compare; };

		iterator			find(const key_type& k) { (void)k; return iterator(*m_root); };
		const_iterator		find(const key_type& k) const { (void)k; return const_iterator(*m_root); };
		size_type			count(const key_type& k) const { (void)k; return m_size; };
		
		iterator			lower_bound(const key_type& k) 
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(k, it->first)))
					return iterator(it--);
			}
			return iterator(*m_root); 
		};

		const_iterator		lower_bound(const key_type& k) const
		{ 
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(k, it->first)))
					return const_iterator(it--);
			}
			return const_iterator(*m_root); 
		};

		iterator			upper_bound(const key_type& k)
		{ 
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(k, it->first)))
					return iterator(it);
			}
			return iterator(*m_root); 
		};

		const_iterator		upper_bound(const key_type& k) const
		{
			for (iterator it = begin(); it != end(); it++)
			{
				if (!(m_compare(k, it->first)))
					return const_iterator(it--);
			}
			return const_iterator(*m_root); 
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
			if (!m_root)
			{
				m_root = new tree*;
				*m_root = newNode(val);
				tree	*last = newNode(val);
				(*m_root)->right = last;
				last->end = 1;
				m_size++;
				return *m_root;
			}
			tree	*ref = *m_root;
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
			newNode->first = pr->first;
			newNode->second = pr->second;
			newNode->color = BLACK;
			newNode->end = 0;
			newNode->father = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		tree	*findKey(const key_type& k) const
		{
			tree *node = *m_root;
		
			while (node)
			{
				if (k < node->first)
					node = node->left;
				else if (k > node->first)
					node = node->right;
				else
					break;
			}
			return node;
		}

		bool	check_key(tree *root, const key_type& k)
		{
			if (!root)
				return (false);
			if (k == root->first)
				return (true);
			else if (k < root->first)
				check_key(root->left, k);
			else
				check_key(root->right, k);
			return (false);
		}

		void	print_tree(tree *root)
		{
			if (root)
			{
				if (root->left)
					print_tree(root->left);
				if (root->right)
					print_tree(root->right);
			}
			std::cout << "Key =   " << root->pair->first << std::endl;
			std::cout << "Value = " << root->pair->second << std::endl << "   ---" << std::endl;
		}

};
};

#endif