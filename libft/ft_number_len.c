/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_number_len.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:59:07 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 19:22:30 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(int n, const int base)
{
	if (n < 0)
		return ((n / base ? 2 : 1) + ft_intlen_base(-(n / base), base));
	return (n < base ? 1 : 1 + ft_intlen_base(n / base, base));
}

int		ft_long_len(const long n)
{
	long	value;
	int		i;

	i = 0;
	value = n < 0 ? -n : n;
	if (!n)
		return (1);
	while (value)
	{
		i++;
		value /= 10;
	}
	return (i);
}

int		ft_ulong_base_len(unsigned long n, const int base)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}
