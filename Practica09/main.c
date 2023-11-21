#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define A 80
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


int rand_loader(){
    return rand()%10;
}

int bar_loader(int perc){
    int i;
    printf("[");
    for(i=0;i<perc;i++){
        printf("=");
    }
    for(i=perc;i<100;i++){
        printf(" ");
    }
    printf("] %d %%\r",perc);
    return 0;
}

int main() {
    srand(time(NULL));
    printf("(c) I014 Corp.\n Press enter to start\n");
    getchar();
    for(int i = 0; i<100 ; ){
        bar_loader(i);
        i+=rand_loader();
        system("sleep 0.1");
    }
}
