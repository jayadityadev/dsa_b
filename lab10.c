#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST NODE;

NODE* createtree(NODE *node, int data) {
    if (node == NULL) { // if tree is empty
        NODE *temp;
        temp = (NODE*)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data) { // if data < root node data
        node->left = createtree(node->left, data);
    } else if (data > node->data) { // if data > root node data
        node->right = createtree(node->right, data);
    }
    return node;
}

NODE* search(NODE *node, int data) {
    if (node == NULL) {
        printf("\nElement not found");
    } else if (data < node->data) {
        node->left = search(node->left, data);
    } else if (data > node->data) {
        node->right = search(node->right, data);
    } else {
        printf("\nElement found is: %d", node->data);
    }
    return node;
}

void inorder(NODE *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node) {
    if (node != NULL) {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}

void main() {
    int data, ch, i, n;
    NODE *root = NULL;
    do {
        printf("\n1. Insertion in Binary Search Tree");
        printf("\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter N value: ");
                scanf("%d", &n);
                printf("\nEnter the values to create BST like (6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2)\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;
            case 2:
                printf("\nInorder Traversal: \n");
                inorder(root);
                break;
            case 3:
                printf("\nPreorder Traversal: \n");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder Traversal: \n");
                postorder(root);
                break;
            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                root = search(root, data);
                break;
            case 6:
                break;
            default:
                printf("\nWrong option");
                break;
        }
    } while (ch != 6); /* end of do-while */
}
