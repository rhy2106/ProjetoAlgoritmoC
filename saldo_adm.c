#include "funcoes.h"

void saldo_adm(Pessoa *contas, Moeda *moedas, int ic, int im) {
  while (1) {
    char cpf[12];
    int i;
    limparString(cpf, 12);
    printf("Digite o CPF do usuario desejado: ");
    scanf("%s", &cpf);
    for (i = 0; i < ic; i++) {
      if (strcmp(cpf,contas[i].cpf) == 0) {
        saldo(contas[i],moedas,im);
        return;
      } else if (i == ic - 1)
        printf("CPF não cadastrado\n");
    }
  }
}
