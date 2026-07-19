#include <cstdio>
#include <format>
#include <string>
#include <iostream>

// int x = 4 + 5;

enum class TokenType{

		IDENTIFIER,
		EQUAL,
		INTEGER,
		PLUS,
		MINUS,
		SEMICOLON,
		ENDOFFILE,
		ILLEGAL,
		MULTIPLICATION

};

struct Token{

		TokenType tokentype;
		std::string text;

		Token(TokenType tokentype, std::string text):tokentype(tokentype),text(std::move(text)){};

};


