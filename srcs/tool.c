/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/17 23:40:48 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 16:22:06 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		valid(t_filler *filler, int x, int y)
{
	int		s;
	int		i;
	int		j;
	int		c;

	s = 0;
	c = 0;
	while (filler->star[s] != -1)
	{
		i = filler->star[s] + x;
		j = filler->star[s + 1] + y;
		if (filler->map[i][j] == filler->c_p2)
			return (0);
		if (filler->map[i][j] == filler->c_p1)
			++c;
		if (c == 2)
			return (0);
		s += 2;
	}
	return (c);
}

int		frame(t_filler *filler)
{
	int		i;

	i = 0;
	filler->x_frame_min = filler->p1[0];
	filler->x_frame_max = filler->p1[filler->n_p1 * 2 - 2];
	filler->y_frame_max = filler->p1[1];
	filler->y_frame_min = filler->p1[1];
	while (filler->p1[i] != -1)
	{
		if (filler->p1[i + 1] < filler->y_frame_min)
			filler->y_frame_min = filler->p1[i + 1];
		if (filler->p1[i + 1] > filler->y_frame_max)
			filler->y_frame_max = filler->p1[i + 1];
		i += 2;
	}
	return (1);
}

int		del(t_filler *filler)
{
	int		i;

	if (filler->map)
	{
		i = -1;
		while (++i < X_MAP)
			if (filler->map[i])
				free(filler->map[i]);
		free(filler->map);
	}
	if (filler->piece)
		free(filler->piece);
	if (filler->star)
		free(filler->star);
	if (filler->p1)
		free(filler->p1);
	if (filler->p2)
		free(filler->p2);
	ft_bzero(filler, sizeof(t_filler));
	return (1);
}

void	get_rep(t_filler *filler, int dif, int x, int y)
{
	filler->i_best = dif;
	filler->x_rep = x;
	filler->y_rep = y;
}
