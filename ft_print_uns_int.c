/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:12:38 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned long n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
}

static void	ft_print_zeroflag(t_conv_spec *spec, long num)
{
	while (spec->buff > 0)
	{
		ft_putchar_fd('0', 1);
		spec->buff--;
	}
	while (spec->pre_buff > 0)
	{
		ft_putchar_fd('0', 1);
		spec->pre_buff--;
	}
	ft_putnbr(num);
}

static void	ft_print_without_zeroflag(t_conv_spec *spec, long num)
{
	while (spec->buff > 0)
	{
		ft_putchar_fd(' ', 1);
		spec->buff--;
	}
	while (spec->pre_buff > 0)
	{
		ft_putchar_fd('0', 1);
		spec->pre_buff--;
	}
	ft_putnbr(num);
}

void	ft_print_uns_int(t_conv_spec *spec, unsigned long num)
{
	if (spec->f_zero == 1)
		ft_print_zeroflag(spec, num);
	else
		ft_print_without_zeroflag(spec, num);
}
