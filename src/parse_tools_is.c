/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:47:26 by nbelouni          #+#    #+#             */
/*   Updated: 2016/09/30 16:56:49 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int			is_valid(char *s)
{
	while (*s)
	{
		if (*s != '}')
		{
			return (1);
		}
		s++;
	}
	return (0);
}

int			is_number(char *s)
{
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || *s == '.' || *s == '+' || *s == '-'))
		{
			return (0);
		}
		s++;
	}
	return (1);
}

int			is_color_initialized(char **values)
{
	int		n;

	if ((n = arr_len(values)) != 3)
	{
		if (n < 3)
			print_error("'color' : missing value\n", 1);
		else
			print_error("'color' : too many values\n", 1);
		return (0);
	}
	if (!is_number(values[0]) ||
		!is_number(values[1]) ||
		!is_number(values[2]))
	{
		print_error("'color' : value != number\n", 1);
		return (0);
	}
	return (1);
}

int			is_initialized(int *is_init, t_scene *scene)
{
	if (is_init[1] == 0)
	{
		print_error("No Camera", 1);
		return (0);
	}
	if (is_init[2] == 0 && scene->ambient_index <= 0.0)
	{
		print_error("No Lights", 2);
		scene->ambient_index = 0.5;
	}
	if (is_init[3] == 0)
	{
		print_error("No Objects", 1);
	}
	if (scene->is_real == 0)
		scene->is_real = REALISTIC;
	return (1);
}

t_color		*get_color(char **values, int ref)
{
	t_color		*c;
	double		c_max;

	if (!(is_color_initialized(values)))
		return (NULL);
	c_max = (ref == OBJECT) ? 1.0 : 255.0;
	if (!(c = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	c->r = ft_atof(values[0]);
	c->g = ft_atof(values[1]);
	c->b = ft_atof(values[2]);
	if (c->r < 0 || c->r > c_max ||
		c->g < 0 || c->g > c_max ||
		c->b < 0 || c->b > c_max)
	{
		print_error(join("'color' : value < 0 or > ", ft_itoa(c_max), "\n"), 1);
		return (NULL);
	}
	return (c);
}
