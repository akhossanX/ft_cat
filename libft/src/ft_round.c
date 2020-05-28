/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:19:19 by akhossan          #+#    #+#             */
/*   Updated: 2019/12/09 12:20:02 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_round(double n)
{
	if (n - (int)n < (double)((int)n + 1) - n)
		return ((int)n);
	return ((int)n + 1);
}
