//Bibliotecas
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
bool defaultStatusFlag = true;     // Indica o estado atual de uma condi��o qualquer (pode ser login, autentica��o, etc.)
int defaultInteger = 0;            // Inteiro padr�o utilizado como valor inicial
float defaultFloat = 0;            // Float padr�o utilizado como valor inicial
char defaultCharacter = 'a';       // Caractere padr�o utilizado como valor inicial
char defaultStringVector[0];       // Vetor para armazenar uma string
char defaultStringMatrix[0][0];    // Matriz de caracteres para armazenamento de dados bidimensionais

int counterInfiniteLoop = 0;       // Contador que limita o n�mero de itera��es de um loop

char userLogin[12];                // Armazena o login do usu�rio
char userPassword[12];             // Armazena a senha do usu�rio
char userCategory[12];             // Informa a categor�a do usu�rio

char loginList[0][12];             // Lista de logins de at� 0 usu�rios, com 11 caracteres cada
char passwordList[0][12];          // Lista de senhas correspondentes, com 11 caracteres cada
char userCategoryList[0][12];      // Lista de categorias correspondentes a cada usu�rio
int existingAccounts = 0;          // Contador para o n�mero de usu�rios registrados

char bookName[22];                 // Armazena o nome de um livro, com at� 21 caracteres
char bookAuthor[22];               // Armazena o nome do autor do livro, com at� 21 caracteres
char bookCategory[22];             // Armazena a categoria do livro, com at� 21 caracteres

char bookNameList[0][22];          // Lista de nomes de at� 0 livros, cada um com at� 21 caracteres
char bookAuthorList[0][22];        // Lista de autores correspondentes aos livros, com at� 21 caracteres cada
char bookCategoryList[0][22];      // Lista de categorias correspondentes aos livros, com at� 21 caracteres cada
int existinBooks = 0;              // Contador para a quantidade de livros cadastrados


// Limpa o buffer de entrada, descartando todos os caracteres at� a nova linha ou EOF
void ClearBuffer()
{
    int defaultInteger = 1;         // Vari�vel para armazenar os caracteres lidos do buffer
    int counterInfiniteLoop = 0;    // Conta at� chegar em 100000, se isso acontecer ele cancela o loop while

    while(defaultInteger != '\n' && defaultInteger != EOF)
    {
        defaultInteger = getchar();    // L� caracteres do buffer at� encontrar uma nova linha ou o final do arquivo

        counterInfiniteLoop++;

        //Se o loop while atingir 1000 intera��es, ele ser� interrompido, permitindo que o programa continue sem erros.
        if(1000 <= counterInfiniteLoop)
        {
            counterInfiniteLoop=0;

            return;
        }
    }

    return;
}


// Imprime cada caractere da string com um tempo de atraso especificado em Milissegundos.
// Permite personaliza��o da string de finaliza��o. Use "\n" para pular linha e "" ou '\0' para fazer nada.
void PrintWithDelay(const char defaultStringVector[], int delay, char endChar[])
{
    if (defaultStringVector == NULL)    // Verifica se o vetor de caracteres n�o est� vazio
    {
        printf("Erro: O vetor de caracteres fornecido para a fun��o 'PrintWithDelay' � inv�lido.\n");
        return;    // Retorna se a entrada for inv�lida
    }
    else if (delay < 0)    // Verifica se o delay � negativo
    {
        printf("Erro: O valor de delay fornecido para a fun��o 'PrintWithDelay' n�o pode ser negativo.\n");
        return;
    }

    int length = strlen(defaultStringVector);    // Obt�m o comprimento da string

    for (int i = 0; i < length; i++)
    {
        printf("%c", defaultStringVector[i]);    // Imprime o caractere atual
        fflush(stdout);                          // Garante que o caractere seja exibido imediatamente
        Sleep(delay);                            // Pausa a execu��o pelo tempo especificado
    }

    if (endChar != NULL)
    {
        printf("%s", endChar);    // Imprime a string de finaliza��o
        fflush(stdout);
    }

    return;
}


// Muda a cor do texto no console.
// Par�metro: color - valor WORD representando a cor desejada (0 a 15).
// Utilize um n�mero entre 0 e 15 para trocar a cor do texto. O valor 7 � branco.
void SetColor(WORD color)
{
    // Verifica se o valor de cor est� dentro do intervalo permitido
    if (color < 0 || color > 15)
    {
        printf("Erro: O valor da cor deve estar entre 0 e 15.\n");
        return;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    // Obt�m o identificador do console padr�o.

    // Verifica se o handle � v�lido.
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        printf("Erro: falha ao obter o identificador do console.\n");
        return;
    }

    SetConsoleTextAttribute(hConsole, color);    // Define a cor do texto no console.

    return;
}


// Principal
int main()
{
    // Configura��es Iniciais
    srand(time(NULL));                           // Inicializa a semente para gera��o de n�meros aleat�rios
    setlocale(LC_CTYPE, "Portuguese_Brazil");    // Configura a acentua��o e caracteres especiais em portugu�s
    SetColor(15);                                // Define a cor do texto para branco brilhante (gostei dela)

    return 0;    // Finaliza o programa
}
