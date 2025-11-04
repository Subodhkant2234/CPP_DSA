#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;   // index for next write
    int tail;   // index for next read
    int count;  // number of elements currently in buffer
} CircularBuffer;

/* Initialize the circular buffer */
void cb_init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

/* Check if buffer is full */
bool cb_is_full(CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

/* Check if buffer is empty */
bool cb_is_empty(CircularBuffer *cb) {
    return cb->count == 0;
}

/* Add element to buffer */
bool cb_enqueue(CircularBuffer *cb, int data) {
    if (cb_is_full(cb)) {
        printf("Buffer full! Cannot enqueue %d\n", data);
        return false;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    return true;
}

/* Remove element from buffer */
bool cb_dequeue(CircularBuffer *cb, int *data) {
    if (cb_is_empty(cb)) {
        printf("Buffer empty! Cannot dequeue\n");
        return false;
    }

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return true;
}

/* Print buffer contents (for debugging) */
void cb_print(CircularBuffer *cb) {
    printf("Buffer: ");
    for (int i = 0; i < cb->count; i++) {
        int index = (cb->tail + i) % BUFFER_SIZE;
        printf("%d ", cb->buffer[index]);
    }
    printf("\n");
}

/* Example usage */
int main() {
    CircularBuffer cb;
    cb_init(&cb);

    cb_enqueue(&cb, 10);
    cb_enqueue(&cb, 20);
    cb_enqueue(&cb, 30);
    cb_print(&cb);

    int val;
    cb_dequeue(&cb, &val);
    printf("Dequeued: %d\n", val);

    cb_enqueue(&cb, 40);
    cb_enqueue(&cb, 50);
    cb_enqueue(&cb, 60); // should fail (full)
    cb_print(&cb);

    return 0;
}
