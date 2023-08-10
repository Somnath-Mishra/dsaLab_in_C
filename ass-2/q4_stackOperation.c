#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int data;
} node;

typedef struct stack {
    struct node *top;
} stack;

void push(stack *s, int x) {
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
}

int pop(stack *s, int *x) {
    if (s->top == NULL) {
        return 0;
    }
    *x = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return 1;
}

int top(stack *s) {
    if (s->top == NULL) {
        return 0;
    }
    return s->top->data;
}

int main() {
    stack s;
    s.top = NULL; // Initialize the stack's top pointer to NULL

    push(&s, 3);
    push(&s, 2);
    push(&s, 34);
    push(&s, 1);

    int popped_value;
    if (pop(&s, &popped_value)) {
        printf("Popped value: %d\n", popped_value);
    }
    if (pop(&s, &popped_value)) {
        printf("Popped value: %d\n", popped_value);
    }
    else {
        printf("Stack is empty.\n");
    }

    return 0;
}