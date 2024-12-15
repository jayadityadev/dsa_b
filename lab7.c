#include <stdio.h>
#include <stdlib.h>

struct node {
    char usn[12], name[20], branch[10], phno[15];
    int sem;
    struct node *link;
};

typedef struct node* NODE;
NODE start = NULL, start1 = NULL;

NODE create_node() {
    NODE ptr;
    ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nINSUFFICIENT MEMORY\n");
        exit(0);
    }
    printf("\n\nEnter student data such as USN, NAME, BRANCH, PHNO, SEM\n\n");
    scanf("%s%s%s%s%d", ptr->usn, ptr->name, ptr->branch, ptr->phno, &ptr->sem);
    ptr->link = NULL;
    return ptr;
}

NODE insert_front(NODE start) {
    NODE ptr;
    ptr = create_node();
    if (start == NULL)
        start = ptr;
    else {
        ptr->link = start;
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
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = ptr;
    }
    return start;
}

NODE delete_front(NODE start) {
    NODE temp;
    if (start == NULL)
        printf("\n\nLIST EMPTY\n\n");
    else {
        temp = start;
        start = start->link;
        printf("\n\nDeleted node is\n");
        printf("|%s|%s|%s|%s|%d|\n\n", temp->usn, temp->name, temp->branch, temp->phno, temp->sem);
        free(temp);
    }
    return start;
}

NODE delete_end(NODE start) {
    NODE p, temp;
    if (start == NULL) {
        printf("\n\nLIST EMPTY\n\n");
        return start;
    }
    temp = start;
    if (temp->link == NULL) {
        start = NULL;
    } else {
        temp = start;
        while (temp->link != NULL) {
            p = temp;
            temp = temp->link;
        }
        p->link = NULL;
    }
    printf("\n\nDeleted node is\n");
    printf("\n\n |%s|%s|%s|%s|%d|", temp->usn, temp->name, temp->branch, temp->phno, temp->sem);
    free(temp);
    return start;
}

void display(NODE start) {
    NODE temp;
    if (start == NULL)
        printf("\n\nLIST EMPTY\n\n");
    else {
        int count = 0;
        temp = start;
        printf("\n\nSINGLY LINKED LIST IS: \n\n");
        while (temp != NULL) {
            printf("|%s|%s|%s|%s|%d|->", temp->usn, temp->name, temp->branch, temp->phno, temp->sem);
            temp = temp->link;
            count++;
        }
        printf("\n\nNUMBER OF NODE IN LIST::%d\n\n", count);
    }
}

NODE list_stack(NODE start1) {
    int choice;
    printf("\n\n OPERATIONS ON STACK\n\n");
    do {
        printf("\n\nLIST AS STACK\n\n");
        printf("\n1: PUSH\n2: POP\n3: DISPLAY\n4: EXIT\n");
        printf("\nEnter choice::\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start1 = insert_front(start1);
                break;
            case 2:
                start1 = delete_front(start1);
                break;
            case 3:
                display(start1);
                break;
            default:
                if (choice != 4)
                    printf("Enter valid choice:");
        }
    } while (choice != 4);
    return start1;
}

void main() {
    int ch, n, i;
    do {
        printf("\nSINGLY LINKED LIST OPERATIONS\n");
        printf("\nMENU\n");
        printf("\n\n1: List creation using Insert front\n2: Display and count\n3: Insert at end\n4: Delete at end\n5: List as Stack\n6: EXIT\n");
        printf("Enter choice::");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\n\nEnter how many student information you want enter::");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("\n\nEnter information of student %d\n\n", i);
                    start = insert_front(start);
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
                start1 = list_stack(start1);
                break;
            default:
                if (ch != 6)
                    printf("Enter correct choice:");
        }
    } while (ch != 6);
}
