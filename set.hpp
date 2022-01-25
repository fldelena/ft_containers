#ifndef SET_HPP
#define SET_HPP


#include "iterator/RBTree.hpp"


namespace ft {


template <class T, class Compare = std::less<T>,
                class Alloc = std::allocator<T> >
class set
{
public:
    //--------------------------------Typedef--------------------------------//
    typedef     T                                                       key_type;
    typedef     T                                                       value_type;
    typedef     Compare                                                 key_compare;
    typedef     Alloc                                                   allocator_type;
    typedef     typename Alloc::reference                               reference;
    typedef     typename Alloc::const_reference                         const_reference;
    typedef     typename Alloc::pointer                                 pointer;
    typedef     typename Alloc::const_pointer                           const_pointer;
    typedef     ft::rbtree<value_type, key_compare, allocator_type>     tree_type;
    typedef     typename tree_type::iterator                            iterator;
    typedef     typename tree_type::const_iterator                      const_iterator;
    typedef     typename tree_type::reverse_iterator                    reverse_iterator;
    typedef     typename tree_type::const_reverse_iterator              const_reverse_iterator;
    typedef     std::ptrdiff_t                                          difference_type;
    typedef     std::size_t                                             size_type;

private:
    tree_type _tree;

public:
    //----------------------------Constructor----------------------------//
    explicit set (const key_compare& comp = key_compare(),
                                            const allocator_type& alloc = allocator_type()) :
                    _tree(tree_type(comp, alloc)) {}

    template <class InputIterator>
    set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                                            const allocator_type& alloc = allocator_type()) :
                    _tree(tree_type(first, last, comp, alloc)) {}
                
    set (const set& x) : _tree(tree_type(x._tree)) {}

    
            
                            


};

}

#endif