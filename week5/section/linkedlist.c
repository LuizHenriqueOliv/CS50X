#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main()
{
    // cria o ponteiro para o início da lista (inicialmente vazia)
    node *list = NULL;

    // aloca espaço na memória para um novo nó
    node *n = malloc(sizeof(node));

    // verifica se a alocação foi bem-sucedida
    if (n == NULL)
    {
        return 1;
    }

    // define o valor armazenado no campo 'number' do nó
    n->number = 1;

    // como é o único nó, o próximo é NULL
    n->next = NULL;

    // faz o ponteiro 'list' apontar para o novo nó
    list = n;

    
}
