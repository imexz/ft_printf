/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:26:06 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(t_conv_spec *spec, unsigned int num)
{
	char	c;

	if (spec->f_precision == 0 && num == 0)
		return ;
	if (spec->type == 'x')
		c = 'a';
	else if (spec->type == 'X')
		c = 'A';
	if (num > 15)
	{
		ft_putnbr_hex(spec, num / 16);
	}
	num = num % 16;
	if (num > 9)
		num += (c - 10);
	else
		num += '0';
	ft_putchar_fd(num, 1);
}

static void	ft_print_prefix(t_conv_spec *spec)
{
	if (spec->type == 'X')
		ft_putstr_fd("0X", 1);
	else
		ft_putstr_fd("0x", 1);
}

void	ft_print_hex_left(t_conv_spec *spec, unsigned int num)
{
	if (num != 0 && spec->f_hash == 1)
		ft_print_prefix(spec);
	while (spec->pre_buff > 0)
	{
		ft_putchar_fd('0', 1);
		spec->pre_buff--;
	}
	if (spec->f_zero == 1)
	{
		while (spec->buff > 0)
		{
			ft_putchar_fd('0', 1);
			spec->buff--;
		}
	}
	ft_putnbr_hex(spec, num);
	while (spec->buff > 0)
	{
		ft_putchar_fd(' ', 1);
		spec->buff--;
	}
}

void	ft_print_hex(t_conv_spec *spec, unsigned int num)
{
	if (spec->f_zero == 0)
	{
		while (spec->buff > 0)
		{
			ft_putchar_fd(' ', 1);
			spec->buff--;
		}
	}
	if (num != 0 && spec->f_hash == 1)
		ft_print_prefix(spec);
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
	ft_putnbr_hex(spec, num);
}
