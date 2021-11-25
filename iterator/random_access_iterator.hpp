#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>


namespace ft{

    template<class T>
    class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef     T       value_type;
    private:
        value_type* _ptr;
    public:
        //-----------------------------ConstructoR-------------------------------//
        random_access_iterator() : _ptr(0) {} 

        // random_access_iterator(random_access_iterator const &other)
        // {this->_ptr = other._ptr;}

        random_access_iterator(T *ptr) : _ptr(ptr) {}

        random_access_iterator &operator=(random_access_iterator const &other)
        {
        this->_ptr = other._ptr;
        return(*this);
        }

        //-------------------------------OperatoR--------------------------------//
        bool operator==(random_access_iterator const &other) const
        { return(this->_ptr == other._ptr); }
        bool operator!=(random_access_iterator const &other) const
        { return(this->_ptr != other._ptr); }

        value_type  &operator*()  { return(*this->_ptr); }
        value_type  *operator->() { return( this->_ptr); }

        // *a = t

        random_access_iterator   &operator++()
        {
            this->_ptr++;
            return (*this);
        }

        random_access_iterator   operator++(int value)
        {
            random_access_iterator tmp = *this;
            this->_ptr++;
            return(tmp);
        }

        // random_access_iterator   operator++(int value)
        // {
        //     random_access_iterator tmp = *this;
        //     *(this->_ptr)++;
        //     return(tmp);
        // }

        random_access_iterator   &operator--()
        {
            this->_ptr--;
            return (*this);
        }

        random_access_iterator   operator--(int value)
        {
            random_access_iterator tmp = *this;
            this->_ptr--;
            return(tmp);
        }

        // random_access_iterator   operator--(int value)
        // {
        //     random_access_iterator tmp = *this;
        //     *(this->_ptr)--;
        //     return(tmp);
        // }

        random_access_iterator   operator+(int n) const
        {
            random_access_iterator tmp;
            this->_ptr + n;
            return (tmp);
        }

        random_access_iterator   operator-(int n) const
        {
            random_access_iterator tmp;
            this->_ptr - n;
            return (tmp);
        }

        random_access_iterator   operator-(random_access_iterator const &other) const
        {
            random_access_iterator tmp;
            this->_ptr - other._ptr;
            return (tmp);
        }

    };



}

#endif