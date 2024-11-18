#include "funcoes.h"

void excluir_invest(Pessoa *contas, Moeda *moedas, int *ic, int im){
  char escolha;
  int i, c;
  while (1) {
    char cpf[12];
    //c = conta a ser excluida
    FILE *arquivo;
    limparString(cpf, 12);
    printf("Digite o CPF do usuario que deseja excluir: ");
    scanf("%s", &cpf);
    getchar();
    for (c = 0; c < ic; c++) {
      if (strcmp(cpf, contas[c].cpf) == 0) {
        saldo(contas[c],moedas,im);
        break;
      } else if (c == ic - 1){
        printf("CPF não cadastrado\n");
        c = ic;
      }
    }
    if(c != ic) break;
  }
  printf("Deseja mesmo excluir a conta?(S/N)\n");
  scanf("%c", &escolha);
  getchar();
  if (escolha == 'S'){
    for(i = c+1; i < *ic; i++){
      contas[i-1] = contas[i];
    }
    *ic = *ic-1;
  }
}