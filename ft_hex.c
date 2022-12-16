/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:10:39 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(t_conv_spec *spec)
{
	if (spec->f_space == 1 || spec->f_plus == 1)
		return (0);
	if (spec->f_minus == 1 && spec->f_zero == 1)
		spec->f_zero = 0;
	if (spec->f_precision > -1)
		spec->f_zero = 0;
	return (1);
}

static int	ft_get_len_hex(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int	ft_get_max_len(t_conv_spec *spec, int len, unsigned int num)
{
	int	ret;

	ret = len;
	if (spec->f_precision > ret)
	{
		spec->pre_buff = spec->f_precision - ret;
		ret = spec->f_precision;
	}
	if (spec->f_width > ret)
	{
		spec->buff = spec->f_width - ret;
		ret = spec->f_width;
	}
	if (num != 0 && spec->f_hash == 1 && spec->buff == 0)
		ret += 2;
	else if (num != 0 && spec->f_hash == 1 && spec->buff == 1)
	{
		ret ++;
		spec->buff--;
	}
	else if (num != 0 && spec->f_hash == 1 && spec->buff >= 2)
		spec->buff -= 2;
	return (ret);
}

int	ft_hex(t_conv_spec *spec, va_list arg)
{
	unsigned int	num;
	int				ret;
	int				len;

	if (ft_valid(spec) == 0)
		return (-1);
	num = (unsigned int) va_arg(arg, int);
	if (num == 0 && spec->f_precision == 0)
	{
		ret = ft_uns_int_null(spec);
		return (ret);
	}
	len = ft_get_len_hex(num);
	ret = ft_get_max_len(spec, len, num);
	if (spec->f_minus == 1)
		ft_print_hex_left(spec, num);
	if (spec->f_minus == 0)
		ft_print_hex(spec, num);
	return (ret);
}
