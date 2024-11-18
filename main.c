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
  
  if(ler(contas,moedas,&ic,&im)) return 0;
  int i = 0;
  while (1) {
    id = logar(contas, ic);
    printf("%d",id);
    if(id == 0){
      while (1) {
        salvar(contas, moedas, ic, im);
        cont = menu_admin();
        if (cont == 1)
          cadastrar(contas, &ic);
        else if (cont == 2)
          excluir_invest(contas, moedas, &ic, im);
        else if (cont == 3)
          cadastrar_m(moedas, &im);
        else if (cont == 4)
          excluir_m(contas, moedas, ic, &im);
        else if (cont == 5)
          saldo_adm(contas,moedas,ic,im);
        else if (cont == 6)
          extrato_adm(contas, moedas, ic, im);
        else if (cont == 7)
          atualizar(moedas, im); // M
        else if (cont == 8)
          break;
        else
          printf("opção invalida\n");
      }
    }
    else{
      while (1) {
        salvar(contas, moedas, ic, im);
        cont = menu();
        if (cont == 1)
          saldo(contas[id], moedas, im); // M
        else if (cont == 2)
          extrato(contas[id], moedas, im); // R
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
    }
    while (1) {
      printf("Deseja finalizar o programa? (S/N)\n");
      scanf("%c", &fim);
      scanf("%c",&lixo);
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
