#pragma once
#include <string>
#include <cstdint>
#include "token.hpp"
class lexer{
    private:
        std::string src;
        std::size_t pos;
        void skip_white_space(void);
        char peek(const std::int32_t i);
        void advance();
        void advance(std::int32_t);
    public:
        lexer()=default;
        lexer(const std::string& src):src(src),pos(0){}
        token next_token();
};