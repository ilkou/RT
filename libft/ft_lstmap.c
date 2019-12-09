/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:53:31 by oouklich          #+#    #+#             */
/*   Updated: 2018/10/17 22:35:37 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*frais;

	if (lst != NULL)
	{
		frais = malloc(sizeof(void));
		frais = f(lst);
		frais->next = ft_lstmap(lst->next, f);
		return (frais);
	}
	return (NULL);
}
