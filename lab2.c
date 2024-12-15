#include <stdio.h>
#include <stdlib.h>

void read(char str[], char pat[], char rep_pat[]);
void replace(char str[], char pat[], char rep_pat[], char new_str[]);

int main() {
    char str[100], pat[20], rep_pat[20], new_str[100];
    read(str, pat, rep_pat);
    replace(str, pat, rep_pat, new_str);
    return 0;
} /* end of main */

void read(char str[], char pat[], char rep_pat[]) {
    printf("Enter the String\n");
    scanf("%s", str);
    printf("Enter the pattern to be searched\n");
    scanf("%s", pat);
    printf("Enter the replacing String with %s\n", pat);
    scanf("%s", rep_pat);
} /* end of read */

void replace(char str[], char pat[], char rep_pat[], char new_str[]) {
    int i = 0, j = 0, k, rep_ind, flag = 0, mflag = 0, n = 0;
    while (str[i] != '\0') {
        j = 0;
        k = i;
        rep_ind = 0;
        while ((str[k] == pat[j]) && (pat[j] != '\0')) {
            k++;
            j++;
        } /* end of inner while */
        if (pat[j] == '\0') {
            flag = 1;
            mflag = 1;
            while (rep_pat[rep_ind] != '\0') {
                new_str[n++] = rep_pat[rep_ind++];
            } /* end of while */
        } /* end of if */
        else {
            flag = 0;
        } /* end of else */
        if (flag == 1) {
            i = k;
        } /* end of if */
        else {
            new_str[n++] = str[i++];
        } /* end of else */
    } /* end of outer while */
    if (mflag != 1) {
        printf("Pattern Not found\n");
        exit(0);
    } /* end of if */
    new_str[n] = '\0';
    printf("The new string is:\n");
    printf("%s\n", new_str);
} /* end of replace */
