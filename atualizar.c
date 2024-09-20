#include "funcoes.h"

void atualizar(Moeda *moedas){
    int i;
    FILE *arquivo;
    srand((unsigned int)time(NULL));

    float bx = 0.05;
    float by = ((float)rand()/(float)(RAND_MAX)) * (2*bx)-bx;
    float bz = ceil(by * 1000.0) / 1000.0;

    float ex = 0.05;
    float ey = ((float)rand()/(float)(RAND_MAX)) * (2*ex)-ex;
    float ez = ceil(ey * 1000.0) / 1000.0;

    float rx = 0.05;
    float ry = ((float)rand()/(float)(RAND_MAX)) * (2*rx)-rx;
    float rz = ceil(ry * 1000.0) / 1000.0;

    moedas[1].ct = moedas[1].ct + (moedas[1].ct * bz);
    moedas[2].ct = moedas[2].ct + (moedas[2].ct * ez);
    moedas[3].ct = moedas[3].ct + (moedas[3].ct * rz);

    arquivo = fopen("moedas.txt","w");
    for(i = 0; i < 4; i++){
        fprintf(arquivo, "%s, %f, %f, %f\n", moedas[i].nome, moedas[i].ct, moedas[i].txc,        moedas[i].txv);
    }
    fclose(arquivo); 

    printf("As novas cotações são:\n");
    for(i = 0; i < 4; i++){
        printf("%s, %f\n", moedas[i].nome, moedas[i].ct);
    }
}