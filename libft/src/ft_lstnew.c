/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:22:43 by akhossan          #+#    #+#             */
/*   Updated: 2019/04/04 14:35:29 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t size)
{
	t_list		*lst;

	if (!(lst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		return (lst);
	if (!(lst->content = ft_memalloc(size)))
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(lst->content, content, size);
	lst->size = size;
	return (lst);
}
