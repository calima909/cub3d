/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_and_color_take.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:35:50 by akoutsou          #+#    #+#             */
/*   Updated: 2023/09/06 18:20:21 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_colors	ft_take_color_core(char *str)
{
	t_colors	color;
	char		**res;
	char		*parsed;
	int			i;

	parsed = ft_strdup_special(str);
	res = ft_split(parsed, ',');
	i = 0;
	while (res[i])
	{
		if (i == 0)
			color.r = ft_atoi_special(res[i]);
		else if (i == 1)
			color.g = ft_atoi_special(res[i]);
		else if (i == 2)
			color.b = ft_atoi_special(res[i]);
		i++;
	}
	free(parsed);
	ft_free_matrix(&res);
	if (i != 3)
		ft_color_err(&color);
	return (color);
}

t_colors	ft_take_color(char **file, char *to_find)
{
	t_colors	color;
	int			i;
	int			j;

	i = 0;
	color.b = -1;
	color.g = -1;
	color.r = -1;
	while (file[i])
	{
		j = 0;
		while (ft_isspace(file[i][j]))
			j++;
		if (to_find[0] == file[i][j])
		{
			j++;
			while (ft_isspace(file[i][j]))
				j++;
			color = ft_take_color_core(file[i] + j);
			return (color);
		}
		i++;
	}
	return (color);
}

char	*ft_take_val(char **file, char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	while (file[++i])
	{
		j = 0;
		while (ft_isspace(file[i][j]))
			j++;
		if (to_find[0] == file[i][j])
		{
			j++;
			if (to_find[1] == file[i][j])
			{
				j++;
				while (ft_isspace(file[i][j]))
					j++;
				res = ft_strdup_special(file[i] + j);
				return (res);
			}
		}
	}
	return (NULL);
}

void	ft_take_tex_and_color(t_program *program, char **file, int i)
{
	if (i == 0)
		program->north.path = ft_take_val(file, "NO");
	else if (i == 1)
		program->south.path = ft_take_val(file, "SO");
	else if (i == 2)
		program->west.path = ft_take_val(file, "WE");
	else if (i == 3)
		program->east.path = ft_take_val(file, "EA");
	else if (i == 4)
		program->color[0] = ft_take_color(file, "F");
	else if (i == 5)
		program->color[1] = ft_take_color(file, "C");
}
