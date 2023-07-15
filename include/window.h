/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:45 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/17 17:39:29 by fraalmei         ###   ########.fr       */
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

typedef struct s_cords
{
	size_t		x;
	size_t		y;
}				t_cords;

typedef struct s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_size	size_map;
	struct s_size	size_img;
}					t_win;

typedef struct s_object
{
	void				*img;
	char				name;
	struct s_cords		cords;
	struct s_location	*loc;
}						t_object;

typedef struct s_location
{
	void				*img;
	char				obj;
	struct s_object		*objt;
	struct s_cords		cords;
	struct s_location	*north;
	struct s_location	*south;
	struct s_location	*east;
	struct s_location	*west;
}						t_location;

typedef struct s_map
{
	struct s_location	*init;
	struct s_cords		cords;
}						t_map;

typedef struct s_prog
{
	t_win			win;
	t_map			*map;
	t_object		*player;
}					t_prog;

	// window
t_win		new_program(t_size map, t_size img, char *str);
int			exit_program(t_win *window, int i);
void		put_map_to_window(t_prog data);
void		put_objects_map(t_prog *data);

	// map
t_prog		read_map(char *argv);
t_map		*create_map(int file, t_prog data);
t_map		*new_map(t_location *init, t_cords cords);

	// check_map
t_size		check_map(char *argv);
int			check_file(char *argv);
int			check_objects(char *argv);
int			check_wall(char *argv, t_size size);
t_size		map_size(char *argv);

	// locations
t_location	*new_location(char *img, t_object *objt, t_cords cord, char obj);
void		add_location_back(t_location **list, t_location *new_loc);
t_location	*last_loc(t_location *loc);
t_location	*locate_location(t_location *loc, size_t x, size_t y);

	// images
t_size		detect_image_size(char *dir);
t_size		higher_size_assets(void);
char		*check_map_image(char i);
char		*check_object_image(char i);

	// keys
int			read_keys(int key_pressed, void *param);

	//objects
t_object	*create_object(char *img, t_cords cord, char c);
int			move_up(t_prog *data);
int			move_down(t_prog *data);
int			move_left(t_prog *data);
int			move_right(t_prog *data);

#endif
