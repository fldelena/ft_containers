#ifndef LEXICOGRAPHICALCOMPARE_HPP
# define LEXICOGRAPHICALCOMPARE_HPP


/*

lexicographical_compare - возвращяет true если диапазон [first1, last1] 
сравнивается лексографически меньше, чем диапазон [first2, last2] 

лексографически - это последовательное сравнение элементов до тех пор пока 
элементы окажутся неэквивалентны друг-другу или пока хотябы одна из последова-
тельностей не закончится. 

*/

namespace ft {

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first2 < *first1)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

}
#endif