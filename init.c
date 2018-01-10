/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhalderm <bhalderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:47:46 by bhalderm          #+#    #+#             */
/*   Updated: 2018/01/09 15:49:45 by bhalderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plc	*init_plc(void)
{
	t_plc *p;

	p = (t_plc *)malloc(sizeof(t_plc));
	p->last = NULL;
	p->next = NULL;
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->x_place = 0;
	p->y_place = 0;
	return (p);
}

t_cam	*init_cam(void)
{
	t_cam *p;

	p = (t_cam *)malloc(sizeof(t_plc));
	p->angle_x = 0;
	p->angle_y = 0;
	p->angle_z = 0;
	return (p);
}

t_read	*init_read(void)
{
	t_read *p;

	p = (t_read *)malloc(sizeof(t_read));
	p->y = 0;
	p->line = NULL;
	return (p);
}

t_cam	*reinit_cam(t_cam *camera)
{
	t_cam *cam;

	cam = camera;
	cam->radian_x = cam->angle_x * (PI / 180);
	cam->radian_y = cam->angle_y * (PI / 180);
	cam->radian_z = cam->angle_z * (PI / 180);
	return (cam);
}

t_all	*init_all(t_cam *cam, t_plc *head)
{
	t_all *p;

	p = (t_all *)malloc(sizeof(t_all));
	p->head = head;
	p->cam = cam;
	p->mlx = init_mlx();
	return (p);
}
