#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include "iterator/VectorIterator.hpp"
#include "iterator/ReverseIterator.hpp"
#include "iterator/LexicographicalCompare.hpp"
#include "iterator/Pair.hpp"
#include "iterator/IsIntegral.hpp"
#include "iterator/EnableIf.hpp"
#include "iterator/IteratorTraits.hpp"
#include "iterator/Equal.hpp"



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
        typedef         VectorIterator<value_type>          iterator;
        typedef         VectorIterator<value_type const>    const_iterator;
        typedef         ReverseIterator<iterator>           reverse_iterator;
        typedef         ReverseIterator<const_iterator>     const_reverse_iterator;





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

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type()) :
        _arr(0), _size(0), _capacity(0), _alloc(alloc)
        {
            this->assign(first, last);
        }

        vector (const vector& x)
        {
            this->_capacity = x._capacity;
            this->_size = x._size;
            this->_alloc = x._alloc;
            this->_arr = (this->_alloc).allocate(x._capacity);
            for(size_type i = 0; i < x._size; i++)
                (this->_alloc).construct(this->_arr + i, *(x._arr + i));
        }

        virtual ~vector()
        {
            if (_arr == 0)
                return ;
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_arr + i);
            _alloc.deallocate(_arr, this->_capacity);
        }

        vector& operator= (const vector& x)
        {
            this->clear();
            if(this->_capacity < x._capacity)
            {
                (this->_alloc).deallocate(this->_arr, this->_capacity);
                this->_capacity = x._capacity;
                this->_size = x._size;
                this->_arr = (this->_alloc).allocate(x._capacity);
            }
            for(size_type i = 0; i < x._size; i++)
                (this->_alloc).construct(this->_arr + i, *(x._arr + i));
            return(*this);
        }

        //------------------------------Iterators----------------------------//
        iterator begin() {
            return(iterator(_arr));
        }

        const_iterator begin() const {
            return(const_iterator(_arr));
        }

        iterator end() {
            return(iterator(&(_arr[_size])));
        }

        const_iterator end() const {
            return(const_iterator(&(_arr[_size])));
        }

        reverse_iterator rbegin(void) {
            return (reverse_iterator(this->end()));
        }

        const_reverse_iterator rbegin(void) const {
            return (const_reverse_iterator(this->end()));
        }

        reverse_iterator rend(void) {
            return (reverse_iterator(this->begin()));
        }

        const_reverse_iterator rend(void) const {
            return (const_reverse_iterator(this->begin()));
        }

        //------------------------------Capacity-----------------------------//

        size_type size() const{
            return (_size);
        }

        size_type max_size() const{
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

        size_type capacity() const{
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

        reference operator[] (size_type n){
            return(*(_arr + n));
        }

        const_reference operator[] (size_type n) const{
            return(*(_arr + n));
        }

        reference at (size_type n)
        {
            if(n < _size)
                return(*(_arr + n));
            else
                throw std::out_of_range("vector");        
        }

        const_reference at (size_type n) const
        {
            if(n < _size)
                return(*(_arr + n));
            else
                throw std::out_of_range("vector");     
        }

        reference front (){
            return(*_arr);
        }

        const_reference front () const{
            return(*_arr);
        }

        reference back (){
            return(*(_arr + (_size - 1)));
        }

        const_reference back () const{
            return(*(_arr + (_size - 1)));
        }
        //----------------------------Modifiers------------------------------//

        void assign (int n, const value_type& val)
        {
            this->clear();
            if(_capacity < n)
            {
                _capacity = n;
                _arr = _alloc.allocate(_capacity);
            }
            _size = n;
            for(int i = 0; i < _size; i++)
            {
                _alloc.construct(_arr + i, val);
            }
        }

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            size_type       count = 0;
            InputIterator   tmp;

            count       =   0;
            tmp         =   first;
            this->clear();
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
                _alloc.construct(_arr + i, *first);
        }
        
        void push_back (const value_type& val)
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

        void pop_back ()
        {
            _size--;
            _alloc.destroy(_arr + _size);
        }

        iterator insert (iterator position, const value_type& val)
        {
            this->insert(position, 1, val);
            return (position);
        }

        void insert (iterator position, int n, const value_type& val)
        {
            if(n == 0)
                return;
            size_type old_siz = _size;
            size_type old_cap = _capacity;
            iterator it_beg = this->begin();
            size_type pos = 0;
            for(; (it_beg != position) && (it_beg != this->end()); it_beg++)
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
                size_type index = 0;
                if(crutch != 0)                     // crutch
                    _capacity -= crutch;            // crutch
                if(n == 2 || n == 1)                // crunch
                    _capacity += (n == 1) ? 2 : 1;  // crunch
                for(size_type i =(_size - 1) ; i >= (pos + n); i--)
                {
                    _alloc.construct(_arr + i, *(_arr + i - pos - n + 1));
                    _alloc.destroy(_arr + i - pos - n + 1);
                }
                for(size_type i = 0; i < n; i++)
                    _alloc.construct(_arr + (pos + i), val);
            }

        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {
            iterator beg = this->begin();
            size_type pos = 0;
            for (;beg != position;beg++)
                pos++;
            size_type n = 0;
            InputIterator first_tmp = first;
            for (;first_tmp != last; first_tmp++)
                n++;
            size_type old_cap = _capacity;
            _size += n;
            if(_size > _capacity * 2)
            {   
                size_type index = 0;
                _capacity = _size;
                if(_capacity == 0)
                    _capacity = n;
                pointer tmp = _alloc.allocate(_capacity);
                for(size_type i = 0; i < pos; i++)
                    _alloc.construct(tmp + i, *(_arr + i));
                for(size_type i = pos; i < pos + n; i++)
                    _alloc.construct(tmp + i, *(first + index++));
                for(size_type i = pos + n; i < _size; i++)
                    _alloc.construct(tmp + i, *(_arr + i - n));
                _alloc.deallocate(_arr, old_cap);
                _arr = tmp;
            } 
            else if (_size > _capacity)
            {
                size_type index = 0;
                _capacity *= 2;
                if (_capacity == 0)
                    _capacity = n;
                pointer tmp = _alloc.allocate(_capacity);
                for(size_type i = 0; i < pos; i++)
                    _alloc.construct(tmp + i, *(_arr + i));
                for(size_type i = pos; i < pos + n; i++)
                    _alloc.construct(tmp + i, *(first + index++));
                for(size_type i = pos + n; i < _size; i++)
                    _alloc.construct(tmp + i, *(_arr + i - n));
                _alloc.deallocate(_arr, old_cap);
                _arr = tmp;
            }
            else
            {
                size_type index = n - 1;
                for (size_type i = _size - 1; i >= pos + n; i--)
                    _alloc.construct(_arr + i, *(_arr + i - n));
                for (size_type i = pos + n; i > pos; i--)
                    _alloc.construct(_arr + i - 1, *(first + index--));
            }
        }

        iterator erase (iterator position)
        {
            this->erase(position, position + 1);
            return position;
        }

        iterator erase (iterator first, iterator last)
        {
            size_type old_size = _size;
            size_type count = 0;
            size_type pos = 0;
            iterator first_tmp = first;
            for(; first_tmp != last; first_tmp++)
                count++;
            _size -= count;
            iterator it_beg = this->begin();
            for(; it_beg != first; it_beg++)
                pos++;

            for(size_type i = 0; i < count; i++)
                _alloc.destroy(_arr + pos + i);
            for(size_type i = pos; i < _size; i++)
                _alloc.construct(_arr + i, *(_arr + i + count));
            return first;
        }

        void swap (vector& x)
        {
            std::swap(this->_arr, x._arr);
            std::swap(this->_size, x._size);
            std::swap(this->_capacity, x._capacity);
        }

        void clear()
        {
            if(_arr == 0)
                return;
            for(size_type i = 0; i < _size; i++)
                _alloc.destroy(_arr + _size);
            _size = 0;
        }

        //----------------------------Allocator------------------------------//

        allocator_type get_allocator() const {
            return (_alloc);
        }

        //----------------------------Exception------------------------------//
        class LimitingArgumentsException : public std::exception {
		    virtual const char* what() const throw() {
			    return "LimitingArgumentsException: ft::vector there is no <n> argument";
		    }
	    };
    };
    
        //-----------------------Relational operators------------------------//

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	}
    
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                                      rhs.begin(),rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}


}







#endif
