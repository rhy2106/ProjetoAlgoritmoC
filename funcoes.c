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

void adicionarExtrato(Pessoa *contas, Moeda moeda, char *acao, float valor, int id, int ic) {
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

  arquivo = fopen("contas.bin", "wb");
  for (i = 0; i < ic; i++) {
    fwrite(&contas[i], sizeof(Pessoa), 1, arquivo);
  }
  fclose(arquivo);
}
