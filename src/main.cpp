#include <iostream>
#include "include\lexer.hpp"
void print(token x){
    std::cout<<x.token_type_to_string(x.get_type())<<' ';
}
int main(void){
    std::string x = "a -> float = \"asds\";";
    lexer* a = new lexer(x);
    auto q = a->next_token();
    print(q);
    auto b = a->next_token();
    print(b);

    auto c = a->next_token();
    print(c);

    auto d = a->next_token();
    print(d);

    auto w = a->next_token();
    print(w);

    auto p = a->next_token();
    print(p);

    auto v = a->next_token();
    print(v);


    return 0;
}