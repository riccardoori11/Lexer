#include <string>

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

struct Program{

		Statement[] Statements;

};
