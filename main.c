
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};
void enqueue(struct CircularQueue *q, int value);
int dequeue(struct CircularQueue *q);
void display(struct CircularQueue q);
int isEmpty(struct CircularQueue q);
int isFull(struct CircularQueue q);
int main() {
    struct CircularQueue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;
    do {
        printf("\n\n------ Circular Queue Menu ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull(q)) {
                    printf("Queue is full. Cannot enqueue.\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    printf("%d enqueued successfully.\n", value);
                }
                break;
            case 2:
                if (isEmpty(q)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    value = dequeue(&q);
                    printf("%d dequeued.\n", value);
                }
                break;
            case 3:
                if (isEmpty(q)) {
                    printf("Queue is empty.\n");
                } else {
                    display(q);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);
    return 0;
}
void enqueue(struct CircularQueue *q, int value) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->items[q->rear] = value;
    }
}
int dequeue(struct CircularQueue *q) {
    int item;
    if (q->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;  // Queue becomes empty after this
        } else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        return item;
    }
}
void display(struct CircularQueue q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements:\n");
    // Case 1: If front is less than or equal to rear, display elements in order
    if (q.front <= q.rear) {
        for (i = q.front; i <= q.rear; i++) {
            printf("[%d]: %d\n", i, q.items[i]);
        }
    }
    // Case 2: If rear has wrapped around, display in two parts
    else {
        // First part: from front to MAX_SIZE - 1
        for (i = q.front; i < MAX_SIZE; i++) {
            printf("[%d]: %d\n", i, q.items[i]);
        }
        // Second part: from 0 to rear
        for (i = 0; i <= q.rear; i++) {
            printf("[%d]: %d\n", i, q.items[i]);
        }
    }
}
int isEmpty(struct CircularQueue q) {
    return (q.front == -1);
}
int isFull(struct CircularQueue q) {
    return ((q.rear + 1) % MAX_SIZE == q.front);
}
















