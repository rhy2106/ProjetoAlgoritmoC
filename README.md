Objetivo do projeto:
   
    Criar um programa que simule um banco, onde é possivel realizar operações de saque, deposito, compras e vendas de criptomoedas
    
Forma de compilação em PowerShell:
    
     gcc -c funcoes.c -o funcoes.o                                      
     gcc -c atualizar.c -o atualizar.o  
     gcc -c comprar.c -o comprar.o    
     gcc -c vender.c -o vender.o  
     gcc -c saldo.c -o saldo.o  
     gcc -c depositar.c -o depositar.o
     gcc -c extrato.c -o extrato.o    
     gcc -c sacar.c -o sacar.o    
     gcc -c login.c -o login.o
     ar rcs sla.a funcoes.o atualizar.o comprar.o vender.o saldo.o depositar.o extrato.o sacar.o logar.o
     gcc -o converter converter.c sla.a
     gcc -o programa projeto.c sla.a
Forma de execução em PowerShell:
   
      ./converter
      ./programa

Explicação sobre a forma de uso do programa:
    
    O programa inicia Pedindo o seu Login (CPF) e Senha.
    Após inserir o login e senha correto você sera direcionado ao menu.
    No Menu estão presentes as 8 funções que podem ser executadas digitando o seu numero.
    1 - Consultar Saldo
        Ao utilizar a função "saldo" o programa mostrara o saldo da sua conta
    2 - Consultar Extrato
        Ao utilizar a função "extrato" o programa mostrara o extrato da sua conta
    3 - Depositar
        Ao ultilizar a função "depositar" o programa ira pedir o valor que você deseja depositar em Reais
    4 - Sacar
        Ao ultilizar a função "sacar" o programa ira pedir o valor que você deseja sacar em Reais
    5 - Comprar Criptomoedas
        Ao ultilizar a função "comprar" o programa ira pedir para você informar qual moeda você deseja comprar
        Apos isso ira pedir o valor que voce deseja comprar em Reais, até que seja digitado um valor valido.
    6 - Vender Criptomoedas
        Ao ultilizar a função "vender" o programa ira pedir para você informar qual moeda você deseja vender
        Apos isso ira pedir o valor que voce deseja vender em Reais, até que seja digitado um valor valido.
    7 - Atualizar Cotação
        Ao ultilizar a função "atualizar cotação" o programa ira atualizar a cotação e mostrar os novos valores de cotação
    8 - Sair
        Ao ultilizar a função ira redirecionar você ao Login ou ira fechar o programa

Nomes:
   
    Rafael Hideaki Yara RA: 24.124.056-3
    Maurício Yudi Kuniyoshi RA: 24.124.032-4
