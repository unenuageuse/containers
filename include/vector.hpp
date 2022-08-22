#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <memory> // std::allocator
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;														// T&
		typedef typename allocator_type::const_reference const_reference; 							// const T&
		typedef typename allocator_type::pointer pointer;																// T*
		typedef typename allocator_type::const_pointer const_pointer;										// const T*
		typedef ft::random_access_iterator<value_type> iterator;
		typedef ft::random_access_iterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type; // ptrdiff_t
		typedef typename allocator_type::size_type size_type;														 // size_t
	private:
		allocator_type _alloc;
		pointer _ptr;
		size_type _capacity;
		size_type _size;
	public:
		explicit vector(const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _ptr(NULL), _capacity(0), _size(0) {}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
				: _alloc(alloc), _ptr(NULL), _capacity(n), _size(n)
		{
			_ptr = _alloc.allocate(n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
					 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
				: _alloc(alloc), _size(0)
		{
			difference_type n = last - first;
			_ptr = _alloc.allocate(n);
			_capacity = n;
			for (; first != last; first++)
				push_back(*first);
		}
		vector(const vector &x)
				: _alloc(allocator_type()), _ptr(NULL), _capacity(0), _size(0)
		{
			*this = x;
		}
		~vector()
		{
			clear();
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
		}
		vector &operator=(const vector &x)
		{
			if (this != &x)
			{
				clear();
				assign(x.begin(), x.end());
			}
			return (*this);
		}
		iterator begin()
		{
			return (iterator(_ptr));
		}
		const_iterator begin() const
		{
			return (const_iterator(_ptr));
		}
		iterator end()
		{
			return (iterator(_ptr + _size));
		}
		const_iterator end() const
		{
			return (const_iterator(_ptr + _size));
		}
		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}
		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(begin()));
		}
		size_type size() const
		{
			return (_size);
		}
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		void resize(size_type n, value_type val = value_type()) 
		//Resize the vector with the second parameters for fill if necessary
		{
			if (n > _capacity)
				reserve(n);
			if (n >= _size)
			{
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_ptr + i, val);
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					_alloc.destroy(_ptr + i);
				_capacity = n;
			}
			_size = n;
		}
		size_type capacity() const
		{
			return (_capacity);
		}
		bool empty() const
		{
			return (size() == 0 ? true : false);
		}
		void reserve(size_type n)
		// Change the capacity of the vector
		{
			if (n > max_size())
			{
				throw(std::length_error("ft::vector::reserve"));
			}
			else if (n > _capacity)
			{
				pointer new_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(new_ptr + i, *(_ptr + i));
				_alloc.deallocate(_ptr, _capacity);
				_ptr = new_ptr;
				_capacity = n;
			}
		}
		reference operator[](size_type n)
		{
			return (_ptr[n]);
		}
		const_reference operator[](size_type n) const
		{
			return (_ptr[n]);
		}
		reference at(size_type n)
		{
			if (n >= size())
			{
				throw(std::out_of_range("ft::vector::at"));
			}
			else
			{
				return (_ptr[n]);
			}
		}
		const_reference at(size_type n) const
		{
			if (n >= size())
			{
				throw(std::out_of_range("ft::vector::at"));
			}
			else
			{
				return (_ptr[n]);
			}
		}
		reference front()
		// Return front
		{
			return (*begin());
		}
		const_reference front() const
		// Return const front
		{
			return (*begin());
		}
		reference back()
		// Return back
		{
			return (*(end() - 1));
		}
		const_reference back() const
		// Return const back
		{
			return (*(end() - 1));
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			clear();
			size_type n = last - first;
			if (n == 0)
				return;
			if (n > _capacity)
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(n);
				_capacity = n;
			}
			for (; first != last; first++)
				push_back(*first);
		}
		void assign(size_type n, const value_type &val)
		// Assign first parameter as size of second parameters
		{
			clear();
			if (n == 0)
				return;
			if (n > _capacity)
			{
				_alloc.deallocate(_ptr, _capacity);
				_ptr = _alloc.allocate(n);
				_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				push_back(val);
		}
		void push_back(const value_type &val)
		// Add the element at the back of vector
		{
			if (_size == _capacity)
				empty() ? reserve(1) : reserve(_size * 2);
			_alloc.construct(_ptr + _size, val);
			_size++;
		}
		void pop_back()
		// Delete the last element of vector
		{
			if (_size > 0)
			{
				_alloc.destroy(_ptr + (_size - 1));
				_size--;
			}
		}
		iterator insert(iterator position, const value_type &val)
		// Insert at the position the value
		{
			size_type idx = position - begin();
			reserve(_size + 1);
			position = begin() + idx;
			move_backward(position);
			_alloc.construct(&(*position), val);
			_size++;
			return (position);
		}
		void insert(iterator position, size_type n, const value_type &val)
		// Insert at the position until n the value
		{
			size_type idx = position - begin();
			reserve(_size + n);
			position = begin() + idx;
			move_backward(position, n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&(*(position + i)), val);
			_size += n;
		}
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = NULL)
		{
			size_type idx = position - begin();
			size_type n = last - first;
			reserve(_size + n);
			position = begin() + idx;
			move_backward(position, n);
			for (size_type i = 0; i < n; i++)
				_alloc.construct(&(*(position + i)), *(first + i));
			_size += n;
		}
		iterator erase(iterator position)
		{
			if (empty())
				return (end());
			iterator it = begin();
			while (it != position)
				it++;
			_alloc.destroy(&(*it));
			while (it + 1 != end())
			{
				_alloc.construct(&(*it), *(it + 1));
				it++;
			}
			pop_back();
			return (position);
		}
		iterator erase(iterator first, iterator last)
		{
			if (empty())
				return (end());
			iterator it = begin();
			iterator rtn = first;
			difference_type dist = last - first;
			while (it != first)
				it++;
			for (; first != last; first++)
				_alloc.destroy(&(*first));
			while (it + dist != end())
			{
				_alloc.construct(&(*it), *(it + dist));
				it++;
			}
			while (dist-- > 0)
				pop_back();
			return (rtn);
		}
		void swap(vector &x)
		{
			allocator_type tmp_alloc = _alloc;
			pointer tmp_ptr = _ptr;
			size_type tmp_capacity = _capacity;
			size_type tmp_size = _size;

			_alloc = x._alloc;
			_ptr = x._ptr;
			_capacity = x._capacity;
			_size = x._size;

			x._alloc = tmp_alloc;
			x._ptr = tmp_ptr;
			x._capacity = tmp_capacity;
			x._size = tmp_size;
		}
		void clear()
		// Delete the vector if the size is more than 0
		{
			if (_size > 0)
			{
				for (iterator it = begin(); it != end(); it++)
					_alloc.destroy(&(*it));
				_size = 0;
			}
		}
		allocator_type get_allocator() const
		{
			return (Alloc(_alloc));
		}
	private:
		void move_backward(iterator position, size_type n = 1)
		{
			if (position == end())
				return;
			move_backward(position + 1, n);
			_alloc.construct(&(*(position + n)), *position);
		}
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}

#endif
