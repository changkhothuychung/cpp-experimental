#ifndef NHAT_OPTIONAL 
#define NHAT_OPTIONAL 

#include <type_traits>
#include <memory>

namespace nhat
{
    struct nullopt_t {}; 

    template<typename T>
    struct optional_storage
    {
        typedef T value_type; 
        union
        {
            char null_state; 
            value_type val; 
        };

        bool engage = false; 

        ~optional_storage() requires (!std::is_trivially_destructible_v<T>)
        {
            if(engage)
            {
                val.~value_type(); 
            }
        }

        ~optional_storage() requires (std::is_trivially_destructible_v<T>) = default; 
        

        constexpr optional_storage(): null_state('\0')
        {

        }

        optional_storage(const optional_storage& other)
        {
            if(engage)
            {
                ::new(std::addressof(val)) value_type(other.val); 
            }
        }
        
        optional_storage(optional_storage&& other) noexcept(std::is_nothrow_move_constructible<value_type>::value)
        {
            if(engage)
            {
                ::new(std::addressof(val)) value_type(std::move(other.val)); 
            }
        }

        /*
        optional_storage& operator=(const optional_storage& other)
        {

        }

        optional_storage& operator=(optional_storage&& other) noexcept(std::is_nothrow_move_assignable<value_type>::type)
        {

        }
        */
        


    };

    // template<typename T>
    // struct optional_storage<T, true>
    // {

    // };

    template<typename T>
    struct optional : public optional_storage<T>
    {

        typedef T value_type;
        typedef optional_storage<T> base; 

        optional(){}

        /*

        template<typename... Args>
        void emplace_back(Args&&... args)
        {

        }

        */

        constexpr value_type& value() const 
        {
            return this->val; 
        }

        value_type& value()
        {
            return this->val; 
        }
    
        template<typename U>
        constexpr value_type value_or(U&& u)
        {
            if(this->engage)
            {
                return this->val; 
            }
            return u; 
        }

        //value_type arrow_operator(){}
        
        bool has_value()
        {
            return this->engage; 
        }

        template<typename U>
        optional& operator=(U&& u) 
        {
            // TODO
            // in case engage is true, forward u 
            // in case engage is false, use inplace new operator 

            this->val = u; 
            this->engage = true; 
        }

        //optional& operator=(const optional& other) = default; 

    };
};

#endif 