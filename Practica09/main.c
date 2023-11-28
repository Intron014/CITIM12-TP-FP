#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define A 80
#define MAX_YEAR 2020
#define MIN_YEAR 1995
const char nombres[8][10+1]={"jose","roberto","fernando","mario",
                             "sandra", "raquel", "isabel", "pilar"};
const char apellidos[8][10+1]={"garcia", "hernandez", "gutierrez",
                               "gomez", "fernandez", "lopez", "sanchez", "perez" };

typedef struct
{  unsigned dia, mes, anyo;
} DATE;

struct ALUMNO
{ char DNI[9+1];
    char nom_comp [20+1];
    DATE nac;
};

void print_DATE(DATE );
void print_ALUMNO (struct ALUMNO);
void rand_DATE(DATE  *);
void rand_nom_comp(char [20+1]);
void rand_ALUMNO(struct ALUMNO  *);
unsigned es_fecha_valida(DATE);

char letra_calculada (unsigned dni);

int main() {
    srand(time(NULL));
    struct ALUMNO a[A];
    for(int i=0; i<A; i++){
        rand_ALUMNO(&a[i]);
    }

}

void rand_DNI (char dni[9+1]){
    int i, j;
    unsigned dgt, tot=0;
    for (i = 1, j = 10000000; i < 9; i++) {
        do {
            dgt = rand()%10;
            if(i == 1 && dgt == 0){
                do{
                    dgt = rand()%10;
                } while (dgt < 1 || dgt > 9);
            }
        } while (dgt < 0 || dgt > 9);
        tot += j * dgt;
        dni[i-1] = dgt + '0';
        j /= 10;
    }
    dni[8] = letra_calculada(tot);
}
void rand_ALUMNO(struct ALUMNO *a){
    int i;
    char dni[9+1];
    rand_DNI(dni);
    strcpy(a->DNI, dni);
    rand_nom_comp(a->nom_comp);
    rand_DATE(&a->nac);
    print_ALUMNO(*a);
}
void print_DATE(DATE d){
    printf("%02d/%02d/%04d", d.dia, d.mes, d.anyo);
}
void print_ALUMNO (struct ALUMNO a){
    printf("%-10s %-21s ", a.DNI, a.nom_comp);
    print_DATE(a.nac);
    printf("\n");
}
void rand_DATE(DATE  *d){
    do {
        d->anyo = rand() % 25 + 1995;
        d->mes = rand() % 12 + 1;
        if (d->mes == 2) {
            if ((d->anyo % 4 == 0 && d->anyo % 100 != 0) || d->anyo % 400 == 0) {
                d->dia = rand() % 29 + 1;
            } else {
                d->dia = rand() % 28 + 1;
            }
        } else {
            d->dia = rand() % 31 + 1; // All other months have 31 days
        }
    } while (!es_fecha_valida(*d));
}
unsigned es_fecha_valida(DATE date){
    if(date.anyo < MIN_YEAR || date.anyo > MAX_YEAR){
        return 0;
    }
    if (date.mes < 1 || date.mes > 12) {
        return 0;
    }
    if (date.mes == 2) {
        if ((date.anyo % 4 == 0 && date.anyo % 100 != 0) || date.anyo % 400 == 0) {
            if (date.dia < 1 || date.dia > 29) {
                return 0;
            }
        } else {
            if (date.dia < 1 || date.dia > 28) {
                return 0;
            }
        }
    }  else {
        if (date.dia < 1 || date.dia > 31) {
            return 0;
        }
    }
    return 1;
}
void rand_nom_comp(char nom_comp[20+1]){
    strcpy(nom_comp, apellidos[rand() % 8]);
    strcat(nom_comp, ", ");
    strcat(nom_comp, nombres[rand() % 8]);
}
char letra_calculada (unsigned dni){
    dni %= 23;
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    return letter[dni];
}
