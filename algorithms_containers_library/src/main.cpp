#include <iostream>
#include "array.hh"

int main() {
    array<int> test(5);
    std::cout << test.get_byte_size()<< std::endl;
    test.push_back(31);
    test.push_back(21);
    
    return 0;
}
