#include "funcoes.h"

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
        strcat(l->nome, tmp);
      if (cont == 1)
        l->senha = atoi(tmp);
      if (cont == 2){
        strcat(l->cpf, tmp);
      }
      if (cont >= 3)
        l->dinheiro[cont-3] = atof(tmp);
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
  int i = 0, ii = 0, ie = 0, cont = 0;
  limparString(p->extratos[p->cont].moeda, 10); // limpar o endereço da moeda
  limparString(p->extratos[p->cont].dia, 10);   // limpar o endereço da dia
  limparString(p->extratos[p->cont].hora, 5);   // limpar o endereço da hora
  limparString(p->extratos[p->cont].acao, 1);   // limpar o endereço da acao
  for(i = 0; i < 10; i++){
    limparString(p->extratos[p->cont].dinheiro_nome[i],10);   // limpar o endereco do nome da moeda
  }
  i = 0;
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
      if (cont >= 9){
        if(cont%2 == 1) strcat(p->extratos[p->cont].dinheiro_nome[ie],tmp);
        else {
            p->extratos[p->cont].dinheiro[ie] = atof(tmp);
            ie++;
        }
      }
      cont++;
      ii = i + 1; // começo da proxima substring
    }
    i++;
  }
  p->cont = p->cont + 1;
}
int ler(Pessoa *contas, Moeda *moedas, int *ic, int *im){
  FILE *arquivo; // arquivo
  int ie = 0, i = 0;
  char palavra[400], tmp[20];


  arquivo = fopen("moedas.bin", "rb"); // le o arquivo de moedas
  if(arquivo != NULL){
    while (fread(&moedas[*im],sizeof(Moeda),1,arquivo)) *im = *im+1;
    // im = quantidade de moedas + 1
    fclose(arquivo); // fecha o arquivo de moedas

    arquivo = fopen("contas.bin", "rb"); // le o arquivo de contas
    while (fread(&contas[*ic],sizeof(Pessoa),1,arquivo)) *ic = *ic+1;
    // *ic = quantidade de contas + 1
    fclose(arquivo); // fecha o arquivo de contas
    return 0;
  }

  arquivo = fopen("contas.txt","r");
  if(arquivo == NULL){
    printf("Arquivo de \"contas.txt\" faltando\n");
    printf("Digite qualquer coisa para fechar o programa");
    scanf("%s", palavra);
    return 1;
  }
  while(!feof(arquivo)){
      fgets(palavra,400,arquivo);
      buildP(palavra, &contas[*ic]);
      *ic = *ic+1;
  }
  fclose(arquivo);
  arquivo = fopen("moedas.txt","r");
  if(arquivo == NULL){
    printf("Arquivo de \"moedas.txt\" faltando\n");
    printf("Digite qualquer coisa para fechar o programa");
    scanf("%s", palavra);
    return 1;
  }
  while(!feof(arquivo)){
      fgets(palavra,400,arquivo);
      buildM(palavra, &moedas[*im]);
      *im = *im+1;
  }
  fclose(arquivo);
  arquivo = fopen("extrato.txt","r");
  if(arquivo == NULL){
    printf("Arquivo de \"extrato.txt\" faltando\n");
    printf("Digite qualquer coisa para fechar o programa");
    scanf("%s", palavra);
    return 1;
  }
  while(!feof(arquivo)){
      fgets(palavra,400,arquivo);
      buildE(palavra, &contas[ContaCpfC(palavra, contas, *ic)]);
  }
  fclose(arquivo);
  *ic = *ic-1;
  *im = *im-1;
  for(i = 0; i < *ic; i++){
    if(contas[i].cont > 0) contas[i].cont--; 
  }
  return 0;
}

void salvar(Pessoa *contas, Moeda *moedas, int ic, int im){
  FILE *arquivo;
  int i, j, k; // index do for
  arquivo = fopen("moedas.txt", "w");
  for (i = 0; i < im; i++) {
    fprintf(arquivo,"%s,%f,%f,%f\n", moedas[i].nome,moedas[i].ct,moedas[i].txc,moedas[i].txv);
  }
  fclose(arquivo);

  arquivo = fopen("contas.txt", "w");
  for (i = 0; i < ic; i++) { // repeticao para cada conta
    fprintf(arquivo,"%s,%d,%s", contas[i].nome, contas[i].senha, contas[i].cpf);
    for(j = 0; j < im; j++){ // repeticao para cada valor das moedas
      fprintf(arquivo,",%.3f", contas[i].dinheiro[j]);
    }
    fprintf(arquivo,"\n");
  }
  fclose(arquivo);

  arquivo = fopen("extrato.txt", "w");
  for (i = 0; i < ic; i++) { // repeticao para cada conta
    for(j = 0; j < contas[i].cont; j++){ // repeticao para cada extrato
      fprintf(arquivo,"%s,%s,%s,%s,%s,%f,%s,%f,%f",
      contas[i].cpf, contas[i].nome, contas[i].extratos[j].dia,
      contas[i].extratos[j].hora,contas[i].extratos[j].acao,
      contas[i].extratos[j].valor,contas[i].extratos[j].moeda,
      contas[i].extratos[j].ct,contas[i].extratos[j].tx);
      for(int k = 0; k < im; k++){ // repeticao para cada valor das moedas 
        fprintf(arquivo,",%s,%.3f",contas[i].extratos[j].dinheiro_nome[k],contas[i].extratos[j].dinheiro[k]);
      }
      fprintf(arquivo, "\n");
    }
  }
  fclose(arquivo);

  arquivo = fopen("moedas.bin", "wb");
  for (i = 0; i < im; i++) {
    fwrite(&moedas[i], sizeof(Moeda), 1, arquivo);
  }
  fclose(arquivo);

  arquivo = fopen("contas.bin", "wb");
  for (i = 0; i < ic; i++) {
    fwrite(&contas[i], sizeof(Pessoa), 1, arquivo);
  }
  fclose(arquivo);

}