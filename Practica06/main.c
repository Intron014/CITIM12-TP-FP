#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define N 100

void buscar_substring(char [N][9+1]);
void buscar_letra(char [N][9+1]);
void print_menu ();
void print_strings_DNIs(char [N][9+1]);
void rand_strings_DNIs(char [N][9+1]);
void rand_str_DNI(char [9+1]);

int main() {
    printf("Initializing...\n");
    srand(time(NULL));
    char dnises[N][9+1];
    rand_strings_DNIs(dnises);

    print_menu();
    int option;
    scanf(" %d", &option);
    while(option != 0){
        switch(option){
            case 1:
                buscar_letra(dnises);
                break;
            case 2:
                buscar_substring(dnises);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
        print_menu();
        scanf("%d", &option);
    }

    return 0;
}

void print_menu(){
    printf("\nPlease, make a selection:\n- 1. Buscar Letra\n- 2. Buscar Substring\n> ");
}
void buscar_letra(char dni[N][9+1]){
    char letra;
    printf("Enter a letter to search: ");
    scanf(" %c", &letra);
    letra = toupper(letra);
    for (int i = 0 ; i<N ; i++)
        if(dni[i][8] == letra)
            printf("- %s\n", dni[i]);
}
void buscar_substring(char dni[N][9+1]){
    char substring[9+1];
    char *pointer;
    printf("Enter a substring to search: ");
    scanf(" %s", substring);

    for (int i = 0 ; i<N ; i++) {
        pointer = strstr(dni[i], substring);
        if(pointer != NULL)
            printf("- %s\n", dni[i]);
    }
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
