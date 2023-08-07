#include "include\lexer.hpp"
void lexer::advance(){
    if(this->pos<this->src.length()&&this->src[this->pos]!='\0')
        this->pos++;   
}
void lexer::advance(std::int32_t i){
    if(this->pos<this->src.length()&&this->src[this->pos]!='\0')
        this->pos+=i;   
}
void lexer::skip_white_space(){
    while(this->src[this->pos]==13||this->src[this->pos]==10||this->src[this->pos]==' '||this->src[this->pos]=='\t')
        this->advance();
}
char lexer::peek(const std::int32_t i){
    return this->src[std::min(this->pos+i,this->src.length())];
}
token lexer::next_token(){
    this->skip_white_space();
    std::string rs;
    if (this->pos >= this->src.length() || this->src[this->pos] == '\0') {
        return token("",token_type::token_eof);
    }
    if (isalpha(this->src[this->pos])){
            while(isalnum(this->src[this->pos])){
                rs += this->src[this->pos];
                this->advance();
            }
            if(rs=="int"){
                return token(rs,token_type::token_int);
            }
            else if(rs=="char"){
                return token(rs,token_type::token_char);
            }
            else if(rs=="str"){
                return token(rs,token_type::token_str);
            }
            else if(rs=="float"){
                return token(rs,token_type::token_float);
            } 
            else{
                return token(rs,token_type::token_iden);
            }
    }
    else if(isdigit(this->src[this->pos])){
        while (isdigit(this->src[this->pos])||this->src[this->pos]=='.') {
            rs+=this->src[this->pos];
            this->advance();
        }
        if (rs.find('.')!=std::string::npos){
            return token(rs,token_type::token_float_literal);
        } else {
        return token(rs,token_type::token_int_literal);
        }
    }
    else if (this->src[this->pos]=='\"'){
        rs += this->src[this->pos];
        this->advance();
        while (this->src[this->pos]!='\"'&&this->src[this->pos]!='\0') {
            rs += this->src[this->pos];
            this->advance();
        }
        if (this->src[this->pos]=='\"') {
            rs += this->src[this->pos];
            this->advance();
            return token(rs,token_type::token_str_literal);
        } else {
            return token("Unterminated string literal",token_type::token_err);
        }
    }
    else if(this->src[this->pos]==';'){
        advance();
        return token(";",token_type::token_semi);
    }
    else if(this->src[this->pos]=='='){
        advance();
        return token("=",token_type::token_assign);
    }
    else if(this->src[this->pos]=='-'&&this->peek(1)=='>'){
        advance(2);
        return token("->",token_type::token_arrow);
    }
    else if(this->src[this->pos]=='('){
        advance();
        return token("(",token_type::token_rparen);
    }
    else if(this->src[this->pos]==')'){
        advance();
        return token(")",token_type::token_lparen);
    }
    else if(this->src[this->pos]=='{'){
        advance();
        return token("{",token_type::token_rbrace);
    }
    else if(this->src[this->pos]=='}'){
        advance();
        return token("}",token_type::token_lbrace);
    }
    return token("unexpected char", token_type::token_err);
}