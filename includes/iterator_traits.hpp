#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <typeinfo>
# include "iterator.hpp"

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

};
#endif