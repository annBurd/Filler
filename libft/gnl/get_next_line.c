/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:30:25 by akupriia          #+#    #+#             */
/*   Updated: 2018/11/27 22:14:15 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list		*ft_makelst(t_list *list, void const *content, size_t content_size)
{
	t_list	*t;
	size_t	len;

	dprintf(2, "gnl make\n");
	len = ft_strlen(content);
	if (!list)
	{
		list = (t_list *)malloc(sizeof(t_list));
		if (!(list->content = malloc(len + 1)))
			return (NULL);
		ft_memcpy((list->content), content, len);
		list->content_size = content_size;
		list->next = list;
	}
	else
	{
		t = list->next;
		list->next = ft_makelst(NULL, content, content_size);
		list = list->next;
		list->next = t;
	}
	dprintf(2, "gnl make end\n");
	return (list);
}

static int	read_buf(const int fd, char **line, t_list *tl)
{
	char	*t;
	char	*s;
	int		var;

	dprintf(2, "gnl read\n");
	if (!((s = ft_strchr(tl->content, '\n'))))
		s = ft_strchr(tl->content,
			((char *)tl->content)[ft_strlen(tl->content)]);
	t = tl->content;
	dprintf(2, "gnl read 1\n");
	tl->content = ft_strsub((char*)tl->content,
		(s - (char*)tl->content) + 1,
		ft_strlen(tl->content) - (s - (char*)tl->content));
	dprintf(2, "gnl read 2\n");
	ft_strdel(&t);
	while ((var = read(fd, *line, BUFF_SIZE)) && var != -1)
	{
		dprintf(2, "gnl read while\n");
		t = *line;
		*line = ft_strsub(*line, 0, var);
		ft_strdel(&t);
		t = tl->content;
		tl->content = ft_strjoin((char*)tl->content, *line);
		ft_strdel(&t);
		if (ft_strchr(tl->content, '\n'))
			break ;
	}
	ft_strdel(line);
	dprintf(2, "gnl read end\n");
	return (var);
}

int			get_next_line(const int fd, char **line)
{
	char				*s;
	static t_list		*tl;
	int					var;
	t_list				*t;


	dprintf(2, "gnl\n");
	if (!line || !(*line = ft_strnew((BUFF_SIZE))) || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	t = tl;
	while (tl && tl->content_size != (size_t)fd)
	{
		dprintf(2, "gnl while\n");
		tl = tl->next;
		if (t->content_size == tl->content_size)
			break ;
	}
	if (!tl || tl->content_size != (size_t)fd)
		tl = ft_makelst(tl, *line, fd);
	if ((var = read_buf(fd, line, tl)) == -1)
		return (-1);
	if (!((s = ft_strchr(tl->content, '\n'))))
		s = ft_strchr(tl->content,
			((char *)tl->content)[ft_strlen(tl->content)]);
	*line = ft_strsub((char*)tl->content, 0, s - (char*)tl->content);
	if (!((char *)tl->content)[0] && !var)
		return (0);

	dprintf(2, "gnl end\n");
	return (1);
}
