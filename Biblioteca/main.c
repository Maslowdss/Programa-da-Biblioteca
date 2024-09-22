// Bibliotecas
#include <stdio.h>      // Para entrada e saída padrão (printf, scanf, etc.)
#include <stdlib.h>     // Para funções de utilidade geral (malloc, free, rand, srand, etc.)
#include <string.h>     // Para manipulação de strings (strlen, strcpy, strcmp, etc.)
#include <ctype.h>      // Para manipulação de caracteres (isalpha, isdigit, tolower, etc.)
#include <stdbool.h>    // Para uso do tipo booleano (true, false)
#include <limits.h>     // Para limites de tipos inteiros (ex: INT_MAX, INT_MIN)
#include <float.h>      // Para limites de tipos de ponto flutuante (ex: FLT_MAX, DBL_MIN)
#include <math.h>       // Para funções matemáticas (pow, sqrt, sin, cos, etc.)
#include <time.h>       // Para manipulação de tempo e data (time, clock, difftime, etc.)
#include <locale.h>     // Para suporte a configurações regionais (setlocale)
#include <conio.h>      // Para funções de console específicas do MS-DOS (getch, clrscr, etc.)
#include <windows.h>    // Para funções específicas do Windows (Sleep, API do Windows)
#include <errno.h>      // Para tratamento de erros (define macros para códigos de erro)


// Constantes Globais
#define CONSTANT 0    // Definição de uma constante global. Atualmente, não possui funcionalidade atribuída.


// Variáveis Globais
// As variáveis padrão/default são utilizadas para evitar a criação excessiva de variáveis ao longo do programa.
// Elas são projetadas para usos temporários e podem perder seu valor logo após a utilização.
bool defaultStatusFlag = false;          // Indica o estado atual de uma condição qualquer (pode ser login, autenticação, etc.)
int defaultInteger = -1;                 // Inteiro padrão utilizado como valor inicial
float defaultFloat = -1.1;               // Float padrão utilizado como valor inicial
char defaultCharacter = 'a';             // Caractere padrão utilizado como valor inicial
char defaultStringVector[1000];          // Buffer para armazenar uma string longa
char defaultStringMatrix[1000][1000];    // Matriz de caracteres para armazenamento de dados bidimensionais

char userLogin[25];                      // Armazena o login do usuário
char userPassword[25];                   // Armazena a senha do usuário
char userCategory[25];                   // Informa a categoría do usuário

char loginList[200][20];                 // Lista de logins de até 200 usuários, com 20 caracteres cada
char passwordList[200][20];              // Lista de senhas correspondentes, com 20 caracteres cada
char userCategoryList[200][20];          // Lista de categorias correspondentes a cada usuário
int existingAccounts = 0;                // Contador para o número de usuários registrados

char bookName[100];                      // Armazena o nome de um livro, com até 100 caracteres
char bookAuthor[100];                    // Armazena o nome do autor do livro, com até 100 caracteres
char bookCategory[20];                   // Armazena a categoria do livro, com até 20 caracteres

char bookNameList[200][100];             // Lista de nomes de até 200 livros, cada um com até 100 caracteres
char bookAuthorList[200][100];           // Lista de autores correspondentes aos livros, com até 100 caracteres cada
char bookCategoryList[200][20];          // Lista de categorias correspondentes aos livros, com até 20 caracteres cada


// Limpa o buffer de entrada, descartando todos os caracteres até a nova linha ou EOF
void ClearBuffer()
{
    defaultInteger = 1;    // Variável para armazenar os caracteres lidos do buffer

    // Lê caracteres do buffer até encontrar uma nova linha ou o final do arquivo
    while(defaultInteger != '\n' && defaultInteger != EOF)
    {
        defaultInteger = getchar();
    }

    return;
}


// Imprime cada caractere da string com um tempo de atraso especificado em Milissegundos.
// Permite personalização da string de finalização. Use "\n" para pular linha e "" para fazer nada.
void PrintWithDelay(const char defaultStringVector[], int delay, char endChar[])
{
    // Verifica se o vetor de caracteres não está vazio
    if (defaultStringVector == NULL || delay < 0)
    {
        printf("Erro: string inválida ou atraso negativo.\n");
        return;    // Retorna se a entrada for inválida
    }

    int length = strlen(defaultStringVector);    // Obtém o comprimento da string

    for (int i = 0; i < length; i++) {
        printf("%c", defaultStringVector[i]);   // Imprime o caractere atual
        fflush(stdout);                         // Garante que o caractere seja exibido imediatamente
        Sleep(delay);                           // Pausa a execução pelo tempo especificado
    }

    printf("%s", endChar);    // Imprime o string de finalização
    fflush(stdout);

    return;
}


// Muda a cor do texto no console
// Parâmetro: color - valor WORD representando a cor desejada
// Escreva um número de 0 a 15 para a trocar a cor de texto. 7 é branco
void SetColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Obtém o identificador do console padrão.

    // Verifica se o handle é válido.
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
    srand(time(NULL));    // Define a semente do gerador de números aleatórios com base no tempo atual
    setlocale(LC_CTYPE, "Portuguese_Brazil");    // Permitinde o uso de caracteres acentuados

    // Exemplo do uso das funções, retirar depois.
    PrintWithDelay("[Projeto da Biblioteca]", 100, "\n\n"); //Exemplo do uso da função, a linha pode ser retirada
    printf("= Criadores =\n\n");
    SetColor(6);
    PrintWithDelay("1 - Arthur", 80, "\n");
    SetColor(10);
    PrintWithDelay("2 - Rebeca", 80, "\n");
    SetColor(9);
    PrintWithDelay("3 - Maslow", 80, "");
    SetColor(7);

    Sleep(3000);
    printf("\n\nGalera, lembrar de modificar essa introdução depois, isso é so um exemplo das funções que eu criei.\n\n");
    // Apaga daqui até o inicio do exemplo

    return 0;
}
