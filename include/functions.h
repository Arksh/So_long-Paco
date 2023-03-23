/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:45:27 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/23 11:53:09 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <so_long.h>

	// window
t_win		new_program(t_size map, t_size img, char *str);
int			exit_program(t_win *window, int i);
void		put_map_to_window(t_prog data);
void		put_objects_map(t_prog data);

	// map
t_prog		read_map(char *argv);
t_map		*create_map(int file, t_prog *data);
int			read_map_line(char *ln, t_prog *dat, t_cords *i, t_location **init);
t_map		*new_map(t_location *init, t_cords cords, int collectables);
void		detect_p_e(t_prog *data, char c, t_object *objt, t_location *loc);

	// check_map
t_size		check_map(char *argv);
int			check_file(char *argv);
int			check_objects(char *argv);
int			check_wall(char *argv, t_size size);
t_size		map_size(char *argv);

	// check_map_utils
int			check_line_objects(int i[5], char *line);
int			check_path(t_prog data);
int			flood_map(t_location *loc, char c);
int			flooding_map(t_location *loc, char c);
void		clean_map(t_location *loc);

	// locations
t_location	*new_location(char *img, t_object *objt, t_cords cord, char name);
void		add_location_back(t_location **list, t_location *new_loc);
t_location	*last_loc(t_location *loc);
t_location	*locate_location(t_location *loc, size_t x, size_t y);

	// images
t_size		detect_image_size(char *dir);
t_size		count_image_size(int i, int file, t_size size);
t_size		higher_size_assets(void);
char		*check_map_image(char i);
char		*check_object_image(char i);

	// keys
int			read_keys(int key_pressed, void *param);
int			movements(int i, int s);

	//objects
t_object	*create_object(char *img, t_cords cord, char c);
void		check_collectables(t_location next, t_prog *data);
void		check_exit(t_location loc, t_prog *data);

	// movement
int			move(t_prog *data, char c);
int			move_to(t_prog *data, t_location *loc, char cord, int i);
void		move_character(t_location *next, t_prog *data, char c, int i);
t_cords		update_cords(t_cords cord, char c, int i);


#endif