#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 5 // Altering this value changes size of stack created
int st[MAX], top = -1;

void push(int val);
int pop();
void palindrome();
void display();

void main()
{
    int val, option;
    clrscr();
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. CHECK PALINDROME");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("\n The value deleted from stack is: %d", val);
            break;

        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        }
    } while (option != 5);
    getch();
    return;
}

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int pop()
{
    int val;
    if (top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n %d", st[i]);
        printf("\n"); // Added for formatting purposes
    }
}

void palindrome()
{
    int num, org, b[10], rev = 0, i = 0, j;
    printf("\nEmptying Stack...");
    while (top != -1)
        printf("\n%d deleted from stack", pop());
    printf("\nEnter the number to check for palindrome:");
    scanf("%d", &num);
    org = num;
    while (num > 0)
    {
        b[i++] = num % 10;
        num = num / 10;
    }
    for (j = i - 1; j >= 0; j--)
        push(b[j]);
    while (top != -1)
    {
        rev = rev * 10 + pop();
    }
    if (org == rev)
        printf("\n%d is palindrome", org);
    else
        printf("\n%d is not palindrome", org);
    return;
}