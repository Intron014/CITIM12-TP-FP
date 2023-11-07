#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100

void print_strings_DNIs(char [N][9+1]);
void rand_strings_DNIs(char [N][9+1]);
void rand_str_DNI(char [9+1]);

void swap_unsigned(unsigned*, unsigned*);
void swap_char(char*, char*);
void bubbleSort(unsigned [N], char [N]);

int main() {
    printf("Initializing...\n");
    srand(time(NULL));
    char dnises[N][9+1];
    rand_strings_DNIs(dnises);
    return 0;
}


void print_strings_DNIs(char le_dnis[N][9+1]){
    for (int i = 0 ; i<N ; i++)
        printf("%s\t", le_dnis[i]);
}
void rand_str_DNI(char dni[9+1]){
    int dig;
    int pos;
    int dni_num;
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    for(pos = 0 ; pos < 8 ; pos++){
        dig = rand()%10;
        dig+='0';
        dni[pos]=(char)dig;
    }
    dni_num=strtoul(dni, NULL, 10);
    dni_num%=23;
    dni[pos] = letter[dni_num];
    dni[pos+1] = '\0';

}
void rand_strings_DNIs(char dnises[N][9+1]){
    for(int pos = 0 ; pos < N ; pos++)
        rand_str_DNI(dnises[pos]);
    print_strings_DNIs(dnises);
}
