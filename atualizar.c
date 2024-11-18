#include "funcoes.h"

void atualizar(Moeda *moedas, int im) {
  int i;
  FILE *arquivo;
  srand((unsigned int)time(NULL));

  for(i = 0; i < im; i++){
    float x = ((rand()%11) - 5)*(0.01);
    moedas[i].ct = moedas[i].ct + (moedas[i].ct * x);
  }
  
  printf("As novas cotações são:\n");
  for (i = 0; i < im; i++) {
    printf("%s: %f\n", moedas[i].nome, moedas[i].ct);
  }
}
