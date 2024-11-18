#include "funcoes.h"

void extrato(Pessoa conta, Moeda *moedas, int im) {
  int i = 0, j = 0;
  printf("\nCPF: %s Nome: %s\n\n", conta.cpf, conta.nome);
  for (i = 0; i < conta.cont; i++) {
    printf("%s %s %s %8.2f %-4s CT: %8.2f TX: %.2f ",
           conta.extratos[i].dia, conta.extratos[i].hora,
           conta.extratos[i].acao, conta.extratos[i].valor,
           conta.extratos[i].moeda, conta.extratos[i].ct, conta.extratos[i].tx);
    for(j = 0; j < im; j++){
      printf("%s: %8.3f ", moedas[j].nome, conta.extratos[i].dinheiro[j]);
    }
    printf("\n");
  }
  printf("\n");
}