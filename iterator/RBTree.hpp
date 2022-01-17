#ifndef RBTREE_HPP
# define RBTREE_HPP
#include <memory>
#include "ReverseIterator.hpp"
#include "TreeIterator.hpp"
#include "Pair.hpp"

namespace ft {

template <class T, class Compare = std::less<T>,
                class Alloc = std::allocator<T> >
class rbtree
{
public:
    typedef     T                                           value_type;        
    typedef     Compare                                     value_compare;
    typedef     Alloc                                       allocator_type;
    typedef     typename allocator_type::reference          reference;
    typedef     typename allocator_type::const_reference    const_reference;   
    typedef     typename allocator_type::pointer            pointer;
    typedef     typename allocator_type::const_pointer      const_pointer;
    typedef     TreeIterator<value_type>                    iterator;
    typedef     TreeIterator<const value_type>              const_iterator;
    typedef     ft::ReverseIterator<iterator>               reverse_iterator;
    typedef     ft::ReverseIterator<const_iterator>         const_reverse_iterator;
    typedef     std::ptrdiff_t                              difference_type;
    typedef     std::size_t                                 size_type;
    typedef     allocator_type::template
                rebind<Node<value_type>>::other             node_allocator;
    typedef     typename node_allocator::pointer            node_pointer;
private:

    allocator_type  _val_alloc;
    node_allocator  _alloc;
    node_pointer    _root;
    node_pointer    _nil;
    node_pointer    _node;
    value_compare   _compare

    node_pointer _tree_min(node_pointer x) const
    {
        while(!x->left->is_nil)
            x = x->left;
        return x;
    }

    node_pointer _tree_max(node_pointer x) const
    {
        while(!x->right->is_nil)
            x = x->right;
        return x;
    }

    void _left_rotate(node_pointer x)
    {
        node_pointer y = x->right;
        x->right = y->left;
         
        if(!y->left->is_nil)
            y->left->parent = x;
        y->parent = x->parent;
        if(x->parent->is_nil)
            _node = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else()
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void _right_rotate(node_pointer x)
    {
        node_pointer y = x->left;
        x->left = y = right;

        if(!y->right->is_nil)
            y->right->parent = x;
        y->parent = x->parent;
        if(x->parent->is_nil)
            _node = y;
        else if(x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    node_pointer _rb_insert(node_pointer new_node)
    {
        if (_node == _root)
            _node = new_node;
        else
            _insert_to_node(_node, new_node);
        return new_node;
    }

    node_pointer _insert_to_node(node_pointer node, node_pointer new_node)
    {
        if (_compare(*node->value, *new_node->value)) // return x<y;
        {
            if(!node->right->is_nil)
                return (_insert_to_node(node->right, new_node));
            node->right = new_node;
        }
        else
        {
            if(!node->left->is_nil)
                return (_insert_to_node(node->left, new_node));
            node->left = new_node;
        }
        new_node->parent = node;
        return new_node;
    }

    void rb_insert_fixup(node_pointer node)
    {
        while(node->parent->is_red)
        {
            if(node->parent == node->parent->parent->left)
            {
                node_pointer y = node->parent->parent->right;
                if(y->is_red)
                {
                    node->parent->is_red = false;
                    y->is_red = false;
                    node->parent->parent->is_red = true;
                    node = node->parent->parent;

                }
                else
                {
                    if(node == node->parent->right)
                    {
                        node = node->parent;
                        _left_rotate(node);
                    }
                    node->parent->is_red = false;
                    node->parent->parent->is_red = true;
                    _right_rotate(node->parent->parent);
                }
            }
            else
            {
                node_pointer y = node->parent->parent->left;
                if(y->is_red)
                {
                    node->parent->is_red = false;
                    y->is_red = false;
                    node->parent->parent->is_red = true;
                    node = node->parent->parent;
                }
                else
                {
                    if(node == node->parent->left)
                    {
                        node = node->parent;
                        _right_rotate(node);
                    }
                    node->parent->is_red = false;
                    node->parent->parent->is_red = true;
                    _left_rotate(node->parent->parent);
                }
            }

        }
        _node->is_red = false;
    }

    void init_nil_root()
    {
        _nil = _alloc.allocate(1);
        _alloc.construct(_nil, Node<value_type>());
        _nil->is_red = false;
        _nil->is_nil = true;
        _root = _alloc.allocate(1);
        _alloc.construct(_root, Node<value_type>());
        _root->value = _val_alloc.allocate(1);
        _val_alloc.construct(_root->value, value_type());
        _root->is_red = false;
    }

    void rb_transplant(node_pointer u, node_pointer v)
    {
        if(u->parent == _node )
            _node = v;
        else if(u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void clear_node(node_pointer node)
    {
        if(!node->is_nil)
        {
            clear_node(node->right);
            clear_node(node->left);
            _val_alloc.destroy(node->value);
            _val_alloc.destroy(node->value, 1);
            _alloc.deallocate(node, 1);
        }
    }

    void free_node(node_pointer node)
    {
        _val_alloc.destroy(node->value);
        _val_alloc.deallocate(node->value, 1);
        _node_alloc.deallocate(node, 1); 
    }



public:
    
    //------------------------------Iterators--------------------------------//
    iterator begin(){
        return(iterator(_root));
    }

    const_iterator begin() const{
        return(const_iterator(_root));
    }

    iterator end(){
        return(iterator(_tree_min(_root)));
    }
    
    const_iterator end() const{
        return(const_iterator(_tree_min(_root)));
    }
    rbegin
    rend
    //------------------------------Capacity---------------------------------//
    empty
    size
    max_size
    //---------------------------Element access------------------------------//
    operator[] // map
    //------------------------------Modifiers--------------------------------//
    insert
    erase
    swap
    clear
    //------------------------------Observers--------------------------------//
    key_comp
    value_comp
    //------------------------------Operations-------------------------------//
    find
    count
    lower_bound
    upper_bound
    equal_range
    //------------------------------Allocator--------------------------------//
    get_allocator

};


}

#endif