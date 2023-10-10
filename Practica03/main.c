#include <stdio.h>

void scan_letra(char *);
void scan_dig(char * , unsigned );
void scan_DNI(unsigned *);
unsigned resto_DNI(unsigned );
char letra_calculada(unsigned );
void print_menu ();
void scan_opcion(char * );

int main() {
    char ans, letter, letteruser;
    unsigned dni;
    print_menu();
    scan_opcion(&ans);
    scan_DNI(&dni);
    letter=letra_calculada(dni);
    if(ans == '2'){
        scan_letra(&letteruser);
        if(letteruser == letter){
            printf("Letra %c = %c", letter, letteruser);
        } else {
            printf("Letra %c != %c", letter, letteruser);
        }
    } else {
        printf("> DNI: %i\n> restoDNI: %i\n> %i%c", dni, dni % 23, dni, letter);
    }
}

void scan_letra (char *letteruser){
    printf("Introduzca su letra a verificar: ");
    scanf(" %c", letteruser);
    if(*letteruser > 'a' && *letteruser < 'z'){
        *letteruser -= 'a';
        *letteruser += 'A';
    }
}

void scan_dig(char *smth, unsigned smthelse){ // ?!?
    printf("IDK");
}

void scan_DNI(unsigned *dni){
    *dni = 0;
    int i, j, comp;
    for (i = 1, j = 10000000; i < 9; i++) {
        do {
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %u", &comp);
        } while (comp < 0 || comp > 9);
        *dni += j * comp;
        j /= 10;
    }
}

unsigned resto_DNI(unsigned dni){
    return dni%23;
}

char letra_calculada(unsigned dni){
    dni = resto_DNI(dni);
    char letter;
    switch (dni) {
        case 0:  letter = 'T'; break;
        case 1:  letter = 'R'; break;
        case 2:  letter = 'W'; break;
        case 3:  letter = 'A'; break;
        case 4:  letter = 'G'; break;
        case 5:  letter = 'M'; break;
        case 6:  letter = 'Y'; break;
        case 7:  letter = 'F'; break;
        case 8:  letter = 'P'; break;
        case 9:  letter = 'D'; break;
        case 10: letter = 'X'; break;
        case 11: letter = 'B'; break;
        case 12: letter = 'N'; break;
        case 13: letter = 'J'; break;
        case 14: letter = 'Z'; break;
        case 15: letter = 'S'; break;
        case 16: letter = 'Q'; break;
        case 17: letter = 'V'; break;
        case 18: letter = 'H'; break;
        case 19: letter = 'L'; break;
        case 20: letter = 'C'; break;
        case 21: letter = 'K'; break;
        case 22: letter = 'E'; break;
    }
    return letter;
}

void print_menu (){
    printf("\n1 - Calculo de letra\n2 - Check letra\n0 - Exit\n> ");
}
void scan_opcion(char *ans){
    scanf(" %s", ans);
}