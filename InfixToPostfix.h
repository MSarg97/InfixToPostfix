#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int = 0, Node* = nullptr);
};

class InfixToPostfix
{
public:
	InfixToPostfix();
	void convertToPostfix();
	void push(int);
	int pop();
	int stackTop();
	bool isEmpty();
	size_t getSize();
	void printStack();
	string getPostfix();
	string getInfix();
	void setInfix(string);
	void setPostfix(string);
	int evaluateExpression();

private:
	Node* first;
	size_t size;
	string infix;
	string postfix;
	bool isOperator(char);
	bool precedence(char, char);
	int calculate(int, char, int);
};
