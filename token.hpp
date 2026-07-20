#include <cstdio>
#include <format>
#include <string>
#include <iostream>


enum class TokenType{

		IDENTIFIER,
		EQUAL,
		INTEGER,
		PLUS,
		MINUS,
		SEMICOLON,
		ENDOFFILE,
		ILLEGAL,
		MULTIPLICATION,
		INT,
		BOOL,
		DOUBLE,
		COMPARE
};

struct Token{

		TokenType tokentype;
		std::string text;
		
		Token(TokenType tokentype, std::string text):tokentype(tokentype),text(std::move(text)){};

};


