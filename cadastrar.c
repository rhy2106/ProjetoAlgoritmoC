#include "funcoes.h"

void cadastrar(Pessoa *contas, int *ic){	
	char letra[20];
	while(1) {

		printf("Cadastro de Invesidor: \n");
		
		printf("Nome: \n");
		scanf("%s", &contas[*ic].nome);
		getchar();
		
		printf("CPF: \n");
		scanf("%s", &contas[*ic].cpf);
		getchar();

		if(sizeof(contas[*ic].cpf) / sizeof(char) > 11){
			printf("CPF invalido!\n");
			printf("Digite qualquer coisa para continuar: \n");
			scanf(" %s", letra);
			getchar();
			continue;
		}
		
		printf("Senha: ");
		scanf("%d", &contas[*ic].senha);
		getchar();
		break;
    }
	*ic = *ic+1;
}