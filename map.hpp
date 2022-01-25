#ifndef MAP_HPP
#define MAP_HPP

#include "iterator/RBTree.hpp"


namespace ft{


template <class Key, class T, class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{

public: 
    //------------------------------Typedef------------------------------//
    typedef     Key                                                     key_type;
    typedef     T                                                       mapped_type;
    typedef     ft::pair<const key_type, mapped_type>                   value_type;
    typedef     Compare                                                 key_compare;
    typedef     Alloc                                                   allocator_type;
    typedef     typename allocator_type::reference                      reference;
    typedef     typename allocator_type::const_reference                const_reference;
    typedef     typename allocator_type::pointer                        pointer;
    typedef     typename allocator_type::const_pointer                  const_pointer;

private:
    class value_compare
    {
        Compare comp;
    public:
        value_compare(Compare c) : comp(c) {}
        bool operator()(const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };

public: 
    typedef     ft::rbtree<value_type, value_compare, allocator_type>   tree_type;
    typedef     typename tree_type::iterator                            iterator;
    typedef     typename tree_type::const_iterator                      const_iterator;
    typedef     typename tree_type::reverse_iterator                    reverse_iterator;
    typedef     typename tree_type::const_reverse_iterator              const_reverse_iterator;
    typedef     std::ptrdiff_t                                          difference_type;
    typedef     std::size_t                                             size_type;

private:

        tree_type       _tree;
        allocator_type  _alloc; // возмоожно в дальнейшем не пригодится
        key_compare     _compare; // и это тоже

public:
    //----------------------------Constructor----------------------------//
    explicit map (const key_compare& comp = key_compare(),
                                            const allocator_type& alloc = allocator_type()) :
                    _tree(tree_type(comp, alloc)), _alloc(alloc), _compare(comp) {}

    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_kompare(),
                                            const allocator_type &alloc = allocator_type()) :
                    _tree(tree_type(comp, alloc)), _alloc(alloc), _compare(comp)
    {
        this->rb.tree.insert(first, last);
    }

    map (const map& x) : _tree(tree_type(x._tree)) {}


    ~map(){}

         


};


}


#endif