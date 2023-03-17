/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:43 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 17:39:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_object	*create_object(char *img, t_cords cord, char c)
{
	t_object	*object;

	object = NULL;
	if (check_object_image(c))
	{
		object = (t_object *)ft_calloc(sizeof(*object), 1);
		object->img = img;
		object->name = c;
		object->cords.x = cord.x;
		object->cords.y = cord.y;
	}
	return (object);
}

int	move_up(t_prog *data)
{
	t_location	*swap;

	if (data->player->loc->north->obj != '1')
	{
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->loc->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		data->player->cords.y--;
		swap = data->player->loc->north;
		data->player->loc->north->objt = data->player;
		data->player->loc->objt = NULL;
		data->player->loc = swap;
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		return (1);
	}
	return (0);
}

int	move_down(t_prog *data)
{
	t_location	*swap;

	if (data->player->loc->south->obj != '1')
	{
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->loc->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		data->player->cords.y++;
		swap = data->player->loc->south;
		data->player->loc->south->objt = data->player;
		data->player->loc->objt = NULL;
		data->player->loc = swap;
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		return (1);
	}
	return (0);
}

int	move_left(t_prog *data)
{
	t_location	*swap;

	if (data->player->loc->west->obj != '1')
	{
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->loc->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		data->player->cords.x--;
		swap = data->player->loc->west;
		data->player->loc->west->objt = data->player;
		data->player->loc->objt = NULL;
		data->player->loc = swap;
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		return (1);
	}
	return (0);
}

int	move_right(t_prog *data)
{
	t_location	*swap;

	if (data->player->loc->east->obj != '1')
	{
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->loc->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		data->player->cords.x++;
		swap = data->player->loc->east;
		data->player->loc->east->objt = data->player;
		data->player->loc->objt = NULL;
		data->player->loc = swap;
		mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, \
					data->player->img, data->win.size_img.width * \
					(int)data->player->cords.x, data->win.size_img.height * \
					(int)data->player->cords.y);
		return (1);
	}
	return (0);
}
