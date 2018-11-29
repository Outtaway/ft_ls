/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:13:59 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/10/26 20:14:00 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n <= 9 && n >= -9)
	{
		(n < 0) ? ft_putchar_fd('-', fd) : 0;
		(n < 0) ? ft_putchar_fd(-n % 10 + 48, fd)
		: ft_putchar_fd(n % 10 + 48, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		(n < 0) ? ft_putchar_fd((-n - 10) % 10 + 48, fd)
		: ft_putchar_fd((n - 10) % 10 + 48, fd);
	}
}
