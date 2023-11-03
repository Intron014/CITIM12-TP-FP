#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 5
#define N 5

void randomFiller(char[M][N]);
void printMatriz(char[M][N]);
void moveOuterRingOnePositionClockwise(char[M][N]);
void moveOuterRingOnePositionCounterClockwise(char[M][N]);

int main() {
    srand(time(NULL));
    char matrix[M][N];
    randomFiller(matrix);
    printMatriz(matrix);
    moveOuterRingOnePositionCounterClockwise(matrix);
    printMatriz(matrix);
    moveOuterRingOnePositionClockwise(matrix);
    printMatriz(matrix);
}

void randomFiller(char matrix[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            matrix[i][j] = rand() % 2;
    }
}
void printMatriz(char matrix[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
void moveOuterRingOnePositionClockwise(char matrix[M][N]) {
    int i, j;
    char temp;
    for (i = 0; i < N / 2; i++) {
        temp = matrix[i][i];
        for (j = i + 1; j < N - i; j++)
            matrix[i][j - 1] = matrix[i][j];
        for (j = i + 1; j < M - i; j++)
            matrix[j - 1][N - i - 1] = matrix[j][N - i - 1];
        for (j = N - i - 1 - 1; j >= i; j--)
            matrix[M - i - 1][j + 1] = matrix[M - i - 1][j];
        for (j = M - i - 1 - 1; j >= i + 1; j--)
            matrix[j + 1][i] = matrix[j][i];
        matrix[i + 1][i] = temp;
    }
}
void moveOuterRingOnePositionCounterClockwise(char matrix[M][N]){
    int i, j;
    char temp;
    for (i = 0; i < N / 2; i++) {
        temp = matrix[i][i];
        for (j = i + 1; j < M - i; j++)
            matrix[j - 1][i] = matrix[j][i];
        for (j = i + 1; j < N - i; j++)
            matrix[M - i - 1][j - 1] = matrix[M - i - 1][j];
        for (j = M - i - 1 - 1; j >= i; j--)
            matrix[j + 1][N - i - 1] = matrix[j][N - i - 1];
        for (j = N - i - 1 - 1; j >= i + 1; j--)
            matrix[i][j + 1] = matrix[i][j];
        matrix[i][i + 1] = temp;
    }
}
