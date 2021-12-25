#ifndef TREEITERATOR_HPP
# define TREEITERATOR_HPP

#include <iterator>
#include "IteratorTraits.hpp"

namespace ft{

template<class T>
struct Node : 
{
    T       *value;     //значение
    Node    *parent;    //родители узла
    Node    *left;      //значение левого узла меньше текущего
    Node    *right;     //значение правого узла больше текущего
    bool    is_red;     //true - Если узел красный, в противном случае от черный О_о
    bool    is_nil;     //true - Если не существует дочернего или родительского узла, по отношению к данному


    Node(T *val) 
    {
        this->value = val;
        this->parent = 0;
        this->left = 0;
        this->rught = 0;
        this->is_red = true;
        this->is_nil = false; 
    }
    
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

    ~Node(){}
};


template<class T>
class TreeIterator : public std::igterator<std::random_access_iterator_tag, T>
{
public:
    typedef typename ft::IteratorTraits<T>::difference_type  difference_type;
    typedef typename ft::IteratorTraits<T>::value_type       value_type;
    typedef typename ft::IteratorTraits<T>::pointer          pointer;
    typedef typename ft::IteratorTraits<T>::reference        reference;
private:
    Node *_node;

public:
    TreeIterator():
    
    TreeIterator &operator=(TreeIterator const *other)
    {
        this->_node = other.node;
        return *this;
    }


    reference operator*(){
        return(*this->_node);
    }

    pointer operator->(){
        return(this->_node);
    }

    TreeIterator &operator++(){
        //Реализовать эту джуйню
    }

    TreeIterator operator++(int){
        //Реализовать эту джуйню
    }

    TreeIterator &operator++(){
        //Реализовать эту джуйню
    }

    TreeIterator operator++(int){
        //Реализовать эту джуйню
    }


};




}

/* 
   1)Корень дерева всегда черный
   2)Каждый лист дерева (NIL) явл черным узлом
   3)После красного узла должен идти обязательно черный 
   4)Для каждого узла все простые пути до листьев явл
   потомками данного узла, содержат одно и тоже
   количество черных узлов
*/












#endif