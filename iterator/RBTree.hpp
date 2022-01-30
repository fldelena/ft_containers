#ifndef RBTREE_HPP
# define RBTREE_HPP
#include <memory>
#include "ReverseIterator.hpp"
#include "TreeIterator.hpp"
#include "Pair.hpp"
#include "EnableIf.hpp"
#include "IsIntegral.hpp"

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
    typedef     TreeIterator<T>                             iterator;
    typedef     TreeIterator<const T>                       const_iterator;
    typedef     ft::ReverseIterator<iterator>               reverse_iterator;
    typedef     ft::ReverseIterator<const_iterator>         const_reverse_iterator;
    typedef     std::ptrdiff_t                              difference_type;
    typedef     std::size_t                                 size_type;
    typedef     typename Alloc::template
                rebind<Node<value_type> >::other            node_allocator;
    typedef     typename node_allocator::pointer            node_pointer;
private:

    allocator_type  _val_alloc;
    node_allocator  _node_alloc;
    node_pointer    _root;
    node_pointer    _nil;
    node_pointer    _node;
    value_compare   _compare;
    size_type       _size;

    node_pointer _tree_min(node_pointer x) const // tree_min
    {
        while(x != NULL && !is_nil(x->left))
            x = x->left;
        return x;
    }

    node_pointer _tree_max(node_pointer x) const // tree_max
    {
        while(x != NULL && !is_nil(x->right))
            x = x->right;
        return x;
    }

    void _left_rotate(node_pointer x) // _rotate_left
    {
        node_pointer y = x->right;
        x->right = y->left;
         
        if(!is_nil(y->left))
            y->left->parent = x;
        y->parent = x->parent;
        if(x->parent == NULL)
            _node = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void _right_rotate(node_pointer x) // _rotate_right
    {
        node_pointer y = x->left;
        x->left = y = right;

        if(!is_nil(y->right))
            y->right->parent = x;
        y->parent = x->parent;
        if(x->parent == NULL)
            _node = y;
        else if(x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    node_pointer _rb_insert(node_pointer new_node, node_pointer where) //_insert_into_tree
    {
        if (_node == _root)
            _node = new_node;
        else
            _insert_to_node(where, new_node);
        return new_node;
    }


    node_pointer _insert_to_node(node_pointer node, node_pointer new_node) // _insert_to_node
    {
        if (_compare(*new_node->value, *node->value)) // return x<y;
        {
            if(!is_nil(node->left))
                return (_insert_to_node(node->left, new_node));
            node->left = new_node;
        }
        else
        {
            if(!is_nil(node->right))
                return (_insert_to_node(node->right, new_node));
            node->right = new_node;
        }
        new_node->parent = node;
        return new_node;
    }

    void rb_insert_fixup(node_pointer node) // _insert_fixup
    {
        if (node != _node && node->parent != _node){
        while(node != _node && node->parent->is_red)
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
        }
        _node->is_red = false;
    }

    void rb_erase_fixup(node_pointer node) // erase_fixup
    {
        while(node != _node && !node->is_red)
        {
            if(node == node->parent->left)
            {
                node_pointer w_node = node->parent->right;
                if(w_node->is_red)
                {
                    w_node->is_red = false;
                    node->parent->is_red = true;
                    _left_rotate(node->parent);
                    w_node = node->parent->right;
                }
                if(!w_node->left->is_red && !w_node->right->is_red)
                {
                    w_node->is_red = true;
                    node = node->parent;
                }
                else
                {
                    if(!w_node->right->is_red)
                    {
                        w_node->left->is_red = false;
                        w_node->is_red = true;
                        _right_rotate(w_node);
                        w_node = node->parent->right;
                    }
                    w_node->is_red = node->parent->is_red;
                    node->parent->is_red = false;
                    w_node->right->is_red = false;
                    _left_rotate(node->parent);
                    node = _node;
                }
            }
            else
            {
                node_pointer w_node = node->parent->left;
                if(w_node->is_red)
                {
                    w_node->is_red = false;
                    node->parent->is_red = true;
                    _right_rotate(node->parent);
                    w_node = node->parent->left;
                }
                if(!w_node->right->is_red && !w_node->left->is_red)
                {
                    w_node->is_red = true;
                    node = node->parent;
                }
                else
                {
                    if(!w_node->left->is_red)
                    {
                        w_node->right->is_red = false;
                        w_node->is_red = true;
                        _left_rotate(w_node);
                        w_node = node->parent->left;
                    }
                    w_node->is_red = node->parent->is_red;
                    node->parent->is_red = false;
                    w_node->left->is_red = false;
                    _right_rotate(node->parent);
                    node = _node;
                }
            } 
        }
    }

    bool is_nil(node_pointer node) const { // is_nil
        return node == _nil || node == _root;
    }

    void init_nil_root() //init_nil_head
    {
        _nil = _node_alloc.allocate(1);
        _node_alloc.construct(_nil, Node<T>());
        _nil->is_red = false;
        _nil->is_nil = true;
        _root = _node_alloc.allocate(1);
        _node_alloc.construct(_root, Node<T>());
        _root->value = _val_alloc.allocate(1);
        _val_alloc.construct(_root->value, T());
        _root->is_red = false;
    }
//
    pointer create_value(const value_type &value)
    {
        pointer new_val = _val_alloc.allocate(1);
        _val_alloc.construct(new_val, value);
        return new_val;
    }

    node_pointer copy_node(node_pointer other)
    {
        node_pointer new_node = _alloc.allocate(1);
        _alloc.construct(new_node, Node<T>());
        new_node->is_red = other->is_red;
        new_node->is_nil = other->is_nil;
        if(other->value)
        {
            new_node->value = _val_alloc.allocate(1);
            _val_alloc.construct(new_node->value, *other->value);
        }
        return new_node;
    }


    void copy_child(node_pointer my_node, node_pointer)
    {
        if(other->left->is_nil)
            my_node->left = _nil;
        else
        {
            my_node->left = copy_node(other->left);
            my_node->left->parent = my_node;
            copy_child(my_node->left, other->left);
        }
        if(other->right->is_nil)
            my_node->right = _nil;
        else if (other->right->right == NULL)
        {
            my_node->right = _root;
            _root->parent = my_node;
        }
        else
        {
            my_node->right = copy_node(other->right);
            my_node->right->parent = my_node;
            copy_child(my_node->right, other->right);
        }
    }

    node_pointer search(value_type const &value, node_pointer node) const
    {
        if(!node || node->is_nil)
            return NULL;
        if(_compare(value, *node->value))
            return search(value, node->left);
        if(_compare(*node->value, value))
            return search(value, node->right);
        return node;
    }
//
    void rb_transplant(node_pointer u, node_pointer v) // transplant
    {
        if(u == _node )
            _node = v;
        else if(u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void clear_node(node_pointer node) // clear_node
    {
        if(node && !is_nil(node))
        {
            clear_node(node->right);
            clear_node(node->left);
            _val_alloc.destroy(node->value);
            _val_alloc.deallocate(node->value, 1);
            _node_alloc.deallocate(node, 1);
        }
    }

    void free_node(node_pointer node) //free_node
    {
        _val_alloc.destroy(node->value);
        _val_alloc.deallocate(node->value, 1);
        _alloc.deallocate(node, 1); 
    }



public:
    //-----------------------------Constructor-------------------------------//
    rbtree(const key_compare& comp, const allocator_type& alloc) :
            _compare(comp), _val_alloc(alloc), _alloc(0), _node(0), size(0) 
    {
        init_nil_root();
        _node = _root;
    }

    rbtree() : _node(0), _val_alloc(allocator_type()), _alloc(node_allocator()), _compare(value_compare()), _size(0) 
    {
        init_nil_root();
        _node = _root;
    }

    rbtree(rbtree const &other) : _compare(other._compare), _node(NULL)
    {
        *this = other
    }

    template<class InputIterator>
    rbtree(typename ft::enable_if<>)

    rbtree& operator=(const rbtree &src)
    {
        if(this == &src)
            return *this
        this->_alloc = src._alloc;
        this->_val_alloc = src._val_alloc;
        this->_compare = src._compare;
        if(this->_node == NULL)
            init_nil_root();
        else
            clear_node(_node);
        if (src._size == 0)
            this->_node = this->_root;
        else
        {
            this->_node = copy_node(src._node);
            copy_child(this->_node, src._node);
        }
        this->_size = src._size;
        return *this;
    }

    ~rbtree()
    {
        clear_node(_node);
        _val_alloc.destroy(_root->value);
        _val_alloc.deallocate(_root->value, 1);
        _alloc.deallocate(_nil, 1);
        _alloc.deallocate(_root, 1);
    }
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
    reverse_iterator rbegin()
    {
        return(reverse_iterator(end()));
    }
    const_reverse_iterator rbegin() const
    {
        return(const_reverse_iterator(end()));
    }
    reverse_iterator rend()
    {
        return(reverse_iterator(begin()));
    }
    const_reverse_iterator rend() const
    {
        return(const_reverse_iterator(begin()));
    }
    //------------------------------Capacity---------------------------------//
    bool empty() const
    {
        return(_size == 0);
    }
    size_type size() const
    {
        return _size;
    }
    size_type max_size() const
    {
        return _alloc.max_xize();
    }
    //---------------------------Element access------------------------------//
    operator[] // map
    //------------------------------Modifiers--------------------------------//
    pair<iterator,bool> insert (const value_type& val)
    {
        node_pointer found_val = search(val, _node);
        if(found_val)
            return ft::pair<iterator, bool>(iterator(found_val), false);
        node_pointer new_node = _alloc.allocate(1);
        _alloc.construct(new_node, Node<value_type>(create_value(val)));
        new_node->left = _nil;
        new_node->right = _nil;
        _rb_insert(new_node, _node);
        ft::pair<iterator, bool> ret(iterator(new_node), true);
        rb_insert_fixup(new_node);
        _size++;
        // new_node = _tree_max(_node);
        // new_node->right = _root;
        // _root->parent = new_node;
        return ret;
    }

    iterator insert (iterator position, const value_type& val)
    {
        node_pointer found_val = search(val, _node);
        if(found_val)
            return iterator(found_val);
        node_pointer new_node = _alloc.allocate(1);
        _alloc.construct(new_node, Node<value_type>(create_value(val)));
        new_node->left = _nil;
        new_node->right = _nil;
        if(position == begin()) 
        {
            if(position != end() && _compare(value, *position))
                _rb_insert(new_node, tree_min(_node));
            else
                _rb_insert(new_node, _node);
        }
        else if(position == end())
        {
            if(position != begin() && _compare(*(--position), value))
                _rb_insert(new_node, _root->parent);
            else
                _rb_insert(new_node, _node);
        }
        else
            _rb_insert(new_node, _node);
        rb_insert_fixup(new_node);
        _size++;
        // node_pointer max_of_tree = _tree_max(_root);
        // max_of_tree->right = _root;
        // _root->parent = max_of_tree;
        return iterator(new_node);
    }

    template <class InputIterator>
    void insert(typename ft::enable_if< !ft::is_integral<InputIterator>::value, InputIterator >::type first, InputIterator last)
    {
        for(; first != last; ++first)
            insert(*first);
    }


    void erase (iterator position) // возможно подправить
	{
        node_pointer y = position.Node();
        node_pointer x;
        bool y_original_is_red = y->is_red;
        if(position->left->is_nil)
        {
            x = position->right;
            rb_transplant(position, position->right);
        }
        else if (position->right->is_nil)
        {
            x = position->left;
            rb_transplant(position, position->left);
        }
        else
        {
            y = _tree_min(position->right)
            y_original_is_red = y->is_red;
            x = y->right;
            if(y->parent == position)
            {
                x->parent = y;
            }
            else
            {
                rb_transplant(y, y->right);
                y->right = position->right;
                y->right->parent = y;
                rb_transplant(position, y);
                y->left = position->left;
                y->left->parent = y;
                y->is_red = position->is_red;
            }
        }
        if(!y_original_is_red)
            rb_erase_fixup(x);
        _size--;
        _nil->parent = NULL;
        if(_size == 0)
            _node = _root;
        else
        {
            if(_size != 1)
                x = _tree_max(_node);
            else
                x = _node;
            x->right = _root;
            _root->parent = x;
        }
    }

    size_type erase (const key_type& k)
    {
        node_pointer res = search(k, _node);
        if(res)
            erase(iterator(res));
        return (res != NULL);
    }
	
    void erase (iterator first, iterator last)
    {
        while (first != last)
            erase(first++); 
    }


    void swap (map& x)
    {
        std::swap(this->_alloc, x._alloc);
        std::swap(this->_root, x._root);
        std::swap(this->_node, x._node);
        std::swap(this->_nil, x._nil);
        std::swap(this->_compare, x._compare);
        std::swap(this->_size, x._size);
        std::swap(this->_val_alloc, x._val_alloc);
    }

    void clear()
    {
        clear_node(_node);
        _node = _root;
        _root->parent = NULL;
        _size = 0;
    }
    //------------------------------Observers--------------------------------//
    //key_comp() map, set
    value_compare value_comp() const
    {
        return(this->_compare);
    }
    //------------------------------Operations-------------------------------//
    iterator find (const value_type& k)
    {
        node_pointer find_ret = search(k, _node);
        return(find_ret == NULL ? end() : iterator(find_ret));
    }
    const_iterator find (const value_type& k) const
    {
        node_pointer find_ret = search(k, _node);
        return(find_ret == NULL ? end() : const_iterator(find_ret));
    }
    
    size_type count (const value_type& k) const
    {
        if(find(k) != end())
            return 1;
        return 0;
    }

    iterator lower_bound (const value_type& k)
    {
        iterator last = end();
        for(iterator first = begin(); first != last; first++)
        {
            if(_compare(*first, value))
                return(first);
        }
        return last;
    }
    const_iterator lower_bound (const key_type& k) const
    {

    }


    upper_bound
    equal_range
    //------------------------------Allocator--------------------------------//
    get_allocator

};


}

#endif