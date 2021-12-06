#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include "iterator/random_access_iterator.hpp"


namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        //------------------------------Typedef------------------------------//

        typedef         T                                   value_type;
        typedef         T*                                  pointer;
        typedef         T&                                  reference;
        typedef         const T*                            const_pionter;
        typedef         const T&                            const_reference;
        typedef         ptrdiff_t                           difference_type;
        typedef         Alloc                               allocator_type;
        typedef         std::size_t                         size_type;
        typedef         random_access_iterator<T>           iterator;
        typedef         random_access_iterator<T>           const_iterator;





    private:
        //-------------------------------Param-------------------------------//
        value_type*     _arr;                 
        size_type       _size;
        size_type       _capacity;
        allocator_type  _alloc;      

    public:
        //----------------------------Constructor----------------------------//
        explicit vector (const allocator_type& alloc = allocator_type()) :
        _arr(0), _size(0), _capacity(0), _alloc(alloc) {}

        explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()) :
        _arr(0), _size(n), _capacity(n), _alloc(alloc)
        {
            _arr = _alloc.allocate(n);
            for(size_type i = 0; i < n; i++)
                _alloc.construct(_arr + i, val);
        }

        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //         const allocator_type& alloc = allocator_type())
        // {}

        vector (const vector& x) {*this = x;}

        //-----------------------------Destructor----------------------------//
        // ~vector();

        //--------------------------------=====------------------------------//
        vector& operator= (const vector& x)
        {
            // добавить функцию clear() для отчистки старого вектора
        }

        //------------------------------Iterators----------------------------//
        iterator begin()
        {
            return(iterator(_arr));
        }

        iterator end()
        {
            return(iterator(_arr + _size));
        }

        //------------------------------Capacity-----------------------------//

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (_alloc.max_size());
        }

        void resize (size_type n, value_type val = value_type())
        {
            pointer arr_tmp;
            size_type old_cap = _capacity;
            size_type old_siz = _size;

            if (n > _capacity)
                _capacity = ((_capacity * 2) < n) ? n : (_capacity * 2);
            _size = n;
            arr_tmp = _alloc.allocate(_capacity);
            if(old_siz > _size)
            {
                for(size_type i = 0; i < _size; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
            }
            else
            {
                for(size_type i = 0; i < old_siz; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
                for(size_type i = old_siz; i < _size; i++)
                    _alloc.construct(arr_tmp + i, val);
            }
            for(size_type i = 0; i < _size; i++)
                _alloc.destroy(_arr + i);
            _alloc.deallocate(_arr, old_cap);
            _arr = arr_tmp;
        }

        size_type capacity() const
        {
            return(_capacity);
        }

        bool empty() const
        {
            if(_size == 0)
                return(true);
            else
                return(false);
        }

        void reserve (size_type n)
        {
            if(n > _capacity)
            {
                pointer arr_tmp = _alloc.allocate(n);
                for(size_type i = 0; i < _size; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
                for(size_type i = 0; i < _size; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr, _size);
                _arr = arr_tmp;
                _capacity = n;
            }
        }

        //-------------------------Element access----------------------------//

        reference operator[](size_type n)
        {
            return(*(_arr + n));
        }

        reference at(size_type n)
        {
            if(n < _size)
                return(*(_arr + n));
            else
                throw std::out_of_range("vector");        
        }

        const_reference at(size_type n) const
        {
            if(n < _size)
                return(*(_arr + n));
            else
                throw std::out_of_range("vector");     
        }

        reference front()
        {
            return(*_arr);
        }

        const_reference front() const
        {
            return(*_arr);
        }

        reference back()
        {
            return(*(_arr + (_size - 1)));
        }

        const_reference back() const
        {
            return(*(_arr + (_size - 1)));
        }
        //----------------------------Modifiers------------------------------//

        void assign(size_type n, const value_type& val)
        {
            // добавить функцию clear() для отчистки старого вектора
            if(_capacity < n)
            {
                _capacity = n;
                _arr = _alloc.allocate(_capacity);
            }
            _size = n;
            for(int i = 0; i < _size; i++)
            {
                _arr[i] = val;
            }
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            size_type       count = 0;
            InputIterator   tmp;

            count       =   0;
            tmp         =   first;
            // добавить функцию clear() для отчистки старого вектора
            while(tmp != last)
            {
                ++count;
                ++tmp;
            }
            if(_capacity < count)
            {
                _capacity = count;
                _arr = _alloc.allocate(_capacity);
            }
            _size = count;
            for(int i = 0; i < _size; i++, first++)
            {
                _arr[i] = *first;
            }
        }
        
        void push_back(const value_type& val)
        {
            _size++;
            if(_capacity == 0)
            {
                _capacity = 1;
                _arr = _alloc.allocate(_capacity);
            }
            if(_size > _capacity)
            {
                size_type old_capacity = _capacity;
                _capacity *= 2;
                pointer arr_tmp = _alloc.allocate(_capacity);
                for(size_type i = 0; i < _size; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
                for(size_type i = 0; i < _size; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr, old_capacity);
                _arr = arr_tmp;
                _alloc.construct(_arr + _size - 1, val);
            }
            else
                _alloc.construct(_arr + _size - 1, val);
        }

        void pop_back()
        {
            _size--;
            _alloc.destroy(_arr + _size);
        }

        iterator insert (iterator position, const value_type& val)
        {
            size_type old_siz = _size;
            size_type old_cap = _capacity;
            iterator it_beg = this->begin();
            size_type pos = 0;
            for(; it_beg != position; it_beg++)
                pos++;
            _size++;
            if(_capacity == 0)
            {
                _capacity = 1;
                _arr = _alloc.allocate(_capacity);
            }
            if(_size > _capacity)
            {
                _capacity *= 2;
                pointer arr_tmp = _alloc.allocate(_capacity);
                for(size_type i = 0; i < pos; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
                _alloc.construct(arr_tmp + pos, val);
                for(size_type i = pos; (i + 1) < _size; i++)
                    _alloc.construct(arr_tmp + (i + 1), *(_arr + i));
                for(size_type i = 0; i < old_siz; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr, old_cap);
                _arr = arr_tmp;
            }
            else
            {
                for(size_type i = _size; i > pos; i--)
                {
                    _alloc.construct(_arr + i, *(_arr + i - 1));
                    _alloc.destroy(_arr + (i - 1));
                }
                _alloc.construct(_arr + pos, val);
            }
            return(iterator(_arr + pos));
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            if(n == 0)
                return;
            size_type old_siz = _size;
            size_type old_cap = _capacity;
            iterator it_beg = this->begin();
            size_type pos = 0;
            for(; it_beg != position; it_beg++)
                pos++;
            int crutch = 0;                 // crutch
            if (pos > _size)                //  |===|
            {                               //  |___|
                crutch = pos - _size;       //   | |
                _size += crutch;            //    ]
            }                               // crutch
            _size += n;
            if(_capacity == 0)
            {
                _capacity = 1;
                _arr = _alloc.allocate(_capacity);
            }
            if(_size > _capacity)
            {
                _capacity = ((_capacity * 2) < _size) ? _size : (_capacity * 2);
                if(crutch != 0)                     // crutch
                    _capacity -= crutch;            // crutch
                if(n == 2 || n == 1)                // crunch
                    _capacity += (n == 1) ? 2 : 1;  // crunch
                pointer arr_tmp = _alloc.allocate(_capacity);
                for(size_type i = 0; i < pos; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i));
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(arr_tmp + pos + i, val);
                for(size_type i = (pos + n); i < _size; i++)
                    _alloc.construct(arr_tmp + i, *(_arr + i - n));
                for(size_type i = 0; i < old_siz; i++)
                    _alloc.destroy(_arr + i);
                _alloc.deallocate(_arr, old_cap);
                _arr = arr_tmp;
            }
            else
            {
                for(size_type i = _size; i > (pos + n); i--)
                {
                    _alloc.construct(_arr + i, *(_arr + pos + n));
                    _alloc.construct(_arr + (pos + n));
                }
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_arr + (pos + i), val);
            }

        }




        void clear()
        {
            if(_arr == 0)
                return;
            for(size_type i = 0; i < _size; i++)
                _alloc.destroy(_arr + _size);
            _size = 0;
        }

    };

}



#endif


//Повторить
