#ifndef NHAT_TUPLE 
#define NHAT_TUPLE 

#include <type_traits>

namespace nhat 
{
    static constexpr int maximum(int a, int b)
    {
        if (a > b)
        {
            return a; 
        }
        return b; 
    }

    template<int Idx, typename A = void, typename... Args>
    struct ArgType
    {
        using type = typename std::conditional<Idx == 0, A, typename ArgType<maximum(Idx - 1, 0), Args...>::type>::type; 

    };

    template<typename T>
    struct ArgType<0, T>
    {
        using type = T;
    };

    struct tuple_leaf; 

    struct member_end{}; 

    template<int Idx, typename M = void, typename... Membs>
    struct tuple_impl
    {
        M member; 
        typename std::conditional<sizeof...(Membs) == 0, member_end, tuple_impl<Idx+1, Membs...>>::type next_member; 
        static constexpr int getIndex()
        {
            return Idx; 
        }
    };

    template<typename... Args>
    struct tuple
    {
        tuple_impl<0, Args...> members; 
        template<int Idx, typename Ret, typename T>
        Ret& getMemberFromHolder(T& holder)
        {
            if constexpr (T::getIndex() == Idx)
            {
                return holder.member; 
            }
            else
            {
                return getMemberFromHolder<Idx, Ret>(holder.next_member); 
            }
        }

        template<int Idx>
        ArgType<Idx, Args...>::type& get()
        {
            return getMemberFromHolder<Idx, typename ArgType<Idx, Args...>::type>(members); 
        }
    };
};


#endif 