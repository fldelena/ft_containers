#include <iostream>
#include <vector>
#include "vector.hpp"



int main()
{

    std::vector<int> arr(5, 5);

    std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;
    std::vector<int>::iterator it_big = arr.begin();
    std::vector<int>::iterator it_end = arr.end();

    for(int i = 0; i < arr.size(); i++)
    { std::cout << i+1 << "). " <<  arr.at(i) << std::endl; }

    arr.assign(7, 7);
    std::cout << std::endl;

    std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;
    for(int i = 0; i < arr.size(); i++)
    { std::cout << i+1 << "). " <<  arr.at(i) << std::endl; }

    std::cout << std::endl;



    ft::vector<int> ars(4, 6);

    std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;
    ft::vector<int>::iterator it_bis = ars.begin();
    ft::vector<int>::iterator it_ens = ars.end();

    for(int i = 0; i < ars.size(); i++)
    { std::cout << i+1 << "). " <<  ars.at(i) << std::endl; }

    ars.assign(7, 7);
    std::cout << std::endl;

    std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;
    for(int i = 0; i < ars.size(); i++)
    { std::cout << i+1 << "). " <<  ars.at(i) << std::endl; }

}