/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:39:33 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/13 17:46:04 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_map(int fd, int ***map, t_set *set)
{
	int		y;
	int		x;
	char	*str;

	get_next_line(fd, &str);
	while (str[0] != '1')
		get_next_line(fd, &str);
	(*map) = malloc(sizeof(int *) * set->map_y);
	y = -1;
	while (++y < set->map_y)
	{
		if (*map != NULL)
			(*map)[y] = malloc(sizeof(int) * set->map_x);
		if (*map == NULL || (*map)[y] == NULL)
			return ("allocation echouée dans read_map");
		x = -1;
		while (x++ < set->map_x - 1)
		{
			(*map)[y][x] = verif_nums(str[x], x, y, set);
			if ((*map)[y][x] == -1)
				return ("Invalid map");
		}
		get_next_line(fd, &str);
	}
	return (NULL);
}

char	*read_res(t_set *set, char *str)
{
	int i;
	int val;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return ("Missing Values of resolution");
	val = ft_atoi(str + i);
	if (val < 0)
		return ("Value of X resolution can't be negative");
	set->res_x = val;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	while (str[i] == ' ')
		i++;
	if (!str[i])
		return ("Missing Value of Y resolution");
	val = ft_atoi(str + i);
	if (val < 0)
		return ("Value of Y resolution can't be negative");
	set->res_y = val;
	return (NULL);
}

char	*read_tex(t_set *set, char *str)
{
	int i;
	int fd;

	i = 2;
	fd = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if (!str[i])
		return (ft_strjoin("Missing path for texture ", str));
	while (str[i] == ' ')
		i++;
	fd = open(str + i, O_RDONLY);
	if (fd < 0)
		return (ft_strjoin("Invalid path : ", str));
	if (str[0] == 'N')
		set->tex_n = fd;
	if (str[0] == 'E')
		set->tex_e = fd;
	if (str[0] == 'S' && str[1] == 'O')
		set->tex_s = fd;
	if (str[0] == 'S' && str[1] == ' ')
		set->tex_p = fd;
	if (str[0] == 'W')
		set->tex_w = fd;
	return (NULL);
}

char	*read_color(t_set *set, char *str)
{
	int red;
	int gre;
	int blu;
	int i;

	i = 1;
	red = atoi(str + i);
	while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != ',')
		return ("Invalid color format, please respect this format : R,G,B");
	gre = atoi(str + i + 1);
	while (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != ',')
		return ("Invalid color format, please respect this format : R,G,B");
	i++;
	blu = atoi(str + i);
	if (blu > 255 || blu < 0 || gre > 255 || gre < 0 || red > 255 || red < 0)
		return ("each color must be an integer between 0 and 255");
	if (str[0] == 'C')
		set->ceil = red * 65536 + gre * 256 + blu;
	if (str[0] == 'F')
		set->floor = red * 65536 + gre * 256 + blu;
	return (NULL);
}
