/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:13:26 by lmeyre            #+#    #+#             */
/*   Updated: 2018/05/15 19:09:22 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_add_end(t_list **lst, t_list *mew)
{
	t_list	*tmp;

	if (!(lst) || (!(*lst)) || !mew)
		return (0);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = mew;
	mew->prev = tmp;
	return (1);
}
