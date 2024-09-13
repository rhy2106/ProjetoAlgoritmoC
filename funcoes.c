#include "funcoes.h"

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
int ContaCpfC(char *linha, Pessoa *contas, int ic) {
  char tmp[20];
  limparString(tmp, 20);
  subString(tmp, linha, 0, 12);
  long int cpf = atol(tmp); // cpf da linha
  int i;
  for (i = 0; i < ic; i++) {
    if (contas[i].cpf == cpf)
      return i; // retorna a posição do cpf na lista de contas
  }
}

void buildP(char *linha, Pessoa *l) {
  char tmp[100]; // tmp = substring da linha
  int i = 0, ii = 0, cont = 0;
  // i = index da linha, ii = index começo da substring
  l->cont = 0;                // certificar que inicialmente o valor seja 0
  limparString(l->nome, 100); // limpar o endereço do nome
  while (linha[i] != '\0') {
    if (linha[i] == ',' || linha[i] == '\n') {
      limparString(tmp, 100);       // limpa a substring
      subString(tmp, linha, ii, i); // pega a substring
      if (cont == 0)
        l->cpf = atol(tmp);
      if (cont == 1)
        l->senha = atoi(tmp);
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
void buildE(char *linha, Pessoa *p) {
  char tmp[100]; // tmp = substring da linha
  int i = 0, ii = 0, cont = 0;
  limparString(p->extratos[p->cont].moeda, 10); // limpar o endereço da moeda
  limparString(p->extratos[p->cont].dia, 10);   // limpar o endereço da dia
  limparString(p->extratos[p->cont].hora, 5);   // limpar o endereço da hora
  limparString(p->extratos[p->cont].acao, 1);   // limpar o endereço da acao
  while (linha[i] != '\0') {
    if (linha[i] == ',' || linha[i] == '\n') {
      limparString(tmp, 100);       // limpa a substring
      subString(tmp, linha, ii, i); // pega a substring
      // cont 0 e 1 sao o nome e o cpf que ja estao na lista de contas
      if (cont == 2)
        strcat(p->extratos[p->cont].dia, tmp);
      if (cont == 3)
        strcat(p->extratos[p->cont].hora, tmp);
      if (cont == 4)
        strcat(p->extratos[p->cont].acao, tmp);
      if (cont == 5)
        p->extratos[p->cont].valor = atof(tmp);
      if (cont == 6)
        strcat(p->extratos[p->cont].moeda, tmp);
      if (cont == 7)
        p->extratos[p->cont].ct = atof(tmp);
      if (cont == 8)
        p->extratos[p->cont].tx = atof(tmp);
      if (cont == 9)
        p->extratos[p->cont].reais = atof(tmp);
      if (cont == 10)
        p->extratos[p->cont].btc = atof(tmp);
      if (cont == 11)
        p->extratos[p->cont].eth = atof(tmp);
      if (cont == 12)
        p->extratos[p->cont].xrp = atof(tmp);
      cont++;
      ii = i + 1; // começo da proxima substring
    }
    i++;
  }
  p->cont = p->cont + 1;
}
void adicionarExtrato(Pessoa *contas, Moeda moeda, char *acao, float valor,int id, int ic) {
  time_t agora;
  struct tm *t;
  int i, j;
  FILE *arquivo;
  time(&agora);
  t = gmtime(
      &agora); // armazena a data e hora em que a função esta sendo executada
  // coloca todas informaçoes da transação no extrato
  limparString(contas[id].extratos[contas[id].cont].dia, 11);
  limparString(contas[id].extratos[contas[id].cont].hora, 6);
  limparString(contas[id].extratos[contas[id].cont].dia, 2);
  strcat(contas[id].extratos[contas[id].cont].moeda, moeda.nome);
  sprintf(contas[id].extratos[contas[id].cont].dia, "%02d-%02d-%d", t->tm_mday,
          t->tm_mon + 1, t->tm_year + 1900);
  sprintf(contas[id].extratos[contas[id].cont].hora, "%02d:%02d", t->tm_hour,
          t->tm_min);
  strcat(contas[id].extratos[contas[id].cont].acao, acao);
  contas[id].extratos[contas[id].cont].valor = valor;
  contas[id].extratos[contas[id].cont].reais = contas[id].reais;
  contas[id].extratos[contas[id].cont].btc = contas[id].btc;
  contas[id].extratos[contas[id].cont].eth = contas[id].eth;
  contas[id].extratos[contas[id].cont].xrp = contas[id].xrp;
  contas[id].extratos[contas[id].cont].ct = moeda.ct;
  if (acao[0] == '+') // verifica se foi uma compra ou deposito
    contas[id].extratos[contas[id].cont].tx = moeda.txc;
  if (acao[0] == '-') // verifica se foi uma venda ou saque
    contas[id].extratos[contas[id].cont].tx = moeda.txv;
  contas[id].cont += 1;

  arquivo = fopen("contas.txt", "w");
  for (i = 0; i < ic; i++) { // reescreve o arquivo de contas
    fprintf(arquivo, "%ld,%d,%s,%f,%f,%f,%f\n", contas[i].cpf, contas[i].senha,
            contas[i].nome, contas[i].reais, contas[i].btc, contas[i].eth,
            contas[i].xrp);
  }
  fclose(arquivo);

  arquivo = fopen("extrato.txt", "w");
  for (i = 0; i < ic; i++) { // reescreve o arquivo de extratos
    for (j = 0; j < contas[i].cont; j++) {
      fprintf(arquivo, "%ld,%s,%s,%s,%s,%.4f,%s,%f,%f,%.4f,%.4f,%.4f,%.4f\n",
              contas[i].cpf, contas[i].nome, contas[i].extratos[j].dia,
              contas[i].extratos[j].hora, contas[i].extratos[j].acao,
              contas[i].extratos[j].valor, contas[i].extratos[j].moeda,
              contas[i].extratos[j].ct, contas[i].extratos[j].tx,
              contas[i].extratos[j].reais, contas[i].extratos[j].btc,
              contas[i].extratos[j].eth, contas[i].extratos[j].xrp);
    }
  }
  fclose(arquivo);
}
