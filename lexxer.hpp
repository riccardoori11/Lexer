#include <ios>
#include <iostream>
#include "token.hpp"

namespace ricc{

		class lexxer{

private:
		std::string input;
		std::size_t pos{};
		
		static constexpr bool is_digit(char c){

				return c >= '0' && c <= '9';
		}
		static constexpr bool is_letter(char c){
				return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
		}

		static constexpr bool is_identifier(char c){
				return is_letter(c) || is_digit(c);
		}

		void skip_whiteSpace(){

				while (input[pos] == ' '){

						++pos;
				}
		}

		Token readIdentifier(){

				std::size_t start = pos;
				++pos;
				while (pos< input.size() && is_identifier(input[pos])){
						++pos;
				}
				
				return Token(TokenType::IDENTIFIER,input.substr(start,pos-start));
		}

		Token readInteger(){

				std::size_t start = pos;
				while(pos < input.size() && is_digit(input[pos])){

						++pos;
				}

				return Token(TokenType::INTEGER, input.substr(start,pos-start));
		}
public:

lexxer(std::string input):input(std::move(input))
		{
		}

Token nextToken(){
				
		while(pos< input.size()){

				skip_whiteSpace();

				if (is_letter(input[pos])){
						return readIdentifier();
						
				}
				else if (is_digit(input[pos])){
						return readInteger();
				}
				std::size_t start = pos;
				pos++;
				
				switch (input[start]){
						case '=':
								return {Token(TokenType::EQUAL, input.substr(start,1))};
						case '+':
								return {Token(TokenType::PLUS, input.substr(start,1))};

						case '-':
								return {Token(TokenType::MINUS, input.substr(start,1))};

						case ';':
								return {Token(TokenType::SEMICOLON, input.substr(start,1))};
						default:
								return {Token(TokenType::ILLEGAL, input.substr(start,1))};
						
				}

		}

		return Token(TokenType::ENDOFFILE,{});
		}
		};
}


