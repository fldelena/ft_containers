#include <iostream>
#include <vector>
#include "vector.hpp"



int main()
{
    std::vector<int> arr(5, 10);
    // ft::vector<int> ars(11, 9);

    std::cout << "size:\t" << arr.size() << " cap:\t" <<  arr.capacity() << std::endl;

    arr.resize(12);
    std::cout << "size:\t" << arr.size() << " cap:\t" <<  arr.capacity() << std::endl;
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