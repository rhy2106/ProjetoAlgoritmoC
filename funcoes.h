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
  char dinheiro_nome[10][10];
  float dinheiro[10];
  float valor;
  float ct;
  float tx;
} Extrato;

typedef struct {
  Extrato extratos[100];
  char nome[100];
  char cpf[11];
  int senha;
  int cont; // quantidade de extratos
  float dinheiro[10];
} Pessoa;

typedef struct {
  char nome[10];
  float ct;
  float txc;
  float txv;
} Moeda;

// funcoes
void limparString(char *p, int tam);
void subString(char *tmp, char *linha, int comeco, int fim);
int ContaCpfC(char *linha, Pessoa *contas, int ic);

// leitura / salvar arquivo
void buildP(char *linha, Pessoa *l);
void buildE(char *linha, Pessoa *p);
void buildM(char *linha, Moeda *m);
void salvar(Pessoa *contas, Moeda *moedas, int ic, int im);
int ler(Pessoa *contas, Moeda *moedas, int *ic, int *im);

// logar
int logar(Pessoa *contas, int ic);

// cliente
int menu();
void saldo(Pessoa conta, Moeda *moedas, int im);
void extrato(Pessoa conta, Moeda *moedas, int im);
void adicionarExtrato(Pessoa *contas, Moeda *moedas, char *acao, float valor, int id, int im,int idm);
void sacar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void depositar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void comprar(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void vender(Pessoa *contas, Moeda *moedas, int ic, int im, int id);
void atualizar(Moeda *moedas,int im);

// admin
int menu_admin();
void cadastrar_m(Moeda *moedas, int *im);
void excluir_invest(Pessoa *contas, Moeda *moedas, int *ic, int im);
void excluir_m(Pessoa *contas, Moeda *moedas, int ic, int *im);
void extrato_adm(Pessoa *contas, Moeda *moedas, int ic, int im);
void saldo_adm(Pessoa *contas, Moeda *moedas, int ic, int im);
void cadastrar(Pessoa *contas, int *ic);

#endif
