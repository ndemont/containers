//#ifndef BINARY_SEARCH_TREE_HPP
//# define BINARY_SEARCH_TREE_HPP

//# include "map_iterator.hpp"
//# include "reverse_iterator.hpp"
//# include "pair.hpp"

//# define BLACK 0
//# define RED 1

//namespace ft
//{

//template <class T>
//class const_map_iterator;
//template <class T>
//class map_iterator;

//template <class T>
//class tree
//{
//	public:
//		typedef	T										value_type;
//		typedef value_type&								reference;
//		typedef const value_type&						const_reference;
//		typedef value_type*								pointer;
//		typedef const value_type*						const_pointer;
//		typedef ft::map_iterator<value_type>			iterator;
//		typedef ft::const_map_iterator<value_type>		const_iterator;
//		typedef ft::reverse_iterator<iterator>			reverse_iterator;
//		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
//		typedef ptrdiff_t								difference_type;
//		typedef size_t									size_type;

//		tree(value_type	pr)
//		{
//			pair = &pr;
//			color = BLACK;
//			father = NULL;
//			left = NULL;
//			right = NULL;
//		}
	
//		tree(const tree& x)
//		{ 
//			(void)x; 
//		}

//		value_type		*pair;
//		size_type		color;
//		tree			*father;
//		tree			*left;
//		tree			*right;

//		bool	check_key(tree *root, value_type pair)
//		{
//			if (!root)
//				return (false);
//			if (pair.second_type == root->value)
//				return (true);
//			else if (pair.map < root->value)
//				check_key(root->left, pair.second_type);
//			else
//				check_key(root->right, pair.second_type);
//			return (false);
//		}

//		tree	*addNode(tree *root)
//		{
//			tree *node;

//			if (!root)
//			{
//				root = this;
//				return root;
//			}
//			node = root;
//			while (node)
//			{
//				if (this->pair->second < node->pair->second)
//				{
//					if (!node->left)
//					{
//						node->left = this;
//						node->left->father = root;
//						return root;
//					}
//					node = node->left;
//				}
//				else
//				{
//					if (!node->right)
//					{
//						node->right = this;
//						node->right->father = node;
//						return root;
//					}
//					node = node->right;
//				}
//			}
//			return root;
//		}

//		value_type&	findKey(tree *root, const value_type& pair)
//		{
//			tree<T> *node = root;
		
//			while (node)
//			{
//				if (pair.second_type < node->value)
//					node = node->left;
//				else if (pair.second_type > node->value)
//					node = node->right;
//				else
//					break;
//			}
//			if (node)
//				return node->value;
//			else
//				return NULL;
//		}

//		void	print_tree(tree *root)
//		{
//			if (root)
//			{
//				if (root->left)
//					print_tree(root->left)l
//			}
//		}
//};
//};

//#endif