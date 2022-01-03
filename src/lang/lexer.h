/*
    File: lexer.h
    Authors: Briggs Richardson, Yasser Dbeis
    Date: 12-21-2021
    Description: Declares the Lexer class. The Lexer performs lexical analysis on an input string
                 and stores the input as tokens in a private tokens vector. The parser can then
                 call the public functions: get_token, peek() in order to perform parsing.
*/

#pragma once

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "error_handler.h"

class Lexer
{
private:
    std::unordered_set<std::string> terminals /* Set containing language key words */
        {";", "->", ",", "=", "bool", "int", "dec", "str", "void", "true", "false", "+", "-", "*", "/", ">", "<",
         ">=", "<=", "is", "and", "or", "not", "!", "{", "{", "(", ")", "while", "if", "elsif", "else", "func", "return"};

    std::unordered_map<std::string, TokenType> terminal_to_token_type =
        {
            {";", TokenType::SEMICOLON},
            {"->", TokenType::RIGHTARROW},
            {",", TokenType::COMMA},
            {"=", TokenType::EQUAL},
            {"bool", TokenType::BOOL},
            {"int", TokenType::INT},
            {"dec", TokenType::DEC},
            {"str", TokenType::STR},
            {"void", TokenType::VOID},
            {"true", TokenType::TRUE},
            {"false", TokenType::FALSE},
            {"+", TokenType::OPERATOR_PLUS},
            {"-", TokenType::OPERATOR_MINUS},
            {"*", TokenType::OPERATOR_MULT},
            {"/", TokenType::OPERATOR_DIV},
            {">", TokenType::OPERATOR_GT},
            {"<", TokenType::OPERATOR_LT},
            {">=", TokenType::OPERATOR_GEQ},
            {"<=", TokenType::OPERATOR_LEQ},
            {"is", TokenType::OPERATOR_IS},
            {"and", TokenType::OPERATOR_AND},
            {"or", TokenType::OPERATOR_OR},
            {"not", TokenType::OPERATOR_NOT},
            {"!=", TokenType::OPERATOR_NEQ},
            {"!", TokenType::OPERATOR_XCL},
            {"{", TokenType::LBRACE},
            {"}", TokenType::RBRACE},
            {"(", TokenType::LPAREN},
            {")", TokenType::RPAREN},
            {"while", TokenType::WHILE},
            {"if", TokenType::IF},
            {"elsif", TokenType::ELSIF},
            {"else", TokenType::ELSE},
            {"func", TokenType::FUNC},
            {"return", TokenType::RETURN}};

    std::unordered_set<char> terminating_symbols{';', '(', '{', '-', ',', '=', '>', '<', '!', ')', '}', '+', '-', '/', '*'};

    std::vector<Token> tokens; /* Vector containing the tokens of the input received in constructor */
    int token_index;           /* Parsing purposes: Keeps track of what token is currently being parsed */
    int input_index;
    int line_number = 1; /* Keep track of current line number for describing the token */

    void lexical_analysis(std::string input); /* Helper function - performs lexical analysis for the constructor */
    void add_token(std::string lexeme, TokenType type);
    void skip_whitespace(std::string input); /* Moves the token_index to the next valid start of a lexeme. Skipping whitespace */
    void consume_comment(std::string);       /* Moves the input_index to the index of the next line */
    void consume_number(std::string);        /* Consumes a number, moves input index onwards, and stores token of the num */
    void consume_string(std::string);        /* Consumes a string terminal, and consquently updates input_index */
    bool is_white_space(char);
    /* Set up the token type map according to the Enum defined in token.h */
    std::unordered_map<TokenType, std::string> token_type_names{{{TokenType::SEMICOLON, "SEMICOLON"},
                                                                 {TokenType::RIGHTARROW, "RIGHTARROW"},
                                                                 {TokenType::COMMA, "COMMA"},
                                                                 {TokenType::EQUAL, "EQUAL"},
                                                                 {TokenType::BOOL, "BOOL"},
                                                                 {TokenType::INT, "INT"},
                                                                 {TokenType::DEC, "DEC"},
                                                                 {TokenType::STR, "STR"},
                                                                 {TokenType::VOID, "VOID"},
                                                                 {TokenType::TRUE, "TRUE"},
                                                                 {TokenType::FALSE, "FALSE"},
                                                                 {TokenType::INT_NUM, "INT_NUM"},
                                                                 {TokenType::DEC_NUM, "DEC_NUM"},
                                                                 {TokenType::STRING, "STRING"},
                                                                 {TokenType::OPERATOR_PLUS, "OPERATOR_PLUS"},
                                                                 {TokenType::OPERATOR_MINUS, "OPERATOR_MINUS"},
                                                                 {TokenType::OPERATOR_MULT, "OPERATOR_MULT"},
                                                                 {TokenType::OPERATOR_DIV, "OPERATOR_DIV"},
                                                                 {TokenType::OPERATOR_GT, "OPERATOR_GT"},
                                                                 {TokenType::OPERATOR_LT, "OPERATOR_LT"},
                                                                 {TokenType::OPERATOR_GEQ, "OPERATOR_GEQ"},
                                                                 {TokenType::OPERATOR_LEQ, "OPERATOR_LEQ"},
                                                                 {TokenType::OPERATOR_IS, "OPERATOR_IS"},
                                                                 {TokenType::OPERATOR_AND, "OPERATOR_AND"},
                                                                 {TokenType::OPERATOR_OR, "OPERATOR_OR"},
                                                                 {TokenType::OPERATOR_NOT, "OPERATOR_NOT"},
                                                                 {TokenType::OPERATOR_XCL, "OPERATOR_XCL"},
                                                                 {TokenType::OPERATOR_NEQ, "OPERATOR_NEQ"},
                                                                 {TokenType::LBRACE, "LBRACE"},
                                                                 {TokenType::RBRACE, "RBRACE"},
                                                                 {TokenType::LPAREN, "LPAREN"},
                                                                 {TokenType::RPAREN, "RPAREN"},
                                                                 {TokenType::WHILE, "WHILE"},
                                                                 {TokenType::IF, "IF"},
                                                                 {TokenType::ELSIF, "ELSIF"},
                                                                 {TokenType::ELSE, "ELSE"},
                                                                 {TokenType::FUNC, "FUNC"},
                                                                 {TokenType::RETURN, "RETURN"},
                                                                 {TokenType::ID, "ID"},
                                                                 {TokenType::END_OF_FILE, "END_OF_FILE"}}};

public:
    Lexer(std::string input); /* Constructs lexer class. Reads input argument and does lexical analysis */
    ~Lexer();                 /* Destructor */

    std::string print_tokens(); /* Testing purposes: Returns a string representing tokens in input */

    Token get_token();          /* Parsing purposes: Consumes and returns the next token in the tokens vector */
    Token peek(int offset = 0); /* Parsing purposes: Returns the token at the given offset in the tokens vector */

    std::string get_token_name(TokenType); /* Gets the stringified name of a token type */

    std::unordered_set<TokenType> operators /* Set containing language key words */
        {
            TokenType::OPERATOR_PLUS,
            TokenType::OPERATOR_MINUS,
            TokenType::OPERATOR_MULT,
            TokenType::OPERATOR_DIV,
            TokenType::OPERATOR_GT,
            TokenType::OPERATOR_LT,
            TokenType::OPERATOR_GEQ,
            TokenType::OPERATOR_LEQ,
            TokenType::OPERATOR_IS,
            TokenType::OPERATOR_AND,
            TokenType::OPERATOR_OR,
            TokenType::OPERATOR_NOT,
            TokenType::OPERATOR_XCL,
            TokenType::OPERATOR_NEQ,
        };

    std::unordered_set<TokenType> leading_operators{
        TokenType::OPERATOR_PLUS,
        TokenType::OPERATOR_MINUS,
        TokenType::OPERATOR_XCL,
        TokenType::OPERATOR_NOT};
};