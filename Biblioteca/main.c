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
#define MAXLINE 100


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

char bookName[30];                 // Armazena o nome de um livro, com até 21 caracteres
char bookAuthor[30];               // Armazena o nome do autor do livro, com até 21 caracteres
char bookCategory[30];                  // Armazena a categoria do livro, com até 21 caracteres
int bookQuant;

char bookNameList[MAXLINE][30] = {"MATEMATICA","MATEMATICA"};          // Lista de nomes de até 0 livros, cada um com até 21 caracteres
char bookAuthorList[MAXLINE][30] = {"CALCULO","CALCULO"};        // Lista de autores correspondentes aos livros, com até 21 caracteres cada
char bookCategoryList[MAXLINE][30] = {"PORTUGUES","PORTUGUES"};           // Lista de categorias correspondentes aos livros, com até 21 caracteres cada
int bookQuantList[MAXLINE]= {10, 10};               // Lista da Quantidade existende de livros
int existinBooks = 0;              // Contador para a quantidade de livros cadastrados


int bookBorrowedStatus[100];       // Lista global para indicar se o livro está emprestado (0 = não, 1 = sim)
char borrowedByUserList[100][12];  // Lista global para armazenar o nome do usuário que pegou o livro emprestado (máx. 100 livros e 11 caracteres por nome)

//Variáveis auxiliares
int i,j,k;
char ch;


//Interface provisória [ALTERE ASSIM QUE POSSÍVEL!!!!!]
//
//   Implementada apenas para testes das funcionalidades
//   das matrizes
//

void OperacionalSpaceMenu()
{
    int intMenu;
    printf("Escolha a função desejada\n\n"
           "1 - Listagem dos Livros\n"
           "2 - Adicionar Livro\n"
           "3 - Remover Livro\n"
           "4 - Editar Livro\n"
           "\n\n[Digite apenas números...]"
          );
    scanf("%d", &intMenu);
    system("CLS");

    switch(intMenu)
    {
        case 1:
            ListAll();
            return;
        case 2:
            AddBook();
            return;
        case 3:
            RemoveBook();
            return;
        case 4:
            EditBook();
            return;
        default:
            PrintWithDelay("\nOpção Inválida...",100,"");
            system("PAUSE");
            return;
    }
}

//Operações nas matrizes
void ListAll() //Lista todos os livros válidos
{
    existinBooks = 0;
    for(i=0; i<MAXLINE; i++)
    {
        if(strlen(bookNameList[i])!=0)
        {
            printf("%.3d || %s || %s || %s || %3d\n",i+1, bookNameList[i], bookAuthorList[i], bookCategoryList[i], bookQuantList[i]);
            existinBooks++;
        }
    }
    printf("Total de Livros: %d", existinBooks);
    printf("\n");
    system("PAUSE");
    return;
}

void AddBook() //Adiciona livros
{
    for(i=0; i<MAXLINE; i++)
    {
        if(strlen(bookNameList[i]) == 0) //Procura o primeiro endereço vazio na Matriz
        {
            //Adiciona o livro na matriz
            j=0;
            printf("\nNome do livro: ");
            while(((ch = getche()) != '\r') && (j<sizeof(bookName)-1))
            {
                bookNameList[i][j] = ch;
                j++;
            }
            //Adiciona o autor na matriz
            j=0;
            printf("\nNome do autor: ");
            while(((ch = getche()) != '\r') && (j<sizeof(bookAuthor)-1))
            {
                bookAuthorList[i][j] = ch;
                j++;
            }
            //Adiciona a categoria na matriz
            j=0;
            printf("\nCategoria: ");
            while(((ch = getche()) != '\r') && (j<sizeof(bookAuthor)-1))
            {
                bookCategoryList[i][j] = ch;
                j++;
            }
            //Adiciona a quantidade de livros cadastrados
            printf("\nQuantidade: ");
            scanf("%d", &bookQuant);
            bookQuantList[i] = bookQuant;

            return;
        }
    }
    return;
}

void RemoveBook() // Anula elementos da Coluna
{
    int bookId;
    printf("\nDigite o ID para remover: ");
    scanf("%d", &bookId);

    for(i=0; i<MAXLINE; i++)
    {
        if(i == bookId-1)
        {
            printf("\n%d %d\n",i, bookId);
            j=0;
            while(j<sizeof(bookName)-1)
            {
                bookNameList[i][j] = NULL;
                bookAuthorList[i][j] = NULL;
                bookCategoryList[i][j] = NULL;
                j++;
            }
            bookQuantList[i] = 0;
            return;
        }
    }
    return;
}

void EditBook() // Edita elementos da Coluna
{
    int bookId;
    printf("\nDigite o ID para Editar: ");
    scanf("%d", &bookId);
    if(strlen(bookNameList[bookId])!=0)
    {
        for(i=0; i<MAXLINE; i++)
        {
            if(i == bookId-1)
            {
                //Edita o nome do livro na matriz
                j=0;
                printf("\nDeseja alterar nome do livro? [s/S para sim || ENTER para pular]");
                if((ch = getche()) != '\r')
                {
                    k=0;
                    while(k<sizeof(bookName)-1) // Limpa o nome da linha
                    {
                        bookNameList[i][k] = NULL;
                        k++;
                    }
                    printf("\nNome do livro: ");
                    while(((ch = getche()) != '\r') && (j<sizeof(bookName)-1))
                    {
                        bookNameList[i][j] = ch;
                        j++;
                    }
                }

                //Edita o autor do livro na matriz
                j = 0;
                printf("\nDeseja alterar o autor do livro? [s/S para sim || ENTER para pular]");
                if((ch = getche()) != '\r')
                {
                    k=0;
                    while(k<sizeof(bookAuthor)-1) // Limpa o autor da linha
                    {
                        bookAuthorList[i][k] = NULL;
                        k++;
                    }
                    printf("\nAutor do livro: ");
                    while(((ch = getche()) != '\r') && (j<sizeof(bookName)-1))
                    {
                        bookAuthorList[i][j] = ch;
                        j++;
                    }
                }

                //Edita a categoria do livro na matriz
                j = 0;
                printf("\nDeseja alterar a categoria do livro? [s/S para sim || ENTER para pular]");
                if((ch = getche()) != '\r')
                {
                    printf("\nAutor do livro: ");
                    k = 0;
                    while(k<sizeof(bookCategory)-1) // Limpa a categoria da linha
                    {
                        bookCategoryList[i][k] = NULL;
                        k++;
                    }
                    while(((ch = getche()) != '\r') && (j<sizeof(bookName)-1))
                    {
                        bookAuthorList[i][j] = ch;
                        j++;
                    }
                }

                //Edita a quantidade de livros na matriz
                printf("\nDeseja alterar a quantidade de livros? [s/S para sim || ENTER para pular]");
                if((ch = getche()) != '\r')
                {
                    printf("\nQuantidade de livros: ");
                    scanf("%d", &bookQuant);
                    bookQuantList[i] = bookQuant;
                }
            }
        }
    }
    else
    {
        PrintWithDelay("\nDigite um valor válido [Verifique na lista de livros]",100,"");
        system("PAUSE");
    }
    return;
}


// Limpa o buffer de entrada, descartando todos os caracteres até a nova linha ou EOF
void ClearBuffer()
{
    int defaultInteger = 1;         // Variável para armazenar os caracteres lidos do buffer
    int counterInfiniteLoop = 0;    // Conta até chegar em 100000, se isso acontecer ele cancela o loop while

    while(defaultInteger != '\n' && defaultInteger != EOF)
    {
        defaultInteger = getchar();    // Lê caracteres do buffer até encontrar uma nova linha ou o final do arquivo

        counterInfiniteLoop++;

        // Se o loop while atingir 1000 interações, ele será interrompido, permitindo que o programa continue sem erros.
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

//Buscar Livro
void SearchBook(char name[], char author[], int category)
{
    bool bookFound = false;  // Flag para indicar se algum livro foi encontrado

    // Verifica todos os livros cadastrados
    for (int i = 0; i < existinBooks; i++)
    {
        // Verifica as condições: nome do livro, autor e categoria podem ser fornecidos individualmente ou juntos.
        bool nameMatch = (strlen(name) == 0 || strcmp(bookNameList[i], name) == 0);  // Verifica se o nome corresponde ou se foi ignorado
        bool authorMatch = (strlen(author) == 0 || strcmp(bookAuthorList[i], author) == 0);  // Verifica se o autor corresponde ou se foi ignorado
        bool categoryMatch = (category == -1 || bookCategoryList[i] == category);  // Verifica se a categoria corresponde ou se foi ignorada

        // Se algum dos critérios for fornecido e corresponder, o livro é considerado um possível resultado
        if (nameMatch && authorMatch && categoryMatch)
        {
            // Exibe as informações do livro encontrado
            printf("Livro Encontrado: \n");
            printf("Nome: %s\n", bookNameList[i]);
            printf("Autor: %s\n", bookAuthorList[i]);
            printf("Categoria: %d\n\n", bookCategoryList[i]);
            bookFound = true;  // Marca que ao menos um livro foi encontrado
        }
    }

    // Se nenhum livro foi encontrado, exibe uma mensagem
    if (!bookFound)
    {
        printf("Nenhum livro correspondente foi encontrado.\n");
    }
}


// Ver se o livro esta emprestado
void CheckBorrower(char name[], char author[], int category)
{
    bool bookFound = false;  // Flag para indicar se o livro foi encontrado

    // Verifica todos os livros cadastrados
    for (int i = 0; i < existinBooks; i++)
    {
        // Verifica as condições: nome do livro, autor e categoria podem ser fornecidos individualmente ou juntos
        bool nameMatch = (strlen(name) == 0 || strcmp(bookNameList[i], name) == 0);  // Verifica se o nome corresponde ou foi ignorado
        bool authorMatch = (strlen(author) == 0 || strcmp(bookAuthorList[i], author) == 0);  // Verifica se o autor corresponde ou foi ignorado
        bool categoryMatch = (category == -1 || bookCategoryList[i] == category);  // Verifica se a categoria corresponde ou foi ignorada

        if (nameMatch && authorMatch && categoryMatch)
        {
            bookFound = true;  // Marca que o livro foi encontrado

            // Verifica se o livro está emprestado
            if (bookBorrowedStatus[i] == 1)  // Se o status for 1, o livro está emprestado
            {
                printf("O livro '%s' foi emprestado por: %s\n", bookNameList[i], borrowedByUserList[i]);
            }
            else
            {
                printf("O livro '%s' está disponível.\n", bookNameList[i]);
            }

            break;  // Para a busca após encontrar o livro
        }
    }

    if (!bookFound)
    {
        printf("Erro: Nenhum livro correspondente foi encontrado.\n");
    }
}


// Pedir livro emprestado
bool BorrowBook(char name[], char author[], int category)
{
    bool bookBorrowed = false;  // Flag para indicar se o empréstimo foi realizado
    bool bookFound = false;     // Flag para indicar se algum livro foi encontrado

    // Verifica todos os livros cadastrados
    for (int i = 0; i < existinBooks; i++)
    {
        // Verifica as condições: nome do livro, autor e categoria podem ser fornecidos individualmente ou juntos
        bool nameMatch = (strlen(name) == 0 || strcmp(bookNameList[i], name) == 0);  // Verifica se o nome corresponde ou foi ignorado
        bool authorMatch = (strlen(author) == 0 || strcmp(bookAuthorList[i], author) == 0);  // Verifica se o autor corresponde ou foi ignorado
        bool categoryMatch = (category == -1 || bookCategoryList[i] == category);  // Verifica se a categoria corresponde ou foi ignorada

        // Se algum dos critérios fornecidos corresponder, o livro é considerado um possível resultado
        if (nameMatch && authorMatch && categoryMatch)
        {
            bookFound = true;  // Marca que ao menos um livro foi encontrado

            // Verifica a disponibilidade do livro
            if (bookBorrowedStatus[i] == 0)  // Se o status do livro for 0, está disponível para empréstimo
            {
                printf("Empréstimo realizado com sucesso para o livro: %s, Autor: %s\n", bookNameList[i], bookAuthorList[i]);

                // Atualiza o status do livro para "emprestado"
                bookBorrowedStatus[i] = 1;  // Marca o livro como emprestado
                bookBorrowed = true;  // Marca que o empréstimo foi realizado

                break;  // Para o loop após encontrar e emprestar o livro
            }
            else
            {
                printf("Erro: O livro '%s' já está emprestado.\n", bookNameList[i]);
            }
        }
    }

    if (!bookFound)
    {
        printf("Erro: Nenhum livro correspondente foi encontrado.\n");
    }
    else if (!bookBorrowed)
    {
        printf("Erro: O livro já foi emprestado.\n");
    }

    return bookBorrowed;  // Retorna verdadeiro se o empréstimo foi bem-sucedido, falso caso contrário
}

// Devolver o livro emprestado
bool ReturnBook(char name[], char author[], int category, char username[])
{
    bool bookReturned = false;  // Flag para indicar se o livro foi devolvido
    bool bookFound = false;     // Flag para indicar se o livro foi encontrado

    // Verifica todos os livros cadastrados
    for (int i = 0; i < existinBooks; i++)
    {
        // Verifica as condições: nome do livro, autor e categoria podem ser fornecidos individualmente ou juntos
        bool nameMatch = (strlen(name) == 0 || strcmp(bookNameList[i], name) == 0);  // Verifica se o nome corresponde ou foi ignorado
        bool authorMatch = (strlen(author) == 0 || strcmp(bookAuthorList[i], author) == 0);  // Verifica se o autor corresponde ou foi ignorado
        bool categoryMatch = (category == -1 || bookCategoryList[i] == category);  // Verifica se a categoria corresponde ou foi ignorada

        if (nameMatch && authorMatch && categoryMatch)
        {
            bookFound = true;  // Marca que o livro foi encontrado

            // Verifica se o livro está emprestado
            if (bookBorrowedStatus[i] == 1)  // Se o status for 1, o livro está emprestado
            {
                // Verifica se o usuário que está devolvendo é o mesmo que emprestou
                if (strcmp(borrowedByUserList[i], username) == 0)
                {
                    printf("Devolução bem-sucedida: O livro '%s' foi devolvido por %s.\n", bookNameList[i], username);

                    // Atualiza o status do livro para disponível
                    bookBorrowedStatus[i] = 0;  // Marca o livro como disponível
                    strcpy(borrowedByUserList[i], "");  // Limpa o nome do usuário que pegou o livro

                    bookReturned = true;  // Marca que o livro foi devolvido

                    break;  // Para o loop após encontrar e devolver o livro
                }
                else
                {
                    printf("Erro: O livro '%s' foi emprestado por %s, não por %s.\n", bookNameList[i], borrowedByUserList[i], username);
                }
            }
            else
            {
                printf("Erro: O livro '%s' não está emprestado.\n", bookNameList[i]);
            }
        }
    }

    if (!bookFound)
    {
        printf("Erro: Nenhum livro correspondente foi encontrado.\n");
    }
    else if (!bookReturned)
    {
        printf("Erro: A devolução não pôde ser concluída.\n");
    }

    return bookReturned;  // Retorna verdadeiro se a devolução foi bem-sucedida, falso caso contrário
}


// Principal
int main()
{
    // Configurações Iniciais
    srand(time(NULL));                           // Inicializa a semente para geração de números aleatórios
    setlocale(LC_ALL,"Portuguese");            // Configura a acentuação e caracteres especiais em português
    SetColor(15);                                // Define a cor do texto para branco brilhante

    while(1)
    {
        OperacionalSpaceMenu();
    }

    return 0;    // Finaliza o programa
}

