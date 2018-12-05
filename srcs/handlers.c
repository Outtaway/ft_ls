/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:19:41 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/12/04 15:19:44 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_atributes(t_list_ *files)
{
	if (S_ISREG(files->stat_obj->st_mode))
		ft_printf("-");
	else if (S_ISDIR(files->stat_obj->st_mode))
		ft_printf("d");
	else if (S_ISBLK(files->stat_obj->st_mode))
		ft_printf("b");
	else if (S_ISCHR(files->stat_obj->st_mode))
		ft_printf("c");
	else if (S_ISFIFO(files->stat_obj->st_mode))
		ft_printf("p");
	else if (S_ISLNK(files->stat_obj->st_mode))
		ft_printf("l");
	else if (S_ISSOCK(files->stat_obj->st_mode))
		ft_printf("s");
	ft_printf((files->stat_obj->st_mode & S_IRUSR) ? "r" : "-"); 
	ft_printf((files->stat_obj->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((files->stat_obj->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((files->stat_obj->st_mode & S_IRGRP) ? "r" : "-"); 
	ft_printf((files->stat_obj->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((files->stat_obj->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((files->stat_obj->st_mode & S_IROTH) ? "r" : "-"); 
	ft_printf((files->stat_obj->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((files->stat_obj->st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(listxattr(files->path_name, NULL, 0,
		XATTR_NOFOLLOW) ? "@" : " ");
	return (0);
}


