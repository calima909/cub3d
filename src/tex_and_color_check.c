/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_and_color_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:34:36 by akoutsou          #+#    #+#             */
/*   Updated: 2023/09/07 13:53:48 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parm_cnt(int *param_cnt, char par, int flg)
{
	if (flg == 0)
	{
		param_cnt[0] = 0;
		param_cnt[1] = 0;
		param_cnt[2] = 0;
		param_cnt[3] = 0;
		param_cnt[4] = 0;
		param_cnt[5] = 0;
	}
	else
	{
		if (par == 'N')
			param_cnt[0]++;
		else if (par == 'S')
			param_cnt[1]++;
		else if (par == 'W')
			param_cnt[2]++;
		else if (par == 'E')
			param_cnt[3]++;
		else if (par == 'F')
			param_cnt[4]++;
		else if (par == 'C')
			param_cnt[5]++;
	}
}

int	ft_check_param_num(char **file)
{
	int	i;
	int	j;
	int	param_cnt[6];

	i = -1;
	ft_parm_cnt(param_cnt, 'I', 0);
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (ft_strchr_i("FC", file[i][j]) != -1 || (ft_strchr_i("WENS",
						file[i][j]) != -1 && file[i][j + 1]
					&& ft_strchr_i("EAO", file[i][j + 1]) != -1))
				ft_parm_cnt(param_cnt, file[i][j], 1);
		}
	}
	i = -1;
	while (++i < 6)
	{
		if (param_cnt[i] != 1)
			return (0);
	}
	return (1);
}

int	ft_check_color(t_colors color)
{
	if (color.r < 0 || color.r > 255)
		return (0);
	if (color.g < 0 || color.g > 255)
		return (0);
	if (color.b < 0 || color.b > 255)
		return (0);
	return (1);
}

int	ft_check_tex(char *path)
{
	int	i;
	int	flg;

	flg = 0;
	i = 0;
	if (!path)
		return (0);
	while (path[i])
	{
		if (path[i] == '.')
		{
			flg = 1;
			i++;
			if (ft_strcmp(path + i, "xpm"))
				return (0);
		}
		i++;
	}
	if (flg == 0)
		return (0);
	if (access(path, F_OK) == -1)
		return (0);
	return (1);
}

int	ft_check_tex_and_color(t_program *program)
{
	if (!ft_check_tex(program->north.path))
		return (0);
	if (!ft_check_tex(program->south.path))
		return (0);
	if (!ft_check_tex(program->west.path))
		return (0);
	if (!ft_check_tex(program->east.path))
		return (0);
	if (!ft_check_color(program->color[0]))
		return (0);
	if (!ft_check_color(program->color[1]))
		return (0);
	return (1);
}
