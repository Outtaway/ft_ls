/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:33:14 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/27 14:33:15 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error_and_exit(char c)
{
	write(1, "ft_ls: illegal option -- ", 25);
	write(1, &c, 1);
	write(1, "\nusage: ./ft_ls [-larRt] [file ...]\n", 36);
	exit(EXIT_FAILURE);
}

int		set_options(char ***argv, t_options *opt, int *argc)
{
	char	*opt_set;
	char	*c;

	opt_set = "alRrt";
	while (*(++(*argv)))
	{
		if (***argv != '-')
			return (0);
		while (*(++(**argv)))
		{
			if ((c = ft_strchr(opt_set, ***argv)) == NULL)
				print_error_and_exit(***argv);
			(*c == 'a') ? opt->a = 1 : 0;
			(*c == 'l') ? opt->l = 1 : 0;
			(*c == 'R') ? opt->r_b = 1 : 0;
			(*c == 'r') ? opt->r = 1 : 0;
			(*c == 't') ? opt->t = 1 : 0;
		}
		(*argc)--;
	}
	return (0);
}

char	**set_paths(char **argv, int argc)
{
	char	**res;
	int		i;

	res = (char **)malloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (argv[i])
	{
		res[i] = ft_strnew(ft_strlen(argv[i]));
		res[i] = ft_strcpy(res[i], argv[i]);
		++i;
	}
	res[i] = NULL;
	return (res);
}

int		main(int argc, char **argv)
{
	t_options	opt;
	char		**paths;

	--argc;
	set_options(&argv, &opt, &argc);
	paths = set_paths(argv, argc);
	main_loop(paths, &opt, argc);
	return (0);
}
