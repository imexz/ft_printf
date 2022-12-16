/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:50:03 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(t_conv_spec *spec)
{
	if (spec->f_hash == 1)
		return (0);
	if (spec->f_minus == 1 && spec->f_zero == 1)
		spec->f_zero = 0;
	if (spec->f_precision > -1)
		spec->f_zero = 0;
	if (spec->f_plus == 1 && spec->f_space == 1)
		spec->f_space = 0;
	return (1);
}

static int	ft_get_max_len(t_conv_spec *spec, int len, long num)
{
	int	ret;
	int	num_dig;

	if (num < 0)
		len--;
	num_dig = len;
	if (spec->f_precision > len)
	{
		spec->pre_buff = spec->f_precision - len;
		num_dig = spec->f_precision;
	}
	if (num < 0 || spec->f_space == 1 || spec->f_plus == 1)
		len++;
	ret = len;
	if (spec->f_precision > ret)
		ret = spec->f_precision;
	if (num_dig >= len && (num < 0 || spec->f_space == 1 || spec->f_plus == 1))
		ret = num_dig + 1;
	if (spec->f_width > ret)
	{
		spec->buff = spec->f_width - ret;
		ret = spec->f_width;
	}
	return (ret);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		ft_putchar_fd('8', 1);
	}
	else if (n < 0)
	{
		ft_putnbr(n *= (-1));
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar_fd('0' + (n % 10), 1);
	}
}

static void	ft_print_left(t_conv_spec *spec, long num)
{
	char	c;

	c = ' ';
	if (num < 0)
		ft_putchar_fd('-', 1);
	else if (spec->f_space == 1)
		ft_putchar_fd(' ', 1);
	else if (spec->f_plus == 1)
		ft_putchar_fd('+', 1);
	while (spec->pre_buff > 0)
	{
		ft_putchar_fd('0', 1);
		spec->pre_buff--;
	}
	ft_putnbr(num);
	while (spec->buff > 0)
	{
		ft_putchar_fd(c, 1);
		spec->buff--;
	}
}

int	ft_int(t_conv_spec *spec, va_list arg)
{
	long	num;
	int		ret;
	int		len;

	if (ft_valid(spec) == 0)
		return (-1);
	num = (long) va_arg(arg, int);
	if (num == 0 && spec->f_precision == 0)
	{
		ret = ft_uns_int_null(spec);
		return (ret);
	}
	len = ft_get_len(num);
	ret = ft_get_max_len(spec, len, num);
	if (spec->f_minus == 1)
		ft_print_left(spec, num);
	if (spec->f_minus == 0)
		ft_print_int(spec, num);
	return (ret);
}
