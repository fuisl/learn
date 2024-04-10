#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* Queue;

Queue createQueue() {
    return NULL;
}

int isEmpty(Queue q) {
    return q == NULL;
}

void insert(Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*q == NULL) {
        *q = newNode;
    } else {
        struct Node* temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int removeData(Queue* q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node* temp = *q;
    *q = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

int peek(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->data;
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();
    insert(&q, 10);
    insert(&q, 20);
    insert(&q, 30);
    insert(&q, 40);
    insert(&q, 50);

    display(q);

    printf("Peek: %d\n", peek(q));

    printf("Removed: %d\n", removeData(&q));
    printf("Removed: %d\n", removeData(&q));

    display(q);

    printf("Peek: %d\n", peek(q));

    return 0;
}