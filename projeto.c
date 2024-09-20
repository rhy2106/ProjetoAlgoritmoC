#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Pessoa contas[10]; // lista de contas
  Moeda moedas[10];
  char lixo,fim;
  int ic = 0, id, im = 0, cont; // i = index
  // ic = i conta, im = i moeda, ie = i extrato
  FILE *arquivo; // arquivo

  arquivo = fopen("contas.bin", "rb"); // le o arquivo de contas
  while (fread(&contas[ic],sizeof(Pessoa),1,arquivo)) {
    ic++;
  }                // ic = quantidade de contas + 1
  fclose(arquivo); // fecha o arquivo de contas

  arquivo = fopen("moedas.bin", "rb"); // le o arquivo de moedas
  while (fread(&moedas[im],sizeof(Moeda),1,arquivo)) {
    im++;
  }                // im = quantidade de moedas + 1
  fclose(arquivo); // fecha o arquivo de moedas

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
        atualizar(moedas, im); // M
      else if (cont == 8)
        break;
      else
        printf("opção invalida\n");
    }
    while (1) {
      printf("Deseja finalizar o programa? (S/N)\n");
      scanf("%c", &fim);
      scanf("%c",%lixo);
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
