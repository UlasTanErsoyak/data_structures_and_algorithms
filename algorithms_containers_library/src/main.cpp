#include <iostream>
#include "array.hh"
int main() {
    array<int> x(3);
    x.push_back(5);
    x.push_back(4);
    x.push_back(3);
    x.insert(3,3);
    return 0;
}
