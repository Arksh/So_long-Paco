/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:47:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 16:34:26 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <dirent.h>

	// open the .xmp files and detect the pixels
t_size	detect_image_size(char *dir)
{
	t_size	size;
	char	*line;
	int		file;
	int		i;

	i = -1;
	size.width = 0;
	size.height = 0;
	file = open(dir, O_RDONLY);
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
	(free (line), close (file));
	return (size);
}

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

char	*check_map_image(char i)
{
	if (i == '1')
		return ("./assets/wall.xpm");
	else if (i == 'E')
		return ("./assets/door.xpm");
	else
		return ("./assets/floor.xpm");
	return (NULL);
}

char	*check_object_image(char i)
{
	if (i == 'P')
		return ("./assets/player.xpm");
	else if (i == 'C')
		return ("./assets/key.xpm");
	return (NULL);
}
