#include <iostream>
#include "stack.hh"
int main() {
    stack<int> x(5);
    x.push(2);
    x.push(3);
    x.push(4);
    x.push(5);
    x.push(6);
    auto p=x.is_full();
    auto q = x.pop();
    auto a = x.pop();
    auto h = x.pop();
    auto u = x.pop();
    auto j = x.pop();
    auto k=x.is_full();
    auto w=x.is_empty();

    return 0;
}
