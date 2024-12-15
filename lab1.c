#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

struct calender {
    char week[12];
    struct date d;
    char activity[20];
};

typedef struct calender* cal;
cal mycal;

void create(), read(), display();

void main() {
    create();
    read();
    display();
} /*end of main*/

void create() {
    mycal = (cal)malloc(sizeof(struct calender) * 7);
} /*end of create*/

void read() {
    int i;
    for (i = 0; i < 7; i++) {
        printf("Enter the week activity details::day %d", i + 1);
        printf("\nEnter day name::");
        scanf("%s", mycal[i].week);
        printf("\nEnter day date::");
        scanf("%d%d%d", &mycal[i].d.day, &mycal[i].d.month, &mycal[i].d.year);
        printf("\nEnter day activity::");
        scanf("%s", mycal[i].activity);
    } /*end of for*/
} /*end of read*/

void display() {
    int i;
    for (i = 0; i < 7; i++) {
        printf("\nWeek activity details::day %d\n", i + 1);
        printf("\nDay name:%s\t", mycal[i].week);
        printf("\n Day date:%d/%d/%d\t", mycal[i].d.day, mycal[i].d.month, mycal[i].d.year);
        printf("\n Day activity:%s\n", mycal[i].activity);
    } /*end of for*/
} /*end of display*/