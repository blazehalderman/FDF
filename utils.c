/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:53:59 by bhalderm          #+#    #+#             */
/*   Updated: 2018/01/09 15:49:40 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plc	*do_find_points(t_cam *cam, t_plc *current)
{
	t_plc *header;
	t_plc *last;

	header = current;
	while (header->next != NULL)
	{
		header = find_points(cam, header);
		last = header;
		header = header->next;
		header->last = last;
	}
	header = find_points(cam, header);
	return (current);
}

t_plc	*find_points(t_cam *cam, t_plc *current)
{
	t_rot	*alg;
	t_plc	*cur;

	cur = current;
	alg = (t_rot *)malloc(sizeof(t_rot));
	alg->x0 = cur->x;
	alg->y0 = (cur->y * cos(cam->angle_x)) + (cur->z * sin(cam->angle_x));
	alg->z0 = (cur->z * cos(cam->angle_x)) - (cur->y * sin(cam->angle_x));
	alg->x1 = (alg->x0 * cos(cam->angle_y)) - (alg->z0 * sin(cam->angle_y));
	alg->y1 = alg->y0;
	alg->z1 = (alg->z0 * cos(cam->angle_y)) + (alg->x0 * sin(cam->angle_y));
	alg->x2 = (alg->x1 * cos(cam->angle_z)) + (alg->y1 * sin(cam->angle_z));
	alg->y2 = (alg->y1 * cos(cam->angle_z)) - (alg->x1 * sin(cam->angle_z));
	alg->x2 *= 10;
	alg->y2 *= 10;
	alg->x2 += 150;
	alg->y2 += 150;
	cur->x_place = (int)alg->x2;
	cur->y_place = (int)alg->y2;
	free(alg);
	return (cur);
}

int		draw(t_all *all)
{
	t_plc	*a;
	t_plc	*down;
	int		x[1];
	int		y[1];

	a = all->head;
	down = find_struct(a, a->x, a->y + 1);
	while (a->next)
	{
		if (down->next != NULL && (down->next->x > down->x))
			coord_calc(a, down, all->mlx);
		if (a->next && (a->next->x > a->x))
			coord_calc(a, a->next, all->mlx);
		if (a->next->x < a->x && down->next != NULL)
			coord_calc(a, down, all->mlx);
		if (a->next != NULL)
			a = a->next;
		if (down->next != NULL)
			down = down->next;
	}
	return (0);
}
