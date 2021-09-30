#ifndef BINARY_SEARCH_TREE_HPP
# define BINARY_SEARCH_TREE_HPP

# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "pair.hpp"

# define BLACK 0
# define RED 1

namespace ft
{

template <class T>
class const_map_iterator;
template <class T>
class map_iterator;

template <class T>
class tree
{
	typedef	T										value_type;
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

	public:
		value_type		*pair;
		size_type		color;
		tree			*father;
		tree			*left;
		tree			*right;

	public:

		bool	check_key(tree *root, value_type pair)
		{
			if (!root)
				return (false);
			if (pair.second_type == root->value)
				return (true);
			else if (pair.map < root->value)
				check_key(root->left, pair.second_type);
			else
				check_key(root->right, pair.second_type);
			return (false);
		}

		void			addNode(tree *root, value_type pair)
		{
			tree *node;

			if (!root)
			{
				root = newNode(pair);
				return ;
			}
			node = root;
			while (node)
			{
				if (pair.second_type < node->value)
				{
					if (!node->left)
					{
						node->left = newNode(pair);
						node->left->father = root;
						return ;
					}
					node = node->left;
				}
				else
				{
					if (!node->right)
					{
						node->right = newNode(pair);
						node->right->father = node;
						return ;
					}
					node = node->right;
				}
			}
		}

		value_type&	findKey(tree *root, const value_type& pair)
		{
			tree<T> *node = root;
		
			while (node)
			{
				if (pair.second_type < node->value)
					node = node->left;
				else if (pair.second_type > node->value)
					node = node->right;
				else
					break;
			}
			if (node)
				return node->value;
			else
				return NULL;
		}

		tree	*newNode(value_type pair)
		{
			tree	*newNode = new tree();

			newNode->value = pair;
			newNode->color = BLACK;
			newNode->father = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			
			return newNode;
		}
};
};

#endif