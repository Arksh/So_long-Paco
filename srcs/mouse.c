/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:56:41 by fraalmei          #+#    #+#             */
/*   Updated: 2023/02/28 15:46:59 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// 
	// 
int	read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
	int			x;
	int			y;
	t_img		*img;
	t_square	s;

	img = (t_img *) param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color(0)};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	(void)button;
	return (0);
}

int	follow_mouse(int mouse_x, int mouse_y, void *param)
{
	int			x;
	int			y;
	t_img		*img;
	t_square	s;

	img = (t_img *) param;
	if (!img)
		return (-1);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->w || mouse_y > img->h)
		return (2);
	if (!follow)
		return (3);
	x = ((mouse_x % img->w) / size) * size;
	y = ((mouse_y % img->h) / size) * size;
	s = (t_square){x, y, size, get_color(0)};
	draw_square(s, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
	return (0);
}
