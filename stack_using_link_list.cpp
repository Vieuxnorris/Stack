#include <iostream>

class Node 
{
    public:
        int data;
        Node* next;
};

class Stack
{
    private:
        Node* top;
    public:
        Stack();
        ~Stack();
        void Push(int x);
        int Pop();
        int Peek(int index);
        int IsEmpty();
        int IsFull();
        int StackTop();
};

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node* p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::Push(int x)
{
    Node *t = new Node;
    if (t == nullptr)
        std::cout << "Stack Overflow!" << std::endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::IsFull()
{
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::IsEmpty()
{
    if (top)
        return top->data;
    return -1;
}

int Stack::Peek(int index)
{
    if (IsEmpty())
        return -1;
    else
    {
        Node* p = top;

        for (int i=0; p!= nullptr && i<index-1; i++)
            p = p->next;
        
        if (p != nullptr)
            return p->data;
        else
            return -1;
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    Stack stk;

    // Populate stack
    for (int i=0; i < sizeof(A)/sizeof(A[0]); i++)
        stk.Push(A[i]);

    std::cout << "Stack peek at 3rd: " << stk.Peek(3) << std::endl;
    std::cout << "Stack peek at 10th: " << stk.Peek(10) << std::endl;
    std::cout << "Stack top: " << stk.StackTop() << std::endl;
    std::cout << "Stack full: " << stk.IsFull() << std::endl;
    std::cout << "Stack empty: " << stk.IsEmpty() << std::endl;

    // Pop out elements from stack
    std::cout << "Popped: " << std::flush;
    for (int i=0; i < sizeof(A)/sizeof(A[0]);i++)
        std::cout << stk.Pop() << ", " << std::flush;
    std::cout << std::endl;

    // Underflow
    std::cout << stk.Pop() << std::endl;

    return 0;
}