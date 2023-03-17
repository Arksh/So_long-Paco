/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:51 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 17:29:34 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_prog	read_map(char *argv)
{
	t_prog	data;
	t_size	size_map;
	t_size	size_img;
	int		file;

	size_map = check_map(argv);
	size_img = higher_size_assets();
	size_map.width = size_map.width * size_img.width;
	size_map.height = size_map.height * size_img.height;
	data.win = new_program(size_map, size_img, "New program");
	file = open(argv, O_RDONLY);
	data.map = create_map(file, data);
	close (file);
	return (data);
}

t_map	*create_map(int file, t_prog data)
{
	t_location	*init;
	char		*line;
	t_cords		i;

	i.y = 0;
	init = NULL;
	line = get_next_line(file);
	while (line)
	{
		i.x = 0;
		while (line[i.x] && line[i.x] != '\n')
		{
			add_location_back(&init, new_location(mlx_xpm_file_to_image(\
				data.win.mlx_ptr, check_map_image(line[i.x]), \
				(int *)&data.win.size_map.width, \
				(int *)&data.win.size_map.height), \
				create_object(mlx_xpm_file_to_image(data.win.mlx_ptr, \
				check_object_image(line[i.x]), (int *)&data.win.size_map.width, \
				(int *)&data.win.size_map.height), i, line[i.x]), i, \
				line[i.x]));
			i.x++;
		}
		line = (free (line), i.y++, get_next_line(file));
	}
	free (line);
	return (new_map(init, i));
}

t_map	*new_map(t_location *init, t_cords cords)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(*map), 1);
	map->init = init;
	map->cords = cords;
	return (map);
}
