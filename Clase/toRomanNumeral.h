//
// Created by intron014 on 27/09/23.
//

#ifndef CLASE_TOROMANNUMERAL_H
#define CLASE_TOROMANNUMERAL_H
void toRomanNumeral(){
    int num;
    do{
        printf("Introduzca un numero del 1-9: ");
        scanf("%d", &num);
    } while (num < 1 || num > 9);
    switch (num) {
        case 1: printf("I\n");    break;
        case 2: printf("II\n");   break;
        case 3: printf("III\n");  break;
        case 4: printf("IV\n");   break;
        case 5: printf("V\n");    break;
        case 6: printf("VI\n");   break;
        case 7: printf("VII\n");  break;
        case 8: printf("VIII\n"); break;
        case 9: printf("IX\n");   break;
    }
    printf("\n");
}
#endif //CLASE_TOROMANNUMERAL_H
