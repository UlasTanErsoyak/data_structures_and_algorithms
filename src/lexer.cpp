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
            if(rs=="if"){
                return token(rs,token_type::token_if);
            }
            else if(rs=="int"){
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
            else if(rs=="while"){
                return token(rs,token_type::token_while);
            }
            else if(rs=="for"){
                return token(rs,token_type::token_for);
            }
            else if(rs=="bundle"){
                return token(rs,token_type::token_bundle);
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
    else if(this->src[this->pos]=='-'&&this->peek(1)=='>'){
        advance(2);
        return token("->",token_type::token_arrow);
    }
    else if(this->src[this->pos]=='+'){
        advance();
        return token("+",token_type::token_accumulate);
    }
    else if(this->src[this->pos]=='-'){
        advance();
        return token("-",token_type::token_substract);
    }
    else if(this->src[this->pos]=='/'){
        advance();
        return token("/",token_type::token_divide);
    }
    else if(this->src[this->pos]=='*'){
        advance();
        return token("*",token_type::token_multiply);
    }
    else if(this->src[this->pos]==';'){
        advance();
        return token(";",token_type::token_semi);
    }
    else if(this->src[this->pos]=='='){
        advance();
        return token("=",token_type::token_assign);
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
    else if(this->src[this->pos]=='['){
        advance();
        return token("[",token_type::token_lbrack);
    }
    else if(this->src[this->pos]==']'){
        advance();
        return token("]",token_type::token_rbrack);
    }
    else if(this->src[this->pos]=='>'){
        advance();
        return token(">",token_type::token_greater);
    }
    else if(this->src[this->pos]=='<'){
        advance();
        return token("<",token_type::token_less);
    }
    else if(this->src[this->pos]==','){
        advance();
        return token(",",token_type::token_comma);
    }
    else if(this->src[this->pos]=='#'){
        std::string rs;
        while(this->src[this->pos]!='\n'){
            rs+=this->src[this->pos];
            advance();
        }
        advance();
        return token(rs,token_type::token_comment);
    }
    return token("unexpected char", token_type::token_err);
}