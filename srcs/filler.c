/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:20:26 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 05:48:58 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/filler.h"

int		player_two(t_filler *filler, char c)
{
	int		p;
	int		x;
	int		y;

	if (!(filler->p2 = malloc((filler->n_p2 * 2 + 1) * 4)))
		return (0);
	p = -1;
	x = -1;
	while (++x < filler->x_map && (y = -1))
		while (++y < filler->y_map)
			if (filler->map[x][y] == c)
				if ((x > 0 && filler->map[x - 1][y] != c) ||
						(y < Y_MAP - 1 && filler->map[x][y + 1] != c) ||
							(x < X_MAP - 1 && filler->map[x + 1][y] != c) ||
								(y > 0 && filler->map[x][y - 1] != c))
				{
					filler->p2[++p] = x;
					filler->p2[++p] = y;
				}
	filler->p2[++p] = -1;
	return (1);
}

int		player_one(t_filler *filler, char c)
{
	int		p;
	int		x;
	int		y;

	if (!(filler->p1 = malloc((filler->n_p1 * 2 + 1) * 4)))
		return (0);
	p = -1;
	x = -1;
	while (++x < filler->x_map && (y = -1))
		while (++y < filler->y_map)
			if (filler->map[x][y] == c)
			{
				filler->p1[++p] = x;
				filler->p1[++p] = y;
			}
	filler->p1[++p] = -1;
	return (1);
}

int		map(t_filler *filler, char p1, char p2)
{
	char	*line;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < filler->x_map && get_next_line(0, &line))
	{
		tmp = line;
		line = ft_strwhile(line, ft_isdigit) + 1;
		ft_memcpy(filler->map[i], ft_strupper(line), Y_MAP);
		free(tmp);
	}
	i = -1;
	while (++i < filler->x_map && (j = -1))
		while (++j < filler->y_map)
		{
			if (filler->map[i][j] == p1)
				++filler->n_p1;
			if (filler->map[i][j] == p2)
				++filler->n_p2;
		}
	return (player_one(filler, p1) && player_two(filler, p2));
}

int		init(t_filler *filler)
{
	int		x;

	if (!(filler->map = malloc(sizeof(char **) * filler->x_map)))
		return (del(filler));
	x = -1;
	while (++x < filler->x_map)
	{
		if (!(filler->map[x] = malloc(sizeof(char *) * (filler->y_map + 1))))
			return (0);
		filler->map[x][filler->y_map] = '\0';
	}
	get_next_free(0);
	return (1);
}

int		main(void)
{
	t_filler	filler;
	char		*line;
	char		*tmp;

	ft_bzero(&filler, sizeof(t_filler));
	get_next_line(0, &line);
	filler.c_p1 = *(line + 10) == '1' ? 'O' : 'X';
	filler.c_p2 = filler.c_p1 == 'O' ? 'X' : 'O';
	free(line);
	if (get_next_line(0, &line) && ft_strncmp(line, "Plateau", 7))
		return (ft_free_zero(line));
	tmp = line;
	line += 8;
	filler.x_map = ft_atoi_ptr(&line);
	filler.y_map = ft_atoi_ptr(&line);
	free(tmp);
	if (!(init(&filler)))
		return (del(&filler));
	if (!(play(&filler)))
		return (del(&filler));
}
