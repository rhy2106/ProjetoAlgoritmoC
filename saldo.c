#include "funcoes.h"

void saldo(Pessoa conta, Moeda *moedas,int im){
    int i = 0;
    printf("Nome: %s\nCPF: %s\n", conta.nome, conta.cpf);
    for(i = 0; i < im; i++){
        printf("%s: %.3f\n", moedas[i].nome, conta.dinheiro[i]);
    }
    printf("\n");
}
