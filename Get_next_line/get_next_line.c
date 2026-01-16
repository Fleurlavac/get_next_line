/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaval <fcaval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:25:29 by fcaval            #+#    #+#             */
/*   Updated: 2025/11/27 13:31:16 by fcaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_this_please(int fd, char *save)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_line;

	read_line = 1;
	while (read_line > 0 && !ft_strgchr(save, '\n'))
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (free(save), NULL);
		if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		save = ft_strgjoin(save, buffer);
		if (!save)
			return (NULL);
	}
	return (save);
}

char	*where_is_the_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || !save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_this_please(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	new_save = malloc(sizeof(char) * (ft_strglen(save) - i + 1));
	if (!new_save)
		return (free(save), NULL);
	i++;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_this_please(fd, save);
	if (!save)
		return (NULL);
	line = where_is_the_line(save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = save_this_please(save);
	return (line);
}

// int	main(int argc, char	**argv)
// {
// 	int		fd;
// 	char	*t;
// 	int		lines;
// 	int		i;

// 	i = 0;
// 	if(argc < 3)
// 		return (1);

// 	lines = atoi(argv[2]);
// 	fd = open (argv[1], O_RDONLY);
// 	while (i < lines)
// 	{
// 		t = get_next_line(fd);
// 		if(!t)
// 			break ;
// 		printf("%s", t);
// 		free(t);
// 		i++;
// 	}
// 	while (t)
// 	{
// 		t = get_next_line(fd);
// 		free(t);
// 	}
// 	close(fd);
// }
