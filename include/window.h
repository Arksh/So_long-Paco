/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/13 17:29:56 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <so_long.h>
# include <map.h>

typedef struct s_size
{
	size_t		width;
	size_t		height;
}				t_size;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
}				t_win;

typedef struct s_location
{
	void				*img;
	int					x;
	int					y;
	struct s_location	*next;
}						t_location;

typedef struct s_map
{
	struct s_location	*init;
	int					x;
	int					y;
}						t_map;

typedef struct s_prog
{
	t_win			win;
	t_map			*map;
}					t_prog;

/* typedef struct s_program
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		x;
	int		y;
	void	*img;
} */

	// window
t_win		new_program(int w, int h, char *str);
int			exit_program(t_win *window);
void		put_map_to_window(int loc_widht, int loc_height, t_prog data);

	// map
t_prog		read_map(char *argv);
t_size		map_size(char *argv);
int			check_map(char *argv, t_size size);
t_map		*create_map(int file, t_prog data);
t_map		*new_map(t_location *init, int x, int y);

	// locations
t_location	*new_location(char *img, int x, int y);
void		add_location_back(t_location **list, t_location *new_loc);
t_location	*last_loc(t_location *loc);

	// images
t_size		detect_image_size(char *dir);
int			higher_size_assets(void);
char		*check_image(char i);

#endif
