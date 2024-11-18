#include "funcoes.h"

int menu_admin() {
  int cont = 0; // id = index da conta da pessoa logada na lista de contas
  char lixo;
  while (1) {
    printf("+----------------------------+\n");
    printf("|    Menu Administrador      |\n");
    printf("+----------------------------+\n");
    printf("| 1 - Cadastrar Investidor   |\n");//M ok
    printf("| 2 - Excluir Investidor     |\n");//M ok
    printf("| 3 - Cadastrar Criptomoeda  |\n");//R ok
    printf("| 4 - Excluir Criptomoeda    |\n");//R ok
    printf("| 5 - Saldo                  |\n");//M ok
    printf("| 6 - Extrato                |\n");//R ok
    printf("| 7 - Atualizar Cotacao      |\n");//fds
    printf("| 8 - Sair                   |\n");//fds
    printf("+----------------------------+\n");
    printf("Digite o numero da acao desejada: ");
    scanf("%d", &cont);
    scanf("%c", &lixo);
    return cont;
  }
}