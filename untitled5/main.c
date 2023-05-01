#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void enqueue(Stack *stack, int item) {
    push(stack, item);
}

int dequeue(Stack *stack) {
    int i, item, last;
    Stack temp;
    temp.top = -1;
    for (i = 0; i <= stack->top; i++) {
        item = pop(stack);
        push(&temp, item);
    }
    last = pop(&temp);
    for (i = 0; i <= temp.top; i++) {
        item = pop(&temp);
        push(stack, item);
    }
    return last;
}

int main(void) {
    Stack queue;
    queue.top = -1;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued item: %d\n", dequeue(&queue));
    return 0;
}