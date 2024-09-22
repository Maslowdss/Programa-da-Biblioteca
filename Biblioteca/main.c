// Bibliotecas
#include <stdio.h>      // Para entrada e sa�da padr�o (printf, scanf, etc.)
#include <stdlib.h>     // Para fun��es de utilidade geral (malloc, free, rand, srand, etc.)
#include <string.h>     // Para manipula��o de strings (strlen, strcpy, strcmp, etc.)
#include <ctype.h>      // Para manipula��o de caracteres (isalpha, isdigit, tolower, etc.)
#include <stdbool.h>    // Para uso do tipo booleano (true, false)
#include <limits.h>     // Para limites de tipos inteiros (ex: INT_MAX, INT_MIN)
#include <float.h>      // Para limites de tipos de ponto flutuante (ex: FLT_MAX, DBL_MIN)
#include <math.h>       // Para fun��es matem�ticas (pow, sqrt, sin, cos, etc.)
#include <time.h>       // Para manipula��o de tempo e data (time, clock, difftime, etc.)
#include <locale.h>     // Para suporte a configura��es regionais (setlocale)
#include <conio.h>      // Para fun��es de console espec�ficas do MS-DOS (getch, clrscr, etc.)
#include <windows.h>    // Para fun��es espec�ficas do Windows (Sleep, API do Windows)
#include <errno.h>      // Para tratamento de erros (define macros para c�digos de erro)


// Constantes Globais
#define CONSTANT 0    // Defini��o de uma constante global. Atualmente, n�o possui funcionalidade atribu�da.


// Vari�veis Globais
// As vari�veis padr�o/default s�o utilizadas para evitar a cria��o excessiva de vari�veis ao longo do programa.
// Elas s�o projetadas para usos tempor�rios e podem perder seu valor logo ap�s a utiliza��o.
bool defaultStatusFlag = false;          // Indica o estado atual de uma condi��o qualquer (pode ser login, autentica��o, etc.)
int defaultInteger = -1;                 // Inteiro padr�o utilizado como valor inicial
float defaultFloat = -1.1;               // Float padr�o utilizado como valor inicial
char defaultCharacter = 'a';             // Caractere padr�o utilizado como valor inicial
char defaultStringVector[1000];          // Buffer para armazenar uma string longa
char defaultStringMatrix[1000][1000];    // Matriz de caracteres para armazenamento de dados bidimensionais

char userLogin[25];                      // Armazena o login do usu�rio
char userPassword[25];                   // Armazena a senha do usu�rio
char userCategory[25];                   // Informa a categor�a do usu�rio

char loginList[200][20];                 // Lista de logins de at� 200 usu�rios, com 20 caracteres cada
char passwordList[200][20];              // Lista de senhas correspondentes, com 20 caracteres cada
char userCategoryList[200][20];          // Lista de categorias correspondentes a cada usu�rio
int existingAccounts = 0;                // Contador para o n�mero de usu�rios registrados

char bookName[100];                      // Armazena o nome de um livro, com at� 100 caracteres
char bookAuthor[100];                    // Armazena o nome do autor do livro, com at� 100 caracteres
char bookCategory[20];                   // Armazena a categoria do livro, com at� 20 caracteres

char bookNameList[200][100];             // Lista de nomes de at� 200 livros, cada um com at� 100 caracteres
char bookAuthorList[200][100];           // Lista de autores correspondentes aos livros, com at� 100 caracteres cada
char bookCategoryList[200][20];          // Lista de categorias correspondentes aos livros, com at� 20 caracteres cada


// Limpa o buffer de entrada, descartando todos os caracteres at� a nova linha ou EOF
void ClearBuffer()
{
    defaultInteger = 1;    // Vari�vel para armazenar os caracteres lidos do buffer

    // L� caracteres do buffer at� encontrar uma nova linha ou o final do arquivo
    while(defaultInteger != '\n' && defaultInteger != EOF)
    {
        defaultInteger = getchar();
    }

    return;
}


// Imprime cada caractere da string com um tempo de atraso especificado em Milissegundos.
// Permite personaliza��o da string de finaliza��o. Use "\n" para pular linha e "" para fazer nada.
void PrintWithDelay(const char defaultStringVector[], int delay, char endChar[])
{
    // Verifica se o vetor de caracteres n�o est� vazio
    if (defaultStringVector == NULL || delay < 0)
    {
        printf("Erro: string inv�lida ou atraso negativo.\n");
        return;    // Retorna se a entrada for inv�lida
    }

    int length = strlen(defaultStringVector);    // Obt�m o comprimento da string

    for (int i = 0; i < length; i++) {
        printf("%c", defaultStringVector[i]);   // Imprime o caractere atual
        fflush(stdout);                         // Garante que o caractere seja exibido imediatamente
        Sleep(delay);                           // Pausa a execu��o pelo tempo especificado
    }

    printf("%s", endChar);    // Imprime o string de finaliza��o
    fflush(stdout);

    return;
}


// Muda a cor do texto no console
// Par�metro: color - valor WORD representando a cor desejada
// Escreva um n�mero de 0 a 15 para a trocar a cor de texto. 7 � branco
void SetColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Obt�m o identificador do console padr�o.

    // Verifica se o handle � v�lido.
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        printf("Erro ao obter o identificador do console.\n");
        return;
    }

    SetConsoleTextAttribute(hConsole, color); // Define a cor do texto no console.

    return;
}


// Principal
int main()
{
    srand(time(NULL));    // Define a semente do gerador de n�meros aleat�rios com base no tempo atual
    setlocale(LC_CTYPE, "Portuguese_Brazil");    // Permitinde o uso de caracteres acentuados

    // Exemplo do uso das fun��es, retirar depois.
    PrintWithDelay("[Projeto da Biblioteca]", 100, "\n\n"); //Exemplo do uso da fun��o, a linha pode ser retirada
    printf("= Criadores =\n\n");
    SetColor(6);
    PrintWithDelay("1 - Arthur", 80, "\n");
    SetColor(10);
    PrintWithDelay("2 - Rebeca", 80, "\n");
    SetColor(9);
    PrintWithDelay("3 - Maslow", 80, "");
    SetColor(7);

    Sleep(3000);
    printf("\n\nGalera, lembrar de modificar essa introdu��o depois, isso � so um exemplo das fun��es que eu criei.\n\n");
    // Apaga daqui at� o inicio do exemplo

    return 0;
}
