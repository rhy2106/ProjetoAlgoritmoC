#include "funcoes.h"

void saldo(Pessoa conta){
    printf("\nNome: %s \nCPF: %ld \nReais: %.2f \nBitcoin: %.3f \nEthereum: %.3f \nRipple: %.3f \n\n", conta.nome, conta.cpf, conta.reais, conta.btc, conta.eth, conta.xrp);
}