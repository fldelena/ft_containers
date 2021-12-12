#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iterator>


namespace ft{

    template<class T>
    class VectorIterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef     T                   value_type;
        typedef     value_type*         pointer;
        typedef     value_type const*   const_pointer;
        typedef     value_type&         reference;
        typedef     value_type const&   const_reference;
        typedef     std::ptrdiff_t      difference_type;

    protected:
        value_type* _ptr;
    public:
        //-----------------------------(Con/De)structoR----------------------------//
        VectorIterator() : _ptr(0) {} 

        VectorIterator(pointer ptr) : _ptr(ptr) {}

        VectorIterator(VectorIterator const &other) : _ptr(other._ptr) {}

        virtual ~VectorIterator() {}

        VectorIterator &operator=(VectorIterator const &other)
        {
            this->_ptr = other._ptr;
            return (*this);
        }

        //-------------------------------OperatoR--------------------------------//
        bool operator==(VectorIterator const &other) const
        { return(this->_ptr == other._ptr); }
        bool operator!=(VectorIterator const &other) const
        { return(this->_ptr != other._ptr); }
        bool operator<(VectorIterator const &other) const
        { return(this->_ptr < other._ptr); }
        bool operator>(VectorIterator const &other) const
        { return(this->_ptr > other._ptr); }
        bool operator<=(VectorIterator const &other) const
        { return(this->_ptr <= other._ptr); }
        bool operator>=(VectorIterator const &other) const
        { return(this->_ptr >= other._ptr); }


        reference operator*() {
            return(*this->_ptr); 
        }
        const_reference operator*() const {
            return(*this->_ptr); 
        }
        pointer operator->() {
            return(this->_ptr);
        }
        const_pointer operator->() const {
            return(this->_ptr);
        }


        VectorIterator   &operator++(){
            this->_ptr++;
            return (*this);
        }
        VectorIterator   operator++(int) {
            VectorIterator tmp(*this);
            this->_ptr++;
            return(tmp);
        }
        VectorIterator   &operator--(){
            this->_ptr--;
            return (*this);
        }
        VectorIterator   operator--(int){
            VectorIterator tmp(*this);
            this->_ptr--;
            return(tmp);
        }


        VectorIterator  &operator+=(int value) {
            this->_ptr += value;
            return(*this);
        }
        VectorIterator  &operator-=(int value) {
            this->_ptr -= value;
            return(*this);
        }


        VectorIterator   operator+(int value) const {
            VectorIterator tmp(*this);
            return (tmp += value);
        }
        VectorIterator   operator-(int value) const {
            VectorIterator tmp(*this);
            return (tmp -= value);
        }


        difference_type   operator-(VectorIterator const &other) const {
            return (this->_ptr - other._ptr);
        }


        reference operator[](int value) {
            return(*(this->_ptr + value));
        }
        const_reference operator[](int value) const {
            return(*(this->_ptr + value));
        }
    };

    
}

#endif