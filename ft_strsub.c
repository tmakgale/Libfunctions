/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:48:00 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/09 20:48:05 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*snew;

	i = 0;
	snew = NULL;
	if (s == NULL)
		return (NULL);
	snew = (char *)malloc((sizeof(char) * len) + 1);
	if (snew == NULL)
		return (NULL);
	while (i < len)
	{
		snew[i] = s[i + start];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
