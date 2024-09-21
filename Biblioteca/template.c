
//
//===========================
//=   GUIA DE ESTILO PARA   =
//= PADRONIZAÇÃO DO CÓDIGO  =
//===========================
//

// Bibliotecas básicas
// Todas as bibliotecas são
// importadas no escopo do programa
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

// Separe as constantes globais do imports das bibliotecas
// Constante global em maiúsculo
#define TAM 5

// Variávelis globais e internas das funções em camelCase
char codLivro[] = "100";
char nameLivro[] = "Cálculo A";
char autorLivro[] = "Diva Flaming";

// Estilo de função
// Use sempre SnakeCase e nome compostos para funções (exceto a função [main])
// As chaves vão abaixo da função

void PrintLogLivro()
{
    printf("%s %s %s\n", codLivro, nameLivro, autorLivro);
    // Utilize void e return NULL para funções sem retorno
    return NULL;
}

void FuncContador()
{
    // Declare a variável [ i ] dentro do loop
    for(int i=0; i<=5; i++)
    {
        printf("%d\n", i);
    }

    return NULL;
}

int main_teste()
{
    // Use o parametro [ LC_CTYPE ]
    // no setlocale para menos bugs
    setlocale(LC_CTYPE, "Portuguese");

    PrintLogLivro();
    FuncContador();

    system("PAUSE");
    return 0;
}




