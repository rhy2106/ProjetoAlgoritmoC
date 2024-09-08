#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  char senha[6];
  long int cpf;
  float reais;
  float btc;
  float eth;
  float xrp;
} Pessoa;

typedef struct {
  char nome[10];
  float ct;
  float txc;
  float txv;
} Moeda;

typedef struct {
  char nome[100];
  char moeda[10];
  char dia[10];
  char hora[5];
  char acao[1];
  long int cpf;
  float valor;
  float reais;
  float btc;
  float eth;
  float xrp;
  float ct;
  float tx;
} Extrato;

void limparString(char *p, int tam) {
  // preenche toda a string com valor nulo para retirar o lixo
  int i;
  for (i = 0; i < tam; i++) {
    p[i] = '\0';
  }
}

void subString(char *tmp, char *linha, int comeco, int fim) {
  // recebe a variavel em que a substring vai ser armazenada
  // a linha e a posição em que a substring está
  char palavra[100];
  int i;
  limparString(palavra, 100);
  for (i = comeco; i < fim; i++) {
    palavra[i - comeco] = linha[i];
  }
  // esta operação (i - comeco) é feita para que a substring
  // seja armazenada no começo da variavel 'tmp'
  strcat(tmp, palavra);
}

void buildP(char *linha, Pessoa *l) {
  char tmp[100]; // tmp = substring da linha
  int i = 0, ii = 0, cont = 0;
  // i = index da linha, ii = index começo da substring
  limparString(l->senha, 6);  // limpar o endereço da senha
  limparString(l->nome, 100); // limpar o endereço do nome
  while (linha[i] != '\0') {
    if (linha[i] == ',' || linha[i] == '\n') {
      limparString(tmp, 100);       // limpa a substring
      subString(tmp, linha, ii, i); // pega a substring
      if (cont == 0)
        l->cpf = atol(tmp);
      if (cont == 1)
        strcat(l->senha, tmp);
      if (cont == 2)
        strcat(l->nome, tmp);
      if (cont == 3)
        l->reais = atof(tmp);
      if (cont == 4)
        l->btc = atof(tmp);
      if (cont == 5)
        l->eth = atof(tmp);
      if (cont == 6)
        l->xrp = atof(tmp);
      cont++;
      ii = i + 1; // começo da proxima substring
    }
    i++;
  }
}

void buildM(char *linha, Moeda *m) {
  char tmp[100]; // tmp = substring da linha
  int i = 0, ii = 0, cont = 0;
  // i = index da linha, ii = index começo da substring
  limparString(m->nome, 10); // limpar o endereço do nome da moeda
  while (linha[i] != '\0') {
    if (linha[i] == ',' || linha[i] == '\n') {
      limparString(tmp, 100);       // limpa a substring
      subString(tmp, linha, ii, i); // pega a substring
      if (cont == 0)
        strcat(m->nome, tmp);
      if (cont == 1)
        m->ct = atof(tmp);
      if (cont == 2)
        m->txc = atof(tmp);
      if (cont == 3)
        m->txv = atof(tmp);
      cont++;
      ii = i + 1; // começo da proxima substring
    }
    i++;
  }
}

void buildE(char *linha, Extrato *e) {
  char tmp[100]; // tmp = substring da linha
  int i = 0, ii = 0, cont = 0;
  limparString(e->nome, 100); // limpar o endereço do nome
  limparString(e->moeda, 10); // limpar o endereço da senha
  limparString(e->dia, 10);   // limpar o endereço da senha
  limparString(e->hora, 5);   // limpar o endereço da senha
  limparString(e->acao, 1);   // limpar o endereço da senha
  while (linha[i] != '\0') {
    if (linha[i] == ',' || linha[i] == '\n') {
      limparString(tmp, 100);       // limpa a substring
      subString(tmp, linha, ii, i); // pega a substring
      // puts(tmp);
      if (cont == 0)
        e->cpf = atol(tmp);
      if (cont == 1)
        strcat(e->nome, tmp);
      if (cont == 2)
        strcat(e->dia, tmp);
      if (cont == 3)
        strcat(e->hora, tmp);
      if (cont == 4)
        strcat(e->acao, tmp);
      if (cont == 5)
        e->valor = atof(tmp);
      if (cont == 6)
        strcat(e->moeda, tmp);
      if (cont == 7)
        e->ct = atof(tmp);
      if (cont == 8)
        e->tx = atof(tmp);
      if (cont == 9)
        e->reais = atof(tmp);
      if (cont == 10)
        e->btc = atof(tmp);
      if (cont == 11)
        e->eth = atof(tmp);
      if (cont == 12)
        e->xrp = atof(tmp);
      // printf("[%s]\n",e->dia);
      cont++;
      ii = i + 1; // começo da proxima substring
    }
    i++;
  }
}

int main() {
  Pessoa contas[10]; // lista de contas
  Moeda moedas[10];
  Extrato extratos[100];
  char palavra[400];                 // variavel para pegar as linhas do arquivo
  int ic = 0, im = 0, ie = 0, i = 0; // i = index
  // ic = i conta, im = i moeda, ie = i extrato
  FILE *arquivo;                      // arquivo
  arquivo = fopen("contas.txt", "r"); // le o arquivo de contas
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo); // pegar a linha do arquivo
    buildP(palavra, &contas[ic]); // colocar todas as info na lista de contas
    ic++;
  }
  fclose(arquivo); // fecha o arquivo de contas

  arquivo = fopen("moedas.txt", "r"); // le o arquivo de moedas
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo); // pegar a linha do arquivo
    buildM(palavra, &moedas[im]);
    // colocar todas as info na lista de moedas
    im++;
  }
  fclose(arquivo); // fecha o arquivo de moedas

  arquivo = fopen("extrato.txt", "r"); // le o arquivo de contas
  while (!feof(arquivo)) {
    fgets(palavra, 400, arquivo);   // pegar a linha do arquivo
    buildE(palavra, &extratos[ie]); // colocar todas as info na lista de contas
    ie++;
  }
  fclose(arquivo); // fecha o arquivo de contas

  /*
      for(i = 0; i < ic-1; i++){
          // imprimir todos os dados das contas
          printf("[%s] [%s] [%ld] [%f] [%f] [%f] [%f]\n",
          contas[i].nome,contas[i].senha,contas[i].cpf,
          contas[i].reais,contas[i].btc,contas[i].eth,
          contas[i].xrp);
      } // ic = quantidade de contas + 1
      for(i = 0; i < im-1; i++){
          // imprimir todos os dados das moedas
          printf("[%s] [%f] [%f] [%f]\n",
          moedas[i].nome, moedas[i].ct, moedas[i].txc,
          moedas[i].txv);
      } // im = quantidade de moedas + 1
  */

  for (i = 0; i < ie - 1; i++) {
    // imprimir todos os dados dos extratos
    printf(
        "[%ld] [%s] [%s] [%s] [%s] [%f] [%s] [%f] [%f] [%f] [%f] [%f] [%f]\n",
        extratos[i].cpf, extratos[i].nome, extratos[i].dia, extratos[i].hora,
        extratos[i].acao, extratos[i].valor, extratos[i].moeda, extratos[i].ct,
        extratos[i].tx, extratos[i].reais, extratos[i].btc, extratos[i].eth,
        extratos[i].xrp);
  } // ie = quantidade de extratos + 1
  return 0;
}
