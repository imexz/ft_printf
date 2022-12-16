/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:07:54 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(t_conv_spec *spec)
{
	if (spec->f_zero == 1)
		return (0);
	if (spec->f_precision > (0))
		return (0);
	if (spec->f_space == 1)
		return (0);
	if (spec->f_hash == 1)
		return (0);
	if (spec->f_plus == 1)
		return (0);
	return (1);
}

static int	ft_get_len_pointer(unsigned long nbr, t_conv_spec *spec)
{
	int	len;

	len = 0;
	if (spec->f_precision == -1 && nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len + 2);
}

static void	ft_putnbr_hex(unsigned long num)
{
	if (num > 15)
	{
		ft_putnbr_hex(num / 16);
	}
	num = num % 16;
	if (num > 9)
		num += ('a' - 10);
	else
		num += '0';
	ft_putchar_fd(num, 1);
}

static void	ft_print_p(t_conv_spec *spec, unsigned long num, int buff)
{
	if (spec->f_minus == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_hex(num);
		while (buff > 0)
		{
			ft_putchar_fd(' ', 1);
			buff--;
		}
	}
	else
	{
		while (buff > 0)
		{
			ft_putchar_fd(' ', 1);
			buff--;
		}
		ft_putstr_fd("0x", 1);
		ft_putnbr_hex(num);
	}
}

int	ft_pointer(t_conv_spec *spec, va_list arg)
{
	unsigned long	num;
	int				ret;
	int				buff;

	if (ft_valid(spec) == 0)
		return (-1);
	num = (unsigned long) va_arg(arg, void *);
	ret = ft_get_len_pointer(num, spec);
	buff = 0;
	if (spec->f_width > ret)
	{
		buff = spec->f_width - ret;
		ret = spec->f_width;
	}
	if (num == 0 && spec->f_precision == 0)
		ft_print_p_edgecase(spec, buff);
	else
		ft_print_p(spec, num, buff);
	return (ret);
}
