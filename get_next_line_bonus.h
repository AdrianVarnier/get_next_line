/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:10:58 by avarnier          #+#    #+#             */
/*   Updated: 2020/02/05 14:17:07 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen_nl(char *s);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	*ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, void *src, size_t len);

#endif
