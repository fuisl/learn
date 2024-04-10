#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* Stack;

void push(Stack* top, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack* top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int main()
{
    char* exp = "425*+7*";
    Stack s = NULL;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            push(&s, exp[i] - '0');
        }
        else
        {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (exp[i])
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            default:
                printf("Invalid operator\n");
                break;
            }
        }
    }
    printf("Result: %d\n", pop(&s));
    return 0;
}
