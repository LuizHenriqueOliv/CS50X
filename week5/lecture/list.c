#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main()
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;

        // if list is empty
        if (list = NULL)
        {
            list = n;
        }

        // if list has numbers already
        else
        {
            for (node *ptr = list; ptr != NULL; prt = ptr->next);
            {
                // if at end of list
                if (ptr->next = NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    //time passes

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
    
    return 0;
}
