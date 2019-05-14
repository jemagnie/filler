/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 03:17:55 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 17:00:25 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		star(t_filler *filler)
{
	char	*piece;
	int		star;
	int		i;

	star = 0;
	i = -1;
	piece = filler->piece;
	while (piece[++i])
		if (piece[i] == '*')
			++star;
	if (!(filler->star = malloc((star * 2 + 1) * 4)))
		return (0);
	filler->star[star * 2] = -1;
	filler->nb_star = star;
	i = -1;
	star = -1;
	while (piece[++i])
		if (piece[i] == '*')
		{
			filler->star[++star] = i / filler->y_piece;
			filler->star[++star] = i % filler->y_piece;
		}
	return (1);
}

int		piece(t_filler *filler)
{
	char	*line;
	char	*tmp;
	int		i;

	get_next_line(0, &line);
	tmp = line;
	line += 5;
	filler->x_piece = ft_atoi_ptr(&line);
	filler->y_piece = ft_atoi_ptr(&line);
	free(tmp);
	if (!(filler->piece = malloc(filler->x_piece * Y_PIECE + 1)))
		return (0);
	filler->piece[filler->x_piece * filler->y_piece] = '\0';
	i = -1;
	while (++i < filler->x_piece)
	{
		get_next_line(0, &line);
		tmp = line;
		ft_memcpy(filler->piece + i * Y_PIECE, line, Y_PIECE);
		free(tmp);
	}
	return (star(filler));
}

void	check(t_filler *filler, int x, int y, int dif)
{
	int		i;
	int		j;

	i = 0;
	if (!filler->i_best)
	{
		filler->i_best = ft_abs((x + STAR[0]) - P2[0]) +
			ft_abs((y + STAR[1]) - P2[1]);
		filler->x_rep = x;
		filler->y_rep = y;
	}
	while (filler->star[i] != -1 && !(j = 0))
	{
		while (filler->p2[j] != -1)
		{
			dif = ft_abs((x + STAR[i]) - P2[j]) +
				ft_abs((y + STAR[i + 1]) - P2[j + 1]);
			if (dif < filler->i_best)
				get_rep(filler, dif, x, y);
			j += 2;
		}
		i += 2;
	}
}

int		solve(t_filler *filler)
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;

	frame(filler);
	x_max = filler->x_frame_max + 1;
	y_max = filler->y_frame_max + 1;
	if (x_max + X_PIECE > X_MAP)
		x_max = X_MAP - X_PIECE + 1;
	if (y_max + Y_PIECE > Y_MAP)
		y_max = Y_MAP - Y_PIECE + 1;
	x = filler->x_frame_min - (filler->x_piece - 1) - 1;
	x < 0 ? x = -1 : 0;
	while (++x < x_max)
	{
		y = filler->y_frame_min - (filler->y_piece - 1) - 1;
		if (y < 0)
			y = -1;
		while (++y < y_max)
			if (valid(filler, x, y))
				check(filler, x, y, 0);
	}
	ft_printf("%d %d\n", filler->x_rep, filler->y_rep);
	return (filler->i_best);
}

int		play(t_filler *filler)
{
	while (1)
	{
		if (!map(filler, filler->c_p1, filler->c_p2))
			return (0);
		if (!piece(filler))
			return (0);
		if (!solve(filler))
			return (0);
		ft_bzero(&filler->nb_star, 48);
		if (filler->piece)
			free(filler->piece);
		if (filler->star)
			free(filler->star);
		if (filler->p1)
			free(filler->p1);
		if (filler->p2)
			free(filler->p2);
		get_next_free(0);
		get_next_free(0);
	}
	return (1);
}
