#include <iostream>
#include "hash_table.hh"
int main() {
    hash_table<char> x(4);
    x.append('c','a');
    x.append('z','b');
    auto b=x['z'];
    return 0;
}
