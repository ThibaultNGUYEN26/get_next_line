/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:07:06 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/20 17:36:36 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_entire_line(char *all_lines)
{
	size_t	i;
	char	*res;

	i = 0;
	while (all_lines[i] && all_lines[i] != '\n')
		i++;
	res = malloc(sizeof(char *) * i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (all_lines[i] && all_lines[i] != '\n')
	{
		res[i] = all_lines[i];
		i++;
	}
	if (all_lines[i] == '\n')
		res[i] = '\n';
	else
		res[i] = '\0';
	res[i + 1] = '\0';
	return (res);
}

char	*get_rest(char *all_lines)
{
	int		i;
	char	*stash;

	i = 0;
	while (all_lines[i] && all_lines[i] != '\n')
		i++;
	if (all_lines[i] == '\0' || all_lines[1] == '\0')
		return (NULL);
	stash = ft_substr(all_lines, i + 1, ft_strlen(all_lines + i));
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (stash);
}

char	*get_all_lines(int fd, char *buf, char *row)
{
	int		nb_letters;
	char	*tmp;

	nb_letters = 1;
	while (nb_letters != 0)
	{
		nb_letters = read(fd, buf, BUFFER_SIZE);
		if (nb_letters == -1)
			return (free(row), row = NULL);
		if (nb_letters == 0)
			break ;
		buf[nb_letters] = '\0';
		if (!row)
			row = ft_strdup("");
		tmp = row;
		row = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(row, '\n'))
			return (row);
	}
	return (row);
}

char	*get_next_line(const int fd)
{
	char		*all_lines;
	char		buf[BUFFER_SIZE + 1];
	char		*entire_line;
	static char	*row;

	all_lines = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(row), row = NULL);
	all_lines = get_all_lines(fd, buf, row);
	if (!all_lines)
		return (NULL);
	entire_line = get_entire_line(all_lines);
	row = get_rest(all_lines);
	free(all_lines);
	all_lines = NULL;
	return (entire_line);
}
