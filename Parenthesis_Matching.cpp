#include <iostream>
#include <cstring>

class Node
{
    public:
        char data;
        Node* next;
};

class Stack
{
    private:
        Node* top;
    public:
        Stack();
        ~Stack();
        void Push(char x);
        char Pop();
        char Peek(int index);
        int IsEmpty();
        int IsFull();
        char StackTop();
};

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node *p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::Push(char x)
{
    Node* t = new Node;
    if (t == nullptr)
        std::cout << "Stack overflow!" << std::endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::Pop()
{
    Node* p;
    char x = -1;
    if (top == nullptr)
        std::cout << "Stack Underflow!" << std::endl;
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::IsFull()
{
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::IsEmpty()
{
    return top ? 0 : 1;
}

char Stack::StackTop()
{
    if (top)
        return top->data;
    return -1;
}

char Stack::Peek(int index)
{
    if(IsEmpty())
        return -1;
    else
    {
        Node* p = top;

        for (int i=0; p != nullptr && i < index-1; i++)
            p = p->next;
        
        if (p != nullptr)
            return p->data;
        else
            return -1;
    }
}

int IsBalanced(char* exp)
{
    Stack stk;

    for (int i=0; i< strlen(exp);i++)
    {
        if (exp[i] == '(')
            stk.Push(exp[i]);
        else if (exp[i] == ')')
        {
            if (stk.IsEmpty())
                return false;
            else
                stk.Pop();
        }
    }
    return stk.IsEmpty() ? true : false;
}

int main()
{
    char E[] = "((a+b)*(c-d))";
    std::cout << IsBalanced(E) << std::endl;

    char F[] = "((a+b)*(c-d)))";
    std::cout << IsBalanced(F) << std::endl;

    char G[] = "(((a+b)*(c-d))";
    std::cout << IsBalanced(G) << std::endl;

    return 0;
}