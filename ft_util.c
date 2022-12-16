/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:10:32 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** used in ft_int.c
** usedd in ft_uns_int.c
*/

int	ft_get_len(long num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	if (num < 0)
		num *= (-1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/*
** used in ft_string.c
*/

static int	ft_helper(t_conv_spec *spec, int len, int passed_ret)
{
	int	ret;

	ret = passed_ret;
	if (spec->f_width > spec->f_precision)
		ret = spec->f_width;
	else if (spec->f_width < spec->f_precision && spec->f_precision < len)
		ret = spec->f_precision;
	else if (spec->f_width < spec->f_precision && spec->f_precision > len \
			&& spec->f_width < len)
		ret = len;
	else if (spec->f_width < spec->f_precision && spec->f_precision > len \
			&& spec->f_width > len)
		ret = spec->f_width;
	else if (spec->f_width == spec->f_precision)
		ret = spec->f_width;
	return (ret);
}

int	ft_get_len_str(t_conv_spec *spec, char *str)
{
	int	ret;
	int	len;

	len = ft_strlen(str);
	if (spec->f_precision == 0)
		len = 0;
	ret = len;
	if (len < spec->f_width)
		ret = spec->f_width;
	if (spec->f_precision > spec->f_width && spec->f_precision < len \
		&& spec->f_precision > 0)
		ret = spec->f_precision;
	if (spec->f_width > 0 && spec->f_precision > 0)
		ret = ft_helper(spec, len, ret);
	return (ret);
}

/*
** used in ft_read_specifier.c
*/

int	ft_specifier(char **format, t_conv_spec *ptr_spec, va_list arg)
{
	int	ret;

	ret = 0;
	ptr_spec->type = **format;
	if (**format == 'c')
		ret = ft_char(ptr_spec, arg);
	else if (**format == 's')
		ret = ft_string(ptr_spec, arg);
	else if (**format == 'p')
		ret = ft_pointer(ptr_spec, arg);
	else if (**format == 'd' || **format == 'i')
		ret = ft_int(ptr_spec, arg);
	else if (**format == 'u')
		ret = ft_unsigned_int(ptr_spec, arg);
	else if (**format == 'x' || **format == 'X')
		ret = ft_hex(ptr_spec, arg);
	else if (**format == '%')
		ret = ft_percentage(ptr_spec);
	return (ret);
}
