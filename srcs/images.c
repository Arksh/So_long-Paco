/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:47:55 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 17:29:14 by fraalmei         ###   ########.fr       */
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
		free (line);
		line = get_next_line(file);
	}
	free (line);
	close (file);
	return (size);
}

	// function to search into directory the .xmp files
int	higher_size_assets(void)
{
	t_size			size;
	DIR				*d;
	struct dirent	*dir;
	t_size			size_swap;
	char			*c;

	size.width = 0;
	size.height = 0;
	d = opendir("./assets");
	if (d)
	{
		dir = readdir(d);
		while ((dir))
		{
			if (ft_strncmp(dir->d_name, ".xpm", 4) > -1)
			{
				c = ft_strjoin("./assets/", dir->d_name);
				size_swap = detect_image_size(c);
				free (c);
			}
			dir = readdir(d);
		}
		closedir(d);
	}
	return (0);
}

char	*check_image(char i)
{
	if (i == '1')
		return ("./assets/wall.xpm");
	//else if (i == '0')
	else
		return ("./assets/floor.xpm");
	/* else if (i == 'P')
		return ("./assets/floor.xpm");
	else if (i == 'E')
		return ("./assets/floor.xpm");
	else if (i == 'C')
		return ("./assets/floor.xpm"); */
	return (NULL);
}
