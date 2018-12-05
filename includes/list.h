/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:04:52 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/29 11:04:54 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include "ft_ls.h"

typedef struct		s_list_
{
	struct s_list_	*next;
	struct stat		*stat_obj;
	char			*path_name;
}					t_list_;

t_list_	*add_node(t_list_ *list, struct stat *data, char *path);
int		name_cmp(t_list_ *a, t_list_ *b);
int		last_modification_cmp(t_list_ *a, t_list_ *b);
void	print_list(t_list_ *list);
void	free_list(t_list_ **list);
void	sort_list(t_list_ **list,  int (*f)(t_list_ *, t_list_ *));
int		list_size(t_list_ *list);

#endif
