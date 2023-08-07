#pragma once
#include <string>
#include <cstdint>
#include "token.hpp"
class lexer{
    private:
        std::string src;
        std::size_t pos;
    public:
        lexer(const std::string& src):src(src),pos(0){}
        void skip_white_space(void);
        void advance();
        void advance(std::int32_t);
        char peek(const std::int32_t i);
        token parse_iden();
        token parse_number();
        token next_token();
};