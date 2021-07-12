#ifndef TESTIE_CONTAINS_METHOD_H
#define TESTIE_CONTAINS_METHOD_H

#include <utility>

#define def_contains(method)\
template<class T, class = void>\
struct impl_contains_##method {\
    static const bool value = false;\
};\
\
template<class T>\
struct impl_contains_##method<T,std::void_t<decltype(std::declval<T>().method())>> {\
    static const  bool value = true;\
};\
\
template<class T>\
constexpr bool contains_##method = impl_contains_##method<T>::value;
#endif //TESTIE_CONTAINS_METHOD_H
