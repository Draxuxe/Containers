#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
	{
		public:
			typedef T value;
			typedef Alloc allocator_type;
			typedef size_t size;
			typedef ptrdiff_t diff_type;
			typedef T &ref;
			typedef const T &const_ref;
			typedef T *pointer;
			typedef const T *const_pointer;
		private:
			size_t capacity;
			allocator_type allocator;
			pointer tab;

		public:
		//MEMBERS FUNCTIONS
			void assign(size_t new_size, const T &value)
			{
				if (new_size > capacity)
				{
					//Throw an error here
					return ;
				}
				else if (tab)
					delete tab;
				tab = new T(new_size);
				this->size = new_size;
				for (int i = 0; i != new_size; i ++)
					push_back(value);
				return ;
			}
			template <class InputIterators>
			void assign(InputIterators first, InputIterators last)
			{
				int i = 0;
				InputIterators temp;
				temp = first;
				while (temp != last)
				{
					i ++;
					temp ++;
				}
				if (i > capacity)
				{
					//Throw an error
					return ;
				}
				this->size = i;
				for (first, first != last; first ++)
					push_back(first);
				return ;
			}

			allocator_type get_allocator() const
			{
				return (this->allocator);
			}
		//ELEMENT ACCESS
			reference at(size_t pos)
			{
				if (pos > size)
				{
					//Throw out of range error
					return ;
				}
				return (this->tab[pos]);
			}
			const reference at(size_t pos) const
			{
				if (pos > size)
				{
					//Throw out of range error
					return ;
				}
				return (this->tab[pos]);
			}
			reference operator[](size_t pos)
			{
				return (tab[pos]);
			}
			const ref operator[](size_t pos) const
			{
				return (tab[pos]);
			}
			reference front()
			{
				return (tab[0]);
			}
			const reference front() const
			{
				return (tab[0]);
			}
			reference back()
			{
				return (tab[size]);
			}
			const reference back() const
			{
				return (tab[size]);
			}
	};
}

#endif