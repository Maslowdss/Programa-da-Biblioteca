
//
//===========================
//=   GUIA DE ESTILO PARA   =
//= PADRONIZA��O DO C�DIGO  =
//===========================
//

// Bibliotecas b�sicas
// Todas as bibliotecas s�o
// importadas no escopo do programa
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

// Separe as constantes globais do imports das bibliotecas
// Constante global em mai�sculo
#define TAM 5

// Vari�velis globais e internas das fun��es em camelCase
char codLivro[] = "100";
char nameLivro[] = "C�lculo A";
char autorLivro[] = "Diva Flaming";

// Estilo de fun��o
// Use sempre SnakeCase e nome compostos para fun��es (exceto a fun��o [main])
// As chaves v�o abaixo da fun��o

void PrintLogLivro()
{
    printf("%s %s %s\n", codLivro, nameLivro, autorLivro);
    // Utilize void e return NULL para fun��es sem retorno
    return NULL;
}

void FuncContador()
{
    // Declare a vari�vel [ i ] dentro do loop
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




