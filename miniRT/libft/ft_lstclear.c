#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_del;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		to_del = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(to_del, del);
	}
}
