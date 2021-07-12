#include "contains_method.h"


def_contains(cool_name)
def_contains(lol_xD)
def_contains(omg_does_it_actually_work)
def_contains(does_not_exist)

struct test {
    int cool_name();
    int lol_xD();
    char omg_does_it_actually_work();
};

int main(){
    static_assert(contains_cool_name<test>);
    static_assert(contains_lol_xD<test>);
    static_assert(contains_omg_does_it_actually_work<test>);
    static_assert(not contains_does_not_exist<test>);
}