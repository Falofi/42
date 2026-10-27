/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
