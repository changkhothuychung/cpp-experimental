#ifndef NHAT_OPTIONAL 
#define NHAT_OPTIONAL 

#include <type_traits>

namespace nhat
{
    struct nullopt_t {}; 


    template<typename T, bool = std::is_trivially_destructible_v<T>>
    struct optional_storage
    {
        typedef T value_type; 
        union
        {
            char null_state; 
            value_type val; 
        };
        bool engage = false; 

        ~optional_storage()
        {
            if(engage)
            {
                val.~value_tupe(); 
            }
        }

        constexpr optional_storage(): null_state('\0')
        {

        }

        /* 
        optional_storage(const optional_storage& other)
        {
            if(engage)
            {
                ::new(std::addressof(val)) value_type(other.val); 
            }
        }
        optional_storage(optional_storage&& other) noexcept(std::is_nothrow_move_constructible<value_type>::value)
        {
            // TODO
        }

        */


    };

    template<typename T>
    struct optional : public optional_storage 
    {

        optional(){}

        template<typename... Args>
        void emplace_back(Args&&... args)
        {

        }

        constexpr value_type value(){}
        value_type& value(){}
        template<typename U>
        constexpr value_type value_or(U&& u){}

        value_type arrow_operator(){}
        bool has_value()
        {
            return this->engage; 
        }
    };
};

#endif 