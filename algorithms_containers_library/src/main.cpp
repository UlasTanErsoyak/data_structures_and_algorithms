#include <iostream>
#include "linked_list.hh"
int main() {
    linked_list<int> x;
    x.push_head(6);
    x.push_head(7);
    x.push_head(8);
    x.push_head(9);
    x.make_circular();
    x.make_doubly();
    x.insert(0,2);
    x.reverse();
    return 0;
}
