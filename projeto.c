#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    long int cpf;
    float reais;
    float btc;
    float eth;
    float xrp;
} Pessoa;

void limparString(char *p, int tam){
    int i;
    for(i = 0; i < tam; i++){
        p[i] = '\0';
    }
}

void substring(char * tmp, char *linha, int i, int ii){
    char palavra[100];
    int z;
    limparString(palavra,100);
    for(z = i; z < ii; z++){
        palavra[z-i] = linha[z];
    }
    strcat(tmp,palavra);
}

void build(char *linha, Pessoa *l){
    char tmp[100];
    int i = 0, ii = 0, cont = 0, iii = 0; // i = index, ii = index2, iii = index3
    while(linha[i] != '\n'){
        if(linha[i] == ','){
            limparString(tmp,100);
            substring(tmp,linha,ii,i);
            if(cont == 0) strcat(l->nome,tmp);
            if(cont == 1) l->cpf = atol(tmp);
            if(cont == 2) l->reais = atof(tmp);
            if(cont == 3) l->btc = atof(tmp);
            if(cont == 4) l->eth = atof(tmp);
            if(cont == 5) l->xrp = atof(tmp);
            cont++;
            ii = i+1;
        }
        i++;
    }
}


int main(){
    Pessoa l[10];
    char palavra[400];
    int i = 0, ii = 0; // i = index, ii = index2
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","r");
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo);
        limparString(l[i].nome,100);
        build(palavra, &l[i]);
        i++;
    }
    for(ii = 0; ii < i-1; ii++){
        printf("[%s] [%ld] [%f] [%f] [%f] [%f]\n",l[ii].nome,l[ii].cpf,l[ii].reais,l[ii].btc,l[ii].eth,l[ii].xrp);
    }
    fclose(arquivo);
    return 0;
}