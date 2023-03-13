/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:12:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 16:23:35 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <window.h>
#include <map.h>

void leaks()
{
	system ("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_prog	data;

	//atexit(leaks);
	if (argc != 2)
		exit (EXIT_SUCCESS);
	data = read_map(*&argv[1]);
	//higher_size_assets();
	put_map_to_window(16, 16, data);
	mlx_hook(data.win.win_ptr, 17, 0, exit_program, &data.win);
	mlx_loop(data.win.mlx_ptr);
	return (0);
}

/* int	main(void)
{
	t_program	data;

	data.name = "Nuevo programa";
	data.mlx_ptr = mlx_init();
	data.width = 1500;
	data.height = 1000;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width, \
		data.height, data.name);
	data.x = 200;
	data.y = 100;
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/image.xpm", \
		&data.width, &data.height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
 */

//data.map->first = new_location("./assets/image.xpm", 0, 0, NULL, data.win);
