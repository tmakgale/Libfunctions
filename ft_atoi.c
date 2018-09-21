/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:48:37 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/24 11:13:07 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_temp(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int num;

	i = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	if (*str == '-')
		num = -1;
	else
		num = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_temp(*str))
		i = (i * 10) + (*str++ - '0');
	return (i * num);
}
