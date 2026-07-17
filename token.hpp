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
		ILLEGAL

};
namespace ricc{
class Token{

		private:
				TokenType tokentype;
				// the actual source text
				std::string_view text;

		public:
				
				Token(TokenType tokentype, std::string text):tokentype(tokentype),text(text)
		{
		}

};
}


