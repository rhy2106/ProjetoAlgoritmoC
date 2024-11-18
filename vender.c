#include "funcoes.h"

void vender(Pessoa *contas, Moeda *moedas, int ic, int im, int id) {
  int continuar, i;
  float valor;
  char opcao[10], lixo;

  continuar = 0;
  while (1) { // pergunta a moeda que o usuario deseja vender ate ser inserido
              // uma moeda valida
    i = 0;
    limparString(opcao, 10);
    printf("Digite que moeda voce deseja vender: (Digite em letra maiuscula)\n");
    printf("Opcoes:\n");
    for(i = 1; i < im; i++){
        printf("- %s\n", moedas[i].nome);
    }
    i = 0;
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
  while (1) { // pergunta o valor desejado em reais da venda
    printf("Digite o valor da moeda que deseja vender em reais:\n");
    printf("Digite 0 para retornar ao menu\n");
    scanf("%f", &valor);
    scanf("%c", &lixo);
    if (valor == 0)
      return;
    if (valor < 0 || (valor / moedas[i].ct > contas[id].dinheiro[i])) {
      printf("Valor invalido digite novamente\n");
      continue;
    } // verifica se o valor é valido
    contas[id].dinheiro[0] += valor * (1 - moedas[i].txv);
    break;
  }
  contas[id].dinheiro[i] -= (valor / moedas[i].ct);
  adicionarExtrato(contas, moedas, "-", valor, id,im,i);
}
