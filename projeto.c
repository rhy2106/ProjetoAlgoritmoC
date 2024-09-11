#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
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
typedef struct{
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
typedef struct{
    char nome[10];
    float ct;
    float txc;
    float txv;
} Moeda;

void limparString(char *p, int tam){
    // preenche toda a string com valor nulo para retirar o lixo
    int i; 
    for(i = 0; i < tam; i++){
        p[i] = '\0';
    }
}
void subString(char * tmp, char *linha, int comeco, int fim){
    // recebe a variavel em que a substring vai ser armazenada
    // a linha e a posição em que a substring está
    char palavra[100];
    int i;
    limparString(palavra,100);
    for(i = comeco; i < fim; i++){
        palavra[i-comeco] = linha[i];
    }
    // esta operação (i - comeco) é feita para que a substring
    // seja armazenada no começo da variavel 'tmp' 
    strcat(tmp,palavra);
}
int ContaCpfC(char *linha, Pessoa *contas, int ic){
    char tmp[20];
    limparString(tmp,20);
    subString(tmp,linha,0,12);
    long int cpf = atol(tmp); // cpf da linha
    int i;
    for(i = 0; i < ic; i++){
        if(contas[i].cpf == cpf) return i; // retorna a posição do cpf na lista de contas
    }
}

void buildP(char *linha, Pessoa *l){
    char tmp[100]; // tmp = substring da linha
    int i = 0, ii = 0, cont = 0;
    // i = index da linha, ii = index começo da substring
    l->cont = 0; // certificar que inicialmente o valor seja 0
    limparString(l->nome,100); // limpar o endereço do nome
    while(linha[i] != '\0'){
        if(linha[i] == ',' || linha[i] == '\n'){
            limparString(tmp,100); // limpa a substring
            subString(tmp,linha,ii,i); // pega a substring
            if(cont == 0) l->cpf = atol(tmp);
            if(cont == 1) l->senha = atoi(tmp);
            if(cont == 2) strcat(l->nome,tmp);
            if(cont == 3) l->reais = atof(tmp);
            if(cont == 4) l->btc = atof(tmp);
            if(cont == 5) l->eth = atof(tmp);
            if(cont == 6) l->xrp = atof(tmp);
            cont++;
            ii = i+1; // começo da proxima substring
        }
        i++;
    }
}
void buildM(char *linha, Moeda *m){
    char tmp[100]; // tmp = substring da linha
    int i = 0, ii = 0, cont = 0;
    // i = index da linha, ii = index começo da substring
    limparString(m->nome,10); // limpar o endereço do nome da moeda
    while(linha[i] != '\0'){
        if(linha[i] == ',' || linha[i] == '\n'){
            limparString(tmp,100); // limpa a substring
            subString(tmp,linha,ii,i); // pega a substring
            if(cont == 0) strcat(m->nome,tmp);
            if(cont == 1) m->ct = atof(tmp);
            if(cont == 2) m->txc = atof(tmp);
            if(cont == 3) m->txv = atof(tmp);
            cont++;
            ii = i+1; // começo da proxima substring
        }
        i++;
    }
}
void buildE(char*linha, Pessoa *p){
    char tmp[100]; // tmp = substring da linha
    int i = 0, ii = 0, cont = 0;
    limparString(p->extratos[p->cont].moeda,10); // limpar o endereço da moeda
    limparString(p->extratos[p->cont].dia,10); // limpar o endereço da dia
    limparString(p->extratos[p->cont].hora,5); // limpar o endereço da hora
    limparString(p->extratos[p->cont].acao,1); // limpar o endereço da acao
    while(linha[i] != '\0'){
        if(linha[i] == ',' || linha[i] == '\n'){
            limparString(tmp,100); // limpa a substring
            subString(tmp,linha,ii,i); // pega a substring
            // cont 0 e 1 sao o nome e o cpf que ja estao na lista de contas
            if(cont == 2) strcat(p->extratos[p->cont].dia,tmp);
            if(cont == 3) strcat(p->extratos[p->cont].hora,tmp);
            if(cont == 4) strcat(p->extratos[p->cont].acao,tmp);
            if(cont == 5) p->extratos[p->cont].valor = atof(tmp);
            if(cont == 6) strcat(p->extratos[p->cont].moeda,tmp);
            if(cont == 7) p->extratos[p->cont].ct = atof(tmp);
            if(cont == 8) p->extratos[p->cont].tx = atof(tmp);
            if(cont == 9) p->extratos[p->cont].reais = atof(tmp);
            if(cont == 10) p->extratos[p->cont].btc = atof(tmp);
            if(cont == 11) p->extratos[p->cont].eth = atof(tmp);
            if(cont == 12) p->extratos[p->cont].xrp = atof(tmp);
            cont++;
            ii = i+1; // começo da proxima substring
        }
        i++;
    }
    p->cont = p->cont + 1;
}
void adicionarExtrato(Pessoa *contas, Moeda moeda, char *acao, float valor, int id, int ic){
    #include <time.h>
    time_t agora;
    struct tm* t;
    int i, j;
    FILE *arquivo;
    time(&agora);
    t = gmtime(&agora); // armazena a data e hora em que a função esta sendo executada
    // coloca todas informaçoes da transação no extrato
    limparString(contas[id].extratos[contas[id].cont].dia,11);
    limparString(contas[id].extratos[contas[id].cont].hora,6);
    limparString(contas[id].extratos[contas[id].cont].dia,2);
    strcat(contas[id].extratos[contas[id].cont].moeda,moeda.nome);
    sprintf(contas[id].extratos[contas[id].cont].dia, "%02d-%02d-%d",t->tm_mday,t->tm_mon+1,t->tm_year+1900);
    sprintf(contas[id].extratos[contas[id].cont].hora, "%02d:%02d",t->tm_hour,t->tm_min);
    strcat(contas[id].extratos[contas[id].cont].acao,acao);
    contas[id].extratos[contas[id].cont].valor = valor;
    contas[id].extratos[contas[id].cont].reais = contas[id].reais;
    contas[id].extratos[contas[id].cont].btc = contas[id].btc;
    contas[id].extratos[contas[id].cont].eth = contas[id].eth;
    contas[id].extratos[contas[id].cont].xrp = contas[id].xrp;
    contas[id].extratos[contas[id].cont].ct = moeda.ct;
    if(acao[0] == '+') // verifica se foi uma compra ou deposito
        contas[id].extratos[contas[id].cont].tx = moeda.txc;
    if(acao[0] == '-') // verifica se foi uma venda ou saque
        contas[id].extratos[contas[id].cont].tx = moeda.txv;
    contas[id].cont += 1;
    
    arquivo = fopen("contas.txt","w");
    for(i = 0; i < ic; i++){ // reescreve o arquivo de contas
        fprintf(arquivo,"%ld,%d,%s,%f,%f,%f,%f\n",
            contas[i].cpf, contas[i].senha, contas[i].nome, contas[i].reais,
            contas[i].btc, contas[i].eth, contas[i].xrp
        );
    }
    fclose(arquivo);

    arquivo = fopen("extrato.txt","w");
    for(i = 0; i < ic; i++){ // reescreve o arquivo de extratos
        for(j = 0; j < contas[i].cont; j++){
            fprintf(arquivo,"%ld,%s,%s,%s,%s,%f,%s,%f,%f,%f,%f,%f,%f\n",
            contas[i].cpf, contas[i].nome,
            contas[i].extratos[j].dia,   contas[i].extratos[j].hora,
            contas[i].extratos[j].acao,  contas[i].extratos[j].valor,
            contas[i].extratos[j].moeda, contas[i].extratos[j].ct,
            contas[i].extratos[j].tx,    contas[i].extratos[j].reais,
            contas[i].extratos[j].btc,   contas[i].extratos[j].eth,
            contas[i].extratos[j].xrp
        );
        }
    }
    fclose(arquivo);
}

void saldo(){
}
void extrato(Pessoa conta){
    int i = 0;
    printf("\nCPF: %ld Nome: %s\n\n", conta.cpf, conta.nome);
    for(i = 0; i < conta.cont; i++){
        printf("%s %s %s %8.2f %-4s CT: %8.2f TX: %.2f REAL: %8.3f BTC: %8.3f ETH: %8.3f XRP: %8.3f\n",
            conta.extratos[i].dia,   conta.extratos[i].hora,
            conta.extratos[i].acao,  conta.extratos[i].valor,
            conta.extratos[i].moeda, conta.extratos[i].ct,
            conta.extratos[i].tx,    conta.extratos[i].reais,
            conta.extratos[i].btc,   conta.extratos[i].eth,
            conta.extratos[i].xrp
            );
    }
    printf("\n");
}
void depositar(){
}
void sacar(){
}
void comprar(Pessoa *contas, Moeda *moedas, int ic, int im, int id){
    int continuar, i;
    float valor;
    char opcao[10], lixo;

    continuar = 0;
    while(1){ // pergunta a moeda que o usuario deseja comprar ate ser inserido uma moeda valida
        i = 0;
        limparString(opcao,10);
        printf("Digite que moeda voce deseja comprar: (Digite em letra maiuscula)\n");
        printf("Opcoes: BTC, ETH, XRP\n");
        scanf("%s",opcao);
        while(i < im){
            if(!strcmp(moedas[i].nome,opcao)) {
                continuar = 1;
                break;
            }
            i++;
        }
        if(continuar) break;
        printf("Moeda invalida, digite novamente\n");
    }
    while(1){ // pergunta o valor desejado em reais da compra 
        printf("Digite o valor da moeda que deseja comprar em reais: ");
        scanf("%f", &valor);
        scanf("%c", &lixo);
        if(valor <= 0 || valor > contas[id].reais){
            printf("Valor invalido digite novamente\n");
            continue;
        }// verifica se o valor é valido
        contas[id].reais -= valor;
        break;
    }
    if(i == 1) contas[id].btc += (valor/moedas[i].ct)*(1-moedas[i].txc);
    if(i == 2) contas[id].eth += (valor/moedas[i].ct)*(1-moedas[i].txc);
    if(i == 3) contas[id].xrp += (valor/moedas[i].ct)*(1-moedas[i].txc);
    adicionarExtrato(contas, moedas[i], "+", valor,id,ic);
}
void vender(){
}
void atualizar(){
}
int logar(Pessoa *contas, int ic){
    while(1){
        long int cpf;
        char linha[20];
        int senha, i;
        limparString(linha,20);
        printf("Digite o seu CPF: ");
        cpf = atol(fgets(linha,20,stdin));
        limparString(linha,20);
        printf("Digite a senha: ");
        senha = atoi(fgets(linha,20,stdin));
        for(i = 0; i < ic; i++){
            if(cpf == contas[i].cpf && senha == contas[i].senha){
                printf("Login realizado com sucesso\n");
                printf("%s %ld\n",contas[i].nome,contas[i].cpf);
                return i;
            } else if(i == ic-1) printf("Login falhou, login ou senha errada\n");
        }
    }
}
void menu(int id, Pessoa *contas, Moeda *moedas, int ic, int im){
    int cont = 0; // id = index da conta da pessoa logada na lista de contas
    char lixo;
    while(1){
        printf("+--------------------------+\n");
        printf("|           Menu           |\n");
        printf("+--------------------------+\n");
        printf("| 1 - Consultar Saldo      |\n");
        printf("| 2 - Consultar Extrato    |\n");
        printf("| 3 - Depositar            |\n");
        printf("| 4 - Sacar                |\n");
        printf("| 5 - Comprar Criptomoedas |\n");
        printf("| 6 - Vender Criptomoedas  |\n");
        printf("| 7 - Atualizar Cotação    |\n");
        printf("| 8 - Sair                 |\n");
        printf("+--------------------------+\n");
        printf("Digite o numero da ação desejada: ");
        scanf("%d",&cont);
        scanf("%c",&lixo);
        if(cont == 1) saldo(); // M
        else if(cont == 2) extrato(contas[id]); // R 
        else if(cont == 3) depositar(); // M
        else if(cont == 4) sacar(); // M
        else if(cont == 5) comprar(contas,moedas,ic,im,id); // R
        else if(cont == 6) vender(); // R
        else if(cont == 7) atualizar(); // M
        else if(cont == 8) return;
        else printf("opção invalida\n");
    }
}
int main(){
    Pessoa contas[10]; // lista de contas
    Moeda moedas[10];
    char palavra[400], tmp[20]; // variavel para pegar as linhas do arquivo
    int ic = 0, im = 0, ie = 0, i = 0; //i = index
    // ic = i conta, im = i moeda, ie = i extrato
    FILE *arquivo; // arquivo

    arquivo = fopen("contas.txt","r"); // le o arquivo de contas
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo); // pegar a linha do arquivo
        buildP(palavra, &contas[ic]); // colocar todas as info na lista de contas
        ic++;
    } // ic = quantidade de contas + 1
    fclose(arquivo); // fecha o arquivo de contas

    arquivo = fopen("moedas.txt","r"); // le o arquivo de moedas
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo); // pegar a linha do arquivo
        buildM(palavra, &moedas[im]);
        // colocar todas as info na lista de moedas
        im++;
    } // im = quantidade de moedas + 1
    fclose(arquivo); // fecha o arquivo de moedas

    arquivo = fopen("extrato.txt","r"); // le o arquivo de extrato
    while(!feof(arquivo)){
        fgets(palavra,400,arquivo); // pegar a linha do arquivo
        buildE(palavra, &contas[ContaCpfC(palavra, contas, ic-1)]);
        // colocar todas as info na lista de extratos dentro da conta
    }
    fclose(arquivo); // fecha o arquivo de extratos
    
    while(1){
        // testes para ver se os dados tao armazenado corretamente
        for(i = 0; i < ic-1; i++){
            // imprimir todos os dados das contas
            printf("[%s] [%d] [%ld] [%f] [%f] [%f] [%f]\n",
                contas[i].nome,contas[i].senha,contas[i].cpf,
                contas[i].reais,contas[i].btc,contas[i].eth,
                contas[i].xrp);
            int j;
            for(j = 0; j < contas[i].cont; j++){ // imprime todos extratos da conta
                printf("[%s] [%s] [%s] [%f] [%s] [%f] [%f] [%f] [%f] [%f] [%f]\n",
                    contas[i].extratos[j].dia,   contas[i].extratos[j].hora,
                    contas[i].extratos[j].acao,  contas[i].extratos[j].valor,
                    contas[i].extratos[j].moeda, contas[i].extratos[j].ct,
                    contas[i].extratos[j].tx,    contas[i].extratos[j].reais,
                    contas[i].extratos[j].btc,   contas[i].extratos[j].eth,
                    contas[i].extratos[j].xrp
                    );
            }
        } // ic = quantidade de contas + 1
        for(i = 0; i < im-1; i++){
            // imprimir todos os dados das moedas
            printf("[%s] [%f] [%f] [%f]\n",
                moedas[i].nome, moedas[i].ct, moedas[i].txc,
                moedas[i].txv);
        } // im = quantidade de moedas + 1
        
        menu(logar(contas,ic-1),contas,moedas,ic-1,im-1);
    }
    return 0;
}
