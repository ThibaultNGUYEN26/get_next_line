/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:16:10 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/13 17:52:11 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*str;
	int		i;
	int		j;

	if (!*s1 || !*s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[0][++i])
		str[i] = s1[0][i];
	j = -1;
	while (s2[0][++j])
		str[i + j] = s2[0][j];
	str[i + j] = '\0';
	free(*s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}

char	*ft_split(char *s, char c)
{
	char	*ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			i++;
			break ;
		}
	}
	ret = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!ret)
		return (free(ret), NULL);
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
