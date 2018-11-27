/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:32:17 by akupriia          #+#    #+#             */
/*   Updated: 2017/12/12 10:32:17 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000

# include <fcntl.h>
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);
t_list	*ft_makelst(t_list *list, void const *content, size_t content_size);

#endif
