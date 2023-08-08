#pragma once
#include "lexer.hpp"
#include "token.hpp"
#include "ast.hpp"
class parser{
    private:
        lexer lex;
        token tok;
    public:
        parser(lexer& lex){
            this->lex=lex;
            this->tok=lex.next_token();
        }
        parser()=default;
        token advance();
        ast parse();





};