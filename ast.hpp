#include <string>
#include "token.hpp"
#include <vector>

class Node{

public:
		virtual ~Node() = default;
		virtual std::string TokenLiteral() const = 0;

};


class Statement: public Node{
public:
		~Statement() override = default;
		
};


class Expression: public Node{

public:
		~Expression() override = default;
};

class Program{

public:
		std::vector<Statement> Statements;

};

class ExpressionDeclaration: public Statement{

		public:

				Token token;


};


std::string TokenLiteral(Program* p);

