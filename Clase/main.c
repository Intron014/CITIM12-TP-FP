#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

void printMenu(){
    printf("Ejercicios de la clase\n");
    printf("1. Fecha mas reciente\n");
    printf("2. Numero -> Numero Romano\n");
    printf("3. Imprimir Armonico\n");
    printf("4. \n");
    printf("5. \n");
}
void main(){
    int cnt;
    do{
        printMenu();
        do{
            printf("Introduzca el numero de ejercicio (1-5): ");
            scanf("%d", &cnt);
        }while(cnt < 0 || cnt > 5);
        switch(cnt){
            case 0:
                printf("Bye!");
                break;
            case 1:
                fechaMasReciente();
                break;
            case 2:
                toRomanNumeral();
                break;
            case 3:
                imprimirArmonico();
                break;
            case 4:
                printf("4");
                break;
            case 5:
                printf("5");
                break;
            default:
                printf("Error");
        }
    } while (cnt != 0);
}
