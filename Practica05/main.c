#include <stdio.h>
#include <time.h>  // time()
#include <stdlib.h> // srand(), rand()
#define N 100

unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );

void rand_dig (char *);
void rand_DNI (unsigned *);
void rand_DNIs (unsigned [N], char [N]);
void print_DNIs (unsigned [N], char [N]);
void calcular_frecuencias (char [N], unsigned [26], float [26]);
void print_frecuencias (unsigned [26], float [26]);
void print_barra (float);

int main() {
    srand(time(NULL));
    float frecuencias[26];
    unsigned causality[26] = {0};
    unsigned dninums[N];
    char dnilets[N];
    rand_DNIs(dninums, dnilets);
    calcular_frecuencias(dnilets, causality, frecuencias);
    print_DNIs(dninums, dnilets);
    print_frecuencias(causality, frecuencias);
}
void calcular_frecuencias (char dnilets[N], unsigned causality[26], float frecs[26]){
    char cletter;
    for(int i=0 ; i<N ; i++){
        cletter = dnilets[i];
        causality[cletter-'A']++;
    }
    for(int i=0 ; i<26 ; i++){
        frecs[i] = (float)causality[i]/N;
    }
}
void print_frecuencias(unsigned causality[26], float frecs[26]){
    printf("> Frecuencias\n");
    for(int i=0 ; i<26; i++){
        printf("%c\t%u\t%f\t", 'A'+i, causality[i], frecs[i]);
        print_barra(frecs[i]);
        printf("\n");
    }
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
unsigned resto_DNI(unsigned dni){
    return dni%23;
}
char letra_calculada (unsigned dni){
    dni = resto_DNI(dni);
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    return letter[dni];
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
void print_barra (float stars){
    stars*=100;
    for(int i=0; i<stars; i++){
        printf("*");
    }
}