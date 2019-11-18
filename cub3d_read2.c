/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_read2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:16:15 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/14 16:13:36 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_nums(t_set *set, char *str)
{
	int x;

	if (set->map_y == 0)
	{
		x = 0;
		while (str[x] && str[x] == '1')
			x++;
		if (str[x])
			return ("Map isn't surrounded by walls");
		set->map_x = x;
	}
	else if (str[set->map_x])
		return ("Invalid map format");
	if (str[set->map_x - 1] != '1')
		return ("Map isn't surrounded by walls");
	set->map_y++;
	return (NULL);
}

int		verif_nums(char c, int x, int y, t_set *set)
{
	int i;

	if (y == set->map_y -1 && c != '1')
		return (-1);
	if (c < '0' || c > '2')
	{
		if (set->play_o == - 1)
		{
			set->play_x = x;
			set->play_y = y;
			if (c == 'N')
				set->play_o = 0;
			else if (c == 'E')
				set->play_o = 90000;
			else if (c == 'S')
				set->play_o = 180000;
			else if (c == 'W')
				set->play_o = 270000;
			else 
				return (-1);
			return (0);
		}
		return (-1);
	}
	return (c - 48);
}

char	*read_line(char *str, t_set *set)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'R' && set->map_y == 0)
		ret = read_res(set, str + i + 1);
	else if (((str[i] == 'N' && str[i + 1] == 'O')
	|| (str[i] == 'S' && str[i + 1] == 'O')
	|| (str[i] == 'W' && str[i + 1] == 'E')
	|| (str[i] == 'S' && str[i + 1] == ' ')
	|| (str[i] == 'E' && str[i + 1] == 'A')) && set->map_y == 0)
		ret = read_tex(set, str + i);
	else if ((str[i] == 'C' || str[i] == 'F') && set->map_y == 0)
		ret = read_color(set, str + i);
	else if (str[i] == '1')
		ret = read_nums(set, str);
	else
		return (ft_strjoin("invalid line or wrong order : ", str));
	return (ret);
}

char	*read_set(int fd, t_set *set)
{
	char	*str;
	char	*ret;
	int		v;

	if (fd < 1)
		return ("Can't find configuation file");
	remp_set(set);
	while (v)
	{
		v = get_next_line(fd, &str);
		if (str[0])
		{
			ret = read_line(str, set);
			if (ret)
				return (ret);
		}
	}
	return (NULL);
}