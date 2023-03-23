/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:43 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 10:00:57 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to create a object
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

	// function to check the numbers of collectionables
	// if the collectables reach 0 open the door
void	check_collectables(t_location next, t_prog *data)
{
	if (next.objt)
	{
		if (next.objt->name == 'C')
		{
			free(next.objt);
			next.img = NULL;
			next.name = '0';
			data->map->collectables--;
		}
		if (data->map->collectables == 0)
		{
			data->exit->name = 'O';
			locate_location(data->map->init, data->exit->cords.x, \
				data->exit->cords.y)->name = 'O';
		}
	}
}

	// function to check the door is open
	// and end the program if its true
void	check_exit(t_location loc, t_prog *data)
{
	if (loc.name == 'O')
	{
		loc.img = NULL;
		loc.name = '0';
		exit_program(&data->win, 3);
	}
}
