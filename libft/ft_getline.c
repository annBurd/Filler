/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:06:10 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/05 18:53:00 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*check_fd(const int fd, t_fd **head)
{
	t_fd	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->s);
		tmp = tmp->next;
	}
	tmp = (t_fd*)malloc(sizeof(t_fd));
	tmp->fd = fd;
	tmp->s = ft_strnew(0);
	tmp->next = (*head);
	(*head) = tmp;
	return (tmp->s);
}

static int	read_till_new_line(const int fd, char **buf)
{
	char	buf_tmp[BUFF_SIZE + 1];
	char	*fresh;
	int		bytes;

	ft_memset(buf_tmp, 0, BUFF_SIZE);
	bytes = read(fd, buf_tmp, BUFF_SIZE);
	if (!bytes)
		return (-2);
	fresh = ft_strjoin(*buf, buf_tmp);
	free(*buf);
	*buf = fresh;
	return (bytes);
}

int			ft_getline(const int fd, char **line)
{
	static t_fd	*head;
	char		*buf;
	char		*rebuf;
	char		*end;
	int			bytes;

	if (fd < 0 || BUFF_SIZE <= 0 || !line || read(fd, "", 0) < 0)
		return (-1);
	buf = check_fd(fd, &head);
	end = ft_strchr(buf, '\n');
	while (end == NULL)
	{
		bytes = read_till_new_line(fd, &buf);
		end = (bytes > 0) ? ft_strchr(buf, '\n') : ft_strchr(buf, 0);
		if (bytes == -2 && end == buf)
			return (0);
	}
	*line = ft_strsub(buf, 0, end - buf);
	rebuf = (buf[end - buf] == 0) ? ft_strnew(0) :
		ft_strsub(buf, end - buf + 1, ft_strlen(buf + (end - buf + 1)));
	free(buf);
	head->s = rebuf;
	return (1);
}
