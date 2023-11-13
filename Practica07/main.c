#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100


void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);

void swap_unsigned(unsigned*, unsigned*);
void swap_char(char*, char*);
void bubbleSort(unsigned [N], char [N]);

int main() {
    printf("Initializing...\n");
    srand(time(NULL));
    unsigned dninums[N];
    char dnilets[N];
    rand_DNIs(dninums, dnilets);
    print_DNIs(dninums, dnilets);
    bubbleSort(dninums, dnilets);
    print_DNIs(dninums, dnilets);
    return 0;
}

void bubbleSort(unsigned DNIs[N], char letter[N]){
    int i, j;
    for (i = 0; i < N-1; i++)
        for (j = 0; j < N-i-1; j++)
            if (DNIs[j] > DNIs[j+1]){
                swap_unsigned(&DNIs[j], &DNIs[j+1]);
                swap_char(&letter[j], &letter[j+1]);
            }
}

void swap_unsigned(unsigned *a, unsigned *b){
    unsigned temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char letra_calculada (unsigned dni){
    dni %= 23;
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    return letter[dni];
}
void print_DNIs (unsigned dninums[N], char dnilets[N]){
    printf("> DNIs Generados\n");
    for(int i=0 ; i<N ; i++){
        printf("%u - %c\t\t", dninums[i], dnilets[i]);
    }
    printf("\n");
}
void rand_DNIs(unsigned dninums [N], char dnilets[N]){
    for(int i=0 ; i<N ; i++){
        rand_DNI(&dninums[i]);
        dnilets[i] = letra_calculada(dninums[i]);
    }
}

void rand_dig(char *num)
{
    *num = rand()%10;
}

void rand_DNI (unsigned *dni){
    *dni = 0;
    int i, j;
    char dgt;
    for (i = 1, j = 10000000; i < 9; i++) {
        do {
            rand_dig(&dgt);
            if(i == 1 && dgt == 0){
                do{
                    rand_dig(&dgt);
                } while (dgt < 1 || dgt > 9);
            }
        } while (dgt < 0 || dgt > 9);
        *dni += j * dgt;
        j /= 10;
    }
}