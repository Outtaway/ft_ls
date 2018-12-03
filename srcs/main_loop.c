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

int		print_atributes(t_list_ *files)
{
	if (S_ISREG(files->stat_obj->st_mode))
		ft_printf("-");
	else if (S_ISBLK(files->stat_obj->st_mode))
		ft_printf("b");
	else if (S_ISCHR(files->stat_obj->st_mode))
		ft_printf("c");
	else if (S_ISFIFO(files->stat_obj->st_mode))
		ft_printf("p");
	else if (S_ISREG(files->stat_obj->st_mode))
		ft_printf("-");
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

int		process_files(t_list_ *files, t_options *options)
{
	char			buff[1024];
	struct passwd	*user;
	struct group	*group;
	time_t			time_;

	if (options->t)
		sort_list(&files, last_modification_cmp);
	else
		sort_list(&files, name_cmp);
	while (files)
	{
		user = getpwuid(files->stat_obj->st_uid);
		group = getgrgid(files->stat_obj->st_gid);
		(options->l) ? print_atributes(files) : 0;
		(options->l) ? ft_printf("%3d", files->stat_obj->st_nlink) : 0;
		(options->l) ? ft_printf("%10s", user->pw_name) : 0;
		(options->l) ? ft_printf("%7s", group->gr_name) : 0;
		(options->l) ? ft_printf("%7d", files->stat_obj->st_size) : 0;
		(options->l) ? ft_printf("%17.16s ", ctime(&(files->stat_obj->st_mtimespec.tv_sec))) : 0;
		ft_printf("%s\n", files->path_name);
		files = files->next;
	}
	return (EXIT_SUCCESS);
}

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
		free(lstat_obj);
		return (EXIT_FAILURE);
	}
	if (S_ISDIR(lstat_obj->st_mode) || (S_ISLNK(lstat_obj->st_mode) && S_ISDIR(stat_obj->st_mode) && !options->l))
		*dirs = add_node(*dirs, lstat_obj, path_name);
	else
		*files = add_node(*files, lstat_obj, path_name);
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
		while (paths_count--)
			fill_list(*(paths++), options, &files, &dirs);
	process_files(files, options);
	free_list(files);
	return (EXIT_SUCCESS);
}
