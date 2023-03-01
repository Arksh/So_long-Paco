/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:12:10 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/01 17:23:41 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	main(void)
{
	t_win	game;
	t_img	img;

	game = new_program(1920, 1080, "Animations");
	img = new_img(1920, 1080, game);
	draw_square((t_square){400, 400, 200, 0x00FFFFFF}, img);
	draw_circle((t_circle){100, 120, 23, 0x0002f999}, img);
	draw_circle((t_circle){150, 250, 15, 0x00f022bf}, img);
	draw_rect((t_rect){10, 10, 20, 50, 0x005F5599}, img);
	draw_rect((t_rect){70, 200, 10, 50, 0x0012daf1}, img);
	penguin(&img);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img_ptr, 0, 0);
	mlx_key_hook(game.win_ptr, read_keys, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_program, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}

	// mlx_hook is a funtion to trigger on a event
	// mlx_hook (program.window, type_event, mask, function to call, &program)
