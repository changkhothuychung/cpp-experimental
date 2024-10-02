#ifndef NHAT_TUPLE 
#define NHAT_TUPLE 


namespace nhat 
{
    struct tuple_leaf; 

    struct member_end{}; 

    template<int Idx, typename Member = void, typename... Membs>
    struct tuple_impl
    {

    };

    template<typename... Args>
    struct tuple
    {

    };
};


#endif 