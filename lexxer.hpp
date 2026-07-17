#include <iostream>
#include <stop_token>

#include "token.hpp"

namespace ricc{

		class lexxer{

private:
		std::string input;
		std::size_t pos{};
		
		static constexpr bool is_digit(char c){

				return c >= '0' || c <= '9';
		}
		static constexpr bool is_letter(char c){
				return c >= 'a' || c <= 'z' || c >= 'A' || c <= '>' || c == '_';
		}

		static constexpr bool is_identifier(char c){

				return is_letter(c) || is_digit(c);
		}

		Token readIdentifier(){

				std::size_t start = pos;

				while (pos < input.size() && is_identifier(input[pos])){

						pos++;
				}
				
				return Token(TokenType::IDENTIFIER,input.substr(start,pos-start));
		}

		Token readInteger(){

				std::size_t start = pos;
				while(pos < input.size() && is_digit(input[pos])){

						pos++;
				}

				return Token(TokenType::INTEGER, input.substr(start,pos-start));
		}


		

public:

		lexxer(std::string input):input(input)
				{
				}

		Token nextToken(){

		while(pos < input.size()){
				switch (input[pos]){
						case '=':
								return Token(TokenType::EQUAL, input.substr(pos,1));
						case '+':
								return Token(TokenType::PLUS, input.substr(pos,1));

						case '-':
								return Token(TokenType::MINUS, input.substr(pos,1));

						case ';':
								return Token(TokenType::SEMICOLON, input.substr(pos,1));
						
				}

				if (is_letter(input[pos])){
						readIdentifier();
				}
				else if (is_digit(input[pos])){

						readInteger();
				}
				else{

						return Token(TokenType::ILLEGAL,input.substr(pos,1));
				}
				pos++;
		}

		return Token(TokenType::ENDOFFILE,{});
		}
		};
}
