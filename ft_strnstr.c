/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:45:05 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/09 20:45:11 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < n && s1[i] != '\0')
	{
		while (s1[i + j] == s2[j] && s2[j] != '\0' && (i + j) < n)
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
