#include "funcoes.h"

void extrato(Pessoa conta) {
  int i = 0;
  printf("\nCPF: %ld Nome: %s\n\n", conta.cpf, conta.nome);
  for (i = 0; i < conta.cont; i++) {
    printf("%s %s %s %8.2f %-4s CT: %8.2f TX: %.2f REAL: %8.3f BTC: %8.3f ETH: "
           "%8.3f XRP: %8.3f\n",
           conta.extratos[i].dia, conta.extratos[i].hora,
           conta.extratos[i].acao, conta.extratos[i].valor,
           conta.extratos[i].moeda, conta.extratos[i].ct, conta.extratos[i].tx,
           conta.extratos[i].reais, conta.extratos[i].btc,
           conta.extratos[i].eth, conta.extratos[i].xrp);
  }
  printf("\n");
}