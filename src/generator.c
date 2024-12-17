/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:13:26 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 19:00:08 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_spawn(t_program *prg)
{
	int	i;
	int	j;

	i = -1;
	while (prg->map[++i])
	{
		j = -1;
		while (prg->map[i][++j])
		{
			if (prg->map[i][j] == 'N' || prg->map[i][j] == 'S'
				|| prg->map[i][j] == 'E' || prg->map[i][j] == 'W')
			{
				prg->spawn_x = j;
				prg->spawn_y = i;
				if (prg->map[i][j] == 'N')
					prg->angle = 270;
				else if (prg->map[i][j] == 'S')
					prg->angle = 90;
				else if (prg->map[i][j] == 'E')
					prg->angle = 0;
				else if (prg->map[i][j] == 'W')
					prg->angle = 180;
			}
		}
	}
}

void	ft_push_tex(t_program *prg)
{
	prg->north.ptr = mlx_xpm_file_to_image(prg->mlx, prg->north.path,
			&prg->north.width, &prg->north.height);
	prg->north.data = mlx_get_data_addr(prg->north.ptr, &prg->north.bpp,
			&prg->north.size_line, &prg->north.endian);
	prg->east.ptr = mlx_xpm_file_to_image(prg->mlx, prg->east.path,
			&prg->east.width, &prg->east.height);
	prg->east.data = mlx_get_data_addr(prg->east.ptr, &prg->east.bpp,
			&prg->east.size_line, &prg->east.endian);
	prg->south.ptr = mlx_xpm_file_to_image(prg->mlx, prg->south.path,
			&prg->south.width, &prg->south.height);
	prg->south.data = mlx_get_data_addr(prg->south.ptr, &prg->south.bpp,
			&prg->south.size_line, &prg->south.endian);
	prg->west.ptr = mlx_xpm_file_to_image(prg->mlx, prg->west.path,
			&prg->west.width, &prg->west.height);
	prg->west.data = mlx_get_data_addr(prg->west.ptr, &prg->west.bpp,
			&prg->west.size_line, &prg->west.endian);
	prg->north.currenty = 0;
	prg->east.currenty = 0;
	prg->south.currenty = 0;
	prg->west.currenty = 0;
}

void	ft_create_image(t_tex *img, t_program *prg)
{
	img->ptr = mlx_new_image(prg->mlx, prg->size.x, prg->size.y);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->size_line, &img->endian);
}

void	ft_create_window(t_program *prg)
{
	prg->mlx = mlx_init();
	prg->win_ptr = mlx_new_window(prg->mlx, prg->size.x, prg->size.y, "Cub3d");
	ft_create_image(&prg->img, prg);
	ft_push_tex(prg);
}
