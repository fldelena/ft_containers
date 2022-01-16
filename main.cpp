#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>
#include <type_traits>
#include "vector.hpp"




int main()
{

    std::vector<int> arr;
    for(int i = 0; i < 4; i++)
        arr.push_back(i);


    std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;

    std::vector<int>::reverse_iterator it_beg = arr.rbegin();
    std::vector<int>::reverse_iterator it_end = arr.rend();
    while(it_beg != it_end)
    {
        std::cout << *it_beg << std::endl;
        ++it_beg;
    }

    
    std::cout << std::endl;
    std::cout << "\n" << "===========" << "\n" << std::endl;
    std::cout << std::endl;


    ft::vector<int> ars;
    for(int i = 0; i < 4; i++)
        ars.push_back(i);


    std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;

    ft::vector<int>::reverse_iterator it_bis = ars.rbegin();
    ft::vector<int>::reverse_iterator it_ens = ars.rend();
    while(it_bis != it_ens)
    {
        std::cout <<  *it_bis << std::endl;
        ++it_bis;
    }
    

}