/*
===========================
=   GUIA DE ESTILO PARA   =
= PADRONIZAÇÃO DO CÓDIGO  =
===========================
*/


/*
    = Bibliotecas Básicas =

- Todas as bibliotecas devem ser importadas no início do programa.
- As bibliotecas necessárias para o funcionamento devem ser listadas.
- A única pessoa que pode remover uma biblioteca é quem a adicionou.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


/*
    = Constantes e Variáveis Globais =

- As constantes globais devem ser separadas das bibliotecas e declaradas primeiro.
- As constantes globais devem ser escritas com letras maiúsculas, separadas por underscores (_).
- As variáveis globais devem ser declaradas após as constantes globais.
- As variáveis globais e internas devem seguir o padrão camelCase.
- A ordem recomendada para declarações é: bibliotecas, constantes globais e, em seguida, variáveis globais.
*/
#define GLOBAL_CONSTANT 5


char globalVariable = 'a';


/*
    = Estilo de Funções =

- O padrão SnakeCase deve ser utilizado para nomear funções.
- Sempre adicione um comentário explicativo logo acima de cada função, descrevendo seu funcionamento e propósito.
- Todas as funções devem retornar um valor, mesmo que seja `void`.
- Para funções `void`, utilize `return;` ao invés de `return NULL;` para sinalizar o fim da função.
- As chaves de abertura devem ficar na linha abaixo da declaração de funções, condições ou laços.
- Evite código duplicado. Se identificar um padrão de repetição, crie funções ou módulos reutilizáveis.
- Cada função deve ter uma responsabilidade clara e realizar apenas uma tarefa específica.
- Reutilize funções existentes antes de criar novas funções semelhantes.
*/
void ExampleFunction()
{
    float internalVariable = 1.23;

    printf("%d - %c - %0.2f\n", GLOBAL_CONSTANT, globalVariable, internalVariable);

    return;
}


/*
    = Observações Gerais =

- As variáveis e funções devem ser nomeadas em inglês, sem abreviações.
- Deixe duas linhas de espaço entre as funções para melhorar a legibilidade.
- Insira uma linha de espaço entre blocos lógicos de código dentro de funções.
- O contador de laços 'for' deve ser declarado dentro do próprio laço. Exemplo: 'for (int i = 0; i <= 69; i++)'.
- Mantenha uma indentação consistente, preferencialmente com 4 espaços por nível.
- Sempre valide entradas do usuário para evitar erros ou comportamentos inesperados.
- Comentários devem ser utilizados para descrever a finalidade do código.
- Evite comentários desnecessários que expliquem código óbvio, mas sempre explique decisões complexas.
*/
int fakemain()
{
    // Use o parâmetro LC_CTYPE para evitar problemas com caracteres locais. Exemplo:
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
    = Controle de Versão (Git) =

- Mensagens de commit devem ser claras, objetivas e descritivas.
- Commits devem ser pequenos e tratar apenas de uma mudança específica.
- Utilize branches para separar novas funcionalidades ou correções.
- Antes de criar um pull request, revise o código e garanta que não há conflitos.
- Evite incluir arquivos temporários ou de configurações pessoais nos commits.
- Faça 'pull' ou 'fetch' regularmente para evitar conflitos ao atualizar o branch.
- Remova código morto ou não utilizado para manter o projeto limpo.
*/
