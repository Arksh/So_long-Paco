/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:26:05 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 17:26:59 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_location	*new_location(char *img, int x, int y)
{
	t_location	*loc;

	loc = (t_location *)ft_calloc(sizeof(*loc), 1);
	loc->img = img;
	loc->next = NULL;
	loc->x = x;
	loc->y = y;
	return (loc);
}

void	add_location_back(t_location **list, t_location *new_loc)
{
	t_location	*last;

	if (list)
	{
		if (*list)
		{
			last = last_loc(*list);
			last->next = new_loc;
		}
		else
			*list = new_loc;
	}
}

t_location	*last_loc(t_location *loc)
{
	while (loc)
	{
		if (!loc->next)
			return (loc);
		loc = loc->next;
	}
	return (loc);
}
