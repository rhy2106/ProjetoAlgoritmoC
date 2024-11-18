## Objetivo do projeto:   
Criar um programa que simule um banco, onde é possivel realizar operações de saque, deposito, compras e vendas de criptomoedas. Alem disso é possivel logar como Admin e Adicionar/remover investidores/moedas.

### Forma de compilação em Bash:

```bash
for nome in {funcoes,atualizar,comprar,vender,saldo,depositar,extrato,sacar,login,menu_admin,cadastrar_m,excluir_m,excluir_investidor,salvar_ler,extrato_adm,saldo_adm,cadastrar}; do gcc -c $nome.c -o $nome.o; done;
ar rcs biblioteca.a *.o
gcc -o programa main.c biblioteca.a
```
### Forma de compilação em PowerShell:
```powershell
gcc -c funcoes.c -o funcoes.o
gcc -c atualizar.c -o atualizar.o
gcc -c comprar.c -o comprar.o
gcc -c vender.c -o vender.o
gcc -c saldo.c -o saldo.o
gcc -c depositar.c -o depositar.o
gcc -c extrato.c -o extrato.o
gcc -c sacar.c -o sacar.o
gcc -c login.c -o login.o
gcc -c menu_admin.c -o menu_admin.o
gcc -c cadastrar_m.c -o cadastrar_m.o
gcc -c excluir_m.c -o excluir_m.o
gcc -c excluir_investidor.c -o excluir_investidor.o
gcc -c salvar_ler.c -o salvar_ler.o
gcc -c extrato_adm.c -o extrato_adm.o
gcc -c saldo_adm.c -o saldo_adm.o
gcc -c cadastrar.c -o cadastrar.o
ar rcs biblioteca.a *.o
gcc -o programa main.c biblioteca.a
```
### Forma de execução em PowerShell e Bash:
```
./programa
```
## Explicação sobre a forma de uso do programa:
    
O programa inicia Pedindo o seu Login (CPF) e Senha.
Após inserir o login e senha correto você sera direcionado ao menu.
No Menu estão presentes as 8 funções que podem ser executadas digitando o seu numero.
> Caso o usuario logue como admin (cpf: 00000000000 senha: 123) ele sera direcionado para um menu do admin
### Investidor
1. Saldo
>Ao utilizar a função "saldo" o programa mostrara o saldo da sua conta
2. Consultar Extrato
>Ao utilizar a função "extrato" o programa mostrara o extrato da sua conta
3. Depositar
>Ao ultilizar a função "depositar" o programa ira pedir o valor que você deseja depositar em Reais
4. Sacar
>Ao ultilizar a função "sacar" o programa ira pedir o valor que você deseja sacar em Reais
5. Comprar Criptomoedas
>Ao ultilizar a função "comprar" o programa ira pedir para você informar qual moeda você deseja comprar
>Apos isso ira pedir o valor que voce deseja comprar em Reais, até que seja digitado um valor valido.
6. Vender Criptomoedas
>Ao ultilizar a função "vender" o programa ira pedir para você informar qual moeda você deseja vender
>Apos isso ira pedir o valor que voce deseja vender em Reais, até que seja digitado um valor valido.
7. Atualizar Cotação
>Ao ultilizar a função "atualizar cotação" o programa ira atualizar a cotação e mostrar os novos valores de cotação
8. Sair
>Ao ultilizar a função ira redirecionar você ao Login ou ira fechar o programa

### Admin
1. Cadastrar Investidor
>Ao utilizar a função "Cadastrar Investidor" é possível entrar com as informações necessárias para criar uma nova conta
2. Excluir Investidor
>Ao utilizar a função "Excluir Investidor" o programa perguntará o CPF do investidor que será excluido, mostrando as informações e pedindo uma confirmação para excluir.
3. Cadastrar Criptomoeda
>Ao ultilizar a função "Cadastrar Criptomoeda" o programa pede as informações de nome, cotação, taxa de compra e taxa de venda
4. Excluir Criptomoeda
>Ao ultilizar a função "Excluir Criptomoeda" o programa ira pedir o nome da criptomoeda que você deseja excluir e pedira a confirmação para excluir.
5. Saldo
>Ao ultilizar a função "Saldo" o programa ira pedir para você informar o CPF de um investidor, mostrando o seu saldo
6. Extrato
>Ao ultilizar a função "Extrato" o programa ira pedir para você informar o CPF de um investidor, mostrando o seu extrato
7. Atualizar Cotação
>Ao ultilizar a função "atualizar cotação" o programa ira atualizar a cotação e mostrar os novos valores de cotação
8. Sair
>Ao ultilizar a função ira redirecionar você ao Login ou ira fechar o programa

## Nomes:   
* Rafael Hideaki Yara RA: 24.124.056-3
* Maurício Yudi Kuniyoshi RA: 24.124.032-4
