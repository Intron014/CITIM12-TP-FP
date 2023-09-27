//
// Created by intron014 on 27/09/23.
//

#ifndef CLASE_IMPRIMIRARMONICO_H
#define CLASE_IMPRIMIRARMONICO_H
void imprimirArmonico(){
    int num, cnt;
    float pnt;
    printf("Introduzca un numero: ");
    scanf("%i", &num);
    for( cnt = 1 ; cnt <= num ; cnt ++){
        pnt = 1.0 / cnt;
        printf("1/%i --> %f\n", cnt, pnt);
    }
}
#endif //CLASE_IMPRIMIRARMONICO_H
