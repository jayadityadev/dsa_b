#include <stdio.h>
#include <string.h>
#include <math.h>

float stack[20];
int top = -1;

void push(float);
float pop();
float evalpost(char[]);
void move(int, char, char, char);

void main() {
    int ch, n;
    char postfix[20];
    float res;

    do {
        printf("\n************MENU************\n");
        printf("1. Evaluation of suffix expression\n");
        printf("2. Tower of Hanoi problem\n");
        printf("3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the postfix expression using digits for operands:\n");
                scanf("%s", postfix);
                res = evalpost(postfix);
                printf("Result of %s = %f\n", postfix, res);
                break;
            case 2:
                printf("Enter the number of rings: ");
                scanf("%d", &n);
                move(n, 'A', 'B', 'C');
                break;
        }
    } while (ch != 3);

    return;
}

float evalpost(char postfix[]) {
    int op1, op2;
    float res;
    char ch;
    int i = 0;

    while (postfix[i] != '\0') {
        ch = postfix[i];
        if (isdigit(ch))
            push(ch - '0');
        else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+':
                    push(op1 + op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
            }
        }
        i++;
    }
    res = pop();
    return res;
}

void push(float num) {
    top = top + 1;
    stack[top] = num;
}

float pop() {
    float num;
    num = stack[top];
    top = top - 1;
    return num;
}

void move(int n, char source, char spare, char dest) {
    if (n == 1)
        printf("\nMove from %c to %c", source, dest);
    else {
        move(n - 1, source, dest, spare);
        move(1, source, spare, dest);
        move(n - 1, spare, source, dest);
    }
}