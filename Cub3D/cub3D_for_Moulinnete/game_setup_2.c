/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalian- <jgalian-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:34:53 by jgalian-          #+#    #+#             */
/*   Updated: 2020/10/27 11:30:05 by jgalian-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_textures(t_all *a)
{
	int		i;

	a->text[0].img = mlx_xpm_file_to_image(a->mlx.mlx,
		a->param.text_no, &a->text[0].width, &a->text[0].height);
	a->text[1].img = mlx_xpm_file_to_image(a->mlx.mlx,
		a->param.text_ea, &a->text[1].width, &a->text[1].height);
	a->text[2].img = mlx_xpm_file_to_image(a->mlx.mlx,
		a->param.text_so, &a->text[2].width, &a->text[2].height);
	a->text[3].img = mlx_xpm_file_to_image(a->mlx.mlx,
		a->param.text_we, &a->text[3].width, &a->text[3].height);
	i = 0;
	while (i < 4)
	{
		a->text[i].addr = mlx_get_data_addr(a->text[i].img, &a->text[i].
			bits_per_pixel, &a->text[i].line_length, &a->text[i].endian);
		i++;
	}
}

void	get_sprites_textures(t_all *a)
{
	int		i;

	a->spr_text[0].img = mlx_xpm_file_to_image(a->mlx.mlx,
		SPR_1_PATH, &a->spr_text[0].width, &a->spr_text[0].height);
	i = 0;
	while (i < 1)
	{
		a->spr_text[i].addr = mlx_get_data_addr(a->spr_text[i].img,
			&a->spr_text[i].bits_per_pixel, &a->spr_text[i].line_length,
			&a->spr_text[i].endian);
		i++;
	}
}

void	count_sprites(t_all *a)
{
	int		i;
	int		j;

	j = 0;
	while (j < a->map.n_lines)
	{
		i = 0;
		while (i < a->map.max_width)
		{
			if (a->map.matrix[j][i] == '2')
				a->map.spr_count++;
			i++;
		}
		j++;
	}
}

void	get_sprite_data(t_all *a)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (j < a->map.n_lines && k < a->map.spr_count)
	{
		i = 0;
		while (i < a->map.max_width && k < a->map.spr_count)
		{
			if (a->map.matrix[j][i] == '2')
			{
				a->spr[k].spr_x = (a->map.tile * i) + (a->map.tile / 2);
				a->spr[k].spr_y = (a->map.tile * j) + (a->map.tile / 2);
				k++;
			}
			i++;
		}
		j++;
	}
}
