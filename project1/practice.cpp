#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int array1[5][5];
    int array2[5][5];
    int array3[5][5];

    int i, j, k = 1, a = 1;


    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            array1[i][j] = k;
            k++;
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            array2[i][j] = 2 * a;
            a++;
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", array3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
