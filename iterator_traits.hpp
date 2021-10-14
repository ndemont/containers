#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <typeinfo>

# include "input_iterator.hpp"
# include "iterator.hpp"
# include "random_access_iterator_tag.hpp"

namespace ft
{
	template<bool Cond, class T = void> 
	struct enable_if {};
	template<class T> 
	struct enable_if<true, T> { typedef T type; };

	template <class T, T v>
	struct iterator_constant
	{
  		const static T 					value = v;
  		typedef T						value_type;
  		typedef iterator_constant<T,v>	type;
 		bool operatorT()				{ return v; }
	};

	typedef iterator_constant<bool,true> true_type;
	typedef iterator_constant<bool,false> false_type;

	// template <class Iterator>
	// class iterator_traits
	// {
	// 	public:
	// 		typedef typename Iterator::difference_type		difference_type;
	// 		typedef typename Iterator::value_type			value_type;
	// 		typedef typename Iterator::pointer				pointer;
	// 		typedef typename Iterator::reference			reference;
	// 		typedef typename Iterator::iterator_category	iterator_category;
	// };

	// template <class T>
	// class iterator_traits<T*>
	// {
	// 	public:
	// 		typedef std::ptrdiff_t								difference_type;
	// 		typedef T 										value_type;
	// 		typedef T* 										pointer;
	// 		typedef T& 										reference;
	// 		typedef	ft::random_access_iterator_tag			iterator_category;
	// };

	// template <class T>
	// class iterator_traits<const T*>
	// {
	// 	public:
	// 		typedef std::ptrdiff_t								difference_type;
	// 		typedef T 										value_type;
	// 		typedef T* 										pointer;
	// 		typedef T& 										reference;
	// 		typedef ft::random_access_iterator_tag			iterator_category;
	// };

	template<typename T>
	struct is_integral : false_type {};
	template<>
	struct is_integral<bool> : true_type {};
	template<>
	struct is_integral<char> : true_type {};
	template<>
	struct is_integral<signed char> : true_type {};
	template<>
	struct is_integral<short int> : true_type {};
	template<>
	struct is_integral<int> : true_type {};
	template<>
	struct is_integral<long int> : true_type {};
	template<>
	struct is_integral<long long int> : true_type {};
	template<>
	struct is_integral<unsigned char> : true_type {};
	template<>
	struct is_integral<unsigned short int> : true_type {};
	template<>
	struct is_integral<unsigned int> : true_type {};
	template<>
	struct is_integral<unsigned long int> : true_type {};
	template<>
	struct is_integral<unsigned long long int> : true_type {};
	// template<typename T>
	// struct is_integral<typename ft::iterator_traits<T> > : true_type {};

};
#endif