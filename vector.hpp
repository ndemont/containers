#ifndef VECTOR_HPP
# define VECTOR_HPP

template <typename T, class Alloc = std::allocator<T>>
class vector
{
	public:
		
		/* MEMBER TYPES */
		//const_iterator
		//reverse_iterator
		//const_reverse_iterator
		//difference_type
		typedef T					value_type;
		typedef alloc 				allocator_type;
		typedef value_type &		reference;
		typedef value_type const &	reference;
		typedef value_type *		pointer;
		typedef value_type const *	pointer;
		typedef size_t 				size_type; 

		explicit vector<T>(void) : _vector(0), _size(0) {} ;
		explicit vector<T>(size_type n, const value_type& val) : _vector(new vector<T>(size)), _size(size)
		{
			for (size_type i = 0; i < size; i++) 
				_vector[i] = val;
		}
		vector<T>(vector<T>::iterator first, vector<T>::iterator last)
		{
			_size = end - begin;
			_vector = new vector<T>(_size);
			for (size_type i = 0; begin != end; i++)
			{
				_vector[i] = *begin;
				i++;
				begin++;
			}
		}
		vector<T>(const vector<T>&x) 
		{
			if (this != &src)
				*this = src;
		}
		~vector<T>(void)
		{
			if (_vector)
				delete _vector;
		}

		vector<T> const & operator=(vector<T> const & rhs)
		{
			delete _vector;
			_size = size.rhs;
			_vector = new vector<T>(_size);
			for (size_type i = 0; i < _size; i++)
				_vector[i] = rhs[i];
			return *this;
		}



	private:
	value_type			*_vector;
	size_type	_size;
};

#endif