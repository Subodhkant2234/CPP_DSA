#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear)
        front = rear = -1;  // Queue becomes empty
    else
        front = (front + 1) % MAX;

    return value;
}

int peek() {
    if (front == -1) {
        printf("Queue empty\n");
        return -1;
    }
    return queue[front];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front element = %d\n", peek());
    printf("Dequeued = %d\n", dequeue());
    printf("New front = %d\n", peek());

    return 0;
}
