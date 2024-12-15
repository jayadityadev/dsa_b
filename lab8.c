#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *llink;
    int ssn;
    char name[20], dept[20], desi[20], phno[12];
    float sal;
    struct node *rlink;
};

typedef struct node* NODE;
NODE start = NULL;

NODE create_node() {
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\n\nINSUFFICIENT MEMORY\n\n");
        exit(0);
    }
    printf("Enter employee data such as SSN, NAME, DEPARTMENT, DESIGNATION, PHONENO AND SALARY\n");
    scanf("%d%s%s%s%s%f", &ptr->ssn, ptr->name, ptr->dept, ptr->desi, ptr->phno, &ptr->sal);
    ptr->llink = NULL;
    ptr->rlink = NULL;
    return ptr;
}

NODE insert_front(NODE start) {
    NODE ptr;
    ptr = create_node();
    if (start == NULL)
        start = ptr;
    else {
        ptr->rlink = start;
        start->llink = ptr;
        start = ptr;
    }
    return start;
}

NODE insert_end(NODE start) {
    NODE ptr, temp;
    ptr = create_node();
    if (start == NULL)
        start = ptr;
    else {
        temp = start;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->rlink = ptr;
        ptr->llink = temp;
    }
    return start;
}

NODE delete_front(NODE start) {
    NODE temp;
    if (start == NULL) {
        printf("\n\nDoubly linked List is empty:\n\n");
        return start;
    } else {
        temp = start;
        start = start->rlink;
        if (start != NULL) {
            start->llink = NULL;
        }
        printf("\n\nDELETED FRONT NODE IS::\n\n");
        printf("\n\n|%d|%s|%s|%s|%s|%f|\n\n", temp->ssn, temp->name, temp->dept, temp->desi, temp->phno, temp->sal);
        free(temp);
    }
    return start;
}

NODE delete_end(NODE start) {
    NODE temp, p;
    if (start == NULL) {
        printf("\n\nDoubly linked List is empty:\n\n");
        return start;
    }
    temp = start;
    if (temp->rlink == NULL) {
        start = NULL;
    } else {
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        p = temp->llink;
        p->rlink = NULL;
    }
    printf("\n\nDELETED END NODE IS::\n\n");
    printf("|%d|%s|%s|%s|%s|%f|", temp->ssn, temp->name, temp->dept, temp->desi, temp->phno, temp->sal);
    free(temp);
    return start;
}

void display(NODE start) {
    NODE temp;
    int count = 0;
    if (start == NULL) {
        printf("\n\nDoubly linked List is empty:\n\n");
        return;
    }
    temp = start;
    printf("\n\nThe nodes of the doubly linked list are:\n\n");
    while (temp != NULL) {
        printf("<->|%d|%s|%s|%s|%s|%f|", temp->ssn, temp->name, temp->dept, temp->desi, temp->phno, temp->sal);
        temp = temp->rlink;
        count++;
    }
    printf("\n\nNumber of node in doubly link list are::%d", count);
}

void main() {
    int ch, n, i;
    do {
        printf("\n\nMENU\n\n");
        printf("\n1:CREATE DLL of N EMPLOYEE USING INSERT END\n2:DISPLAY and COUNT\n3:INSERT END\n4:DELETE END\n5:INSERT FRONT\n6:DELETE FRONT\n7:DLL AS EQUEUE\n8:EXIT\n\n");
        printf("\nEnter the choice:: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n\nEnter how many employee information you want to enter::");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("\n\nEnter information of employee %d\n", i);
                    start = insert_end(start);
                }
                break;
            case 2:
                display(start);
                break;
            case 3:
                start = insert_end(start);
                break;
            case 4:
                start = delete_end(start);
                break;
            case 5:
                start = insert_front(start);
                break;
            case 6:
                start = delete_front(start);
                break;
            case 7:
                printf("\n\nDEQUEUE INSERTION AND DELETION AT BOTH ENDS\n\n");
                printf("\n\nINSERTION AT FRONT OF DEQUEUE\n\n");
                start = insert_front(start);
                display(start);
                printf("\n\nINSERTION AT END OF DEQUEUE\n\n");
                start = insert_end(start);
                display(start);
                printf("\n\nDELETION AT FRONT OF DEQUEUE\n\n");
                start = delete_front(start);
                display(start);
                printf("\n\nDELETION AT END OF DEQUEUE\n\n");
                start = delete_end(start);
                display(start);
                break;
            default:
                exit(0);
        }
    } while (ch != 8);
}
