#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <iostream>
# include <utility>

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< std::pair < const Key, T > > >
class map
{
	public:

	typedef Key										key_type;
	typedef	T										mapped_type;
	typedef	std::pair<const key_type,mapped_type>	value_type;
	typedef	Compare									key_compare;
	typedef	Compare									value_compare;
	typedef Alloc									allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef value_type*								pointer;
	typedef const value_type*						const_pointer;
	class iterator;
	typedef const iterator							const_iterator;
	//reverse_iterator	reverse_iterator<iterator>	
	//const_reverse_iterator	reverse_iterator<const_iterator>
	typedef ptrdiff_t							difference_type;
	typedef size_t								size_type;
	typedef struct								s_binary_tree
	{
		value_type				elem;
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
		if (!check_key(*m_root, k))
			std::cout << "coucou" << std::endl;
		
	}

	/* MODIFIERS */
	std::pair<iterator,bool>	insert(const value_type& val);
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
	iterator							find(const key_type& k);
	const_iterator						find(const key_type& k) const;
	size_type							count(const key_type& k) const;
	iterator							lower_bound(const key_type& k);
	const_iterator						lower_bound(const key_type& k) const;
	iterator							upper_bound(const key_type& k);
	const_iterator						upper_bound(const key_type& k) const;
	std::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
	std::pair<iterator,iterator>				equal_range(const key_type& k);

	/* ALLOCATORS */
	allocator_type get_allocator() const;

	private:
		allocator_type	m_alloc;
		size_type		m_size;
		t_binary_tree	*m_root;
	
	bool	check_key(t_binary_tree root, key_type key)
	{
		if (!root)
			return (false);
		if (key == root.elem.first)
			return (true);
		else if (key < root.elem.first)
			check_key(root.left, key);
		else
			check_key(root.right, key);
	}
};

};



#endif