// Bibliotecas
#include <stdio.h>      // Para entrada e saída padrão (printf, scanf, etc.)
#include <stdlib.h>     // Para funções de utilidade geral (malloc, free, rand, srand, etc.)
#include <string.h>     // Para manipulação de strings (strlen, strcpy, strcmp, etc.)
#include <math.h>       // Para funções matemáticas (pow, sqrt, sin, cos, etc.)
#include <windows.h>    // Para funções específicas do Windows (Sleep, API do Windows)
#include <locale.h>     // Para suporte a configurações regionais (setlocale)
#include <time.h>       // Para manipulação de tempo e data (time, clock, difftime, etc.)
#include <conio.h>      // Para funções de console específicas do MS-DOS (getch, clrscr, etc.)


// Constantes Globais
#define MAXLINE 100


// Variáveis Globais
int bookNumber = 0; // Quantidade de Livros Existentes.

struct Book{
    int bookAmount;
    char bookName[30];
    char bookAuthor[30];
    char bookCategory[30];
};

struct Book listBook[1000]; //Lista de Livros

// Funções Gerais para o Embelezamento do Código
void SetColor(WORD color) //Muda a cor do Texto
{
    // Verifica se o valor de cor está dentro do intervalo permitido
    if (color < 0 || color > 15)
    {
        printf("Erro: O valor da cor deve estar entre 0 e 15.\n");
        return;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (hConsole == INVALID_HANDLE_VALUE)
    {
        printf("Erro: falha ao obter o identificador do console.\n");
        return;
    }

    SetConsoleTextAttribute(hConsole, color);    // Define a cor do texto no console.

    return;
}


// Imprime cada caractere da string com um tempo de atraso especificado em Milissegundos.
void PrintWithDelay(const char defaultStringVector[], int delay, char endChar[])
{
    if (defaultStringVector == NULL)
    {
        printf("Erro: O vetor de caracteres fornecido para a função 'PrintWithDelay' é inválido.\n");
        return;
    }
    else if (delay < 0)
    {
        printf("Erro: O valor de delay fornecido para a função 'PrintWithDelay' não pode ser negativo.\n");
        return;
    }

    int length = strlen(defaultStringVector);
    int time = 0;

    for (int i = 0; i < length; i++)
    {
        printf("%c", defaultStringVector[i]);
        fflush(stdout);
        time = rand()%delay+25;
        Sleep(time);

        if (kbhit()) // Se apertar Enter Imprime tudo de uma Vez
        {
            char ch = getch();
            if (ch == 13)
            {
                for(i; i<length; i++)
                {
                    printf("%c", defaultStringVector[i]);
                    fflush(stdout);
                }
            break;
            }
        }
    }

    if (endChar != NULL)
    {
        printf("%s", endChar);
        fflush(stdout);
    }

    return;
}


// Inicialização e Partes do Programa
void Menu()
{
    int intMenu=-1, error=0;

    while(intMenu > 5 || intMenu < 1)
    {
        if(error == 0)
        {
            printf("Escolha a função desejada\n\n"
           "1 - Listagem dos Livros\n"
           "2 - Buscar Livro\n"
           "3 - Adicionar Livro\n"
           "4 - Remover Livro\n"
           "5 - Editar Livro\n"
           "\n\n[Digite apenas números...]\n\nResposta: ");
        }
        else
        {
            printf("\n\nErro, Digite Novamente: ");
        }
        scanf("%d", &intMenu);
        error++;
        if (error>10)
        {
            printf("\n\nErro geral!");
            Sleep(5000);
            break;
        }
    }
    error = 0;
    system("CLS");

    switch(intMenu)
    {
        case 1:
            //ListAll();
            return;
        case 2:
            //SearchBook();
            return;
        case 3:
            //AddBook();
            return;
        case 4:
            //RemoveBook();
            return;
        case 5:
            //EditBook();
            return;
        //default:
            //PrintWithDelay("\nOpção Inválida...",100,"");
            //system("PAUSE");
            //return;
    }
}
/*
//Buscar Livro
void SearchBook()
{
    int bookFound = 0;  // Flag para indicar se algum livro foi encontrado
    int c=0;
    char l;
    char name[100];

    printf("Digite o nome do Livro que deseja buscar: ");
    while (((l = getche()) != '\r') && (c<100))
    {
        name[c] = l;
        c++;
    }
    name[c] = '\0';

    PrintWithDelay("\n\nBuscando pelo Livro...", 80, "");

    Sleep(1000);
    system("cls");
    printf("Correspondencias com %s", name);
    // Verifica todos os livros cadastrados
    for (int i = 0; i < 101; i++)
    {
        Sleep(1000);
        if ((strcmp(bookNameList[i], name)) == 0)
        {
            // Exibe as informações do livro encontrado
            printf("\n\nLivro Encontrado: \n");
            printf("Nome: %s\n", bookNameList[i]);
            printf("Autor: %s\n", bookAuthorList[i]);
            printf("Categoria: %d\n", bookCategoryList[i]);
            bookFound = 1;  // Marca que ao menos um livro foi encontrado
        }
    }
    printf("\n\n");
    // Se nenhum livro foi encontrado, exibe uma mensagem
    if (bookFound == 0)
    {
        printf("Nenhum livro correspondente foi encontrado.\n");
    }
}
/*
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
}*/


// Principal
int main()
{
    // Configurações Iniciais
    srand(time(NULL));                         // Inicializa a semente para geração de números aleatórios
    setlocale(LC_ALL,"Portuguese");            // Configura a acentuação e caracteres especiais em português
    SetColor(15);                              // Define a cor do texto para branco brilhante

    while(1)
    {
        Menu();
    }

    return 0;    // Finaliza o programa
}
