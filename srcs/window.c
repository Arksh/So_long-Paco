/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:41:15 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 17:29:59 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <map.h>
/* 
t_prog start_program()
{
	t_prog	data;

	return (data);
}
 */
t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

int	exit_program(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	//system("leaks so_long");
	exit(EXIT_SUCCESS);
}

void	put_map_to_window(int loc_widht, int loc_height, t_prog data)
{
	t_location	*swap;

	swap = data.map->init;
	while (swap)
	{
		if (swap->img)
			mlx_put_image_to_window(data.win.mlx_ptr, data.win.win_ptr, \
				swap->img, loc_widht * swap->x, loc_height * swap->y);
		swap = swap->next;
	}
}

