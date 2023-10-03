#include <stdio.h>

int main() {
    int dni, ans, i, j, comp;
    char letter, letteruser;
    do {
        do {
            printf("1 - Calculo de letra\n2 - Check letra\n0 - Exit\n> ");
            scanf(" %i", &ans);
        } while (ans < 0 || ans > 2);
        if (ans == 1) {
            j = 10000000;
            i = 1;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            comp = dni % 23;
            switch (comp) {
                case 0:letter = 'T';break;
                case 1:letter = 'R';break;
                case 2:letter = 'W';break;
                case 3:letter = 'A';break;
                case 4:letter = 'G';break;
                case 5:letter = 'M';break;
                case 6:letter = 'Y';break;
                case 7:letter = 'F';break;
                case 8:letter = 'P';break;
                case 9:letter = 'D';break;
                case 10:letter = 'X';break;
                case 11:letter = 'B';break;
                case 12:letter = 'N';break;
                case 13:letter = 'J';break;
                case 14:letter = 'Z';break;
                case 15:letter = 'S';break;
                case 16:letter = 'Q';break;
                case 17:letter = 'V';break;
                case 18:letter = 'H';break;
                case 19:letter = 'L';break;
                case 20:letter = 'C';break;
                case 21:letter = 'K';break;
                case 22:letter = 'E';break;
            }
            printf("> DNI: %i\n> restoDNI: %i\n> %i%c", dni, dni % 23, dni, letter);
        } else if (ans == 2) {
            j = 10000000;
            i = 1;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            j /= 10;
            i++;
            printf("Introduzca la posicion %i del DNI: ", i);
            scanf(" %i", &comp);
            dni += j * comp;
            comp = dni % 23;
            printf("> DNI: %i\n", dni);
            printf("Introduzca la letra del DNI: ");
            scanf(" %c", &letteruser);
            switch (dni % 23) {
                case 0:letter = 'T';break;
                case 1:letter = 'R';break;
                case 2:letter = 'W';break;
                case 3:letter = 'A';break;
                case 4:letter = 'G';break;
                case 5:letter = 'M';break;
                case 6:letter = 'Y';break;
                case 7:letter = 'F';break;
                case 8:letter = 'P';break;
                case 9:letter = 'D';break;
                case 10:letter = 'X';break;
                case 11:letter = 'B';break;
                case 12:letter = 'N';break;
                case 13:letter = 'J';break;
                case 14:letter = 'Z';break;
                case 15:letter = 'S';break;
                case 16:letter = 'Q';break;
                case 17:letter = 'V';break;
                case 18:letter = 'H';break;
                case 19:letter = 'L';break;
                case 20:letter = 'C';break;
                case 21:letter = 'K';break;
                case 22:letter = 'E';break;
            }
            if (letteruser == letter) {
                printf("Letra %c es correcta", letter);
            } else {
                printf("Whoops, %c no es la letra, era %c", letteruser, letter);
            }
        }
    } while (ans);
    return 0;
}
