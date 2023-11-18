#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100

int rand_dig ();
void rand_DNI (char [10]);
void rand_DNIs (char [N][10]);
void print_DNIs (char [N][10]);

void strings_swap(char [9+1], char [9+1]);
void strings_bubbleSort(char [N][9+1]);

int main() {
    srand(time(NULL));
    char DNIs[N][10];
    rand_DNIs(DNIs);
    printf("DNIs Generados\n");
    print_DNIs(DNIs);
    strings_bubbleSort(DNIs);
    printf("DNIs Ordenados (Con Bubble Sort, ineficiente pero didactico)\n");
    print_DNIs(DNIs);
    return 0;
}

void strings_swap(char a[9+1], char b[9+1]){
    char temp[9+1];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}
void strings_bubbleSort(char dniArray[N][10]){
    int i, j;
    for (i = 0; i < N-1; i++)
        for (j = 0; j < N-i-1; j++)
            if(memcmp(dniArray[j], dniArray[j+1], 9) > 0)
                strings_swap(dniArray[j], dniArray[j+1]);
}

char letra_calculada (unsigned dni){
    dni %= 23;
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    return letter[dni];
}
void print_DNIs (char dnises[N][10]){
    for(int i=0 ; i<N ; i++){
        printf("%s\t\t\t", dnises[i]);
    }
    printf("\n");
}
void rand_DNIs(char dnis[N][10]){
    for(int i=0 ; i<N ; i++){
        rand_DNI(dnis[i]);
    }
}

int rand_dig()
{
    return rand()%(57-48)+48;
}

void rand_DNI (char dni[10]){
    int i, j;
    char dgt;
    int dniValue = 0;

    for (i = 0, j = 10000000; i < 8; i++) {
        do {
            dgt = rand_dig();
        } while (dgt < 48 || dgt > 57);

        dni[i] = dgt;
        dniValue += j * (dgt - '0');
        j /= 10;
    }

    dni[8] = letra_calculada(dniValue);
    dni[9] = '\0';
}
