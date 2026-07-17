#include "lexxer.hpp"
#include <format>

std::string TokenTypename(TokenType t){

		switch (t){
				case TokenType::ENDOFFILE:
						return "END OF FILE";
				case TokenType::PLUS:
						return "PLUS";
				case TokenType::INTEGER:
						return "INTEGER";
				case TokenType::IDENTIFIER:
						return "IDENTIFIER";
				case TokenType::SEMICOLON:
						return "SEMICOLON";
				case TokenType::EQUAL:
						return "EQUAL";
				case TokenType::MINUS:
						return "MINUS";

		}

		return "ILLEGAL";
}

int main(){

		ricc::lexxer lexxer{"int x = 5;"};

		while(true){

				Token token = lexxer.nextToken();

				std::string message(std::format("{} is of TokenType {}", token.text,TokenTypename(token.tokentype))

								);
				  
				std::cout << message << std::endl;

				if (token.tokentype == TokenType::ENDOFFILE){

						break;
				}
		}

		

		return 0;
}



