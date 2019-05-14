/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_free.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/15 23:52:45 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 02:11:32 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	get_next_free(const int fd)
{
	char	*line;

	get_next_line(fd, &line);
	free(line);
}
