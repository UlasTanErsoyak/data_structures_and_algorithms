#include <iostream>
#include "linked_list.hh"
int main() {
    linked_list<int> x;
    x.push_head(6);
    x.push_head(7);
    x.push_head(8);
    x.push_head(9);
    auto a = x.pop_head();
    auto b = x.pop_head();
    auto c = x.pop_head();
    auto d = x.pop_head();
    return 0;
}
