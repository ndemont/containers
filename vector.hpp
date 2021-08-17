#ifndef VECTOR_HPP
# define VECTOR_HPP

template <typename T>
class vector
{
	public:
		vector<T>(void) : _vector(0), _size(0) {} ;
		vector<T>(size_type size, T value) : _vector(new vector<T>(size)), _size(size)
		{
			for (size_type i = 0; i < size; i++) 
				_vector[i] = value;
		}
		vector<T>(vector<T>::iterator begin, vector<T>::iterator end)
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
		vector<T>(vector<T> const & src) 
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
	T			*_vector;
	size_type	_size;
};

#endif