/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:42:07 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/09 20:42:15 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*snew;

	size = 0;
	i = 0;
	snew = NULL;
	if (s == NULL && f == NULL)
		return (NULL);
	size = ft_strlen(s);
	snew = (char*)malloc((sizeof(char) * size) + 1);
	if (snew == NULL)
		return (NULL);
	while (i < size)
	{
		snew[i] = (*f)(s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
