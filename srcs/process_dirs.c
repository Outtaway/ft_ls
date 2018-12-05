/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:19:17 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/12/04 15:19:18 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "list.h"

char *create_name(char *prev, char *new)
{
	char *temp;

	temp = ft_strnew(ft_strlen(prev) + ft_strlen(new) + 1);
	temp = ft_strncpy(temp, prev, ft_strlen(prev));
	temp[ft_strlen(temp)] = '/';
	temp = ft_strncat(temp, new, ft_strlen(new));
	return (temp);
}

int		each_dir(char *path_dir, t_options *options, int paths_count)
{
	DIR		*dir_obj;
	struct dirent *dirent_obj;
	t_list_ *all_obj;
	char	*full_path;
	t_list_ *temp;

	dir_obj = opendir(path_dir);
	all_obj = NULL;
	(paths_count > 1 || options->R) ? ft_printf("\n%s:\n", path_dir) : 0;
	while ((dirent_obj = readdir(dir_obj)))
	{
		if (dirent_obj->d_name[0] == '.' && !options->a)
			continue ;
		full_path = create_name(path_dir, dirent_obj->d_name); // leaks
		fill_list(full_path, options, &all_obj, &all_obj);
	}
	process_files(all_obj, options, __DIRECTORY);
	temp = all_obj;
	if (options->R)
	{
		while (all_obj)
		{
			if (S_ISDIR(all_obj->stat_obj->st_mode) && get_fact_name(all_obj->path_name, __DIRECTORY)[0] != '.')
				each_dir(all_obj->path_name, options, paths_count);
			all_obj = all_obj->next;
		}
	}
	free_list(temp);
	closedir(dir_obj);
	return (EXIT_SUCCESS);
}

int		process_dirs(t_list_ *dirs, t_options *options, int paths_count)
{
	sort_list(&dirs, (options->t) ? last_modification_cmp : name_cmp);
	while (dirs)
	{
		each_dir(dirs->path_name, options, paths_count);
		dirs = dirs->next;
	}
	return (EXIT_SUCCESS);
}
