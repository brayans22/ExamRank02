#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int data;
    struct s_list *next;
} t_list;

int list_size(t_list *list)
{
	int i = 0;
	t_list *aux = list;

	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *aux_1 = lst;
	int	i = 0;
	int	j = 0;
	int	temp = 0;
	int size = list_size(lst);

	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			
			if (cmp(aux_1->data, aux_1->next->data))
			{
				temp = aux_1->data;
				aux_1->data = aux_1->next->data;
				aux_1->next->data = temp;
			}
			aux_1 = aux_1->next;
			j++;
		}
		j = 0;
		aux_1 = lst;
		i++;
	}
	aux_1 = lst;
	return (aux_1);
}

int compare(int a, int b)
{
    return (a > b) ? 1 : ((a < b) ? -1 : 0);
}

// Función para imprimir los elementos de la lista
void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    // Crear una lista de ejemplo
    t_list *head = NULL;
    t_list *current = NULL;

    for (int i = 5; i >= 1; i--)
    {
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        new_node->data = i;
        new_node->next = NULL;

        if (current == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }

    // Imprimir la lista antes de ordenar
    printf("Lista antes de ordenar: ");
    print_list(head);

    // Llamar a la función de ordenamiento
    head = sort_list(head, compare);

    // Imprimir la lista después de ordenar
    printf("Lista después de ordenar: ");
    print_list(head);

    return 0;
}
