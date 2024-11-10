#ifndef NHAT_TUPLE 
#define NHAT_TUPLE 

#include <type_traits>

namespace nhat 
{
    template<typename T, typename... Ts> 
    struct tuple
    {
        T value; 
        tuple<Ts...> rest; 

        constexpr tuple(const T& value, const Ts...& rest): value(value), rest(rest)
        {

        }
    }; 

    template<typename T> 
    struct tuple
    {
        T value; 
        constexpr tuple(const T& value) value(value)
        {
            
        }
    }; 


};


#endif 