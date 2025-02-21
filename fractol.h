/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:49:20 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:17 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> 
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h> 
# include <unistd.h> 
# include <math.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_comp_num
{
	double	x;
	double	y;
}	t_comp_num;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	hypotenuse;
	int		max_iter;
	double	x_shift;
	double	y_shift;
	double	zoom_factor;
	double	ju_x;
	double	ju_y;
}	t_fractol;

# define ERROR_PART1 "Error: Invalid Parameters: "
# define ERROR_PART2 "Please use the following options:\n"
# define ERROR_PART3 "[1]- ./fractol mandelbrot\n"
# define ERROR_PART4 "[2]- ./fractol julia <r_num> <i_num>\n"

# define WIDTH	800
# define HEIGHT	800

# define BLACK       			0x000000
# define WHITE       			0xFFFFFF
# define RED         			0xFF0000
# define GREEN       			0x00FF00
# define BLUE        			0x0000FF
# define MAGENTA_BURST   		0xFF00FF
# define LIME_SHOCK      		0xCCFF00
# define NEON_ORANGE     		0xFF6600
# define AQUA_DREAM				0x33CCCC
# define HOT_PINK				0xFF66B2
# define ELECTRIC_BLUE			0x0066FF
# define LAVA_RED       		0xFF3300
# define PSYCHEDELIC_PURPLE   	0x8000FF
# define TRIPPY_TEAL          	0x00FFFF
# define ELECTRIC_LIME        	0xCCFF00
# define VIBRANT_ORANGE       	0xFFA500
# define PSYCHEDELIC_PINK     	0xFF1493
# define NEON_YELLOW          	0xFFFF00
# define PSYCHEDELIC_LAVENDER   0xE6E6FA
# define SOFT_PINK              0xFFB6C1
# define LIGHT_CORAL            0xF08080
# define PALE_GOLDENROD         0xEEE8AA
# define LIGHT_SEA_GREEN        0x20B2AA
# define SOFT_CREAM   			0xFDFFE2 
# define SKY_BLUE     			0x83B4FF
# define DEEP_BLUE   			0x5A72A0
# define MIDNIGHT_BLUE			0x1A2130 

int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2, int n);
double		ft_atod(const char *str);
void		rendering_fractol(t_fractol *fractol);
void		initialize_fractol(t_fractol *fractol);
void		pixels_draw(int x, int y, t_fractol *fractol);
void		toggel_set_values(t_comp_num *z, t_comp_num *c, t_fractol *fractol);
void		ft_put_pixels(int x, int y, t_img *img, int color);
t_comp_num	square_comp_num(t_comp_num z);
t_comp_num	sum_comp_num(t_comp_num z, t_comp_num c);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
void		listen_to_events(t_fractol *fractol);
void		initialize_data(t_fractol *fractol);
void		malloc_exit_error(char *str);
int			close_func(t_fractol *fractol);
int			key_func(int keysym, t_fractol *fractol);
int			mouse_func(int button, int x, int y, t_fractol *fractol);
void		exit_error(char *str);
int			parse_ju_arg(char **av);
int			ft_check_float(char *str);
int			ft_isdigit(int c);
long		integer_handel(const char **str, int *sign);

#endif
