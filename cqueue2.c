#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int cqueue[MAX];
int front = -1;
int rear = -1;
void insert(int item) 
{
if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) { 
        front = 0;
        rear = 0;
    } else {
        if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
    }
    cqueue[rear] = item;
}

void del() {
    
    if (front == -1) {
        printf("Queue underflow\n");
        return;
    }
    printf("The element deleted from queue is: %d\n", cqueue[front]);
    if (front == rear) { 
        front = -1;
        rear = -1;
    } else {
        if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("The elements in the queue are: ");
    int front_pos = front;
    int rear_pos = rear;

    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            printf("%d ", cqueue[front_pos]);
            front_pos++;
        }
    } else {
        while (front_pos < MAX) {
            printf("%d ", cqueue[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            printf("%d ", cqueue[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\nCircular Queue Menu:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
