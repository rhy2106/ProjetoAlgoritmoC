#ifndef funcoes_h
#define funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
  char moeda[10];
  char dia[11];
  char hora[6];
  char acao[2];
  float valor;
  float reais;
  float btc;
  float eth;
  float xrp;
  float ct;
  float tx;
} Extrato;

typedef struct {
  Extrato extratos[100];
  char nome[100];
  int senha;
  int cont; // quantidade de extratos
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

void limparString(char *p, int tam);
void subString(char *tmp, char *linha, int comeco, int fim);
int ContaCpfC(char *linha, Pessoa *contas, int ic);
void adicionarExtrato(Pessoa *contas, Moeda moeda, char *acao, float valor,int id, int ic);
void buildP(char *linha, Pessoa *l);
void buildE(char *linha, Pessoa *p);
void adicionarExtrato(Pessoa *contas, Moeda moeda, char *acao, float valor, int id, int ic);
void comprar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
int logar(Pessoa *contas, int ic);
int menu();
void vender(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void extrato(Pessoa conta);
void saldo(Pessoa conta);
void depositar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void sacar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void atualizar(Moeda *moedas,int im);

#endif
