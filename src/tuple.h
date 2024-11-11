#ifndef NHAT_TUPLE 
#define NHAT_TUPLE 

#include <type_traits>

/*
// all freestanding
#include <compare>              // see [compare.syn]

namespace std {
  // [tuple.tuple], class template tuple
  template<class... Types>
    class tuple;

  // [tuple.like], concept tuple-like
  template<class T>
    concept tuple-like = see below;         // exposition only
  template<class T>
    concept pair-like =                     // exposition only
      tuple-like<T> && tuple_size_v<remove_cvref_t<T>> == 2;

  // [tuple.common.ref], common_reference related specializations
  template<tuple-like TTuple, tuple-like UTuple,
           template<class> class TQual, template<class> class UQual>
    struct basic_common_reference<TTuple, UTuple, TQual, UQual>;
  template<tuple-like TTuple, tuple-like UTuple>
    struct common_type<TTuple, UTuple>;

  // ignore
  struct ignore-type {                      // exposition only
    constexpr const ignore-type
      operator=(const auto &) const noexcept { return *this; }
  };
  inline constexpr ignore-type ignore;

  // [tuple.creation], tuple creation functions
  template<class... TTypes>
    constexpr tuple<unwrap_ref_decay_t<TTypes>...> make_tuple(TTypes&&...); // added

  template<class... TTypes>
    constexpr tuple<TTypes&&...> forward_as_tuple(TTypes&&...) noexcept; 

  template<class... TTypes>
    constexpr tuple<TTypes&...> tie(TTypes&...) noexcept;

  template<tuple-like... Tuples>
    constexpr tuple<CTypes...> tuple_cat(Tuples&&...);

  // [tuple.apply], calling a function with a tuple of arguments
  template<class F, tuple-like Tuple>
    constexpr decltype(auto) apply(F&& f, Tuple&& t) noexcept(see below);

  template<class T, tuple-like Tuple>
    constexpr T make_from_tuple(Tuple&& t);

  // [tuple.helper], tuple helper classes
  template<class T> struct tuple_size;                  // not defined
  template<class T> struct tuple_size<const T>;

  template<class... Types> struct tuple_size<tuple<Types...>>;

  template<size_t I, class T> struct tuple_element;     // not defined
  template<size_t I, class T> struct tuple_element<I, const T>;

  template<size_t I, class... Types>
    struct tuple_element<I, tuple<Types...>>;

  template<size_t I, class T>
    using tuple_element_t = typename tuple_element<I, T>::type;

  // [tuple.elem], element access
  template<size_t I, class... Types>
    constexpr tuple_element_t<I, tuple<Types...>>& get(tuple<Types...>&) noexcept;
  template<size_t I, class... Types>
    constexpr tuple_element_t<I, tuple<Types...>>&& get(tuple<Types...>&&) noexcept;
  template<size_t I, class... Types>
    constexpr const tuple_element_t<I, tuple<Types...>>& get(const tuple<Types...>&) noexcept;
  template<size_t I, class... Types>
    constexpr const tuple_element_t<I, tuple<Types...>>&& get(const tuple<Types...>&&) noexcept;
  template<class T, class... Types>
    constexpr T& get(tuple<Types...>& t) noexcept;
  template<class T, class... Types>
    constexpr T&& get(tuple<Types...>&& t) noexcept;
  template<class T, class... Types>
    constexpr const T& get(const tuple<Types...>& t) noexcept;
  template<class T, class... Types>
    constexpr const T&& get(const tuple<Types...>&& t) noexcept;

  // [tuple.rel], relational operators
  template<class... TTypes, class... UTypes>
    constexpr bool operator==(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, tuple-like UTuple>
    constexpr bool operator==(const tuple<TTypes...>&, const UTuple&);
  template<class... TTypes, class... UTypes>
    constexpr common_comparison_category_t<synth-three-way-result<TTypes, UTypes>...>
      operator<=>(const tuple<TTypes...>&, const tuple<UTypes...>&);
  template<class... TTypes, tuple-like UTuple>
    constexpr see below operator<=>(const tuple<TTypes...>&, const UTuple&);

  // [tuple.traits], allocator-related traits
  template<class... Types, class Alloc>
    struct uses_allocator<tuple<Types...>, Alloc>;

  // [tuple.special], specialized algorithms
  template<class... Types>
    constexpr void swap(tuple<Types...>& x, tuple<Types...>& y) noexcept(see below);
  template<class... Types>
    constexpr void swap(const tuple<Types...>& x, const tuple<Types...>& y) noexcept(see below);

  // [tuple.helper], tuple helper classes
  template<class T>
    constexpr size_t tuple_size_v = tuple_size<T>::value;
*/

#endif 