#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int *a;
    int rear, front;
} queue;

void initializeQueue(queue *q, int size) {
    q->a = (int *)malloc(size * sizeof(int));
    q->rear = -1;
    q->front = -1;
}

int enqueue(queue *q, int data, int size) {
    if (q->rear == size - 1)
        return 0;
    else {
        q->rear = q->rear + 1;
        q->a[q->rear] = data;
        return 1;
    }
}

int dequeue(queue *q, int *data) {
    if (q->rear == -1) {
        q->front = -1;
        *data = INT_MAX;
        return 0;
    } else {
        q->front = q->front + 1;
        *data = q->a[q->front];
        return 1;
    }
}

int numberOfElement(queue *q) {
    return (q->rear - q->front );
}

int isFull(queue *q, int size) {
    if (q->rear == size )
        return 1;
    else {
        return 0;
    }
}

int isEmpty(queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

int main() {
    int n, temp, k = 0, value, deletedEle, size;
    queue q;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &size);
    initializeQueue(&q, size);

    printf("Enter number of elements in queue: ");
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);
        if (!enqueue(&q, temp, size)) {
            printf("Enqueue not possible \n");
            return 1;
        }
    }

    printf("Enter a number to insert in queue: ");
    scanf("%d", &value);
    int success = enqueue(&q, value, size);
    if (success)
        printf("Enqueue is successfully done \n");
    else
        printf("Enqueue not possible \n");

    printf("Now delete a number from the queue \n");
    success = dequeue(&q, &deletedEle);
    if (success)
        printf("Deleted element is %d \n", deletedEle);
    else
        printf("Deletion is not possible due to an empty queue \n");

    printf("The number of elements in the queue is %d\n", numberOfElement(&q));

    printf("Is this queue full: ");
    success = isFull(&q, size);
    if (success)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Is the queue empty: ");
    success = isEmpty(&q);
    if (success)
        printf("Yes\n");
    else
        printf("No\n");

    free(q.a);
    return 0;
}
