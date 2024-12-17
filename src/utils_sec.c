/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:37:40 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 19:00:54 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_err(t_colors *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

int	ft_atoi_special(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (n);
		i++;
	}
	n = ft_atoi(str);
	return (n);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c > 7 && c < 13))
		return (1);
	else
		return (0);
}

int	ft_strlen_special(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strdup_special(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	len = ft_strlen_special(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
