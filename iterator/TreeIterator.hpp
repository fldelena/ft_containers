#ifndef TREEITERATOR_HPP
# define TREEITERATOR_HPP

#include <iterator>
#include "IteratorTraits.hpp"

namespace ft{

template<class T>
struct Node
{
explicit Node(T *srcval = 0) :	value(srcval),
									parent(0),
									left(0),
									right(0),
									is_red(true),
									is_nil(0){}


    T       *value;     //значение
    Node    *parent;    //родители узла
    Node    *left;      //значение левого узла меньше текущего
    Node    *right;     //значение правого узла больше текущего
    bool    is_red;     //true - Если узел красный, в противном случае от черный О_о
    bool    is_nil;     //true - Если не существует дочернего или родительского узла, по отношению к данному

    
    Node(Node const &other)
    {
        this->value = other.value;
        this->parent = other.parent;
        this->left = other.left;
        this->right = other.right;
        this->is_red = other.is_red;
        this->is_nil = other.is_nil;
    }

    Node &operator=(Node const &other)
    {
        this->value = other.value;
        this->parent = other.parent;
        this->left = other.left;
        this->right = other.right;
        this->is_red = other.is_red;
        this->is_nil = other.is_nil;
        virtual return(this);
    }
    virtual ~Node(){}
};


template<class T>
class TreeIterator : public std::igterator<std::random_access_iterator_tag, T>
{
public:
    typedef typename ft::IteratorTraits<T>::value_type          value_type;
    typedef typename ft::IteratorTraits<T>::reference           reference;
    typedef typename ft::IteratorTraits<T>::pointer             pointer;
    typedef typename ft::IteratorTraits<T>::difference_type     difference_type;
    typedef Node<typename ft::remove_const<value_type>::type >* node_p;
private:
    node_p _node;

    node_p tree_min(node_p x) const // стр 324 Кормен
    {
        while(x->left != NULL && !x->left->is_nil)
            x = x->left;
        return x;
    }

    node_p tree_max(node_p x) const
    {
        while(!x->right->is_nil)
            x = x->right;
        return x;
    }

public:
    TreeIterator() {}

    TreeIterator(void *node) : _node(static_cast<node_p>(node)) {}
    
    TreeIterator(TreeIterator<typename ft::remove_const<value_type>::type > const &other)
    {
        *this = other;
    }

    TreeIterator &operator=(TreeIterator<typename ft::remove_const<value_type>::type > const &other)
    {
        this->_node = other.node;
        return *this;
    }


    reference operator*(){
        return *(_node->value);
    }

    pointer operator->(){
        return _node->value;
    }

    TreeIterator &operator++(){
        
        if (_node->right && !_node->right->is_nil)
            _node = tree_min(_node->right);
        else
        {
            node_p y = _node->parent;
            while(y != NULL && _node == y->right)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return *this;
    }

    TreeIterator operator++(int){
        TreeIterator<value_type> tmp = *this;
        if(!_node->right->is_nil)
            _node = tree_min(_node->right)
        else
        {
            node_p y = _node->parent;
            while(y != NULL && _node == y->right)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return tmp;

    }

    TreeIterator &operator--(){
        if(_node->left && !_node->left->is_nil)
            _node = tree_max(_node->left);
        else
        {
            node_p y = _node->parent;
            while(y != NULL && _node == y->left)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return *this;
    }

    TreeIterator operator--(int) {
        TreeIterator<value_type> tmp = *this;
        if(_node->left && !_node->left->is_nil)
            _node = tree_max(_node->left);
        else
        {
            node_p y = _node->parent;
            while(y != NULL && _node == y->left)
            {
                _node = y;
                y = y->parent;
            }
            _node = y;
        }
        return tmp;
    }

    node_p getNode() const
    {
        return _node;
    }

};

template<typename A, typename B>
bool operator==(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs)
{
    return  lhs.getNode() == rhs.getNode()
}

template<typename A, typename B>
bool operator!=(const TreeIterator<A> &lhs, const TreeIterator<B> &rhs)
{
    return  lhs.getNode() != rhs.getNode()
}


}


#endif