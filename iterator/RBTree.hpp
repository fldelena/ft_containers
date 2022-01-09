#ifndef RBTREE_HPP
# define RBTREE_HPP
#include <memory>
#include "ReverseIterator.hpp"
#include "TreeIterator.hpp"

namespace ft {

template <class T, class Compare = std::less<T>,
                class Alloc = std::allocator<T> >
class rbtree
{
public:
    typedef     T                                   value_type;        
    typedef     Compare                             value_compare;
    typedef     Alloc                               allocator_type;
    typedef     allocator_type::reference           reference;
    typedef     allocator_type::const_reference     const_reference;   
    typedef     allocator_type::pointer             pointer;
    typedef     allocator_type::const_pointer       const_pointer;
    typedef     TreeIterator<value_type>            iterator;
    typedef     TreeIterator<const value_type>      const_iterator;
    typedef     ft::ReverseIterator<iterator>       reverse_iterator;
    typedef     ft::ReverseIterator<const_iterator> const_reverse_iterator;
    typedef     std::ptrdiff_t                      difference_type;
    typedef     std::size_t                         size_type;
private:

// СОБРАТЬ ДРЕВЕСНЫЙ ИТЕРАТОР




public:
    

};


}

#endif