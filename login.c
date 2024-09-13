#include "funcoes.h"

int logar(Pessoa *contas, int ic) {
  while (1) {
    long int cpf;
    char linha[20];
    int senha, i;
    limparString(linha, 20);
    printf("Digite o seu CPF: ");
    cpf = atol(fgets(linha, 20, stdin));
    limparString(linha, 20);
    printf("Digite a senha: ");
    senha = atoi(fgets(linha, 20, stdin));
    for (i = 0; i < ic; i++) {
      if (cpf == contas[i].cpf && senha == contas[i].senha) {
        printf("Login realizado com sucesso\n");
        printf("%s %ld\n", contas[i].nome, contas[i].cpf);
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
    printf("| 7 - Atualizar Cotação    |\n");
    printf("| 8 - Sair                 |\n");
    printf("+--------------------------+\n");
    printf("Digite o numero da ação desejada: ");
    scanf("%d", &cont);
    scanf("%c", &lixo);
    return cont;
  }
}