/*
===========================
=   GUIA DE ESTILO PARA   =
= PADRONIZA��O DO C�DIGO  =
===========================
*/


/*
    = Bibliotecas B�sicas =

- Todas as bibliotecas devem ser importadas no in�cio do programa.
- As bibliotecas necess�rias para o funcionamento devem ser listadas.
- A �nica pessoa que pode remover uma biblioteca � quem a adicionou.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


/*
    = Constantes e Vari�veis Globais =

- As constantes globais devem ser separadas das bibliotecas e declaradas primeiro.
- As constantes globais devem ser escritas com letras mai�sculas, separadas por underscores (_).
- As vari�veis globais devem ser declaradas ap�s as constantes globais.
- As vari�veis globais e internas devem seguir o padr�o camelCase.
- A ordem recomendada para declara��es �: bibliotecas, constantes globais e, em seguida, vari�veis globais.
*/
#define GLOBAL_CONSTANT 5


char globalVariable = 'a';


/*
    = Estilo de Fun��es =

- O padr�o SnakeCase deve ser utilizado para nomear fun��es.
- Sempre adicione um coment�rio explicativo logo acima de cada fun��o, descrevendo seu funcionamento e prop�sito.
- Todas as fun��es devem retornar um valor, mesmo que seja `void`.
- Para fun��es `void`, utilize `return;` ao inv�s de `return NULL;` para sinalizar o fim da fun��o.
- As chaves de abertura devem ficar na linha abaixo da declara��o de fun��es, condi��es ou la�os.
- Evite c�digo duplicado. Se identificar um padr�o de repeti��o, crie fun��es ou m�dulos reutiliz�veis.
- Cada fun��o deve ter uma responsabilidade clara e realizar apenas uma tarefa espec�fica.
- Reutilize fun��es existentes antes de criar novas fun��es semelhantes.
*/
void ExampleFunction()
{
    float internalVariable = 1.23;

    printf("%d - %c - %0.2f\n", GLOBAL_CONSTANT, globalVariable, internalVariable);

    return;
}


/*
    = Observa��es Gerais =

- As vari�veis e fun��es devem ser nomeadas em ingl�s, sem abrevia��es.
- Deixe duas linhas de espa�o entre as fun��es para melhorar a legibilidade.
- Insira uma linha de espa�o entre blocos l�gicos de c�digo dentro de fun��es.
- O contador de la�os 'for' deve ser declarado dentro do pr�prio la�o. Exemplo: 'for (int i = 0; i <= 69; i++)'.
- Mantenha uma indenta��o consistente, preferencialmente com 4 espa�os por n�vel.
- Sempre valide entradas do usu�rio para evitar erros ou comportamentos inesperados.
- Coment�rios devem ser utilizados para descrever a finalidade do c�digo.
- Evite coment�rios desnecess�rios que expliquem c�digo �bvio, mas sempre explique decis�es complexas.
*/
int fakemain()
{
    // Use o par�metro LC_CTYPE para evitar problemas com caracteres locais. Exemplo:
    // setlocale(LC_CTYPE, "Portuguese");

    ExampleFunction();
    printf("teste");

    Sleep(1000);
    system("cls");

    ExampleFunction();

    printf("\n\n\n");
    system("PAUSE");

    return 0;
}


/*
    = Controle de Vers�o (Git) =

- Mensagens de commit devem ser claras, objetivas e descritivas.
- Commits devem ser pequenos e tratar apenas de uma mudan�a espec�fica.
- Utilize branches para separar novas funcionalidades ou corre��es.
- Antes de criar um pull request, revise o c�digo e garanta que n�o h� conflitos.
- Evite incluir arquivos tempor�rios ou de configura��es pessoais nos commits.
- Fa�a 'pull' ou 'fetch' regularmente para evitar conflitos ao atualizar o branch.
- Remova c�digo morto ou n�o utilizado para manter o projeto limpo.
*/
