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

int		print_atributes(mode_t st_mode, char *path_name)
{
	if (S_ISREG(st_mode))
		write(1, "-", 1);
	else if (S_ISDIR(st_mode))
		write(1, "d", 1);
	else if (S_ISBLK(st_mode))
		write(1, "b", 1);
	else if (S_ISCHR(st_mode))
		write(1, "c", 1);
	else if (S_ISFIFO(st_mode))
		write(1, "p", 1);
	else if (S_ISLNK(st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK(st_mode))
		write(1, "s", 1);
	write(1, (st_mode & S_IRUSR) ? "r" : "-", 1); 
	write(1, (st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (st_mode & S_IRGRP) ? "r" : "-", 1); 
	write(1, (st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (st_mode & S_IROTH) ? "r" : "-", 1); 
	write(1, (st_mode & S_IWOTH) ? "w" : "-", 1);
	write(1, (st_mode & S_IXOTH) ? "x" : "-", 1);
	write(1, listxattr(path_name, NULL, 0,
		XATTR_NOFOLLOW) ? "@ " : "  ", 2);
	return (0);
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

void	additional_columns(t_list_ *files,
							struct passwd *users, struct group *groups)
{
	print_atributes(files->stat_obj->st_mode, files->path_name);
	ft_printf("  %-5d", files->stat_obj->st_nlink);
	ft_printf("%-15s", users->pw_name);
	ft_printf("%-15s", groups->gr_name);
	ft_printf("%-10d", files->stat_obj->st_size);
	ft_printf("%15.12s\t",ctime(&(files->stat_obj->st_mtimespec.tv_sec)) + 4);
}

int		process_files(t_list_ *files, t_options *opt, enum e_obj_type type)
{
	char			buff[1024];
	struct passwd	*users;
	struct group	*groups;
	time_t			time_;

	if (type == __DIRECTORY && opt->l)
		print_blocks(files);
	while (files)
	{
		users = getpwuid(files->stat_obj->st_uid);
		groups = getgrgid(files->stat_obj->st_gid);
		if (opt->l)
			additional_columns(files, users, groups);
		ft_printf("%s\n", get_fact_name(files->path_name, type));
		files = files->next;
	}
	write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
