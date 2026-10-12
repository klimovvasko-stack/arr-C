#include <stdio.h>
#include <stdlib.h>


int main() {
    int rows;  
    int num;
    int row_s, col_s;
    puts("Enter the size of arr:");
    scanf_s("%d", &rows);

    int** a = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        a[i] = (int*)malloc(rows * sizeof(int));
    }
    puts("Enter the numbers:");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            scanf_s("%d", &num);
            a[i][j] = num;
            }
    }
    puts("Your arr:");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            printf("%d ", a[i][j]);
            }
        printf("\n");
    }

    puts("What row and colom you want to switch:");
    scanf_s("%d %d", &row_s, &col_s);

    if (row_s < 1 || row_s > rows || col_s < 1 || col_s > rows) {
        puts("Invalid row or column number!");
    } else {
        int r = row_s - 1;
        int c = col_s - 1;

        int* temp_row = (int*)malloc(rows * sizeof(int));
        int* temp_col = (int*)malloc(rows * sizeof(int));

        for (int i = 0; i < rows; i++) {
            temp_row[i] = a[r][i];
            temp_col[i] = a[i][c];
        }

        for (int i = 0; i < rows; i++) {
            a[r][i] = temp_col[i];
        }
        for (int i = 0; i < rows; i++) {
            a[i][c] = temp_row[i];
        }

        free(temp_row);
        free(temp_col);
    }

    puts("Your arr:");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < rows; j++){
            printf("%d ", a[i][j]);
            }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}