#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 4
#define N 4

void randomFiller(int[M][N]);
void printMatriz(int[M][N], int);
void moveOuterRingOnePositionClockwise(int[M][N], int);
void moveOuterRingOnePositionCounterClockwise(int[M][N], int);

int main() {
    srand(time(NULL));
    int matrix[M][N];
    int debug = 1;
    randomFiller(matrix);
    moveOuterRingOnePositionClockwise(matrix, debug);
    moveOuterRingOnePositionCounterClockwise(matrix, debug);
}

void randomFiller(int matrix[M][N]) {
    int c = 'A';
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            matrix[i][j] = c + (rand() % 23);
    }
    printMatriz(matrix, 0);
}
void printMatriz(int matrix[M][N], int caseNumber) {
    switch (caseNumber) {
        case 0: printf("Initial Matrix:\n"); break;
        case 2: printf("Matrix after CounterClockwise:\n"); break;
        case 3: printf("Matrix after Clockwise:\n"); break;
        default: break;
    }
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
void moveOuterRingOnePositionCounterClockwise(int matrix[M][N], int debug) {
    int i, j;
    int temp;
    if(debug){printf("CounterClockwise Debug: \n");}
    for (i = 0; i < N / 2; i++) {
        temp = matrix[i][i];
        if(debug){printf("temp: %c\n", temp);}
        for (j = i + 1; j < N - i; j++) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", i, j - 1, i, j);}
            matrix[i][j - 1] = matrix[i][j];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = i + 1; j < M - i; j++) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", j - 1, N - i - 1, j, N - i - 1);}
            matrix[j - 1][N - i - 1] = matrix[j][N - i - 1];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = N - i - 1 - 1; j >= i; j--) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", M - i - 1, j + 1, M - i - 1, j);}
            matrix[M - i - 1][j + 1] = matrix[M - i - 1][j];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = M - i - 1 - 1; j >= i + 1; j--) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", j + 1, i, j, i);}
            matrix[j + 1][i] = matrix[j][i];
            if(debug){printMatriz(matrix, 1);}
        }
        matrix[i + 1][i] = temp;
    }
    printMatriz(matrix, 2);
}
void moveOuterRingOnePositionClockwise(int matrix[M][N], int debug){
    int i, j;
    int temp;
    if(debug){printf("Clockwise Debug\n");}
    for (i = 0; i < N / 2; i++) {
        temp = matrix[i][i];
        if(debug){printf("temp: %c\n", temp);}
        for (j = i + 1; j < M - i; j++) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", j - 1, i, j, i);}
            matrix[j - 1][i] = matrix[j][i];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = i + 1; j < N - i; j++) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", M - i - 1, j - 1, M - i - 1, j);}
            matrix[M - i - 1][j - 1] = matrix[M - i - 1][j];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = M - i - 1 - 1; j >= i; j--) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", j + 1, N - i - 1, j, N - i - 1);}
            matrix[j + 1][N - i - 1] = matrix[j][N - i - 1];
            if(debug){printMatriz(matrix, 1);}
        }
        for (j = N - i - 1 - 1; j >= i + 1; j--) {
            if(debug){printf("i: %d - j: %d\n", i, j);}
            if(debug){printf("matrix[%d][%d] = matrix[%d][%d]\n", i, j + 1, i, j);}
            matrix[i][j + 1] = matrix[i][j];
            if(debug){printMatriz(matrix, 1);}
        }
        matrix[i][i + 1] = temp;
    }
    printMatriz(matrix, 3);
}
