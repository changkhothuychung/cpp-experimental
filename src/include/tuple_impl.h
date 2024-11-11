#ifndef TUPLE_IMPL_H 
#define TUPLE_IMPL_H 

#include <type_traits> 

namespace nhat 
{
    template<typename... Ts> 
    struct tuple{};

    template<typename T, typename... Ts> 
    struct tuple
    {
        T value; 
        tuple<Ts...> rest; 

        constexpr tuple(const T& value, const Ts&... rest): value(value), rest(rest...)
        {

        }
    }; 

    template<typename T> 
    struct tuple<T>
    {
        T value; 
        constexpr tuple(const T& value): value(value)
        {
            
        }
    }; 

    template<size_t N, typename T, typename... Ts> 
    struct get_nth: get_nth<N - 1, Ts...> 
    {
        static constexpr auto get(tuple<T, Ts...>& t)
        {
            if constexpr (N == 0)
            {
                return t.value; 
            }
            else
            {
                return get_nth<N-1, Ts...>::get(t.rest); 
            }
        }
    };

    template<typename T, typename... Ts> 
    struct get_nth<0, T, Ts...>
    {
        using type = T; 

        static constexpr T& get(tuple<T, Ts...>& t)
        {   
            return t.value;
        }
    };

    template<size_t I, typename... Ts> 
    typename get_nth<I, Ts...>::type& get(tuple<Ts...>& t)
    {
        return get_nth<I, Ts...>::get(t); 
    }

    template<class... TTypes>
    constexpr tuple<unwrap_ref_decay_t<TTypes>...> make_tuple(TTypes&&... t)
    {
        return tuple<unwrap_ref_decay_t<TTypes>...>(std::forward<TTypes>(t)...); 
    }

    template<class... TTypes>
    constexpr tuple<TTypes&&...> forward_as_tuple(TTypes&&... t) noexcept 
    {
        return tuple<TTypes&&...>(std:;forward<TTypes>(t)...); 
    }

    template<class F, class Tuple>
    constexpr decltype(auto) apply(F&& f, Tuple&& t); 


};


#endif 