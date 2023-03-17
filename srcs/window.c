/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:41:15 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 15:30:16 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_win	new_program(t_size map, t_size img,char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, map.width, map.height, \
		str), map, img});
}

int	exit_program(t_win *window, int i)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	if (i == 0)
		ft_printf("Error, no se ha encontrado archivo compatible.\n");
	else if (i == 1)
		ft_printf("Error, mapa erroneo.\n");
	else if (i == 2)
		ft_printf("Error, no existe el archivo.\n");
	//system("leaks so_long");
	exit(EXIT_SUCCESS);
}

void	put_map_to_window(t_prog data)
{
	t_location	*swap_x;
	t_location	*swap_y;

	swap_y = data.map->init;
	while (swap_y)
	{
		swap_x = swap_y;
		while (swap_x)
		{
			if (swap_x->img)
				mlx_put_image_to_window(data.win.mlx_ptr, data.win.win_ptr, \
					swap_x->img, data.win.size_img.width * \
					(int)swap_x->cords.x, \
					data.win.size_img.height * (int)swap_x->cords.y);
			swap_x = swap_x->east;
		}
		swap_y = swap_y->south;
	}
}

void	put_objects_map(t_prog *data)
{
	t_location	*swap_x;
	t_location	*swap_y;

	swap_y = data->map->init;
	while (swap_y)
	{
		swap_x = swap_y;
		while (swap_x)
		{
			if (swap_x->objt)
			{
				mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					swap_x->objt->img, data->win.size_img.width * \
					(int)swap_x->cords.x, data->win.size_img.height * \
					(int)swap_x->cords.y);
				if (swap_x->objt->name == 'P')
				{
					data->player = swap_x->objt;
					data->player->loc = swap_x;
				}
			}
			swap_x = swap_x->east;
		}
		swap_y = swap_y->south;
	}
}
