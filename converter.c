#include "funcoes.h"

int main(){
    Pessoa contas[10];
    Moeda moedas[10];
    char palavra[400], tmp[20];
    int ic = 0, im = 0, ie = 0, i = 0;
    FILE *arquivo; 
    arquivo = fopen("contas.txt","r");
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo);
        buildP(palavra, &contas[ic]);
        ic++;
    }
    fclose(arquivo);
    arquivo = fopen("moedas.txt","r");
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo);
        buildM(palavra, &moedas[im]);
        im++;
    }
    fclose(arquivo);
    arquivo = fopen("extrato.txt","r");
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo);
        buildE(palavra, &contas[ContaCpfC(palavra, contas, ic-1)]);
    }
    fclose(arquivo);
    
    arquivo = fopen("contas.bin", "wb");
    for (i = 0; i < ic; i++) {
        fwrite(&contas[i], sizeof(Pessoa), 1, arquivo);
    }
    fclose(arquivo);
    
    arquivo = fopen("moedas.bin", "wb");
    for (i = 0; i < im; i++) {
        fwrite(&moedas[i], sizeof(Moeda), 1, arquivo);
    }
    fclose(arquivo);
}