#include <iostream>
#include "InfixToPostfix.h"

using namespace std;

int main()
{
	InfixToPostfix obj;

	obj.setInfix("(7*6-5*4)/2+((3*6-9/3*2)*3-4)*5");
	
	cout << "Infix: " << obj.getInfix() << endl;
	
	obj.convertToPostfix();
	
	cout << "Postfix: " << obj.getPostfix() << endl;	
	cout << "Value of posfix expression: " << obj.evaluateExpression() << endl;
	
	return 0;
}