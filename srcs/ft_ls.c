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

int		set_options(char *argv, t_options *options)
{
	char	*options_set;
	char	*c;

	if (argv[0] != '-')
		return (0);
	argv++;
	options_set = "alRrt";
	while (*argv)
	{
		if ((c = ft_strchr(options_set, *argv)) == NULL)
			return (EXIT_FAILURE);
		(*c == 'a') ? options->a = 1 : 0;
		(*c == 'l') ? options->l = 1 : 0;
		(*c == 'R') ? options->R = 1 : 0;
		(*c == 'r') ? options->r = 1 : 0;
		(*c == 't') ? options->t = 1 : 0;
		argv++;
	}
	options->enabled = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	t_options	options;

	if (argc > 1)
		_ERROR(set_options(argv[1], &options), "ft_ls: illegal option -- ");
	argv++;
	argc--;
	(options.enabled) ? argv++ && argc-- : 0;
	main_loop(argv, &options, argc);
	return (0); 
}
