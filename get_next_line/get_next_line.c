/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:07:06 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/13 18:38:33 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concat_stash(int size, char *buf, char *stash, int fd)
{
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		stash = ft_strjoin(&stash, &buf);
		if (ft_strchr(stash, '\n') && size > 0)
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_line(char *stash, int i)
{
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(stash) - i);
	if (!res)
		return (NULL);
	i = -1;
	while (stash[++i])
	{
		if (stash[i] == '\n')
			break ;
		res[i] = stash[i];
	}
	res[i++] = '\n';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*row;
	char		*buf;
	char		*stash;
	char		*line;
	int			i;

	if (!fd)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = malloc(0);
	if (!stash)
		return (NULL);
	if (row)
		stash = row;
	row = NULL;
	stash = ft_concat_stash(1, buf, stash, fd);
	i = -1;
	while (stash[++i])
		if (stash[i] == '\n')
			break ;
	line = get_line(stash, i);
	row = ft_split(stash, '\n');
	return (line);
}

/* int main()
{
	int fd;
	char *str;
	int j;

	fd = open("test", O_RDONLY);
	j = 0;
	for (int i = 0; i < 3; i++)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		while (str[j])
			str[j++] = 0;
		j = 0;
	}
	close(fd);
	
	return 0;
} */