/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaval <fcaval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:50:17 by fcaval            #+#    #+#             */
/*   Updated: 2025/11/27 09:56:27 by fcaval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strglen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strgchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strgjoin(char *save, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!save)
	{
		save = malloc(1 * sizeof(char));
		if (!save)
			return (NULL);
		save[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strglen(save) + ft_strglen(buffer) + 1));
	if (!str)
		return (free(save), NULL);
	i = -1;
	while (save[++i])
		str[i] = save[i];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(save);
	return (str);
}
