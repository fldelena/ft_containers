#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <utility>
#include "vector.hpp"


int main()
{
    

  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  return 0;



    // std::vector<int> arr;
    // for(int i = 0; i < 4; i++)
    //     arr.push_back(i);
    // // arr.reserve(6);

    // std::cout << "size:\t" << arr.size() << " cap:\t" << arr.capacity() << std::endl;

    // std::vector<int>::reverse_iterator it_beg = arr.rbegin();
    // std::vector<int>::reverse_iterator it_end = arr.rend();
    // while(it_beg != it_end)
    // {
    //     std::cout << *it_beg << std::endl;
    //     ++it_beg;
    // }

    
    // std::cout << std::endl;
    // std::cout << "\n" << "===========" << "\n" << std::endl;
    // std::cout << std::endl;


    // ft::vector<int> ars;
    // for(int i = 0; i < 4; i++)
    //     ars.push_back(i);
    // // ars.reserve(6);

    // std::cout << "size:\t" << ars.size() << " cap:\t" << ars.capacity() << std::endl;

    // ft::vector<int>::reverse_iterator it_bis = ars.rbegin();
    // ft::vector<int>::reverse_iterator it_ens = ars.rend();
    // while(it_bis != it_ens)
    // {
    //     std::cout <<  *it_bis << std::endl;
    //     ++it_bis;
    // }
    

}