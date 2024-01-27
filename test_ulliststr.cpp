#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
 ULListStr list;

    // list.push_back("fred");
    // list.push_front("bob");

    // std::cout << "first list\n";
    // for (size_t i = 0; i < list.size(); ++i) {
    //     std::cout << list.get(i) << " ";
    // }
    // std::cout<<std::endl;

    list.push_front("bob");
    list.pop_back();

    std::cout << "list\n";
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << list.get(i) << " ";
        std::cout << list.size();
    }
    std::cout<<std::endl;
    return 0;
}
