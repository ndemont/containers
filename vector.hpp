#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "itertor_traits.hpp"

template <typename T, class Alloc = std::allocator<T> >
class vector
{
	public:
		
		/* MEMBER TYPES */
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef allocator_type::reference					reference;
		typedef allocator_type::const_reference				const_reference;
		typedef allocator_type::pointer						pointer;
		typedef allocator_type::const_pointer				const_pointer;
		typedef std::random_access_iterator_tag				iterator;
		typedef cosnt std::random_access_iterator_tag		const_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef const reverse_iterator<iterator>			const_reverse_iterator;
		typedef	iterator_traits<iterator>::difference_type	difference_type;
		typedef	unsigned difference_type 					size_type;

		/* CONSTRUCTORS */
		explicit vector<T>(const allocator_type& alloc = allocator_type()) : m_alloc(alloc), m_vector(0) {};
		explicit vector<T>(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			for (size_type i = 0; i < n; i++) 
				m_vector[i] = val;
		}
		template <class iterator<T> >
        vector (iterator<T> first, iterator<T> last, const allocator_type& alloc = allocator_type());
		{
			if (m_vector)
				delete m_vector;
			m_vector = new vector<T>(last - min);
			for (size_type i = 0; min != last; i++)
			{
				_vector[i] = *min;
				i++;
				min++;
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
			if (m_vector)
				delete m_vector;
			m_vector = new vector<T>(_size);
			for (size_type i = 0; i < _size; i++)
				m_vector[i] = rhs[i];
			return *this;
		}

	private:
	value_type		*m_vector;
	//size_type		m_size;
	allocator_type 	m_alloc;
};

#endif