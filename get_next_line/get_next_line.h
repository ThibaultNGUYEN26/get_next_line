/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:16:05 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/13 18:26:34 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_concat_stash(int size, char *buf, char *stash, int fd);
char	*get_line(char *stash, int i);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strchr(char *s, int c);
char	*ft_split(char *s, char c);

#endif