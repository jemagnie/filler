/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 21:20:51 by jemagnie     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 15:38:38 by jemagnie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define NAME		"jemagnie.filler"

# define ABS(value)	(value < 0 ? -value : value)
# define Y_MAP		filler->y_map
# define X_MAP		filler->x_map
# define Y_PIECE	filler->y_piece
# define X_PIECE	filler->x_piece
# define MAP		filler->map
# define P1			filler->p1
# define P2			filler->p2
# define STAR		filler->star
# define P1			filler->p1
# define P2			filler->p2

typedef struct		s_filler
{
	char			**map;
	char			*piece;
	int				*star;
	int				*p1;
	int				*p2;
	char			c_p1;
	char			c_p2;
	int				x_map;
	int				y_map;
	int				nb_star;
	int				n_p1;
	int				n_p2;
	int				x_piece;
	int				y_piece;
	int				x_frame_max;
	int				x_frame_min;
	int				y_frame_max;
	int				y_frame_min;
	int				i_best;
	int				x_rep;
	int				y_rep;
}					t_filler;

int					play(t_filler *filler);
int					map(t_filler *filler, char p1, char p2);
int					del(t_filler *filler);
int					frame(t_filler *filler);
int					valid(t_filler *filler, int x, int y);
void				get_rep(t_filler *filler, int dif, int x, int y);

#endif
