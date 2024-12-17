/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:05:47 by akoutsou          #+#    #+#             */
/*   Updated: 2023/08/24 19:02:10 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_path(t_program *program)
{
	free(program->north.path);
	free(program->south.path);
	free(program->west.path);
	free(program->east.path);
}

int	ft_close(t_program *program)
{
	mlx_destroy_image(program->mlx, program->north.ptr);
	mlx_destroy_image(program->mlx, program->south.ptr);
	mlx_destroy_image(program->mlx, program->east.ptr);
	mlx_destroy_image(program->mlx, program->west.ptr);
	mlx_destroy_image(program->mlx, program->img.ptr);
	mlx_destroy_window(program->mlx, program->win_ptr);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	ft_free_path(program);
	ft_free_matrix(&program->map);
	exit(0);
	return (0);
}

void	ft_init_struct(t_program *prg)
{
	prg->size.x = 800;
	prg->size.y = 600;
	prg->half_h = prg->size.y / 2;
	prg->half_w = prg->size.x / 2;
	prg->rdelay = 30;
	prg->fov = 66;
	prg->half_fov = 0;
	prg->rc_precision = 64;
	prg->rc_incrementing = prg->fov / prg->size.x;
	prg->half_fov = prg->fov / 2;
}

void	ft_init_game(t_program *prg)
{
	ft_init_struct(prg);
	ft_spawn(prg);
	ft_create_window(prg);
	ft_raycasting(prg);
	mlx_put_image_to_window(prg->mlx, prg->win_ptr, prg->img.ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 2)
	{
		printf("Error: troppi argomenti ciccio, ripigliati e fai il bravo\n");
		return (0);
	}
	ft_take_file_and_check(argv, &program);
	if (program.error != 1)
	{
		if (program.error != 3)
			ft_free_path(&program);
		if (program.error == 0)
			ft_free_matrix(&program.map);
		return (0);
	}
	ft_init_game(&program);
	mlx_hook(program.win_ptr, 2, 1L << 0, ft_handlekeys, &program);
	mlx_hook(program.win_ptr, 17, 0, ft_close, &program);
	mlx_loop(program.mlx);
}
