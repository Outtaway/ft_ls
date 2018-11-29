/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:06:38 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/28 18:06:39 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		fill_list(char *path_name, t_options *options,
				t_list_ **files, t_list_ **dirs)
{
	struct stat *stat_obj;

	stat_obj = (struct stat *)malloc(sizeof(struct stat));
	lstat(path_name, stat_obj);
	if (errno)
	{
		ft_printf("ls: %s: %s\n", path_name, strerror(errno));
		free(stat_obj);
		return (EXIT_FAILURE);
	}
	if (S_ISDIR(stat_obj->st_mode))
		*dirs = add_node(*dirs, stat_obj);
	else
		*files = add_node(*files, stat_obj);
	return (EXIT_SUCCESS);
}

int		main_loop(char **paths, t_options *options, int paths_count)
{
	t_list_ *files;
	t_list_ *dirs;

	files = NULL;
	dirs = NULL;
	if (paths_count == 0)
		fill_list(".", options, &files, &dirs);
	else
	{
		while (paths_count--)
			fill_list(*(paths++), options, &files, &dirs);
	}
	print_list(files);
	ft_printf("---------------\n");
	print_list(dirs);
	return (EXIT_SUCCESS);
}
