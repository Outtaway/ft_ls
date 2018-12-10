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

t_list_		*get_list(char *path_dir, t_options *opt)
{
	DIR				*dir_obj;
	char			*full_path;
	struct dirent	*dirent_obj;
	t_list_			*new_list;

	if ((dir_obj = opendir(path_dir)) == NULL)
	{
		ft_printf("ls: %s: %s\n", path_dir, strerror(errno));
		errno = 0;
		return (NULL);
	}
	new_list = NULL;
	while ((dirent_obj = readdir(dir_obj)))
	{
		if (dirent_obj->d_name[0] == '.' && !opt->a)
			continue ;
		full_path = create_name(path_dir, dirent_obj->d_name);
		fill_list(full_path, opt, &new_list, &new_list);
	}
	closedir(dir_obj);
	return (new_list);
}

int			is_dot(char *path)
{
	return ((ft_strlen(path) == 2 && ft_strcmp(path, "..") == 0) ||
			(ft_strlen(path) == 1 && ft_strcmp(path, ".") == 0));
}

int			each_dir(char *path_dir, t_options *opt, int paths_count)
{
	t_list_ *all_obj;
	char	*full_path;
	t_list_ *temp;

	(paths_count > 1 || opt->r_b) ? write(1, "\n", 1) : 0;
	(paths_count > 1 || opt->r_b) ? write(1, path_dir, ft_strlen(path_dir)) : 0;
	(paths_count > 1 || opt->r_b) ? write(1, ":\n", 2) : 0;
	if ((all_obj = get_list(path_dir, opt)) == NULL)
		return (EXIT_FAILURE);
	process_files(&all_obj, opt, __DIRECTORY);
	temp = all_obj;
	if (opt->r_b)
	{
		while (temp)
		{
			if (S_ISDIR(temp->stat_obj->st_mode) &&
						!is_dot(get_fact_name(temp->path_name, __DIRECTORY)))
				each_dir(temp->path_name, opt, paths_count);
			temp = temp->next;
		}
	}
	free_list(&all_obj);
	return (EXIT_SUCCESS);
}

int			process_dirs(t_list_ **dirs, t_options *opt, int paths_count)
{
	t_list_ *head;

	sort_list(dirs, (opt->t) ? last_modification_cmp : name_cmp, opt);
	head = (*dirs);
	while (head)
	{
		each_dir(head->path_name, opt, paths_count);
		head = head->next;
	}
	return (EXIT_SUCCESS);
}
