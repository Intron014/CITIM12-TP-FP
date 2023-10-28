#include <stdio.h>
#include <stdlib.h>

void scan_dig(char * , unsigned );
void scan_DNI(unsigned *);
unsigned resto_DNI(unsigned );
void scan_letra(char *);
char letra_calculada(unsigned );
void validar_letra_DNI(unsigned, char);

int main() {
    int *ans;
    unsigned *dni;
    char *letter, *letteruser;
    ans = (int *)malloc(sizeof(int));
    dni = (unsigned *)malloc(sizeof(unsigned));
    letter = (char *)malloc(sizeof(char));
    letteruser = (char *)malloc(sizeof(char));
    do {
        printf("\n1 - Calculo de letra\n2 - Check letra\n> ");
        scanf(" %i", ans);
        if (*ans == 1) {
            scan_DNI(dni);
            *letter = letra_calculada(*dni);
            printf("> DNI: %i\n> restoDNI: %i\n> %i%c", *dni, *dni % 23, *dni, *letter);
        } else {
            scan_DNI(dni);
            scan_letra(letteruser);
            validar_letra_DNI(*dni, *letteruser);
        }
        printf("\n\nDesea continuar? (1/0): ");
        scanf(" %i", ans);
    } while (*ans);
    free(ans);
    printf("ans cleared (1/4)\n");
    free(dni);
    printf("dni cleared (2/4)\n");
    free(letter);
    printf("letter cleared (3/4)\n");
    free(letteruser);
    printf("letteruser cleared (4/4)\n");
    printf("all variables cleared, have a nice day\n");
}

void scan_dig (char *number, unsigned pos){
    printf("Intoduzca la posicion %i del dni: ", pos);
    scanf(" %c", number);
}

void scan_DNI(unsigned *dni){
    *dni = 0;
    int i, j, comp;
    char dgt;
    for (i = 1, j = 10000000; i < 9; i++) {
        do {
            scan_dig(&dgt, i);
            comp = (dgt - '0');
        } while (comp < 0 || comp > 9);
        *dni += j * comp;
        j /= 10;
    }
}

unsigned resto_DNI(unsigned dni){
    return dni%23;
}

void scan_letra (char *letteruser){
    printf("Introduzca su letra a verificar: ");
    scanf(" %c", letteruser);
    if(*letteruser > 'a' && *letteruser < 'z'){
        *letteruser -= 'a';
        *letteruser += 'A';
    }
}

char letra_calculada (unsigned dni){
    dni = resto_DNI(dni);
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    return letter[dni];
}

void validar_letra_DNI(unsigned dni, char letteruser){
    char letter = letra_calculada(dni);
    if(letteruser == letter){
        printf("Letra %c = %c", letter, letteruser);
    } else {
        printf("Letra %c != %c", letter, letteruser);
    }
}

