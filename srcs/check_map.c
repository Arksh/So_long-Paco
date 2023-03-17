/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:04:16 by p                 #+#    #+#             */
/*   Updated: 2023/03/15 11:29:48 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to call functions to cjeck the necesary element for the map
t_size	check_map(char *argv)
{
	t_size		size;

	if (check_file(argv))
		exit_program (NULL, 0);
	size = map_size(argv);
	if (size.width == 0 || size.height == 0 || \
			check_wall(argv, size) || check_objects(argv))
		exit_program (NULL, 1);
	return (size);
}

	// function to check the file exists and can be read
int	check_file(char *argv)
{
	int			file;

	if (ft_strnstr(argv, ".ber", ft_strlen(argv)) == 0)
		return (-1);
	file = open(argv, O_RDONLY);
	if (file < 0 || read(file, 0, 0) < 0)
	{
		close (file);
		return (-1);
	}
	return (0);
}

	// function to check the correct number of element in the map
int	check_objects(char *argv)
{
	char		*line;
	int			file;
	int			i[4];

	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	file = open(argv, O_RDONLY);
	line = get_next_line(file);
	while (line)
	{
		i[0] = 0;
		while (line[i[0]])
		{
			if (line[i[0]] == 'P')
				i[1]++;
			else if (line[i[0]] == 'C')
				i[2]++;
			else if (line[i[0]] == 'E')
				i[3]++;
			i[0]++;
		}
		line = (free (line), get_next_line(file));
	}
	(free (line), close (file));
	if (i[1] != 1 || i[2] == 0 || i[3] != 1)
		return (-1);
	return (0);
}

	// function to check the wall arround the map
int	check_wall(char *argv, t_size size)
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
	(free (line), close (file));
	return (0);
}

	// functio to check the correct size of the map
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
	{
		if (ft_strchr(line, '\n') && size.width + 1 != ft_strlen(line))
		{
			size.width = 0;
			return (size);
		}
		else if (!ft_strchr(line, '\n') && size.width != ft_strlen(line))
		{
			size.width = 0;
			return (size);
		}
		line = (free(line), size.height++, get_next_line(file));
	}
	(free (line), close (file));
	return (size);
}
