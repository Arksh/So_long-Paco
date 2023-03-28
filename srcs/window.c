/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:41:15 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/25 15:00:59 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to create the program (mlx + window)
t_win	new_program(t_size map, t_size img, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, map.width, map.height, \
		str), map, img});
}

	// function to exit the program
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
	else if (i == 3)
		ft_printf("Completado.\n");
	else if (i == 4)
		ft_printf("Error al reservar.\n");
	else if (i == 5)
		ft_printf("Imagen faltante.\n");
	exit(EXIT_SUCCESS);
}
	//system("leaks so_long");

	// function to print the map on the window
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
				put_img(swap_x->img, swap_x->cords, &data);
			swap_x = swap_x->east;
		}
		swap_y = swap_y->south;
	}
}

	// funtion to print the objects on the window
void	put_objects_map(t_prog data)
{
	t_location	*swap_x;
	t_location	*swap_y;

	swap_y = data.map->init;
	while (swap_y)
	{
		swap_x = swap_y;
		while (swap_x)
		{
			if (swap_x->objt)
				put_img(swap_x->objt->img, swap_x->objt->cords, &data);
			swap_x = swap_x->east;
		}
		swap_y = swap_y->south;
	}
}

int	put_img(void *img, t_cords cords, t_prog *data)
{
	if (!img)
		exit_program(&data->win, 5);
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
				img, data->win.size_img.width * ((int)cords.x), \
				data->win.size_img.height * ((int)cords.y));
	return (0);
}
