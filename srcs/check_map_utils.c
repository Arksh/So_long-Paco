/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:55:53 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/25 09:38:46 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// second part of the funtion to check the necesary objects in the map
int	check_line_objects(int i[6], char *line)
{
	while (line[i[0]])
	{
		if (line[i[0]] == 'P')
			i[1]++;
		else if (line[i[0]] == 'C')
			i[2]++;
		else if (line[i[0]] == 'E')
			i[3]++;
		else if (line[i[0]] != 'E' && line[i[0]] != 'P' && line[i[0]] != 'C' \
				&& line[i[0]] != '1' && line[i[0]] != '0' && line[i[0]] != '\n')
			i[5] = -1;
		i[0]++;
	}
	return (*i);
}

	// funtion to check the if is it a correct path to end the game
int	check_path(t_prog data)
{
	int		i;

	clean_map(data.map->init);
	i = flood_map(data.player->loc, 'C');
	if (i != data.map->collectables)
		return (1);
	clean_map(data.map->init);
	i = flood_map(data.player->loc, 'E');
	if (i != 1)
		return (1);
	clean_map(data.map->init);
	return (-1);
}

	// function to flood the map from the player position
int	flood_map(t_location *loc, char c)
{
	int		i;

	i = 0;
	if (loc->name == '0')
		loc->name = 'X';
	i += flooding_map(loc->north, c);
	i += flooding_map(loc->east, c);
	i += flooding_map(loc->south, c);
	i += flooding_map(loc->west, c);
	return (i);
}

	// second part of the flood map
int	flooding_map(t_location *loc, char c)
{
	int			i;

	i = 0;
	if (loc->objt && loc->objt->name != '1')
	{
		if (loc->objt->name == c && loc->name == '0')
			i++;
		i += flood_map(loc, c);
	}
	else if (loc->objt && loc->objt->name == '1')
	{
	}
	else if (loc->name == '0')
		i += flood_map(loc, c);
	return (i);
}

	// clean the map to nae the locations to 0
void	clean_map(t_location *loc)
{
	t_location	*swap1;
	t_location	*swap2;

	swap1 = loc;
	swap2 = loc;
	while (swap1)
	{
		if (swap1->name == 'X')
			swap1->name = '0';
		if (swap1->east)
			swap1 = swap1->east;
		else
		{
			swap1 = swap2->south;
			swap2 = swap2->south;
		}
	}
}
