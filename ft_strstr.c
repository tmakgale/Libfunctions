/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:47:40 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/09 20:47:45 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == s2)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		while (s1[i + j] == s2[j] && s2[j] != '\0')
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + i));
		j = 0;
		i++;
	}
	return (NULL);
}
