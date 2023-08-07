#include "include\lexer.hpp"
void lexer::advance(){
    if(this->pos<this->src.length()&&this->src[this->pos]!='\0')
        this->pos++;   
}
void lexer::skip_white_space(){
    while(this->src[this->pos]==13||this->src[this->pos]==10||this->src[this->pos]==' '||this->src[this->pos]=='\t')
        this->advance();   
}
char lexer::peek(const std::int32_t i){
    return this->src[std::min(this->pos+i,this->src.length())];
}

