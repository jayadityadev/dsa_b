#include <stdio.h>
#include <stdlib.h>

#define max 5

int front = -1, rear = -1, count = 0;
char cirq[max], ch;

void insert() {
    if (count == max) {
        printf("\nCIRCULAR QUEUE OVERFLOW\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("\nEnter the Character to be inserted::");
        getchar();
        scanf(" %c", &ch);
        rear = (rear + 1) % max; // when rear=4 and we need to insert an element at 0th position, incrementing rear by 1 will become 5 and cirq[5] doesn’t exist element needs to be inserted at cirq[0]. Hence we do rear=(rear+1) %5
        cirq[rear] = ch;
        count++;
    }
}

void delete() {
    if (count == 0) {
        printf("\nUNDERFLOW\n");
    } else {
        ch = cirq[front];
        front = (front + 1) % max; // when front=4 and we need to delete an element, incrementing front by 1 will become 5 and cirq[5] doesn’t exist. Instead Front has to point at cirq[0]. Hence we do front=(front+1) %5
        count--;
        printf("\nThe deleted element is: %c", ch);
    }
}

void display() {
    int i, j;
    if (count == 0) {
        printf("CIRCULAR QUEUE IS EMPTY\n");
    } else {
        printf("\nContents of the circular queue are:\n");
        j = front;
        for (i = 0; i < count; i++) {
            printf("%c \t", cirq[j]);
            j = (j + 1) % max;
        }
    }
}

void main() {
    int choice;
    do {
        printf(" \n IMPLEMENTATION OF CIRCULAR QUEUE\n");
        printf("\n MENU\n");
        printf("\n1.INSERT\n 2.DELETE\n 3.DISPLAY\n 4.EXIT\n\n");
        printf("\nEnter Your Choice::");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice");
        }
    } while (choice != 4);
}
