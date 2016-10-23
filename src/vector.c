/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 05:31:40 by sduprey           #+#    #+#             */
/*   Updated: 2016/10/04 17:05:38 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_vec		init_vector(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double		get_length(t_vec vec)
{
	double	x;
	double	y;
	double	z;

	x = vec.x * vec.x;
	y = vec.y * vec.y;
	z = vec.z * vec.z;
	return (sqrt(x + y + z));
}

t_vec		normalize(t_vec vec)
{
	t_vec	res;
	double	len;

	len = get_length(vec);
	if (len == 0.0f)
	{
		res.x = 0.0;
		res.y = 0.0;
		res.z = 0.0;
	}
	else
	{
		res.x = vec.x / len;
		res.y = vec.y / len;
		res.z = vec.z / len;
	}
	return (res);
}
