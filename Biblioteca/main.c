// -----------------------------------------------------------------------------------------------------

// Bibliotecas e Arquivos
#include <stdio.h>         // Para entrada e saída padrão (printf, scanf, etc.)
#include <stdlib.h>        // Para funções de utilidade geral (malloc, free, rand, srand, etc.)
#include <string.h>        // Para manipulação de strings (strlen, strcpy, strcmp, etc.)
#include <math.h>          // Para funções matemáticas (pow, sqrt, sin, cos, etc.)
#include <windows.h>       // Para funções específicas do Windows (Sleep, API do Windows)
#include <locale.h>        // Para suporte a configurações regionais (setlocale)
#include <time.h>          // Para manipulação de tempo e data (time, clock, difftime, etc.)
#include <conio.h>         // Para funções de console específicas do MS-DOS (getch, clrscr, etc.)

// -----------------------------------------------------------------------------------------------------

// Variáveis Globais
int bookNumber = 0;                 // Quantidade de Livros Existentes
int userNumber = 0;                 // Quantidade de Usuários Existentes
int currentLogin = -1;              // Usuário Atual Logado no Sistema
int Mostborrowedbooks[1000];        // Vetor que i é o indice do livro, escreva quantas vezes foi emprestado

struct Book
{
    int bookAmount;
    char bookName[100];
    char bookAuthor[100];
    char bookCategory[100];
};

struct User
{
    int category;              // Adm = 1 e Usuário = 0
    int bookE; // Quantidade de livos emprestados.
    char userName[100];
    char userPassword[100];
    char userGraduation[100];
    struct Book userListBook[10];
};

struct Book listBook[1000];    // Lista de Livros
struct User listUser[1000];    // Lista de Usuários

// -----------------------------------------------------------------------------------------------------

// Evite mexer nessa seção!
// Funções Gerais para o Embelezamento do Código e inicializações do sistema.
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
                i++;
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

void AddInitialBooksAndUser()
{
    for (int i = 0; i<1000; i++)
    {
        Mostborrowedbooks[i] = 0;
    }

    listBook[0].bookAmount = rand()%3+1;
    strcpy(listBook[0].bookName, "Calculo 1");
    strcpy(listBook[0].bookAuthor, "Guidorizzi");
    strcpy(listBook[0].bookCategory, "Matemática");

    listBook[1].bookAmount = rand()%3+1;
    strcpy(listBook[1].bookName, "Calculo 2");
    strcpy(listBook[1].bookAuthor, "Guidorizzi");
    strcpy(listBook[1].bookCategory, "Matemática");

    listBook[2].bookAmount = rand()%3+1;
    strcpy(listBook[2].bookName, "Calculo 3");
    strcpy(listBook[2].bookAuthor, "Guidorizzi");
    strcpy(listBook[2].bookCategory, "Matemática");

    listBook[3].bookAmount = rand()%3+1;
    strcpy(listBook[3].bookName, "Calculo 4");
    strcpy(listBook[3].bookAuthor, "Guidorizzi");
    strcpy(listBook[3].bookCategory, "Matemática");

    listBook[4].bookAmount = 1;
    strcpy(listBook[4].bookName, "Geometria Analitica");
    strcpy(listBook[4].bookAuthor, "Elon Lages");
    strcpy(listBook[4].bookCategory, "Matemática");

    listBook[5].bookAmount = rand()%10+1;
    strcpy(listBook[5].bookName, "Algebra Linear");
    strcpy(listBook[5].bookAuthor, "Elon Lages");
    strcpy(listBook[5].bookCategory, "Matemática");

    listBook[6].bookAmount = rand()%2+2;
    strcpy(listBook[6].bookName, "Analise Real 1");
    strcpy(listBook[6].bookAuthor, "Elon Lages");
    strcpy(listBook[6].bookCategory, "Matemática");

    listBook[7].bookAmount = rand()%2+1;
    strcpy(listBook[7].bookName, "Analise Real 2");
    strcpy(listBook[7].bookAuthor, "Elon Lages");
    strcpy(listBook[7].bookCategory, "Matemática");

    listBook[8].bookAmount = rand()%10+1;
    strcpy(listBook[8].bookName, "Analise Real 3");
    strcpy(listBook[8].bookAuthor, "Elon Lages");
    strcpy(listBook[8].bookCategory, "Matemática");

    listBook[9].bookAmount = rand()%2+1;
    strcpy(listBook[9].bookName, "Analise Real Rn");
    strcpy(listBook[9].bookAuthor, "Elon Lages");
    strcpy(listBook[9].bookCategory, "Matemática");

    listUser[0].category = 1;
    strcpy(listUser[0].userName, "Rebeca");
    strcpy(listUser[0].userPassword, "1234");
    strcpy(listUser[0].userGraduation, "Matemática Computacional");
    listUser[0].bookE = 0;

    listUser[1].category = 1;
    strcpy(listUser[1].userName, "Maslow");
    strcpy(listUser[1].userPassword, "Senha");
    strcpy(listUser[1].userGraduation, "Matemática");
    listUser[1].userListBook[0] = listBook[6];
    listBook[6].bookAmount--;
    Mostborrowedbooks[6]++;
    listUser[1].bookE = 1; // Quantidade de livos emprestados.

    listUser[2].category = 1;
    strcpy(listUser[2].userName, "Arthur");
    strcpy(listUser[2].userPassword, "Arthur");
    strcpy(listUser[0].userGraduation, "Ciência da Computação");
    listUser[1].bookE = 0;

    listUser[3].category = 0;
    strcpy(listUser[3].userName, "0");
    strcpy(listUser[3].userPassword, "0");
    strcpy(listUser[3].userGraduation, "Música");

    listUser[4].category = 1;
    strcpy(listUser[4].userName, "1");
    strcpy(listUser[4].userPassword, "1");
    strcpy(listUser[4].userGraduation, "Medicina");

    bookNumber = 10;
    userNumber = 5;
    return;
}

void InitializeLibrarySystem()
{
    SetColor(7);
    PrintWithDelay("[Inicializando o Sistema da Biblioteca]", 80, "\n\n");
    PrintWithDelay(".\n.\n..\n...\n\nPor favor, aguarde.\n\n", 50, "\n");
    SetColor(15);

    // Simulação de inicialização dos módulos
    PrintWithDelay("Carregando a base de dados dos livros...", 80, "\n");
    printf("Status: ");
    SetColor(9);
    Sleep(rand() % 100 + 1000);
    printf("OK!\n");
    SetColor(15);

    PrintWithDelay("Configurando o sistema de usuários...", 80, "\n");
    printf("Status: ");
    SetColor(9);
    Sleep(rand() % 100 + 1000);
    printf("OK!\n");
    SetColor(15);

    PrintWithDelay("Estabelecendo conexão com os arquivos...", 80, "\n");
    printf("Status: ");
    SetColor(9);
    Sleep(rand() % 100 + 1000);
    printf("OK!\n");
    SetColor(15);

    PrintWithDelay("Inicializando o sistema de controle de empréstimos...", 80, "\n");
    printf("Status: ");
    SetColor(9);
    Sleep(rand() % 100 + 1000);
    printf("OK!\n");
    SetColor(15);

    PrintWithDelay("Verificando atualizações do sistema...", 80, "\n");
    printf("Status: ");
    SetColor(9);
    Sleep(rand() % 100 + 1000);
    printf("OK!\n\n\n\n\n");
    SetColor(15);

    SetColor(10);
    Sleep(3000);
    PrintWithDelay("[Sistema da Biblioteca inicializado com sucesso]\n\n", 80, "\n");
    SetColor(15);

    Sleep(2000);
    system("cls");
}

void Start()
{
    InitializeLibrarySystem();

    SetColor(14);
    PrintWithDelay("Sejam Muito Bem-Vindos a Biblioteca RMA!", 80, "\n\n\n\n");
    SetColor(15);
    PrintWithDelay("+  - Criadores - +\n|     Maslow     |\n|     Rebeca     |\n|     Arthur     |\n+ -------------- +", 20, "\n\n\n");

    Sleep(2500);
    system("cls");
    return;
}

void End()
{
    system("cls");
    SetColor(9);
    PrintWithDelay("Muito obrigado por usar o nosso sistema!", 80, "");
    SetColor(12);
    PrintWithDelay(" <3", 80, "\n");
    Sleep(3000);
    system("cls");
    Sleep(3000);
    SetColor(15);
    PrintWithDelay("+  - Criadores - +\n|     Maslow     |\n|     Rebeca     |\n|     Arthur     |\n+ -------------- +", 20, "\n\n\n");
    Sleep(5000);
    system("cls");
    SetColor(7);
    return;
}

// -----------------------------------------------------------------------------------------------------

// Menus
int ChooseMenu()
{
    char tecla;
    int c=1;

    system("cls");
    SetColor(11);
    printf("| =  Menu Inicial  = |");
    printf("\n\n --------------------");
    for (int i = 1; i <=5; i++)
    {
        printf("\n|");
        if (i == c) SetColor(9);
        else SetColor(14);
        switch (i)
        {
        case 1:
            printf("    Login         ");
            break;
        case 2:
            printf("    Criar Conta   ");
            break;
        case 3:
            printf("    Ver Catálogo  ");
            break;
        case 4:
            printf("    Créditos      ");
            break;
        case 5:
            printf("    Desligar      ");
            break;
        }
        SetColor(12);
        printf("%s  ", c == i ? "<" : "");
        SetColor(11);
        printf("|");
        }
    printf("\n --------------------");
    SetColor(12);
    printf("\n\n+--------------------------------------------------+");
    printf("\n| Use as SETAS para navegar e ENTER para confirmar |");
    printf("\n+--------------------------------------------------+\n");
    SetColor(11);
    Sleep(100);
    while (1)
    {
        if (_kbhit())
        {
            tecla = getch();
            if (tecla == 13)
                {
                    SetColor(15);
                    if (c == 1) Login();
                    else if (c == 2) CreateAccount();
                    else if (c == 3) Catalog();
                    else if (c == 4) Credits();
                    else if (c == 5) return 0;
                }
            if (tecla == 72)
                {
                    c--;
                }
            else if (tecla == 80)
            {
                c++;
            }

        if (c < 1) c = 5;
        if (c > 5) c = 1;

        system("cls");
        SetColor(11);
        printf("| =  Menu Inicial  = |");
        printf("\n\n --------------------");
        for (int i = 1; i <=5; i++)
        {
            printf("\n|");
            if (i == c) SetColor(9);
            else SetColor(14);
            switch (i)
            {
            case 1:
                printf("    Login         ");
                break;
            case 2:
                printf("    Criar Conta   ");
                break;
            case 3:
                printf("    Ver Catálogo  ");
                break;
            case 4:
                printf("    Créditos      ");
                break;
            case 5:
                printf("    Desligar      ");
                break;
            }
            SetColor(12);
            printf("%s  ", c == i ? "<" : "");
            SetColor(11);
            printf("|");
            }
        printf("\n --------------------");
        Sleep(100);
        }
    }

    return 1;
}

void AllFunctionMenu() {
    char tecla;
    int c = 1;

    system("cls");
    SetColor(9);
    printf("Administrador: ");
    SetColor(15);
    printf("%s\n", listUser[currentLogin].userName);
    SetColor(9);
    printf("Graduação: ");
    SetColor(15);
    printf("%s\n", listUser[currentLogin].userGraduation);
    SetColor(9);
    printf("Livros: ");
    SetColor(15);
    printf("%d\n", listUser[currentLogin].bookE);
    SetColor(11);
    PrintWithDelay("\n\nO que deseja fazer?\n", 80, "");
    printf("\n -------------------------------");
    for (int i = 1; i <= 10; i++) {
        printf("\n|");
        if (i == c) SetColor(9);
        else SetColor(14);
        switch (i) {
            case 1:
                printf("    Listar Todos os Livros  ");
                break;
            case 2:
                printf("    Buscar Livros           ");
                break;
            case 3:
                printf("    Adicionar Livros        ");
                break;
            case 4:
                printf("    Remover Livros          ");
                break;
            case 5:
                printf("    Editar Livros           ");
                break;
            case 6:
                printf("    Livros Emprestados      ");
                break;
            case 7:
                printf("    Devolver Livros         ");
                break;
            case 8:
                printf("    Renovar Livros          ");
                break;
            case 9:
                printf("    Outro                   ");
                break;
            case 10:
                printf("    Sair                    ");
                break;
        }
        SetColor(12);
        printf("%s  ", c == i ? "<" : "");
        SetColor(11);
        printf("|");
    }

    printf("\n -------------------------------");
    SetColor(12);
    printf("\n\n+--------------------------------------------------+");
    printf("\n| Use as SETAS para navegar e ENTER para confirmar |");
    printf("\n+--------------------------------------------------+\n");
    SetColor(11);
    Sleep(100);

    while (1) {
        if (_kbhit()) {
            tecla = getch();

            if (tecla == 13) {  // 'Enter' key
                SetColor(15);
                if (c == 1) ListAll();
                else if (c == 2) SearchBook();
                else if (c == 3) AddBook();
                else if (c == 4) RemoveBook();
                else if (c == 5) EditBook();
                else if (c == 6) ;
                else if (c == 7) ;
                else if (c == 8) ;
                else if (c == 9) OtherAdm();
                else if (c == 10) {  // Sair
                    currentLogin = -1;
                    return;
                }
            }

            // Set navigation for up and down arrows
            if (tecla == 72) {  // Up arrow
                c--;
            } else if (tecla == 80) {  // Down arrow
                c++;
            }

            // Ensure the index wraps around
            if (c < 1) c = 10;
            if (c > 10) c = 1;

            system("cls");
            SetColor(9);
            printf("Administrador: ");
            SetColor(15);
            printf("%s\n", listUser[currentLogin].userName);
            SetColor(9);
            printf("Graduação: ");
            SetColor(15);
            printf("%s\n", listUser[currentLogin].userGraduation);
            SetColor(9);
            printf("Livros: ");
            SetColor(15);
            printf("%d\n", listUser[currentLogin].bookE);
            SetColor(11);
            printf("\n\nO que deseja fazer?\n", 80, "");
            printf("\n -------------------------------");

            for (int i = 1; i <= 10; i++) {
                printf("\n|");
                if (i == c) SetColor(9);
                else SetColor(14);
                switch (i) {
                    case 1:
                        printf("    Listar Todos os Livros  ");
                        break;
                    case 2:
                        printf("    Buscar Livros           ");
                        break;
                    case 3:
                        printf("    Adicionar Livros        ");
                        break;
                    case 4:
                        printf("    Remover Livros          ");
                        break;
                    case 5:
                        printf("    Editar Livros           ");
                        break;
                    case 6:
                        printf("    Livros Emprestados      ");
                        break;
                    case 7:
                        printf("    Devolver Livros         ");
                        break;
                    case 8:
                        printf("    Renovar Livros          ");
                        break;
                    case 9:
                        printf("    Outro                   ");
                        break;
                    case 10:
                        printf("    Sair                    ");
                        break;
                }
                SetColor(12);
                printf("%s  ", c == i ? "<" : "");
                SetColor(11);
                printf("|");
            }
            printf("\n -------------------------------");
            Sleep(100);
        }
    }

    currentLogin = -1;
    return;
}

// Essa opção é para se vocês adicionarem funções novas, dai podem colocar um menu aqui.
// Essa função aparece nas opções e ao ser clicada levará para esse menu criado por vocês.
void OtherAdm() // Para os Administradores
{
    return;
}

void UserFunctionMenu()
{
    char tecla;
    int c=1;

    system("cls");
    SetColor(9);
    printf("Usuário: ");
    SetColor(15);
    printf("%s\n", listUser[currentLogin].userName);
    SetColor(9);
    printf("Graduação: ");
    SetColor(15);
    printf("%s\n", listUser[currentLogin].userGraduation);
    SetColor(9);
    printf("Livros: ");
    SetColor(15);
    printf("%d\n", listUser[currentLogin].bookE);
    SetColor(11);
    PrintWithDelay("\n\nO que deseja fazer?\n", 80, "");
    printf("\n ----------------------------");
    for (int i = 1; i <=5; i++)
    {
        printf("\n|");
        if (i == c) SetColor(9);
        else SetColor(14);
        switch (i)
        {
        case 1:
            printf("    Livros Emprestados  ");
            break;
        case 2:
            printf("    Devolver Livros     ");
            break;
        case 3:
            printf("    Renovar Livros      ");
            break;
        case 4:
            printf("    Outro               ");
            break;
        case 5:
            printf("    Sair                ");
            break;
        }
        SetColor(12);
        printf("%s  ", c == i ? "<" : "");
        SetColor(11);
        printf("|");
        }
    printf("\n ----------------------------");
    Sleep(100);

    SetColor(12);
    printf("\n\n+--------------------------------------------------+");
    printf("\n| Use as SETAS para navegar e ENTER para confirmar |");
    printf("\n+--------------------------------------------------+\n");
    SetColor(11);

    while (1)
    {
        if (_kbhit())
        {
            tecla = getch();
            if (tecla == 13)
                {
                    SetColor(15);
                    if (c == 1) ;
                    else if (c == 2) ;
                    else if (c == 3) ;
                    else if (c == 4) OtherUser();
                    else if (c == 5){
                        currentLogin = -1;
                        return;
                    }
                }
            if (tecla == 72)
                {
                    c--;
                }
            else if (tecla == 80)
            {
                c++;
            }

        if (c < 1) c = 5;
        if (c > 5) c = 1;

        system("cls");
        SetColor(9);
        printf("Usuário: ");
        SetColor(15);
        printf("%s\n", listUser[currentLogin].userName);
        SetColor(9);
        printf("Graduação: ");
        SetColor(15);
        printf("%s\n", listUser[currentLogin].userGraduation);
        SetColor(9);
        printf("Livros: ");
        SetColor(15);
        printf("%d\n", listUser[currentLogin].bookE);
        SetColor(11);
        printf("\n\nO que deseja fazer?\n");
        printf("\n ----------------------------");
        for (int i = 1; i <=5; i++)
        {
            printf("\n|");
            if (i == c) SetColor(9);
            else SetColor(14);
            switch (i)
            {
            case 1:
                printf("    Livros Emprestados  ");
                break;
            case 2:
                printf("    Devolver Livros     ");
                break;
            case 3:
                printf("    Renovar Livros      ");
                break;
            case 4:
                printf("    Outro               ");
                break;
            case 5:
                printf("    Sair                ");
                break;
            }
            SetColor(12);
            printf("%s  ", c == i ? "<" : "");
            SetColor(11);
            printf("|");
            }
        printf("\n ----------------------------");
        Sleep(100);
        }
    }

    currentLogin = -1;

    return;
}

// Essa opção é para se vocês adicionarem funções novas, dai podem colocar um menu aqui.
// Essa função aparece nas opções e ao ser clicada levará para esse menu criado por vocês.
void OtherUser() // Para os Usuarios
{
    return 0;
}

// -----------------------------------------------------------------------------------------------------

// Funções Para ChooseMenu
void Login()
{
    char username[100], password[100];
    int authenticated = 0;

    system("cls");
    SetColor(11);
    printf("========== LOGIN ==========\n\n");
    SetColor(14);
    PrintWithDelay("Digite seu nome de usuário: ", 80, "");
    SetColor(15);
    scanf("%s", username);

    SetColor(14);
    PrintWithDelay("Digite sua senha: ", 80, "");
    SetColor(15);
    char ch;
    int i = 0;
    // Entrada de senha com máscara
    while (i < sizeof(password) - 1 && (ch = getch()) != '\r') {
        if (ch == '\b') {  // Verifica se o usuário pressionou backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // Apaga o último caractere da tela
            }
        } else if (ch >= 32 && ch <= 126) {  // Apenas caracteres imprimíveis
            password[i++] = ch;
            printf("*");  // Exibe um asterisco como máscara
        }
    }
    password[i] = '\0'; // Finaliza a string da senha

    printf("\n\n");

    for (int i = 0; i < userNumber; i++) {
        if (strcmp(listUser[i].userName, username) == 0 && strcmp(listUser[i].userPassword, password) == 0) {
            authenticated = 1;
            currentLogin = i;
            SetColor(10);
            if (listUser[i].category == 1) {
                printf("\nBem-vindo, administrador %s!\n", username);
                Sleep(2000);
                SetColor(15);
                AllFunctionMenu();
            } else {
                printf("\nBem-vindo, usuário %s!\n", username);
                Sleep(2000);
                SetColor(15);
                UserFunctionMenu();
            }
            break;
        }
    }

    if (!authenticated) {
        SetColor(12);
        printf("\n\nCredenciais invalidas. Tente novamente.\n");
        Sleep(2000);
    }

    SetColor(15);
    return;
}

void CreateAccount() {
    system("cls");
    SetColor(11);
    printf("========== CRIAR CONTA ==========\n\n");

    char tecla;
    if (userNumber >= 100) {
        SetColor(12);
        PrintWithDelay("Limite máximo de usuários atingido!\n", 80, "");
        Sleep(2000);
        return;
    }

    struct User newUser;
    char confirm[100];

    SetColor(14);
    PrintWithDelay("Digite o nome de usuário: ", 80, "");
    SetColor(15);
    scanf(" %[^\n]", newUser.userName);

    for (int i = 0; i < userNumber; i++) {
        if (strcmp(newUser.userName, listUser[i].userName) == 0) {
            SetColor(12);
            PrintWithDelay("\n\nNome de Usuário já registrado. Tente outro.\n", 80, "");
            Sleep(3000);
            CreateAccount();
            return;
        }
    }

    SetColor(14);
    PrintWithDelay("\nDigite a sua senha: ", 80, "");
    SetColor(15);
    scanf(" %[^\n]", newUser.userPassword);

    SetColor(14);
    PrintWithDelay("Confirme a sua senha: ", 80, "");
    SetColor(15);
    scanf(" %[^\n]", confirm);

    if (strcmp(newUser.userPassword, confirm) != 0) {
        SetColor(12);
        PrintWithDelay("\n\nSenhas não coincidem. Tente novamente.\n", 80, "");
        Sleep(3000);
        CreateAccount();
        return;
    }

    SetColor(14);
    PrintWithDelay("\nDigite sua graduação (digite 0 se não houver): ", 80, "");
    SetColor(15);
    scanf(" %[^\n]", newUser.userGraduation);

    if (strcmp(newUser.userGraduation, "0") == 0) {
        strcpy(newUser.userGraduation, "Nenhuma graduação informada");
    }


    newUser.bookE = 0;
    newUser.category = 0;

    listUser[userNumber++] = newUser;

    SetColor(9);
    PrintWithDelay("\n\nConta criada com sucesso!\n", 80, "");
    Sleep(2000);

    SetColor(15);
    printf("\n[Pressione Enter para voltar]", 80, "");
    getch();
    return;
}


void Catalog()
{
    ListAll();
    return;
}

void Credits()
{
    End();
    return;
}

// -----------------------------------------------------------------------------------------------------

// Funções Importantes Para o Funcionamento da Biblioteca
void ListAll() {
    system("cls");
    SetColor(11);
    printf("========== LISTA DE LIVROS ==========\n\n\n");

    if (bookNumber == 0) {
        SetColor(12);
        PrintWithDelay("Nenhum livro registrado no sistema.\n", 80, "");
        Sleep(2000);
        return;
    }

    SetColor(14);
    for (int i = 0; i < bookNumber; i++) {
        printf("---------- Livro %d ----------\n\n", i + 1);

        SetColor(11);
        printf("Nome       : ");
        SetColor(15);
        printf("%s\n", listBook[i].bookName);

        SetColor(11);
        printf("Autor      : ");
        SetColor(15);
        printf("%s\n", listBook[i].bookAuthor);

        SetColor(11);
        printf("Categoria  : ");
        SetColor(15);
        printf("%s\n", listBook[i].bookCategory);

        SetColor(11);
        printf("Quantidade : ");
        SetColor(15);
        printf("%d\n", listBook[i].bookAmount);

        printf("\n");
        SetColor(14);
        Sleep(10);
    }


    SetColor(15);
    PrintWithDelay("\n\nPressione Enter quando Terminar de Olhar!", 20, "");
    getch();
    return;
}

void AddBook() {
    if (bookNumber >= 1000) {
        SetColor(12);
        printf("\nLimite máximo de livros atingido!\n");
        Sleep(2000);
        SetColor(15);
        return;
    }

    struct Book newBook;

    system("cls");
    SetColor(14);
    printf("========== ADICIONAR LIVRO ==========\n\n");

    SetColor(11);
    printf("Digite o nome do livro: ");
    SetColor(15);
    scanf(" %[^\n]", newBook.bookName);

    SetColor(11);
    printf("Digite o autor: ");
    SetColor(15);
    scanf(" %[^\n]", newBook.bookAuthor);

    SetColor(11);
    printf("Digite a categoria: ");
    SetColor(15);
    scanf(" %[^\n]", newBook.bookCategory);

    SetColor(11);
    printf("Digite a quantidade disponível: ");
    SetColor(15);
    scanf("%d", &newBook.bookAmount);

    listBook[bookNumber++] = newBook; // Adiciona o novo livro à lista

    SetColor(10);
    printf("\nLivro adicionado com sucesso!\n");
    Sleep(2000);
    SetColor(15);
}


void SearchBook() {
    char searchName[100];
    int found = 0;

    system("cls");
    SetColor(14);
    printf("========== BUSCAR LIVRO ==========\n\n");

    SetColor(11);
    printf("Digite o nome do livro para buscar: ");
    SetColor(15);
    scanf(" %[^\n]", searchName);

    SetColor(14);
    printf("\n\n========== RESULTADOS DA BUSCA ==========\n\n");

    for (int i = 0; i < bookNumber; i++) {
        if (strstr(listBook[i].bookName, searchName) != NULL) {
            SetColor(10);
            printf("Livro encontrado!\n\n");
            SetColor(11);
            printf("Nome       : %s\n", listBook[i].bookName);
            printf("Autor      : %s\n", listBook[i].bookAuthor);
            printf("Categoria  : %s\n", listBook[i].bookCategory);
            printf("Quantidade : %d\n\n", listBook[i].bookAmount);
            found = 1;
        }
    }

    if (!found) {
        SetColor(12);
        printf("Nenhum livro encontrado com o nome \"%s\".\n", searchName);
    }

    SetColor(15);
    printf("\nPressione Enter para voltar.");
    getchar();
    getchar();
}

void RemoveBook() {
    int bookIndex;
    char confirm;

    system("cls");
    SetColor(14);
    ListAll();
    printf("========== REMOVER LIVRO ==========\n\n");

    SetColor(11);
    printf("Escolha o número do livro que deseja remover: ");
    SetColor(15);
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > bookNumber) {
        SetColor(12);
        printf("\nNúmero de livro inválido.\n");
        Sleep(2000);
        SetColor(15);
        return;
    }

    SetColor(14);
    printf("\nTem certeza que deseja remover o livro \"%s\" (S/N)? ", listBook[bookIndex - 1].bookName);
    SetColor(15);
    scanf(" %c", &confirm);

    // Move os livros para deixar o final livre
    if (confirm == 'S' || confirm == 's') {
        for (int i = bookIndex - 1; i < bookNumber - 1; i++) {
            listBook[i] = listBook[i + 1];
        }

        bookNumber--;
        SetColor(10);
        printf("\nLivro removido com sucesso!\n");
        Sleep(2000);
    } else {
        SetColor(12);
        printf("\nRemoção cancelada.\n");
        Sleep(2000);
    }

    SetColor(15);
}

void EditBook() {
    int bookIndex;
    char confirm;

    system("cls");
    SetColor(14);
    printf("========== EDITAR LIVRO ==========\n\n");

    ListAll();

    SetColor(11);
    printf("\n\nDigite o número do livro para editar: ");
    SetColor(15);
    scanf("%d", &bookIndex);

    if (bookIndex < 1 || bookIndex > bookNumber) {
        SetColor(12);
        printf("\nNúmero de livro inválido.\n");
        Sleep(2000);
        SetColor(15);
        return;
    }

    SetColor(14);
    printf("\nTem certeza que deseja editar o livro \"%s\" (S/N)? ", listBook[bookIndex - 1].bookName);
    SetColor(15);
    scanf(" %c", &confirm);

    if (confirm == 'S' || confirm == 's') {
        char buffer[100];
        int newAmount;

        SetColor(11);
        printf("\nDigite o novo nome do livro (digite 0 para não alterar): ");
        SetColor(15);
        scanf(" %[^\n]", buffer);
        if (strcmp(buffer, "0") != 0) {
            strcpy(listBook[bookIndex - 1].bookName, buffer);
        }

        SetColor(11);
        printf("Digite o novo autor (digite 0 para não alterar): ");
        SetColor(15);
        scanf(" %[^\n]", buffer);
        if (strcmp(buffer, "0") != 0) {
            strcpy(listBook[bookIndex - 1].bookAuthor, buffer);
        }

        SetColor(11);
        printf("Digite a nova categoria (digite 0 para não alterar): ");
        SetColor(15);
        scanf(" %[^\n]", buffer);
        if (strcmp(buffer, "0") != 0) {
            strcpy(listBook[bookIndex - 1].bookCategory, buffer);
        }

        SetColor(11);
        printf("Digite a nova quantidade de livros (digite 0 para não alterar): ");
        SetColor(15);
        scanf("%d", &newAmount);
        if (newAmount != 0) {
            listBook[bookIndex - 1].bookAmount = newAmount;
        }

        SetColor(10);
        printf("\nLivro editado com sucesso!\n");
        Sleep(2000);
    } else {
        SetColor(12);
        printf("\nEdição cancelada.\n");
        Sleep(2000);
    }

    SetColor(15);
}


// -----------------------------------------------------------------------------------------------------

// Funções de Emprestimo

// -----------------------------------------------------------------------------------------------------

int main()
{
    int Continue = 1;

    srand(time(NULL));                         // Inicializa a semente para geração de números aleatórios
    setlocale(LC_ALL,"Portuguese");            // Configura a acentuação e caracteres especiais em português
    SetColor(15);                              // Define a cor do texto para branco brilhante
    AddInitialBooksAndUser();                  // Função importante, não mexa
    //Start();                                   // Pode desativar essa  função caso queira uma inicialização mais rápida

    while (Continue)
    {
        Continue = ChooseMenu();
    }

    End();
    system("PAUSE");
    return 0;
}
