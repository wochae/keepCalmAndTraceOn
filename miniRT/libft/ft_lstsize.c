#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int count;
	t_list *curr;

	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		++count;
	}
	return (count);
}
