#include <stdio.h>
#include <string.h>

int stck(char symb) {
    switch (symb) {
        case '+':
        case '-': return 2;
        case '*':
        case '/':
        case '%': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
    }
}

int expr(char symb) {
    switch (symb) {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^': return 6;
        case '(': return 7;
        case ')': return 0;
    }
}

void inf_post(char infix[], char posfix[]) {
    int i, top, j;
    char s[20], symb;
    top = -1;
    j = 0;
    s[++top] = '#';
    for (i = 0; i < strlen(infix); i++) {
        symb = infix[i];
        switch (symb) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case '%':
            case ')':
            case '^':
                while (stck(s[top]) > expr(symb)) {
                    posfix[j] = s[top--];
                    j++;
                }
                if (stck(s[top]) != expr(symb))
                    s[++top] = symb;
                else
                    top--;
                break;
            default:
                posfix[j] = symb;
                j++;
        }
    }
    while (s[top] != '#')
        posfix[j++] = s[top--];
    posfix[j] = '\0';
    return;
}

void main() {
    char infix[20], postfix[20];
    printf("Enter the valid infix expression:\n");
    scanf("%s", infix);
    inf_post(infix, postfix);
    printf("The postfix expression is:\n");
    printf("%s\n", postfix);
    return;
}
