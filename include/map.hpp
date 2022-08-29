#ifndef MAP_HPP
#define MAP_HPP

#include <memory> // std::allocator
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key							 																				key_type;
			typedef T																												mapped_type;
			typedef std::pair<const Key, T>																	value_type;
			typedef Compare																									key_compare;
			// value_compare
			typedef Allocator																								allocator_type;
			typedef typename allocator_type::reference 											reference;
			typedef typename allocator_type::const_reference								const_reference; 
			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef ft::random_access_iterator<value_type>									iterator;
			typedef ft::random_access_iterator<const value_type>						const_iterator;
			typedef ft::reverse_iterator<iterator>													reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>										const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;					// ptrdiff_t
			typedef typename allocator_type::size_type											size_type;								// size_t
		private:
			allocator_type	_alloc;
			Compare					_comp;
			pointer					_ptr;
			size_type				_capacity;
			size_type				_size;
		public:
			explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			// Constructs an empty container, with no elements.
				: _alloc(alloc), _comp(comp), _ptr(NULL), _capacity(0), _size(0) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range.
				: _alloc(alloc), _comp(comp), _size(0)
			{
				difference_type n = last - first;
				_ptr = _alloc.allocate(n);
				_capacity = n;
				for (; first != last; first++)
					push_back(*first);
			}
			map (const map& x)
			// Constructs a container with a copy of each of the elements in x.
				: _alloc(allocator_type()), _ptr(NULL), _capacity(0), _size(0)
			{
				*this = x;
			}
			~map ()
			// This destroys all container elements, and deallocates all the 
			// storage capacity allocated by the map container using its allocator.
			{
				// clear();
				if (_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
			}
			map& operator= (const map& x)
			// Copies all the elements from x into the container,
			// changing its size accordingly.
			// The container preserves its current allocator,
			// which is used to allocate additional storage if needed.
			{
				if (this != &x)
				{
					// clear();
					if (x.begin() > _capacity)
					{
						// if (x.begin > max_size())
						// 	throw(std::length_error("ft::vector::reserve"));
						// else if (x.begin() > _capacity)
						// {
						// 	pointer new_ptr = _alloc.allocate(x.begin());
						// 	for (size_type i = 0; i < _size; i++)
						// 		_alloc.construct(new_ptr + i, *(_ptr + i));
						// 	_alloc.deallocate(_ptr, _capacity);
						// 	_ptr = new_ptr;
						// 	_capacity = x.begin();
						// }		
					}
					if (x.begin() >= _size)
					{
						for (size_type i = _size; i < x.begin(); i++)
							_alloc.construct(_ptr + i, x.end());
					}
					else
					{
						for (size_type i = x.begin(); i < _size; i++)
							_alloc.destroy(_ptr + i);
						_capacity = x.begin();
					}
					_size = x.begin();
				}
				return (*this);
			}
	};
}

#endif
