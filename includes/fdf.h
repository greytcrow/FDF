/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ielkatra <ielkatra@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 18:07:19 by ielkatra     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 17:56:54 by ielkatra    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <string.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
typedef struct	s_matrix
{
	double		matrix[3][3];
}				t_matrix;

typedef struct	s_point
{
	double		vector3d[3];
}				t_point;

typedef struct	s_2dpoint
{
	double		vector2d[2];
}				t_2dpoint;

typedef struct	s_map
{
	t_point		*coord;
	size_t		width;
	size_t		height;
}				t_map;

typedef struct	s_transmap
{
	t_2dpoint	*coord2d;
	size_t		width;
	size_t		height;
}				t_transmap;

typedef struct	s_bresenham
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_bresenham;

typedef struct	s_bresenparms
{
	int			x;
	int			y;
	int			z;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	int			widthmax;
	int			heightmax;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		space;
	int			zoom;
	int			xoffset;
	int			yoffset;
	int			extrusion;
}				t_bresenparms;

typedef struct	s_angle
{
	int			x;
	int			y;
	int			z;
}				t_angle;

t_matrix		mult_matrix(t_matrix aa, t_matrix bb);
void			ft_init_matrix(t_matrix *a);
t_matrix		xrotation(t_matrix a, double angle);
t_matrix		yrotation(t_matrix a, double angle);
t_matrix		zrotation(t_matrix a, double angle);
int				parsing(int fd, t_map *space,char *string);
t_map			spacerotation(t_map space, double angle, char axis);
void			bresenhamdraw(t_bresenparms p);
t_map			mapcreation(int fd, char *);
t_transmap		projection(t_map threed, t_bresenparms p);
void			init_vector(t_point *a);
t_point			mult_vector(t_matrix a, t_point b);
t_point			xvectorrotation(t_point a, double angle);
t_point			yvectorrotation(t_point a, double angle);
t_point			zvectorrotation(t_point a, double angle);
int				hook_key(int key, t_bresenparms *p);
t_map			rotation_input(t_map space, t_bresenparms *t);
int				displaymap(t_transmap map2d, t_bresenparms p);
int				mouse_hook(int button, int x, int y, t_bresenparms *t);
int				is_directory(char *accessdir);
int				count(char **tableau);
void			usage_case(void);
void	free_data(char *line,char **list);

#endif
