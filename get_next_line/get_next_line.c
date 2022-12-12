/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:07:06 by thibnguy          #+#    #+#             */
/*   Updated: 2022/12/12 17:04:53 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	// static int	row;
	char	*buf;
	int		size;
	
	if (!fd)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	buf[size] = 0;
	return ("ca marche");
}

int main()
{
	/* Un file descriptor */
	int fd;
	/* Taille lut : */
	int size;
	
	/* On ouvre le fichier : en fait on recupere un fd sur le fichier*/
	fd = open("test", O_RDONLY);
	/* il ne peus pas y avoir de fd negatif,
	** si open nous retourne -1 c'est que l'ouverture a echoue
	** dans ce cas on quitte
	*/
	if (fd == -1)
	return 1;
	
	/*
	** On lit :
	** on passe a read :
	** - le fd,
	** - le buffer
	** - la taille du buffer
	** Attention si tu passe une taille de buffer plus grande que la taille de ton buffer,
	** ton programme deviens sensible aux Buffer Overflow
	*/
	size = get_next_line(fd);
	
	/*
	** On affiche ce que l'on viens de lire dans la console :
	** NOTE :
	** il existe des FD speciaux :
	** Le fd 1 est la sortie standart ( console )
	*/
	
	write (1, size+1, size);
	
	/* Ne pas oublier de libérer ton file descriptor */
	close(fd);
	
	return 0;
}