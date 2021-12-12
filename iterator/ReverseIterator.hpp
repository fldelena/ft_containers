#ifndef REVERSEITERATOR_HPP
#define REVERSEITERATOR_HPP

#include <iterator>
#include  "VectorIterator.hpp"

namespace ft{

    template<typename It>
    class ReverseIterator: public It
    {
    public:
        using typename It::value_type;
        using typename It::pointer;
        using typename It::const_pointer;
        using typename It::reference;
        using typename It::const_reference;
        using typename It::difference_type;

    public:
        ReverseIterator(): It() {}
        ReverseIterator(It const &it): It(it) {}
        ReverseIterator(ReverseIterator const &other): It(other._ptr) {}

        ReverseIterator &operator=(ReverseIterator const &other) {
            this->_ptr = other._ptr;
            return (*this);
        }

        reference operator*() {
            It tmp(*this);
            return(*--tmp);
        }

        const_reference operator*() const {
            It tmp(*this);
            return(*--tmp);
        }

        pointer operator->() {
            It tmp(*this);
            return(&*--tmp);
        }

        const_pointer operator->() const {
            It tmp(*this);
		    return (&*--tmp);
        }

	    ReverseIterator operator++(int) {
		    ReverseIterator tmp(*this);
		    operator++();
		    return (tmp);
	    }

        It &operator++() {
            return (this->It::operator--());
        }

	    ReverseIterator operator--(int) {
		    ReverseIterator tmp(*this);
		    operator--();
		    return (tmp);
	    }

        It &operator--() {
		    return (this->It::operator++());
	    }
    };
};


#endif