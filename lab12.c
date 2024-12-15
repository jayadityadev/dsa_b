#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int empno, flag; // employee number is the key- K with 4 digits
    char name[10];
} emp[100];

int hash(int m) {
    int r;
    r = m % 100;
    return r;
}

void main() {
    int m, k, eno, loc, i, n, j;
    char name[10];
    FILE *in;

    printf("\nEnter no of records to read from file: ");
    scanf("%d", &n);
    in = fopen("input.txt", "r");

    if (n <= 10) {
        for (k = 0; k < 100; k++)
            emp[k].flag = 0;

        for (i = 0; i < n; i++) {
            fscanf(in, "%d%s", &eno, name);
            loc = hash(eno);

            if (emp[loc].flag == 0) {
                printf("\nRecord:%d is mapped to address:%d\n", i, loc);
                emp[loc].empno = eno;
                emp[loc].flag = 1;
                strcpy(emp[loc].name, name);
            } else {
                printf("\n\nCollision occurred for record %d resolved using linear probing\n\n", i);
                for (j = loc + 1; j < 100; j++) {
                    if (emp[j].flag == 0) {
                        printf("\nRecord:%d is at address:%d\n", i, j);
                        strcpy(emp[j].name, name);
                        emp[j].empno = eno;
                        emp[j].flag = 1;
                        break;
                    }
                }
                if (j >= 100) {
                    printf("HASH TABLE IS FULL\n");
                    printf("\n------------------------\n");
                }
            }
        }
        fclose(in);

        printf("\n\nThe Hash Table Content is: ");
        for (i = 0; i < 100; i++) {
            if (emp[i].flag == 1)
                printf("\n%d\t%d\t%s", i, emp[i].empno, emp[i].name);
            else
                printf("\n####");
        }
    } else {
        printf("\nFile is containing only 10 records\n\n");
    }
}
