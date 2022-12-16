/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:33:07 by mstrantz          #+#    #+#             */
/*   Updated: 2022/12/16 13:28:44 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_read_flags(char **format, t_conv_spec *ptr_spec)
{
	char	*flags;

	flags = "-0 +#";
	while (ft_strchr(flags, **format))
	{
		if (**format == '-')
			ptr_spec->f_minus = 1;
		else if (**format == '0')
			ptr_spec->f_zero = 1;
		else if (**format == ' ')
			ptr_spec->f_space = 1;
		else if (**format == '+')
			ptr_spec->f_plus = 1;
		else if (**format == '#')
			ptr_spec->f_hash = 1;
		(*format)++;
	}
	return (0);
}

static void	ft_read_width(char **format, t_conv_spec *ptr_spec, va_list arg)
{
	int	width;

	if (**format == '*')
	{
		width = va_arg(arg, int);
		if (width < 0)
		{
			ptr_spec->f_minus = 1;
			ptr_spec->f_width = (width * (-1));
		}
		else
			ptr_spec->f_width = width;
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		ptr_spec->f_width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

static void	ft_read_precision(char **format, t_conv_spec *ptr_spec, va_list arg)
{
	int	precision;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(arg, int);
			if (precision < 0)
				ptr_spec->f_precision = (-1);
			else
				ptr_spec->f_precision = precision;
			(*format)++;
		}
		else if (ft_isdigit((**format)))
		{
			ptr_spec->f_precision = ft_atoi(*format);
			while (ft_isdigit((**format)))
				(*format)++;
		}
		else if (**format == 's' || **format == 'p' || **format == 'x' \
			|| **format == 'X' || **format == 'u' || **format == 'd' \
			|| **format == 'i')
			ptr_spec->f_precision = 0;
	}
}

static int	ft_read_specifier(char **format, t_conv_spec *ptr_spec, va_list arg)
{
	char	*type;
	int		ret;

	type = "cspdiuxX%";
	ret = 0;
	if (ft_strchr(type, **format))
		ret = ft_specifier(format, ptr_spec, arg);
	else
		return (-1);
	(*format)++;
	return (ret);
}

int	ft_read_conv_spec(char **format, va_list arg)
{
	t_conv_spec	*ptr_spec;
	int			ret;

	ptr_spec = ft_new_list();
	if (ptr_spec == 0)
		return (-1);
	ret = ft_read_flags(format, ptr_spec);
	if (ret != 0)
	{
		free(ptr_spec);
		if (ret == -1)
			return (-1);
		else
			return (1);
	}
	ft_read_width(format, ptr_spec, arg);
	ft_read_precision(format, ptr_spec, arg);
	ret = ft_read_specifier(format, ptr_spec, arg);
	if (ret == -1)
	{
		free(ptr_spec);
		return (-1);
	}
	free(ptr_spec);
	return (ret);
}
