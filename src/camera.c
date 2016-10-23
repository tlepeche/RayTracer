/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:20:20 by sduprey           #+#    #+#             */
/*   Updated: 2016/10/04 17:04:48 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_cam		init_camera(t_vec pos, t_vec look)
{
	t_cam	cam;

	cam.ray.pos = pos;
	cam.ray.dir.x = 0;
	cam.ray.dir.y = 0;
	cam.ray.dir.z = 0;
	cam.look_at = look;
	cam.d = 1.0f;
	cam.h = 0.28f;
	cam.w = 0.5f;
	return (cam);
}

t_vec		calc_vec_dir(int x, int y, t_cam cam, t_vec look)
{
	double	x_indent;
	double	y_indent;
	t_vec	res;
	t_vec	tmp;

	x_indent = cam.w / (double)WIDTH;
	y_indent = cam.h / (double)HEIGHT;
	res.x = ((x - (double)WIDTH * 0.5) * x_indent);
	res.y = ((y - (double)HEIGHT * 0.5) * y_indent);
	res.z = cam.d;
	tmp = vec_rot_x(res, look.x);
	tmp = vec_rot_y(tmp, look.y);
	tmp = vec_rot_z(tmp, look.z);
	return (tmp);
}
