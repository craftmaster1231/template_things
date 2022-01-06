#ifndef BASIC_COUNTERH
#define BASIC_COUNTERH

#include <utility>

namespace meta::basic_counter {
        namespace details {

            template<std::size_t V>
            struct decl {
                auto friend tag(decl<V>);
            };

            template<class T>
            struct def {
                auto friend tag(T) { return int{}; }
            };

            struct dummy : def<decl<0>> {
            };

            template<std::size_t V, auto u, class = void>
            struct get_impl {
                static const std::size_t value = V - 1;
            };

            template<std::size_t V, auto u>
            struct get_impl<V, u, std::void_t<decltype(tag(decl<V>{}))>> {
                static const std::size_t value = get_impl<V + 1, [](){}, void>::value;
            };

            //get_impl_for_incr to avoid ICE

            template<std::size_t V, auto u, class = void>
            struct get_impl_for_incr {
                static const std::size_t value = V - 1;
            };

            template<std::size_t V, auto u>
            struct get_impl_for_incr<V, u, std::void_t<decltype(tag(decl<V>{}))>> {
                static const std::size_t value = get_impl<V + 1, [](){}, void>::value;
            };
        }

        template<auto = [](){}>
        struct get : details::get_impl<0, [](){}> {};

        template<auto = []() {}, auto = sizeof(details::def<details::decl<details::get_impl_for_incr<0,[](){}>::value + 1 >> )>
        struct incr {};

        template<auto = []() {}>
        constexpr auto get_v = get<[](){}>::value;

        template<auto uniq = [](){}>
        constexpr std::size_t fget() {
            return meta::basic_counter::get<uniq>::value;
        }

        template<auto uniq = [](){}, auto = sizeof(basic_counter::details::def<basic_counter::details::decl<basic_counter::get<uniq>::value + 1>>)>
        constexpr void fincr() { }
    }
#ifndef // BASIC_COUNTERH
