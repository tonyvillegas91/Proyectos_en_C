
#include <stdbool.h>

#include "list.h"

void	ft_swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *current;
	t_list *next;
	bool	swapped;

	if (lst == 0)
		return (0);
	swapped = true;
	while (swapped)
	{
		swapped = false;
		current = lst;
		while (current)
		{
			next = current->next;
			if (next != 0 && (*cmp)(current->data, next->data) == 0)
			{
				ft_swap_int(&(current->data), &(next->data));
				swapped = true;
			}
			current = next;
		}
	}
	return (lst);
}
