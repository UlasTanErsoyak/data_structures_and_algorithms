#include "include\lexer.hpp"
#include "include\token.hpp"
#include "include\io.hpp"
int main(void){
    std::string path = "../main.yvt";
    std::string src=read_from_file(path);
    if(src==""){
        std::cout<<"invalid file extension";
        return 1;
    }
    lexer* lex=new lexer(src);
    token tk;
    while(tk.get_type()!=token_eof){
        tk = lex->next_token();
        std::cout<<tk.token_to_str()<<std::endl;
    }
    return 0;
}