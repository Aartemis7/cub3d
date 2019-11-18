/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:44:11 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/18 14:12:03 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include <math.h>

typedef struct	s_set
{
	int res_x;
	int res_y;
	int	tex_n;
	int	tex_e;
	int	tex_s;
	int tex_w;
	int tex_p;
	int floor;
	int ceil;
	int map_x;
	int map_y;
	int play_x;
	int play_y;
	int play_o;
}				t_set;

typedef struct	s_play
{
	int	unit;
	int x;
	int	y;
	int	o;
	int res_x;
	int res_y;
	int map_y;
	int map_x;
}				t_play;

//get_next_line
int				get_next_line(int fd, char **line);
char			**init(char **line, char **buf, int fd);
void			join(char **line, char **buf, int x);
int				increase_buf(char **buf);
int				clear_buff(int x, int fd, char ***buf);

//cub3d_utils
int				ft_strlen(char *str);
int				ft_atoi(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			remp_set(t_set	*set);
int				display_errors(char *str, t_set *set, int ***map);

//cub3d_utils2
int   		 	verif_set(t_set set);
t_play			init_play(t_set set);
float			angle(int angle);

// cub3d_read
char			*read_map(int fd, int ***map_p, t_set *set);
char			*read_res(t_set *set, char *str);
char			*read_tex(t_set *set, char *str);
char			*read_color(t_set *set, char *str);

//cub3d_read2
char			*read_nums(t_set *set, char *str);
int				verif_nums(char c, int x, int y, t_set *set);
char			*read_set(int fd, t_set *set);
char			*read_line(char *str, t_set *set);

//cub3d_display
void			display_frame(t_play play, int **map, void *mlx_ptr, void *win_ptr);
int				find_dist(t_play play, float angle, int **map);
int				find_dist_v(t_play play, float angle, int **map);
int				find_dist_h(t_play play, float angle, int **map);
int				hit_wall(int ** map, int x, int y, t_play play);


//AUB
float angle_r(float angle);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (10)
#endif
