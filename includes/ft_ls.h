/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:35:04 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/27 14:35:05 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "list.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <stdio.h>

# define _ERROR(code, msg) if (code) { ft_printf("%s\n", msg); exit(code); };

enum			e_obj_type
{
	__DIRECTORY,
	__FILE
}				obj_type;

typedef struct	s_options
{
	unsigned char	enabled : 1;
	unsigned char	a : 1;
	unsigned char	l : 1;
	unsigned char	r_b : 1;
	unsigned char	r : 1;
	unsigned char	t : 1;
}				t_options;

int				main_loop(char **paths, t_options *opt, int paths_count);
int				process_files(t_list_ **files, t_options *opt,
				enum e_obj_type type);
int				process_dirs(t_list_ **dirs, t_options *opt, int paths_count);
int				print_atributes(mode_t st_mode);
int				fill_list(char *path_name, t_options *opt,
				t_list_ **files, t_list_ **dirs);
void			sort_list(t_list_ **list, int (*f)(t_list_ *, t_list_ *),
							t_options *opt);
void			print_symbolic_link(t_list_ *list);
char			*get_fact_name(char *full_path, enum e_obj_type type);
char			*create_name(char *prev, char *new);

#endif
