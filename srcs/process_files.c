/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:19:21 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/12/04 15:19:22 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_fact_name(char *full_path, enum e_obj_type type)
{
	if (type == __DIRECTORY)
	{
		if (ft_strrchr(full_path, '/') == NULL)
			return (full_path);
		return (ft_strrchr(full_path, '/') + 1);
	}
	return (full_path);
}

int		print_blocks(t_list_ *files)
{
	__int64_t	 blocks;

	blocks = 0;
	while (files)
	{
		blocks += files->stat_obj->st_blocks;
		files = files->next;
	}
	ft_printf("total %llu\n", blocks);
	return (EXIT_SUCCESS);
}

int		process_files(t_list_ *files, t_options *options, enum e_obj_type type)
{
	char			buff[1024];
	struct passwd	*user;
	struct group	*group;
	time_t			time_;

	if (options->t)
		sort_list(&files, last_modification_cmp);
	else
		sort_list(&files, name_cmp);
	if (type == __DIRECTORY && options->l)
		print_blocks(files);
	while (files)
	{
		user = getpwuid(files->stat_obj->st_uid);
		group = getgrgid(files->stat_obj->st_gid);
		(options->l) ? print_atributes(files) : 0;
		(options->l) ? ft_printf("%3d", files->stat_obj->st_nlink) : 0;
		(options->l) ? ft_printf("%10s", user->pw_name) : 0;
		(options->l) ? ft_printf("%7s", group->gr_name) : 0;
		(options->l) ? ft_printf("%7d", files->stat_obj->st_size) : 0;
		(options->l) ? ft_printf("%13.12s ",
				ctime(&(files->stat_obj->st_mtimespec.tv_sec)) + 4) : 0;
		ft_printf("%s\n", get_fact_name(files->path_name, type));
		files = files->next;
	}
	return (EXIT_SUCCESS);
}
