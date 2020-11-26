#include "InfixToPostfix.h"

Node::Node(int data, Node* next) : data(data), next(next) {
}

InfixToPostfix::InfixToPostfix()
{
	size = 0;
	first = nullptr;
}

bool InfixToPostfix::isEmpty()
{
	return (first == nullptr);
}

size_t InfixToPostfix::getSize()
{
	return size;
}

void InfixToPostfix::setInfix(string infixString)
{
	infix = infixString;
}

void InfixToPostfix::setPostfix(string postFixString)
{
	postfix = postFixString;
}

string InfixToPostfix::getInfix()
{
	return infix;
}

string InfixToPostfix::getPostfix()
{
	return postfix;
}

void InfixToPostfix::printStack()
{
	if (isEmpty())
		cout << "Stack is empty! Nothing to print!\n";
	else
	{
		Node* current = first;

		while (current != nullptr)
		{
			cout << current->data << ' ';
			current = current->next;
		}
	}
}

void InfixToPostfix::convertToPostfix()
{
	push('(');
	infix.append(")");

	for (string::iterator it = infix.begin(); it != infix.end(); it++)
	{
		if (isdigit(*it))
			postfix += *it;
		else if (*it == '(')
			push(*it);
		else if (isOperator(*it))
		{
			while (stackTop() != '(' && precedence(stackTop(), *it))
				postfix += pop();
			push(*it);
		}
		else if (*it == ')')
		{
			while (stackTop() != '(')
				postfix += pop();
			pop();
		}
	}
}

bool InfixToPostfix::isOperator(char character)
{
	return (character == '+' || character == '-' || character == '*' || character == '/') ? true : false;
}

bool InfixToPostfix::precedence(char operator1, char operator2)
{
	return ((operator1 == '+' || operator1 == '-') && (operator2 == '*' || operator2 == '/')) ? false : true;
}

void InfixToPostfix::push(int data)
{
	Node* current = first;

	if (isEmpty())
		first = new Node(data);
	else if (first->next == nullptr)
		first->next = new Node(data);
	else
	{
		while (current->next != nullptr)
			current = current->next;

		current->next = new Node(data);
	}
	size++;
}

int InfixToPostfix::pop()
{
	Node* current = first;
	int currentNodeData;

	if (isEmpty())
		cout << "Stack is empty! Nothing to pop!\n";
	else if (first->next == nullptr)
	{
		first = nullptr;
		size--;
		return current->data;
	}
	else
	{
		while (current->next->next != nullptr)
			current = current->next;

		currentNodeData = current->next->data;
		current->next = nullptr;
		size--;
		return currentNodeData;
	}
}

int InfixToPostfix::stackTop()
{
	Node* current = first;
	
	while (current->next != nullptr)
		current = current->next;

	return current->data;
}

int InfixToPostfix::calculate(int operand1, char op, int operand2)
{	
	int result = 0;

	switch (op)
	{
	case '+': result = operand1 + operand2;
		break;
	case '-': result = operand1 - operand2;
		break;
	case '*': result = operand1 * operand2;
		break;
	case '/': result = operand1 / operand2;
		break;
	}	
	return result;
}

int InfixToPostfix::evaluateExpression()
{
	int op1, op2;
	
	for (string::iterator it = postfix.begin(); it != postfix.end(); it++)
	{
		if (isdigit(*it))
			push(*it - '0');
		else if (isOperator(*it))
		{
			op1 = pop();
			op2 = pop();
			
			push(calculate(op2, *it, op1));
		}
	}	
	return pop();
}
