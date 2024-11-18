#include "funcoes.h"

void cadastrar_m(Moeda *moedas, int *im){
    int erro = 0, i;
    while(1){
        erro = 0;
        limparString(moedas[*im].nome,10);
        moedas[*im].ct = 0;
        moedas[*im].txc = 0;
        moedas[*im].txv = 0;
        printf("Digite o nome da moeda que voce deseja cadastrar: (max 10 caracteres)\n");
        scanf("%s", moedas[*im].nome);
        getchar();
        for(i = 0; i < 10; i++){
            if(moedas[*im].nome[i] >= 97 && moedas[*im].nome[i] < 123) moedas[*im].nome[i] = (int)moedas[*im].nome[i] - 32;
        }
        for(i = 0; i < *im; i++){
            if(!strcmp(moedas[*im].nome,moedas[i].nome)){
                printf("Nome Invalido!!!\n");
                erro++;
            }
        }
        if(erro) continue;
        while(moedas[*im].ct <= 0){
            printf("Digite a Cotacao inicial:\n");
            scanf("%f", &moedas[*im].ct);
            if(moedas[*im].ct > 0) break;
            else printf("Valor invalido!\n");
        }
        while(moedas[*im].txc <= 0){
            printf("Digite a taxa de compra inicial:\n");
            scanf("%f", &moedas[*im].txc);
            if(moedas[*im].txc > 0) break;
            else printf("Valor invalido!\n");
        }
        while(moedas[*im].txv <= 0){
            printf("Digite a taxa de venda inicial:\n");
            scanf("%f", &moedas[*im].txv);
            if(moedas[*im].txv > 0) break;
            else printf("Valor invalido!\n");
        }
        *im = *im+1;
        break;
    }
}