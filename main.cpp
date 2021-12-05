#include <iostream>
#include <vector>
#include "vector.hpp"


//insert -  возвращает итероатор указывающий на положение в векторе сообветствующему прложению нового элемента


int main()
{
    std::vector<int> arr(3, 3);
    std::vector<int>::iterator it = arr.begin();
    std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;
    it += 5;
    arr.insert(it, 4, 777);
    
    std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;
    std::vector<int>::iterator it_beg = arr.begin();
    std::vector<int>::iterator it_end = arr.end();

    while(it_beg != it_end)
    {
        std::cout << *it_beg << std::endl;
        ++it_beg;
    }

    
    std::cout << std::endl;
    std::cout << "\n" << "===========" << "\n" << std::endl;
    std::cout << std::endl;


    ft::vector<int> ars(3, 3);
    ft::vector<int>::iterator is = ars.begin();
    std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;
    is += 5;
    ars.insert(is, 4, 777);
    
    std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;
    ft::vector<int>::iterator it_bis = ars.begin();
    ft::vector<int>::iterator it_ens = ars.end();

    while(it_bis != it_ens)
    {
        std::cout <<  *it_bis << std::endl;
        ++it_bis;
    }
    std::cout << std::endl;

}