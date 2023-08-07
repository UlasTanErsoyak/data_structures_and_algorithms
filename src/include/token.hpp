#pragma once
#include <string>
#include <map>
enum token_type{
    token_iden,

    token_arrow,

    token_int,
    token_char,
    token_str,
    token_float,

    token_int_literal,
    token_char_literal,
    token_str_literal,
    token_float_literal,

    token_assign,
    token_semi,

    token_lparen,
    token_rparen,
    token_lbrace,
    token_rbrace,

    token_comment,

    token_err,
    token_eof,
};
class token{
    private:
        std::string lexeme;
        token_type type;
    public:
        token(std::string lexeme,token_type type):lexeme(lexeme),type(type){}
        std::uint32_t get_token_len(){
            return this->lexeme.length();
        }
        std::string get_lexeme(){
            return this->lexeme;
        }
        token_type get_type(){
            return this->type;
        }
        std::map<token_type, std::string> token_type_strings = {
        {token_type::token_iden, "token_iden"},
        {token_type::token_arrow, "token_arrow"},
        {token_type::token_int, "token_int"},
        {token_type::token_char, "token_char"},
        {token_type::token_str, "token_str"},
        {token_type::token_float, "token_float"},
        {token_type::token_int_literal, "token_int_literal"},
        {token_type::token_char_literal, "token_char_literal"},
        {token_type::token_str_literal, "token_str_literal"},
        {token_type::token_float_literal, "token_float_literal"},
        {token_type::token_assign, "token_assign"},
        {token_type::token_semi, "token_semi"},
        {token_type::token_lparen, "token_lparen"},
        {token_type::token_rparen, "token_rparen"},
        {token_type::token_lbrace, "token_lbrace"},
        {token_type::token_rbrace, "token_rbrace"},
        {token_type::token_comment, "token_comment"},
        {token_type::token_err, "token_err"},
        {token_type::token_eof, "token_eof"},
    };

std::string token_type_to_string(token_type type) {
    auto it = token_type_strings.find(type);
    if (it != token_type_strings.end()) {
        return it->second;
    }
    return "Unknown Token Type";
}
};