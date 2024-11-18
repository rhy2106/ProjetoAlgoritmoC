#include "funcoes.h"

void excluir_m(Pessoa *contas, Moeda *moedas, int ic, int *im){
  int continuar, m, i, iconta; // m = moeda que vai ser deletada
  // i = index da moeda // iconta = index da conta
  char opcao[10], lixo, escolha;
  continuar = 0;
  while (1) { // pergunta a moeda que o usuario deseja comprar ate ser inserido uma moeda valida
    m = 0;
    limparString(opcao, 10);
    printf("Digite que moeda voce deseja excluir: (Digite em letra maiuscula)\n");
    printf("Opcoes:\n");
    for(m = 1; m < *im; m++){
        printf("- %s\n", moedas[m].nome);
    }
    m = 0;
    printf("Digite 0 para retornar ao menu\n");
    scanf("%s", opcao);
    if (opcao[0] == '0') return;
    while (m < *im) {
      if (!strcmp(moedas[m].nome, opcao)) {
        continuar = 1;
        break;
      }
      m++;
    }
    if(continuar) break;
    printf("Moeda invalida, digite novamente\n");
  }
  printf("Deseja mesmo excluir a moeda?(S/N)\n");
  scanf("%c", &escolha);
  getchar();
  if(escolha != 'S') return;
  for(i = m+1; i < *im; i++){
    moedas[i-1] = moedas[i];
  }
  for(iconta = 0; iconta < ic; iconta++){
    for(int i = m+1; i < *im; i++)
        contas[iconta].dinheiro[i-1] = contas[iconta].dinheiro[i];
  }
  *im = *im-1;
}