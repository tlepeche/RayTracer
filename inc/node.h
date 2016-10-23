/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 23:53:34 by sduprey           #+#    #+#             */
/*   Updated: 2016/09/16 13:40:51 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NODE_H
# define _NODE_H

# define NONE		0

# define SCENE		1
# define LIGHT		2
# define OBJECT		3
# define CAMERA		4

# define SPHERE		5
# define CYLINDER	6
# define PLANE		7
# define CONE		8
# define ELIPS		9
# define TRIAN		10
# define PARA		11
# define TETRA		12

typedef struct		s_node
{
	int				type;
	char			*name;
	void			*data;
	struct s_node	*next;
}					t_node;

t_node				*init_node(int type, void *data, char *name);
void				node_add(t_node **node, t_node *new);
void				free_node_list(t_node **node_list);

#endif
