/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:04:01 by mel-atti          #+#    #+#             */
/*   Updated: 2024/07/01 17:37:38 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rendering_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels_draw(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}

void	pixels_draw(int x, int y, t_fractol *fractol)
{
	t_comp_num	z;
	t_comp_num	c;
	int			counter;
	int			color;

	z.x = (map(x, -2, 2, 800) * fractol->zoom_factor) + fractol->x_shift;
	z.y = (map(y, 2, -2, 800) * fractol->zoom_factor) + fractol->y_shift;
	toggel_set_values(&z, &c, fractol);
	counter = 0;
	while (counter < fractol->max_iter)
	{
		z = sum_comp_num(square_comp_num(z), c);
		if (((z.x * z.x) + (z.y * z.y)) > (fractol->hypotenuse))
		{
			color = map(counter, BLACK, WHITE, fractol->max_iter);
			ft_put_pixels(x, y, &fractol->img, color);
			return ;
		}
		counter++;
	}
	ft_put_pixels(x, y, &fractol->img, BLACK);
}

void	toggel_set_values(t_comp_num *z, t_comp_num *c, t_fractol *fractol)
{
	if (!ft_strncmp("julia", fractol->name, 5))
	{
		c->x = fractol->ju_x;
		c->y = fractol->ju_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_put_pixels(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
