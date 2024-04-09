#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node* Stack;

void push(Stack *top, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack *top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int main()
{
    int n = 5;

    Stack s = NULL;

    if (n == 0)
    {
        push(&s, 0);
    }

    while (n > 0)
    {
        push(&s, n % 2);
        n /= 2;
    }

    while (s != NULL)
    {
        printf("%d", pop(&s));
    }
    printf("\n");
    return 0;
}