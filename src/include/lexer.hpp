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
        void advance_this();
        char peek(const std::int32_t i);
        token parse_id();
        token parse_number();
        token next_token();
};