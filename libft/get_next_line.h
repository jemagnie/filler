/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/25 21:51:55 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 14:52:02 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct		s_gnl
{
	char			buff[BUFF_SIZE];
	int				ret;
	int				start;
	int				len;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
