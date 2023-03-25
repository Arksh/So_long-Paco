/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:26:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/24 17:55:37 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to create a new location
t_location	*new_location(char *img, t_object *objt, t_cords cord, char name)
{
	t_location	*loc;

	loc = (t_location *)ft_calloc(sizeof(*loc), 1);
	loc->img = img;
	loc->objt = objt;
	loc->north = NULL;
	loc->south = NULL;
	loc->east = NULL;
	loc->west = NULL;
	loc->cords.x = cord.x;
	loc->cords.y = cord.y;
	loc->name = name;
	return (loc);
}

	// funtion to add a location to the last position
void	add_location_back(t_location **list, t_location *new_loc)
{
	t_location	*west;
	t_location	*north;

	west = NULL;
	north = NULL;
	if (*list)
	{
		if (new_loc->cords.y > 0)
		{
			north = locate_location(*list, new_loc->cords.x, \
				new_loc->cords.y - 1);
			new_loc->north = north;
			north->south = new_loc;
		}
		if (new_loc->cords.x > 0)
		{
			west = locate_location(*list, new_loc->cords.x - 1, \
				new_loc->cords.y);
			new_loc->west = west;
			west->east = new_loc;
		}
	}
	else
		*list = new_loc;
}

	// function to find the last position
t_location	*last_loc(t_location *loc)
{
	while (loc->south)
		loc = loc->south;
	while (loc->east)
		loc = loc->east;
	return (loc);
}

	// function to locate a location in a map
	// the start of the map and the coordinates needed
t_location	*locate_location(t_location *loc, size_t x, size_t y)
{
	while (loc)
	{
		if (loc->cords.x == x && loc->cords.y == y)
			return (loc);
		if (loc->south && loc->cords.y < y)
			loc = loc->south;
		else if (loc->east && loc->cords.x < x)
			loc = loc->east;
	}
	return (NULL);
}
