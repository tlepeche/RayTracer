/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 00:35:14 by nbelouni          #+#    #+#             */
/*   Updated: 2016/08/25 16:21:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RAY_H
# define _RAY_H

# include <vector.h>

typedef struct	s_ray
{
	t_vec		pos;
	t_vec		dir;
	double		length;
}				t_ray;

#endif
