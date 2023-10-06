#include <stdio.h>

int main() {
    int dni=0, ans, i, j, comp;
    char letter, letteruser;
    do {
        do {
            printf("\n1 - Calculo de letra\n2 - Check letra\n0 - Exit\n> ");
            scanf(" %i", &ans);
        } while (ans < 0 || ans > 2);
        if(ans) {
            for (i = 1, j = 10000000; i < 9; i++) {
                do {
                    printf("Introduzca la posicion %i del DNI: ", i);
                    scanf(" %i", &comp);
                } while (comp < 0 || comp > 9);
                dni += j * comp;
                j /= 10;
            }
            if (ans == 2) {
                printf("Introduzca su letra a verificar: ");
                scanf(" %c", &letteruser);
            }
            comp = dni % 23;
            switch (comp) {
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
            if (ans == 1) {
                printf("> DNI: %i\n> restoDNI: %i\n> %i%c", dni, dni % 23, dni, letter);
            } else {
                if (letter == letteruser) {
                    printf("La letra %c es correcta", letter);
                } else {
                    printf("La letra %c no es correcta, era %c", letteruser, letter);
                }
            }
        }
    } while (ans);
    return 0;
}
