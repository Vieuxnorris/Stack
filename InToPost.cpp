#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


struct Node {
	char data;
	struct Node* Next;
}*top=NULL;

void push(char x)
{
	struct Node* t;
	t = new Node;
	if (t == NULL)
		std::cout << "Stack Overflow" << std::endl;
	else
	{
		t->data = x;
		t->Next = top;
		top = t;
	}
}

char pop()
{
	struct Node* t;
	char x = -1;
	
	if (top == NULL)
		std::cout << "Stack is empty" << std::endl;
	else
	{
		t = top;
		top = top->Next;
		x = t->data;
		free(t);
	}
	return x;
}

int pre(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	return 0;
}

int isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else
		return 1;
}

char* InToPost(char* infix)
{
	int i = 0, j = 0;
	char* postfix;
	int len = strlen(infix);
	postfix = new char(len + 1);

	while (infix[i] != '\0')
	{
		if (isOperand(infix[i]))
			postfix[j++] = infix[i++];
		else
		{
			if (pre(infix[i]) > pre(top->data))
				push(infix[i++]);
			else
				postfix[j++] = pop();
		}
	}
	while (top != NULL)
	{
		postfix[j++] = pop();
		postfix[j] = '\0';
		return postfix;
	}
}

int main()
{
	char *infix = (char*)"a+b*c-d/e";
	push('#');

	char* postfix = InToPost(infix);
	std::cout << postfix << std::endl;
	return 0;
}