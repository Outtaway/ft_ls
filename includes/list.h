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
	struct s_list_	*prev;
	struct stat		*stat_obj;
}					t_list_;

t_list_	*add_node(t_list_ *list, struct stat *data);
void	print_list(t_list_ *list);

#endif
