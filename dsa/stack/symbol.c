#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};
typedef struct Node* Stack;

void push(Stack* top, char data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(Stack* top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}



int main()
{
    char* exp = "{}{{{[()]}}}";
    Stack s = NULL;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(&s, exp[i]);
        }
        if (exp[i] == '}')
        {
            if (pop(&s) != '{')
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
        if (exp[i] == ']')
        {
            if (pop(&s) != '[')
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
        if (exp[i] == ')')
        {
            if (pop(&s) != '(')
            {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }

    if (s != NULL)
    {
        printf("Not Balanced\n");
        return 0;
    }
    printf("Balanced\n");
    return 0;
}