/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_take_and_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutsou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:40:19 by akoutsou          #+#    #+#             */
/*   Updated: 2023/09/13 16:02:08 by akoutsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_take_fields(t_program *program, char **file)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		ft_take_tex_and_color(program, file, i);
		i++;
	}
	if (!ft_check_param_num(file))
		return (0);
	if (!ft_check_tex_and_color(program))
		return (0);
	ft_take_map(program, file);
	return (1);
}

int	ft_lineinfile(char *path)
{
	int		count;
	int		fd;
	int		i;
	char	buf[1];

	count = 0;
	i = 1;
	fd = open(path, O_RDONLY);
	while (i != 0)
	{
		i = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
	}
	close(fd);
	count++;
	return (count);
}

int	ft_check_cub(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] == 'b')
		i--;
	if (path[i] == 'u')
		i--;
	if (path[i] == 'c')
		i--;
	if (path[i] == '.')
		return (1);
	return (0);
}

char	**ft_openfile(char *path)
{
	char	**file;
	int		i;
	int		fd;

	i = 0;
	if (!ft_check_cub(path))
		return (NULL);
	if (access(path, F_OK) == -1)
		return (NULL);
	file = (char **)malloc(sizeof(char *) * (ft_lineinfile(path) + 1));
	fd = open(path, O_RDONLY);
	file[i] = get_next_line(fd);
	while (file[i])
	{
		i++;
		file[i] = get_next_line(fd);
	}
	return (file);
}

void	ft_take_file_and_check(char **argv, t_program *program)
{
	char	**file;

	file = ft_openfile(argv[1]);
	if (!file)
	{
		printf("Error: file %s non valido\n", argv[1]);
		program->error = 3;
		return ;
	}
	if (!ft_take_fields(program, file))
	{
		ft_free_matrix(&file);
		printf("Error: mappa e/o texture errati o mancanti\n");
		program->error = 2;
		return ;
	}
	if (!ft_check_map(program->map))
	{
		ft_free_matrix(&file);
		printf("Error: mappa e/o texture errati o mancanti\n");
		program->error = 0;
		return ;
	}
	program->error = 1;
	ft_free_matrix(&file);
}
