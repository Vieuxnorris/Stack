#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *s;
};

void Create(struct Stack *stk)
{
    printf("entrer la taille de votre stack : ");
    scanf("%d", &stk->size);
    stk->top = -1;
    stk->s = (int *)malloc(stk->size * sizeof(int));
}

void Diplay(struct Stack stk)
{
    int i;
    for(i=stk.top;i>=0;i--)
        printf("%d ", stk.s[i]);
    printf("\n");
}

void push(struct Stack *stk, int x)
{
    if (stk->top == stk->size-1)
        printf("Stack overflow\n");
    else
    {
        stk->top++;
        stk->s[stk->top] = x;
    }
}

int pop(struct Stack *stk)
{
    int x=-1;

    if(stk->top == -1)
        printf("Stack Underflow\n");
    else
        x = stk->s[stk->top--];
    return x;
}

int peek(struct Stack stk, int index)
{
    int x = -1;
    if (stk.top-index+1 < 0)
        printf("Invalid Index \n");
    x = stk.s[stk.top-index+1];
    return x;
}

int isEmpty(struct Stack stk)
{
    if (stk.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack stk)
{
    return stk.top == stk.size-1;
}

int stackTop(struct Stack stk)
{
    if(!isEmpty(stk))
        return stk.s[stk.top];
    return -1;
}

int main()
{
    struct Stack stk;
    Create(&stk);

    push(&stk, 10);
    push(&stk, 20);
    push(&stk, 30);
    push(&stk, 40);
    printf("%d \n", peek(stk, 2));

    Diplay(stk);

    return 0;
}