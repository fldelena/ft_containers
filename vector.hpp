#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
// #include <memory>


namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        //----------------------Typedef-----------------------//

        typedef         T                   value_type;
        typedef         std::size_t         size_type;
        typedef         Alloc               allocator_type;

        //----------------------param-------------------------//
    private:
        value_type*     _arr;                 
        size_type       _size;
        size_type       _capacity;
        allocator_type  _alloc;      

    public:
        //---------------------Constructor--------------------//
        explicit vector(const allocator_type& alloc = allocator_type()) :
        _arr(0), _size(0), _capacity(0), _alloc(alloc) {}

        explicit vector (size_type n, const value_type& val = value_type(),
                            const allocator_type& alloc = allocator_type()) :
        _arr(0), _size(n), _capacity(n), _alloc(alloc)
        {
            _arr = _alloc.allocate(n);
            for(size_type i = 0; i < n; i++)
                _arr[i] = val; // НЕПРВАВИЛЬНО
        }

        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //         const allocator_type& alloc = allocator_type())
        // {}

        vector (const vector& x) {*this = x;}



        //----------------------Capacity----------------------//

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (4611686018427387903);
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
    };

}



#endif