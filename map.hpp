#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iostream>
# include "pair.hpp"
# include <reverse_iterator.hpp>
# include <map_iterator.hpp>
# define BLACK 0
# define RED 1

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair < const Key, T > > >
class map
{
	public:

		typedef Key										key_type;
		typedef	T										mapped_type;
		typedef	ft::pair<const key_type, mapped_type>	value_type;
		typedef	Compare									key_compare;
		typedef	Compare									value_compare;
		typedef Alloc									allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef ft::map_iterator<value_type>			iterator;
		typedef ft::const_map_iterator<value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t								difference_type;
		typedef size_t									size_type;

		typedef struct									s_binary_tree
		{
			key_type				key;
			mapped_type				value;
			value_type				pair;
			size_type				color;
			struct	s_binary_tree	*father;
			struct	s_binary_tree	*left;
			struct	s_binary_tree	*right;
		}												t_binary_tree;

	explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_alloc(alloc), m_root(NULL) { voic(comp); };
	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& x) { (void)x; };
	~map(void) {};
	
	map&	operator=(const map& x) { (void)x; };

	iterator				begin(void) {return iterator(m_root);};
	const_iterator			begin(void) const { return const_iterator(m_root);};
	iterator				end(void) { return iterator(m_root + m_size); };
	const_iterator			end(void) const { return const_iterator(m_root + m_size); };
	//reverse_iterator		rbegin(void) { return rbegin(); };
	//const_reverse_iterator	rbegin(void) const { return rbegin(); };
	//reverse_iterator		rend(void) { return rbegin(); };
	//const_reverse_iterator	rend(void) const { return rbegin(); };


	bool					empty(void) const { return (m_size); }
	size_type				size(void) const { return (m_size); }
	size_type				max_size(void) const { return (m_alloc.max_size()); }

	mapped_type&	operator[](const key_type& k)
	{
		if (!check_key(m_root, k))
		{
			addNode(k, mapped_type());
			m_size++;
		}
		return (findKey(k));
	}

	ft::pair<iterator,bool>					insert(const value_type& val) { (void)val; };
	iterator								insert(iterator position, const value_type& val) {(void)position; (void)val;};
	template <class InputIterator>
	void									insert(InputIterator first, InputIterator last) {(void)last; (void)first;};
	
	void									erase(iterator position) {  (void)position; };
	size_type								erase(const key_type& k) { (void)k; };
	void									erase(iterator first, iterator last) { (void)last; (void)first; };


	void									swap(map& x) { (void)x; };
	void									clear(void) {};

	key_compare								key_comp(void) const {};
	value_compare							value_comp(void) const {};

	iterator								find(const key_type& k) { (void)k; };
	const_iterator							find(const key_type& k) const { (void)k; };
	size_type								count(const key_type& k) const { (void)k;};
	iterator								lower_bound(const key_type& k) { (void)k; };
	const_iterator							lower_bound(const key_type& k) const { (void)k; };
	iterator								upper_bound(const key_type& k) { (void)k; };
	const_iterator							upper_bound(const key_type& k) const { (void)k; };
	ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const { (void)k; };
	ft::pair<iterator,iterator>				equal_range(const key_type& k) { (void)k; };

	allocator_type get_allocator() const;

	private:
		allocator_type	m_alloc;
		size_type		m_size;
		t_binary_tree	*m_root;
	
	bool	check_key(t_binary_tree *root, key_type k)
	{
		if (!root)
			return (false);
		if (k == root->value)
			return (true);
		else if (k < root->value)
			check_key(root->left, k);
		else
			check_key(root->right, k);
		return (false);
	}

	void			addNode(key_type key, mapped_type value)
	{
		t_binary_tree *root;

		if (!m_root)
		{
			m_root = newNode(key, value);
			return ;
		}
		root = m_root;
		while (root)
		{
			if (key < root->value)
			{
				if (!root->left)
				{
					root->left = newNode(key, value);
					root->left->father = root;
					return ;
				}
				root = root->left;
			}
			else
			{
				if (!root->right)
				{
					root->right = newNode(key, value);
					root->right->father = root;
					return ;
				}
				root = root->right;
			}
		}
	}

	mapped_type&	findKey(const key_type& k)
	{
		t_binary_tree *root = m_root;
	
		while (root)
		{
			if (k < root->value)
				root = root->left;
			else if (k > root->value)
				root = root->right;
			else
				break;
		}
		if (root)
			return root->value;
		else
			return NULL;
	}
	
	t_binary_tree	*newNode(key_type key, mapped_type value)
	{
		t_binary_tree	*newNode = new t_binary_tree();

		newNode->key = key;
		newNode->value = value;
		newNode->color = BLACK;
		newNode->father = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
		
		return newNode;
	}
};

};

#endif