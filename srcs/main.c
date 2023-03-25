/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:12:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/25 10:04:39 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	leaks(void)
{
	system ("leaks -q so_long");
}
	//atexit(leaks);

int	main(int argc, char **argv)
{
	t_prog	data;

	if (argc != 2)
		exit_program (NULL, 0);
	data = read_map(*&argv[1]);
	put_map_to_window(data);
	put_objects_map(data);
	mlx_key_hook(data.win.win_ptr, read_keys, &data);
	mlx_hook(data.win.win_ptr, 17, 0, exit_program, &data.win);
	mlx_loop(data.win.mlx_ptr);
	return (0);
}
