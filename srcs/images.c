/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:47:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 11:54:44 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// open the .xmp files and detect the pixels
t_size	detect_image_size(char *dir)
{
	t_size	size;
	int		file;
	int		i;

	i = -1;
	size.width = 0;
	size.height = 0;
	file = open(dir, O_RDONLY);
	size = count_image_size(i, file, size);
	close (file);
	return (size);
}

	// function to calculate the size of an image
t_size	count_image_size(int i, int file, t_size size)
{
	char	*line;

	line = get_next_line(file);
	while (line)
	{
		if (ft_strncmp(line, "/* pixels */", 12) == 0 && i == -1)
			i = 0;
		else if (ft_strncmp(line, "};", 2) > -1 && i == 0)
		{
			i = -1;
			free (line);
			return (size);
		}
		else if (i == 0)
		{
			if (ft_strlen(line) - 4 > size.width)
				size.width = ft_strlen(line) - 4;
			size.height++;
		}
		line = (free (line), get_next_line(file));
	}
	free (line);
	return (size);
}

	// travel all visible characters to detect all files
	// and detect the  maximun size between them
t_size	higher_size_assets(void)
{
	t_size	size;
	t_size	size_swap;
	char	c;

	c = 32;
	size.width = 0;
	size.height = 0;
	while (c < 126)
	{
		if (check_map_image(c))
			size_swap = detect_image_size(check_map_image(c));
		else if (check_object_image(c))
			size_swap = detect_image_size(check_object_image(c));
		if (size_swap.width > size.width)
			size.width = size_swap.width;
		if (size_swap.height > size.height)
			size.height = size_swap.height;
		c++;
	}
	return (size);
}

	// function to check the char of the map and return it file
char	*check_map_image(char i)
{
	if (i != '1')
		return ("./textures/floor.xpm");
	return (NULL);
}

	// function to check the char of the map and return it file
char	*check_object_image(char i)
{
	if (i == '1')
		return ("./textures/wall.xpm");
	else if (i == 'P')
		return ("./textures/player.xpm");
	else if (i == 'C')
		return ("./textures/key.xpm");
	else if (i == 'O')
		return ("./textures/door_closed.xpm");
	else if (i == 'E')
		return ("./textures/door_open.xpm");
	return (NULL);
}
