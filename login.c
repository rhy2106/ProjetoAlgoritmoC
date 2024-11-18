#include "funcoes.h"

int logar(Pessoa *contas, int ic) {
  while (1) {
    char cpf[12];
    char linha[20];
    int senha, i;
    limparString(cpf, 11);
    printf("Digite o seu CPF: ");
    scanf("%s",&cpf);
    getchar();
    limparString(linha, 20);
    printf("Digite a senha: ");
    scanf("%s",&linha);
    senha = atoi(linha);
    for (i = 0; i < ic; i++) {
      if (strcmp(cpf,contas[i].cpf) == 0 && senha == contas[i].senha) {
        printf("Login realizado com sucesso\n");
        return i;
      } else if (i == ic - 1)
        printf("Login falhou, login ou senha errada\n");
    }
  }
}
int menu() {
  int cont = 0; // id = index da conta da pessoa logada na lista de contas
  char lixo;
  while (1) {
    printf("+--------------------------+\n");
    printf("|           Menu           |\n");
    printf("+--------------------------+\n");
    printf("| 1 - Consultar Saldo      |\n");
    printf("| 2 - Consultar Extrato    |\n");
    printf("| 3 - Depositar            |\n");
    printf("| 4 - Sacar                |\n");
    printf("| 5 - Comprar Criptomoedas |\n");
    printf("| 6 - Vender Criptomoedas  |\n");
    printf("| 7 - Atualizar Cotacao    |\n");
    printf("| 8 - Sair                 |\n");
    printf("+--------------------------+\n");
    printf("Digite o numero da acao desejada: ");
    scanf("%d", &cont);
    scanf("%c", &lixo);
    return cont;
  }
}
