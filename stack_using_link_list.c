#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t==NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int peek(int Index)
{
    if (top == NULL)
        return -1;
    else
    {
        struct Node *t = top;

        for (int i=0; t != NULL && i < Index-1; i++)
            t = t->next;

        if (t != NULL)
            return t->data;
        else
            return -1;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;
    
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    printf("%d ", pop());
    return 0;
}