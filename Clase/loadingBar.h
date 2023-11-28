//
// Created by intron014 on 28/11/23.
//

#ifndef CLASE_LOADINGBAR_H
#define CLASE_LOADINGBAR_H
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

#endif //CLASE_LOADINGBAR_H
