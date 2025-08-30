/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:02:33 by yaait-am          #+#    #+#             */
/*   Updated: 2025/08/29 10:12:07 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	hayad_nl(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i + 1] == 0)
			(*str)[i] = 0;
		i++;
	}
}

void	fill_texture(t_cub3d *all)
{
	int		i;
	char	filename[256];

	i = 0;
	while (i < 32)
	{
		sprintf(filename, "textures/portal/portal_%d.xpm", i);
		all->por_tex[i].path = hb_strdup(filename);
		all->por_tex[i].img = mlx_xpm_file_to_image(all->mlx,
				all->por_tex[i].path,
				&(all->por_tex[i].txtr_w),
				&(all->por_tex[i].txtr_h));
		if (!all->por_tex[i].img)
		{
			printf("Error\nFailed to load: %s\n", all->por_tex[i].path);
			clean_exit(all);
		}
		i++;
	}
	all->por_tex[32].path = NULL;
	all->por_tex[32].img = NULL;
}

void	init_tex(t_cub3d *all)
{
	hayad_nl(&(all->data->north));
	hayad_nl(&(all->data->south));
	hayad_nl(&(all->data->weast));
	hayad_nl(&(all->data->east));
	all->por_tex = yalloc(sizeof(t_img) * 33);
	all->no_texture.img = mlx_xpm_file_to_image(all->mlx, all->data->north,
			&(all->no_texture.txtr_w), &(all->no_texture.txtr_h));
	all->so_texture.img = mlx_xpm_file_to_image(all->mlx, all->data->south,
			&(all->so_texture.txtr_w), &(all->so_texture.txtr_h));
	all->we_tex.img = mlx_xpm_file_to_image(all->mlx, all->data->weast,
			&(all->we_tex.txtr_w), &(all->we_tex.txtr_h));
	all->ea_texture.img = mlx_xpm_file_to_image(all->mlx, all->data->east,
			&(all->ea_texture.txtr_w), &(all->ea_texture.txtr_h));
	all->dor_tex.img = mlx_xpm_file_to_image(all->mlx, "textures/door.xpm",
			&(all->dor_tex.txtr_w), &(all->dor_tex.txtr_h));
	fill_texture(all);
	if (!(all->no_texture.img) || !(all->so_texture.img) || !(all->we_tex.img)
		|| !(all->ea_texture.img) || !(all->dor_tex.img))
	{
		printf("Error\nXPM file to img failes\n");
		clean_exit(all);
	}
	all->no_texture.addr = mlx_get_data_addr(all->no_texture.img,
			&all->no_texture.bits_per_pixel, &all->no_texture.line_length,
			&all->no_texture.endian);
}

void	textures(t_cub3d *all)
{
	int (i);
	init_tex(all);
	all->so_texture.addr = mlx_get_data_addr(all->so_texture.img,
			&all->so_texture.bits_per_pixel, &all->so_texture.line_length,
			&all->so_texture.endian);
	all->we_tex.addr = mlx_get_data_addr(all->we_tex.img,
			&all->we_tex.bits_per_pixel, &all->we_tex.line_length,
			&all->we_tex.endian);
	all->ea_texture.addr = mlx_get_data_addr(all->ea_texture.img,
			&all->ea_texture.bits_per_pixel, &all->ea_texture.line_length,
			&all->ea_texture.endian);
	all->dor_tex.addr = mlx_get_data_addr(all->dor_tex.img,
			&all->dor_tex.bits_per_pixel, &all->dor_tex.line_length,
			&all->dor_tex.endian);
	i = 0;
	while (all->por_tex[i].img)
	{
		all->por_tex[i].addr = mlx_get_data_addr(all->por_tex[i].img,
				&all->por_tex[i].bits_per_pixel,
				&all->por_tex[i].line_length,
				&all->por_tex[i].endian);
		i++;
	}
}

void	initialize(t_data *data)
{
	t_cub3d	*all;

	all = init_data_for_simulation(data);
	all->data = data;
	init_all(all);
	find_position(all);
	init_angle(all);
	textures(all);
	mlx_hook(all->win, 2, 1L << 0, key_press, all);
	mlx_hook(all->win, 6, 1L << 6, mouse_move, all);
	render(all);
	mlx_hook(all->win, 17, 0, clean_exit, all);
	if (!mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0))
	{
		printf("Error\nput image to window failed !!\n");
		clean_exit(all);
	}
	mlx_loop(all->mlx);
}
