#include <iostream>
#include <vector>
#include "vector.hpp"



int main()
{
    std::vector<int> arr(3, 5);
    ft::vector<int> ars(4, 6);

    std::cout << "size:\t" << arr.size() << " cap:\t" <<  arr.capacity() << std::endl;

    std::vector<int>::iterator it_big = arr.begin();
    std::vector<int>::iterator it_end = arr.end();
    while (it_big != it_end)
    {
        std::cout << *it_big << std::endl;
        it_big++;
    }

    std::cout << std::endl;

    std::cout << "size:\t" << ars.size() << " cap:\t" <<  ars.capacity() << std::endl;
    std::vector<int>::iterator it_bis = ars.begin();
    std::vector<int>::iterator it_ens = ars.end();
    while (it_bis != it_ens)
    {
        std::cout << *it_bis << std::endl;
        it_bis++;
    }

}