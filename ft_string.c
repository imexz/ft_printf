/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:54:45 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_valid(t_conv_spec *spec)
{
	if (spec->f_zero == 1)
		return (0);
	if (spec->f_space == 1)
		return (0);
	if (spec->f_hash == 1)
		return (0);
	if (spec->f_plus == 1)
		return (0);
	return (1);
}

static void	ft_print_str(t_conv_spec *spec, char *str, char *src)
{
	int	len_src;
	int	len_str;

	len_src = ft_strlen(src);
	len_str = ft_strlen(str);
	if (spec->f_precision >= 0)
	{
		if (spec->f_precision < len_src)
			len_src = spec->f_precision;
	}
	if (spec->f_minus == 1)
		str = ft_memcpy(str, src, len_src);
	else
	{
		while (len_src > 0)
		{
			str[len_str - 1] = src[len_src - 1];
			len_src--;
			len_str--;
		}
	}
	ft_putstr_fd(str, 1);
}

static int	ft_input_null(t_conv_spec *spec)
{
	char	*s;
	char	*str;
	int		ret;

	s = "(null)";
	ret = ft_get_len_str(spec, s);
	str = malloc(sizeof(char) * ret + 1);
	if (str == 0)
		return (-1);
	str[ret] = 0;
	str = ft_memset(str, ' ', ret);
	ft_print_str(spec, str, s);
	free(str);
	return (ret);
}

int	ft_string(t_conv_spec *spec, va_list arg)
{
	char	*src;
	char	*str;
	int		ret;

	ret = ft_valid(spec);
	if (ret == 0)
		return (-1);
	src = va_arg(arg, char *);
	if (src == 0)
	{
		ret = ft_input_null(spec);
		return (ret);
	}
	ret = ft_get_len_str(spec, src);
	str = malloc(sizeof(char) * ret + 1);
	if (str == 0)
		return (-1);
	str[ret] = 0;
	str = ft_memset(str, ' ', ret);
	ft_print_str(spec, str, src);
	free(str);
	return (ret);
}
