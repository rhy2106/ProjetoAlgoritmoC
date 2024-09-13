#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Pessoa contas[10]; // lista de contas
  Moeda moedas[10];
  char palavra[400], tmp[20], fim; // variavel para pegar as linhas do arquivo
  int ic = 0, id, im = 0, ie = 0, cont; // i = index
  // ic = i conta, im = i moeda, ie = i extrato
  FILE *arquivo; // arquivo

  arquivo = fopen("contas.txt", "r"); // le o arquivo de contas
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo); // pegar a linha do arquivo
    buildP(palavra, &contas[ic]); // colocar todas as info na lista de contas
    ic++;
  }                // ic = quantidade de contas + 1
  fclose(arquivo); // fecha o arquivo de contas

  arquivo = fopen("moedas.txt", "r"); // le o arquivo de moedas
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo); // pegar a linha do arquivo
    buildM(palavra, &moedas[im]);
    // colocar todas as info na lista de moedas
    im++;
  }                // im = quantidade de moedas + 1
  fclose(arquivo); // fecha o arquivo de moedas

  arquivo = fopen("extrato.txt", "r"); // le o arquivo de extrato
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo); // pegar a linha do arquivo
    buildE(palavra, &contas[ContaCpfC(palavra, contas, ic - 1)]);
    // colocar todas as info na lista de extratos dentro da conta
  }
  fclose(arquivo); // fecha o arquivo de extratos

  while (1) {
    id = logar(contas, ic - 1);
    while (1) {
      cont = menu();
      if (cont == 1)
        saldo(contas[id]); // M
      else if (cont == 2)
        extrato(contas[id]); // R
      else if (cont == 3)
        depositar(contas, moedas, ic, im, id); // M
      else if (cont == 4)
        sacar(contas, moedas, ic, im, id); // M
      else if (cont == 5)
        comprar(contas, moedas, ic, im, id); // R
      else if (cont == 6)
        vender(contas, moedas, ic, im, id); // R
      else if (cont == 7)
        atualizar(moedas); // M
      else if (cont == 8)
        break;
      else
        printf("opção invalida\n");
    }
    while (1) {
      printf("Deseja finalizar o programa? (S/N)\n");
      scanf("%c", &fim);
      if (fim == 'S')
        return 0;
      else if (fim == 'N')
        break;
      else
        printf("Opcao invalida\n");
    }
  }
  return 0;
}
