#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "include\lexer.hpp"
int main(void){
    std::ifstream f("../syntax_example.zz");
    std::string str;
    if(f){
       std::ostringstream ss;
       ss << f.rdbuf();
       str = ss.str();
    }
    lexer* a=new lexer(str);
    for(int i =0;i<27;i++){
        auto q=a->next_token();
        std::cout<<q.token_to_str()<<std::endl;
    }

    return 0;
}