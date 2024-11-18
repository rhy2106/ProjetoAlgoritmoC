#include "funcoes.h"

void sacar(Pessoa *contas, Moeda *moedas, int ic, int im, int id){
    int continuar, i;
    float valor;
    char opcao[10], lixo;

    continuar = 0;
    while(1){
        i = 0;
        limparString(opcao,10);
        printf("Digite o valor a ser sacado em reais: \n");
        printf("Digite 0 para retornar ao menu\n");
        scanf("%f", &valor);
        scanf("%c", &lixo);

        if(valor == 0) return;
        if(valor < 0 || (valor > contas[id].dinheiro[0])){
            printf("Valor invalido, digiite novamente\n");
            continue;
        }
        contas[id].dinheiro[0] = contas[id].dinheiro[0] - valor;
        break;
    }
    adicionarExtrato(contas, moedas, "-", valor,id,im,i);
}