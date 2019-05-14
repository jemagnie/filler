/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strwhile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 14:33:11 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 19:30:57 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwhile(const char *s, int (*f)(int))
{
	while ((*f)(*s))
		s++;
	return ((char *)s);
}
