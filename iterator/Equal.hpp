#ifndef EQUAL_HPP
#define EQUAL_HPP


/*
    Сравнивает элементы в диапазоне [first1,last1) с элементами в диапазоне,
    начинающемся с first2, и возвращает true, если все элементы в обоих
    диапазонах совпадают.
*/

namespace ft{

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
    while (first1!=last1)
    {
        if (!(*first1 == *first2))
            return false;
        ++first1; ++first2;
    }
    return true;
};

}



#endif