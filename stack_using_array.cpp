#include <iostream>

class Stack{
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(int size);
        ~Stack();
        void push(int x);
        int pop();
        int peek(int index);
        int isFull();
        int isEmpty();
        void display();
        int stackTop();
};

Stack::Stack(int size)
{
    this->size = size;
    this->top = -1;
    this->s = new int(size);
}

Stack::~Stack()
{
    delete[] this->s;
}

int Stack::peek(int index)
{
    int x = -1;
    if (this->top-index+1 < 0 || this->top-index+1 == size)
        std::cout << "Invalid position" << std::endl;
    else
        x = this->s[this->top-index+1];
    return x;
}

void Stack::push(int x)
{
    if(isFull())
        std::cout << "Stack Overflow!" << std::endl;
    else
    {
        this->top++;
        this->s[this->top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
        std::cout << "Stack Underflow!" << std::endl;
    else
    {
        x = this->s[this->top];
        this->top--;
    }
    return x;
}

int Stack::isFull()
{
    if (this->top == this->size-1)
        return 1;
    return 0;
}

int Stack::isEmpty()
{
    if (this->top == -1)
        return 1;
    return 0;
}

void Stack::display()
{
    for (int i=this->top;i>=0;i--)
        std::cout << this->s[i] << " | " << i << std::endl << std::flush;
    std::cout << std::endl;
}

int Stack::stackTop()
{
    if (isEmpty())
        return -1;
    return this->s[this->top];
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};

    Stack stk(sizeof(A) / sizeof(A[0]));

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        stk.push(A[i]);

    stk.push(11);

    std::cout << "Stack full: " << stk.isFull() << std::endl;

    std::cout << "Stack: " << std::endl;
    stk.display();

    std::cout << "Peek at 0th: " << stk.peek(0) << std::endl;
    std::cout << "Peek at 3rd: " << stk.peek(3) << std::endl;
    std::cout << "Peek at 10rd: " << stk.peek(10) << std::endl;

    std::cout << "Top element: " << stk.stackTop() << std::endl;

    std::cout << "Popped out elements: " << std::flush;
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++)
        std::cout << stk.pop() << ", " << std::flush;
    
    std::cout << std::endl;
    stk.pop();

    std::cout << "Stack empty: " << stk.isEmpty() << std::endl;

    return 0;
}