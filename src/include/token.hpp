#include <string>
enum token_type{
    token_iden,

    token_arrow,
    token_int,

    token_equals,
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
};