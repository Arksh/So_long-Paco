/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:51 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 17:30:11 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <window.h>
#include <map.h>

t_prog	read_map(char *argv)
{
	t_prog	data;
	int		file;
	t_size	size;

	size = map_size(argv);
	if (check_map(argv, size))
		exit (EXIT_SUCCESS);
	file = open(argv, O_RDONLY);
	data.win = new_program(size.width * 16, size.height * 16 \
		, "New program");
	data.map = create_map(file, data);
	close (file);
	return (data);
}

t_size	map_size(char *argv)
{
	t_size	size;
	char	*line;
	int		file;

	file = open(argv, O_RDONLY);
	line = get_next_line(file);
	size.width = ft_strlen(line) - 1;
	size.height = 0;
	while (line)
		line = (free(line), size.height++, get_next_line(file));
	free (line);
	close (file);
	return (size);
}

int	check_map(char *argv, t_size size)
{
	t_size		i;
	char		*line;
	int			file;

	file = open(argv, O_RDONLY);
	i.height = 1;
	line = get_next_line(file);
	while (line)
	{
		i.width = 0;
		while (line[i.width] && i.width < size.width)
		{
			if ((i.height == 0 || i.height == size.height) \
					&& line[i.width] != '1')
				return (-1);
			else if ((i.width == 0 || i.width == size.width - 1) \
					&& line[i.width] != '1')
				return (-1);
			i.width++;
		}
		line = (free (line), i.height++, get_next_line(file));
	}
	free (line);
	close (file);
	return (0);
}

t_map	*create_map(int file, t_prog data)
{
	t_location	*init;
	char		*line;
	t_size		i;

	i.height = 0;
	init = NULL;
	line = get_next_line(file);
	while (line)
	{
		i.width = 0;
		while (line[i.width] && line[i.width] != '\n')
		{
			add_location_back(&init, new_location(mlx_xpm_file_to_image(\
					data.win.mlx_ptr, check_image(line[i.width]), \
					&data.win.width, &data.win.height), i.width, i.height));
			i.width++;
		}
		i.height++;
		free (line);
		line = get_next_line(file);
	}
	free (line);
	return (new_map(init, i.width, i.height));
}


t_map	*new_map(t_location *init, int x, int y)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(*map), 1);
	map->init = init;
	map->x = x;
	map->y = y;
	return (map);
}
