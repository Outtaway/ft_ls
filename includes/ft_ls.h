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

typedef struct	s_options
{
	unsigned char	enabled : 1;
	unsigned char	a : 1;
	unsigned char	l : 1;
	unsigned char	R : 1;
	unsigned char	r : 1;
	unsigned char	t : 1;
}				t_options;

int		main_loop(char **paths, t_options *options, int paths_count);

#endif
