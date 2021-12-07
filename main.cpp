#include <iostream>
#include <vector>
#include "vector.hpp"


//insert -  возвращает итероатор указывающий на положение в векторе сообветствующему прложению нового элемента


int main()
{
    std::vector<int> arr1(3, 3);
    std::vector<int> arr2(5, 5);
    

    arr1.swap(arr2);
    std::cout << "size:\t" << arr1.size() << " cap:\t" << arr1.capacity() << std::endl;
    std::cout << "size:\t" << arr2.size() << " cap:\t" << arr2.capacity() << std::endl;
    std::vector<int>::iterator it_beg = arr1.begin();
    std::vector<int>::iterator it_end = arr1.end();
    while(it_beg != it_end)
    {
        std::cout << *it_beg << std::endl;
        ++it_beg;
    }

    
    std::cout << std::endl;
    std::cout << "\n" << "===========" << "\n" << std::endl;
    std::cout << std::endl;


    ft::vector<int> ars(3, 3);

    ars.erase(ars.begin(), ars.end());

    std::cout << "size:\t" << arr1.size() << " cap:\t" << arr1.capacity() << std::endl;
    ft::vector<int>::iterator it_bis = ars.begin();
    ft::vector<int>::iterator it_ens = ars.end();
    while(it_bis != it_ens)
    {
        std::cout <<  *it_bis << std::endl;
        ++it_bis;
    }
    std::cout << std::endl;

}