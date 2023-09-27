//
// Created by intron014 on 27/09/23.
//
#ifndef CLASE_FECHAMASRECIENTE_H
#define CLASE_FECHAMASRECIENTE_H
void fechaMasReciente(){
    char ans;
    do {
        printf("fechaMasReciente\n----------\n");
        int day1, month1, year1;
        int day2, month2, year2;
        do { // Date 1
            printf("Introduzca dd/mm/yyyy (1): ");
            scanf("%d/%d/%d", &day1, &month1, &year1);
        } while (day1 < 1 || day1 > 31 || month1 < 1 || month1 > 12 || year1 < 0);
        do { // Date 2
            printf("Introduzca dd/mm/yyyy (2): ");
            scanf("%d/%d/%d", &day2, &month2, &year2);
        } while (day2 < 1 || day2 > 31 || month2 < 1 || month2 > 12 || year2 < 0);
        if (year1 == year2) {
            if (month1 == month2) {
                if (day1 == day2) {
                    printf("Same dates OwO");
                } else if (day1 > day2) {
                    printf("%d/%d/%d", day1, month1, year1);
                } else {
                    printf("%d/%d/%d", day2, month2, year2);
                }
            } else if (month1 > month2) {
                printf("%d/%d/%d", day1, month1, year1);
            } else {
                printf("%d/%d/%d", day2, month2, year2);
            }
        } else if (year1 > year2) {
            printf("%d/%d/%d", day1, month1, year1);
        } else {
            printf("%d/%d/%d", day2, month2, year2);
        }
        printf("\nWanna go again (y/n): ");
        scanf(" %c", &ans);
    }while (ans == 'Y' || ans == 'y');
    printf("Bye!\n");
}
#endif //CLASE_FECHAMASRECIENTE_H
