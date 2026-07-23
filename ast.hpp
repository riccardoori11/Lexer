#include <algorithm>
#include <memory>
#include "token.hpp"
#include <string>
#include <vector>

class Node{

public:

		virtual ~Node() = default;
		virtual std::string TokenLiteral() const = 0;

};


class Statement: public Node{
public:
		~Statement() override = default;
		virtual void statementNode(){};
		
};


class Expression: public Node{

public:

		virtual void expressionNode() {};
		~Expression() override = default;
};

class Program: public Node{

public:

		std::vector<std::unique_ptr<Statement>> statements;

		std::string TokenLiteral()const override{

				if (statements.empty()){

						return "";
				}
				return statements.front()->TokenLiteral();
			
		}

};

class VariableDeclaration: public Statement{

		public:
				Token token;
				Token name;
				std::unique_ptr<Expression> value;
				
		void statementNode() override {};
		std::string TokenLiteral() const override{

				return token.text;
		};


};

class Identifier: public Expression{

		public:
				Token token;
				std::string value;

		void expressionNode() override {};
};



