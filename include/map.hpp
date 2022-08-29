#ifndef MAP_HPP
#define MAP_HPP

#include <memory> // std::allocator
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
	class map
	{
		private:
			Key							 																key_type;
			T																								mapped_type;
			std::pair<const Key, T>													value_type;
			Compare																					key_compare;
			// value_compare
			Allocator																				allocator_type;
			value_type&																			reference;
			const value_type&																const_reference;
			allocator_type::pointer													pointer;
			allocator_type::const_pointer										const_pointer;
			//iterator
			//const iterator
			std::reverse_iterator<iterator>									reverse_iterator;
			std::reverse_iterator<const_iterator>						const_reverse_iterator;
			ft::iterator_traits<iterator>::difference_type	difference_type;					// ptrdiff_t
			allocator_type::size_type												size_type;								// size_t
		public:
			explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
			}
			tremplate <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			{
			}
			map (const map& x)
			{
			}
			~map ()
			{
			}
			map& operator= (const map& x)
			{
			}
	};
}

#endif
