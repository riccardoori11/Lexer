#include "ast.hpp"
#include <string>

std::string TokenLiteral(Program *p){

		if (p->Statements.size() > 0){

				return p->Statements[0].TokenLiteral();
		}
		else{
				return "";
		}
}



