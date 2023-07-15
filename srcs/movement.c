/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:19:49 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/25 10:23:28 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to call the move function and the arguments needed
int	move(t_prog *data, char c)
{
	int		i;

	i = 0;
	if (c == 'N')
		i = move_to(data, data->player->loc->north, 'y', -1);
	if (c == 'E')
		i = move_to(data, data->player->loc->east, 'x', 1);
	if (c == 'S')
		i = move_to(data, data->player->loc->south, 'y', 1);
	if (c == 'W')
		i = move_to(data, data->player->loc->west, 'x', -1);
	return (i);
}

	// function to move and check the next location
int	move_to(t_prog *data, t_location *loc, char cord, int i)
{
	char	c;

	c = '0';
	if (loc->objt)
		c = loc->objt->name;
	if (c != '1')
	{
		check_collectables(*loc, data);
		move_character(loc, data, cord, i);
		check_exit(*data->player->loc, data);
		return (1);
	}
	return (0);
}

	// function to move the images of the player and the floor
void	move_character(t_location *next, t_prog *data, char c, int i)
{
	t_location	*swap;

	if (data->player->cords.x == data->exit->cords.x && \
			data->player->cords.y == data->exit->cords.y)
	{
		put_img(data->player->loc->img, data->player->cords, data);
		put_img(data->exit->img, data->exit->cords, data);
	}
	else
		put_img(data->player->loc->img, data->player->cords, data);
	data->player->cords = update_cords(data->player->cords, c, i);
	swap = next;
	next->objt = data->player;
	data->player->loc->objt = NULL;
	data->player->loc = swap;
	put_img(data->player->img, data->player->cords, data);
}

	// funtion to update the coordenates of the player when it moves
t_cords	update_cords(t_cords cord, char c, int i)
{
	if (c == 'x' && i > 0)
		cord.x++;
	if (c == 'x' && i < 0)
		cord.x--;
	if (c == 'y' && i > 0)
		cord.y++;
	if (c == 'y' && i < 0)
		cord.y--;
	return (cord);
}
