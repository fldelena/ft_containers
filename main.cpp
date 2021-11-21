#include <iostream>
#include <vector>
#include "vector.hpp"



int main()
{
    std::vector<int> arr;
    ft::vector<int> ars(11, 9);

    std::cout << "max_size:\t" << arr.max_size() << " cap:\t" <<  arr.capacity() << std::endl;
    std::cout << "max_size:\t" << ars.max_size() << " cap:\t" <<  ars.capacity() << std::endl;

    // std::cout <<  "maxSize:\t" << arr.max_size() << std::endl;

    std::vector<int>::iterator it = arr.begin();
    std::vector<int>::iterator ti = arr.end();

    while (it != ti)
    {
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << std::endl;
    
    // std::vector<int>::iterator it1 = arr.begin();
    // std::vector<int>::iterator ti1 = arr.end();

    // while (it1 != ti1)
    // {
    //     std::cout << *it1 << std::endl;
    //     it1++;
    // }


}