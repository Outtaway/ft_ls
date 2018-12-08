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
	char attr[11];

	if (S_ISREG(st_mode))
		attr[0] = '-';
	else if (S_ISDIR(st_mode))
		attr[0] = 'd';
	else if (S_ISLNK(st_mode))
		attr[0] = 'l';
	else if (S_ISBLK(st_mode))
		attr[0] = 'b';
	else if (S_ISCHR(st_mode))
		attr[0] = 'c';
	else if (S_ISFIFO(st_mode))
		attr[0] = 'p';
	else if (S_ISSOCK(st_mode))
		attr[0] = 's';
	attr[1] = (st_mode & S_IRUSR) ? 'r' : '-'; 
	attr[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	attr[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	attr[4] = (st_mode & S_IRGRP) ? 'r' : '-'; 
	attr[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	attr[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	attr[7] = (st_mode & S_IROTH) ? 'r' : '-'; 
	attr[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	attr[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	attr[10] = listxattr(path_name, NULL, 0,
	XATTR_NOFOLLOW) ? '@' : ' ';
	write(1, attr, 11);
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
	write(1, "total ", 6);
	ft_printf("%llu\n", blocks);
	return (EXIT_SUCCESS);
}

void	additional_columns(t_list_ *files)
{
	struct passwd	*users;
	struct group	*groups;
	char			*buff;

	users = getpwuid(files->stat_obj->st_uid);
	groups = getgrgid(files->stat_obj->st_gid);
	print_atributes(files->stat_obj->st_mode, files->path_name);
	ft_printf("  %-5d", files->stat_obj->st_nlink);
	ft_printf("%-15s", users->pw_name);
	ft_printf("%-15s", groups->gr_name);
	if (S_ISCHR(files->stat_obj->st_mode) || S_ISBLK(files->stat_obj->st_mode))
		ft_printf("%5d, %-5d",
		(long)major(files->stat_obj->st_rdev),
		(long)minor(files->stat_obj->st_rdev));
	else
		ft_printf("%-10d", files->stat_obj->st_size);
	buff = ctime(&(files->stat_obj->st_mtimespec.tv_sec)) + 4;
	buff[12] = ' ';
	write(1, buff, 13);
}

int		process_files(t_list_ **files, t_options *opt, enum e_obj_type type)
{
	char			*buff;
	t_list_			*head;

	sort_list(files, opt->t ? &last_modification_cmp : &name_cmp);
	head = *files;
	if (type == __DIRECTORY && opt->l)
		print_blocks(head);
	while (head)
	{
		if (opt->l)
			additional_columns(head);
		buff = get_fact_name(head->path_name, type);
		write(1, buff, ft_strlen(buff));
		if (S_ISLNK(head->stat_obj->st_mode) && opt->l)
			print_symbolic_link(head);
		write(1, "\n", 1);
		head = head->next;
	}
	write(1, "\n", 1);
	return (EXIT_SUCCESS);
}
