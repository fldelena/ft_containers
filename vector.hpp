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
        explicit vector(const allocator_type& alloc = allocator_type()) :
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
            value_type arr_tmp;

            if (n > _capacity)
                _capacity = ((_capacity * 2) < n) ? n : (_capacity * 2);

            arr_tmp = _alloc.allocate(_capacity);
            size_type i = 0;
            while(i < _size)
            {
                arr_tmp[i] = _arr[i];
                i++;
            }
            while(i < n)
            {
                _alloc.construct(arr_tmp[i], _arr[i]);
                i++;
            }
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
                value_type arr_tmp = _alloc.allocate(n);
                for(size_type i = 0; i < _size, i++;)
                    arr_tmp[i] = _arr[i];
                _alloc.deallocate(_arr);
                _alloc.destroy(_arr);
                _arr = arr_tmp;
                _capacity = n;
            }
        }

        //-------------------------Element access----------------------------//

        reference operator[](size_type n)
        {
            return(*(this->_arr + n));
        }

        reference at (size_type n)
        {
            
        }


    };

}



#endif


//Повторить
//typename
//template