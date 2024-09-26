//Bibliotecas
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
bool defaultStatusFlag = true;     // Indica o estado atual de uma condição qualquer (pode ser login, autenticação, etc.)
int defaultInteger = 0;            // Inteiro padrão utilizado como valor inicial
float defaultFloat = 0;            // Float padrão utilizado como valor inicial
char defaultCharacter = 'a';       // Caractere padrão utilizado como valor inicial
char defaultStringVector[0];       // Vetor para armazenar uma string
char defaultStringMatrix[0][0];    // Matriz de caracteres para armazenamento de dados bidimensionais

int counterInfiniteLoop = 0;       // Contador que limita o número de iterações de um loop

char userLogin[12];                // Armazena o login do usuário
char userPassword[12];             // Armazena a senha do usuário
char userCategory[12];             // Informa a categoría do usuário

char loginList[0][12];             // Lista de logins de até 0 usuários, com 11 caracteres cada
char passwordList[0][12];          // Lista de senhas correspondentes, com 11 caracteres cada
char userCategoryList[0][12];      // Lista de categorias correspondentes a cada usuário
int existingAccounts = 0;          // Contador para o número de usuários registrados

char bookName[22];                 // Armazena o nome de um livro, com até 21 caracteres
char bookAuthor[22];               // Armazena o nome do autor do livro, com até 21 caracteres
char bookCategory[22];             // Armazena a categoria do livro, com até 21 caracteres

char bookNameList[0][22];          // Lista de nomes de até 0 livros, cada um com até 21 caracteres
char bookAuthorList[0][22];        // Lista de autores correspondentes aos livros, com até 21 caracteres cada
char bookCategoryList[0][22];      // Lista de categorias correspondentes aos livros, com até 21 caracteres cada
int existinBooks = 0;              // Contador para a quantidade de livros cadastrados


// Limpa o buffer de entrada, descartando todos os caracteres até a nova linha ou EOF
void ClearBuffer()
{
    int defaultInteger = 1;         // Variável para armazenar os caracteres lidos do buffer
    int counterInfiniteLoop = 0;    // Conta até chegar em 100000, se isso acontecer ele cancela o loop while

    while(defaultInteger != '\n' && defaultInteger != EOF)
    {
        defaultInteger = getchar();    // Lê caracteres do buffer até encontrar uma nova linha ou o final do arquivo

        counterInfiniteLoop++;

        //Se o loop while atingir 1000 interações, ele será interrompido, permitindo que o programa continue sem erros.
        if(1000 <= counterInfiniteLoop)
        {
            counterInfiniteLoop=0;

            return;
        }
    }

    return;
}


// Imprime cada caractere da string com um tempo de atraso especificado em Milissegundos.
// Permite personalização da string de finalização. Use "\n" para pular linha e "" ou '\0' para fazer nada.
void PrintWithDelay(const char defaultStringVector[], int delay, char endChar[])
{
    if (defaultStringVector == NULL)    // Verifica se o vetor de caracteres não está vazio
    {
        printf("Erro: O vetor de caracteres fornecido para a função 'PrintWithDelay' é inválido.\n");
        return;    // Retorna se a entrada for inválida
    }
    else if (delay < 0)    // Verifica se o delay é negativo
    {
        printf("Erro: O valor de delay fornecido para a função 'PrintWithDelay' não pode ser negativo.\n");
        return;
    }

    int length = strlen(defaultStringVector);    // Obtém o comprimento da string

    for (int i = 0; i < length; i++)
    {
        printf("%c", defaultStringVector[i]);    // Imprime o caractere atual
        fflush(stdout);                          // Garante que o caractere seja exibido imediatamente
        Sleep(delay);                            // Pausa a execução pelo tempo especificado
    }

    if (endChar != NULL)
    {
        printf("%s", endChar);    // Imprime a string de finalização
        fflush(stdout);
    }

    return;
}


// Muda a cor do texto no console.
// Parâmetro: color - valor WORD representando a cor desejada (0 a 15).
// Utilize um número entre 0 e 15 para trocar a cor do texto. O valor 7 é branco.
void SetColor(WORD color)
{
    // Verifica se o valor de cor está dentro do intervalo permitido
    if (color < 0 || color > 15)
    {
        printf("Erro: O valor da cor deve estar entre 0 e 15.\n");
        return;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    // Obtém o identificador do console padrão.

    // Verifica se o handle é válido.
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
    // Configurações Iniciais
    srand(time(NULL));                           // Inicializa a semente para geração de números aleatórios
    setlocale(LC_CTYPE, "Portuguese_Brazil");    // Configura a acentuação e caracteres especiais em português
    SetColor(15);                                // Define a cor do texto para branco brilhante (gostei dela)

    return 0;    // Finaliza o programa
}
