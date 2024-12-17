/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_take.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:38:39 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 19:05:51 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_map(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	len = ft_strlen(str) - 1;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		if (str[i] != '\n')
		{
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	ft_otherline_after(char **file, int i)
{
	int	j;

	j = i;
	while (file[j])
	{
		if (ft_strchars_i(file[j], "10NSEW") != -1)
			return (1);
		j++;
	}
	return (0);
}

int	ft_map_start(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if ((ft_strchars_i(file[i], "10") != -1)
			&& (ft_strchars_i(file[i], ",") == -1))
			return (i);
		i++;
	}
	return (i);
}

int	ft_maplen(char **file)
{
	int	i;
	int	len;

	i = ft_map_start(file);
	len = 0;
	while (file[i] && ft_otherline_after(file, i))
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_take_map(t_program *program, char **file)
{
	int	i;
	int	j;

	j = 0;
	i = ft_map_start(file);
	program->map = (char **)malloc(sizeof(char *) * (ft_maplen(file) + 1));
	while (file[i] && ft_otherline_after(file, i))
		program->map[j++] = ft_strdup_map(file[i++]);
	program->map[j] = NULL;
}
