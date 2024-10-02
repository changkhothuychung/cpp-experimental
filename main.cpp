#include <iostream>
#include <type_traits>
#include "src/tuple.h"


int main()
{
    nhat::tuple<bool, int, float> tuple;
    tuple.get<2>() = 2.0f;
    std::cout << tuple.get<2>() << std::endl; 
    return 0;
}