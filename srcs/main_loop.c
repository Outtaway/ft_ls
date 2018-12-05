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
	struct stat *lstat_obj;
	struct stat *stat_obj;

	lstat_obj = (struct stat *)malloc(sizeof(struct stat));
	stat_obj = (struct stat *)malloc(sizeof(struct stat));
	lstat(path_name, lstat_obj);
	stat(path_name, stat_obj);
	if (errno)
	{
		ft_printf("ls: %s: %s\n", path_name, strerror(errno));
		errno = 0;
		free(lstat_obj);
		return (EXIT_FAILURE);
	}
	if (S_ISDIR(lstat_obj->st_mode) || (S_ISLNK(lstat_obj->st_mode) && S_ISDIR(stat_obj->st_mode) && !options->l))
		*dirs = add_node(*dirs, lstat_obj, ft_strdup(path_name));
	else
		*files = add_node(*files, lstat_obj, ft_strdup(path_name));
	free(stat_obj);
	return (EXIT_SUCCESS);
}

int		main_loop(char **paths, t_options *options, int paths_count)
{
	t_list_ *files;
	t_list_ *dirs;
	int		iter;

	iter = paths_count;
	files = NULL;
	dirs = NULL;
	if (paths_count == 0)
		fill_list(".", options, &files, &dirs);
	else
		while (iter--)
			fill_list(*(paths++), options, &files, &dirs);
	process_files(files, options, __FILE);
	process_dirs(dirs, options, paths_count);
	free_list(&files);
	free_list(&dirs);
	return (EXIT_SUCCESS);
}
