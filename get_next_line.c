/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:49:59 by tmakgale          #+#    #+#             */
/*   Updated: 2017/11/09 20:50:04 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cpy_contents(int const fd, char **stack)
{
	char	*buff;
	char	*temp;
	int		value;

	if (!(buff = (char *)ft_memalloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	value = read(fd, buff, BUFF_SIZE);
	if (value > 0)
	{
		buff[value] = '\0';
		temp = ft_strjoin(*stack, buff);
		free(*stack);
		*stack = temp;
	}
	free(buff);
	return (value);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stack = NULL;
	char		*line_feed;
	int			value;

	if ((!stack && (stack = (char *)ft_memalloc(sizeof(*stack))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	line_feed = ft_strchr(stack, '\n');
	while (line_feed == NULL)
	{
		value = ft_cpy_contents(fd, &stack);
		if (value == 0)
		{
			if (ft_strlen(stack) == 0)
				return (0);
			stack = ft_strjoin(stack, "\n");
		}
		if (value < 0)
			return (-1);
		else
			line_feed = ft_strchr(stack, '\n');
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(line_feed));
	stack = ft_strdup(line_feed + 1);
	return (1);
}
