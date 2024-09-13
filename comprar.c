#include "funcoes.h"

void comprar(Pessoa *contas, Moeda *moedas, int ic, int im, int id) {
  int continuar, i;
  float valor;
  char opcao[10], lixo;

  continuar = 0;

  while (1) { // pergunta a moeda que o usuario deseja comprar ate ser inserido
              // uma moeda valida
    i = 0;
    limparString(opcao, 10);
    printf(
        "Digite que moeda voce deseja comprar: (Digite em letra maiuscula)\n");
    printf("Opcoes: BTC, ETH, XRP\n");
    printf("Digite 0 para retornar ao menu\n");
    scanf("%s", opcao);
    if (opcao[0] == '0')
      return;
    while (i < im) {
      if (!strcmp(moedas[i].nome, opcao)) {
        continuar = 1;
        break;
      }
      i++;
    }
    if (continuar)
      break;
    printf("Moeda invalida, digite novamente\n");
  }

  while (1) { // pergunta o valor desejado em reais da compra
    printf("Digite o valor da moeda que deseja comprar em reais:\n");
    printf("Digite 0 para retornar ao menu\n");
    scanf("%f", &valor);
    scanf("%c", &lixo);
    if (valor == 0)
      return;
    if (valor < 0 || valor > contas[id].reais) {
      printf("Valor invalido digite novamente\n");
      continue;
    } // verifica se o valor é valido
    contas[id].reais -= valor;
    break;
  }
  if (i == 1)
    contas[id].btc += (valor / moedas[i].ct) * (1 - moedas[i].txc);
  if (i == 2)
    contas[id].eth += (valor / moedas[i].ct) * (1 - moedas[i].txc);
  if (i == 3)
    contas[id].xrp += (valor / moedas[i].ct) * (1 - moedas[i].txc);
  adicionarExtrato(contas, moedas[i], "+", valor, id, ic);
}