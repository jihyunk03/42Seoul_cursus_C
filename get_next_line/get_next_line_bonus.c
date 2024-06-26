/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:51:44 by jihykim2          #+#    #+#             */
/*   Updated: 2022/12/19 14:28:27 by jihykim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*gnl;
	size_t		gnl_len;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (backup[fd] == NULL)
		backup[fd] = ft_strdup("");
	if (backup[fd] == NULL)
		return (NULL);
	gnl_len = read_file(&backup[fd], fd);
	if (gnl_len == 0)
		return (free_all(&backup[fd]));
	gnl = (char *)malloc(sizeof(char) * (gnl_len + 1));
	if (gnl == NULL)
		return (free_all(&backup[fd]));
	ft_strlcpy(gnl, backup[fd], gnl_len + 1);
	backup[fd] = restore_backup(backup[fd], gnl_len);
	if (backup[fd] == NULL)
		return (free_all(&gnl));
	if (*backup[fd] == '\0')
		free_all(&backup[fd]);
	return (gnl);
}

size_t	read_file(char **backup, int fd)
{
	ssize_t	readsize;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

	while (check_newline(*backup) == 0)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == 0)
			return (ft_strlen(*backup));
		else if (readsize < 0)
			return (0);
		buf[readsize] = '\0';
		tmp = *backup;
		*backup = ft_strjoin(*backup, buf);
		free (tmp);
		if (*backup == NULL)
			return (0);
	}
	return (check_newline(*backup));
}

size_t	check_newline(char *backup)
{
	size_t	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*restore_backup(char *backup, size_t gnl_len)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(backup) - gnl_len;
	tmp = backup;
	backup = (char *)malloc(sizeof(char) * (len + 1));
	if (backup == NULL)
		return (free_all(&tmp));
	ft_strlcpy(backup, tmp + gnl_len, len + 1);
	free (tmp);
	return (backup);
}

void	*free_all(char **str)
{
	if (*str == NULL)
		return (NULL);
	free(*str);
	*str = NULL;
	return (NULL);
}
