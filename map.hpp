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

		typedef struct s_tree
		{
			value_type		*pair;
			key_type		first;
			mapped_type		second;
			size_type		color;
			s_tree			*father;
			s_tree			*left;
			s_tree			*right;
		}				tree;

		typedef ft::map_iterator<tree>						iterator;
		typedef ft::const_map_iterator<tree>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ptrdiff_t									difference_type;

		explicit	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_alloc(alloc), m_root(NULL) { (void)comp; }
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : m_size(0), m_root(NULL), m_alloc(alloc), m_compare(comp)
		{
			for (InputIterator it = first; it != last; it++)
				insert(*it);
		};
		map(const map& x) { (void)x; };
		~map(void) {};
	
		map&	operator=(const map& x) { (void)x; };

		iterator				begin(void) { return iterator(*m_root); };
		const_iterator			begin(void) const { return const_iterator(*m_root); };
		iterator				end(void) { return iterator(*m_root); };
		const_iterator			end(void) const { return const_iterator(*m_root); };
		reverse_iterator		rbegin(void) { return rbegin(*m_root); };
		const_reverse_iterator	rbegin(void) const { return rbegin(*m_root); };
		reverse_iterator		rend(void) { return rbegin(*m_root); };
		const_reverse_iterator	rend(void) const { return rbegin(*m_root); };


		bool					empty(void) const { return (m_size); }
		size_type				size(void) const { return (m_size); }
		size_type				max_size(void) const { return (m_alloc.max_size()); }

		//mapped_type&	operator[](const key_type& k)
		//{
		//	//if (!check_key(m_root, k))
		//	//{
		//	//	addNode(k, mapped_type());
		//	//	m_size++;
		//	//}
		//	//return (findKey(k));
		//}

		//ft::pair<iterator,bool>		insert(const value_type& val)
		void		insert(const value_type& val)
		{
			addNode(val);
		};

		iterator insert(iterator position, const value_type& val)
		{
			(void)position;
			(void)val;
		};
		template <class InputIterator>
		void									insert(InputIterator first, InputIterator last) {(void)last; (void)first;};
		
		void									erase(iterator position) {  (void)position; };
		size_type								erase(const key_type& k) { (void)k; };
		void									erase(iterator first, iterator last) { (void)last; (void)first; };


		void									swap(map& x) 
		{ 
			map<Key, T> tmp = x;
				
			x = *this;
			*this = tmp;
		};
		void									clear(void) {};

		key_compare		key_comp(void) const { return m_compare; };
		value_compare	value_comp(void) const { return m_compare; };

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
			size_type		m_size;
			tree			**m_root;
			allocator_type	m_alloc;
			key_compare		m_compare;

		void	addNode(ft::pair<const key_type, mapped_type> val)
		{
			if (!m_root)
			{
				m_root = new tree*;
				*m_root = newNode(val);
				return ;
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
						return ;
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
						return ;
					}
					ref = ref->right;
				}
			}
			return ;
		}
 
		tree	*newNode(ft::pair<const key_type, mapped_type> val)
		{
			tree									*newNode = new tree;
			ft::pair<const key_type, mapped_type>	*pr = new pair<const key_type, mapped_type>(val);
			
			newNode->pair = pr;
			newNode->first = pr->first;
			newNode->second = pr->second;
			newNode->color = BLACK;
			newNode->father = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
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