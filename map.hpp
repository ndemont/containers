#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iostream>
# include "pair.hpp"
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
	class iterator;
	typedef const iterator							const_iterator;
	reverse_iterator								reverse_iterator<iterator>	
	const_reverse_iterator							reverse_iterator<const_iterator>
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;
	typedef struct									s_binary_tree
	{
		key_type				key;
		mapped_type				value;
		size_type				color;
		struct	s_binary_tree	*father;
		struct	s_binary_tree	*left;
		struct	s_binary_tree	*right;
	}											t_binary_tree;

	/* CONSTRUCTORS */
	explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_alloc(alloc), m_root(NULL) {};
	//template <class InputIterator>
	//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	map(const map& x) {};

	/* DESTRUCTOR */
	~map(void) {};
	/* OPERATOR = */
	map&	operator=(const map& x);

	/* ITERATORS */
	iterator				begin(void);
	const_iterator			begin(void) const;
	iterator				end(void);
	const_iterator			end(void) const;
	//reverse_iterator		rend(void);
	//const_reverse_iterator	rend(void) const;
	//reverse_iterator		rend(void);
	//const_reverse_iterator	rend(void) const;


	/* CAPACITY */
	bool		empty(void) const
	{
		if (m_size)
			return (true);
		else
			return (false);
	}
	size_type	size(void) const
	{
		return (m_size);
	}
	size_type	max_size(void) const
	{
		return (m_alloc.max_size());
	}


	/* ELEMENT ACCESS */
	mapped_type&	operator[](const key_type& k)
	{
		if (!check_key(m_root, k))
		{
			addNode(k, mapped_type());
			m_size++;
		}
		return (findKey(k));
		//return (*((this->insert(make_pair(k,mapped_type()))).m_first)).m_second;
	}

	/* MODIFIERS */
	ft::pair<iterator,bool>	insert(const value_type& val)
	{

	}
	iterator					insert(iterator position, const value_type& val);
	template <class InputIterator>
	void				insert(InputIterator first, InputIterator last);
	void				erase(iterator position);
	size_type			erase(const key_type& k);
	void				erase(iterator first, iterator last);
	void				swap(map& x);
	void				clear(void);

	/* OBSERVERS */
	key_compare		key_comp(void) const;
	value_compare	value_comp(void) const;

	/* OPERATIONS */
	iterator								find(const key_type& k);
	const_iterator							find(const key_type& k) const;
	size_type								count(const key_type& k) const;
	iterator								lower_bound(const key_type& k);
	const_iterator							lower_bound(const key_type& k) const;
	iterator								upper_bound(const key_type& k);
	const_iterator							upper_bound(const key_type& k) const;
	ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
	ft::pair<iterator,iterator>				equal_range(const key_type& k);

	/* ALLOCATORS */
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